// This is the REAL "hello world" for CUDA!
// It takes the string "Hello ", prints it, then passes it to CUDA with an array
// of offsets. Then the offsets are added in parallel to produce the string "World!"
// By Ingemar Ragnemalm 2010
 
#include <stdio.h>

const int N = 7;
const int blocksize = 7;

__device__
int		ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0')
		count++;
	return (((unsigned char)s1[count] - (unsigned char)s2[count]));
}

__device__
char *test(void)
{
	return ("NOK");
}

__global__
void hello(char *a, int *b)
{
	if (ft_strcmp("OK", test()) == 0)
		a[threadIdx.x] += b[threadIdx.x];
}

int main()
{
	char a[N] = "Hello ";
	int b[N] = {15, 10, 6, 0, -11, 1, 0};

	char *ad;
	int *bd;
	const int csize = N*sizeof(char);
	const int isize = N*sizeof(int);

	//printf("%s", a);

	cudaMalloc( (void**)&ad, csize );
	cudaMalloc( (void**)&bd, isize );
	cudaMemcpy( ad, a, csize, cudaMemcpyHostToDevice );
	cudaMemcpy( bd, b, isize, cudaMemcpyHostToDevice );

	dim3 dimBlock( blocksize, 1 );
	dim3 dimGrid( 1, 1 );
	hello<<<dimGrid, dimBlock>>>(ad, bd);
	cudaMemcpy( a, ad, csize, cudaMemcpyDeviceToHost );
	cudaFree( ad );

	printf("%s\n", a);
	return EXIT_SUCCESS;
}
