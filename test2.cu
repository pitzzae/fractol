#include <stdio.h>

__global__ void helloCUDA(int **f)
{
  printf("Hello thread %d, %d, %d, %d, %d, %d, f=%d\n", 
  	threadIdx.x, threadIdx.y, blockIdx.x, blockIdx.y, blockDim.x, blockDim.y, f[threadIdx.y][threadIdx.x]);
}

int main()
{
	int	H = 32;
	int	W = 32;

	int *h_A = new int[W];
	for (int i = 0; i < W; i++)
	{
	    h_A[i] = i;
	    printf("%d\n", i);
	}

	int	**h_AA;
	h_AA = (int**)malloc(H* sizeof(int*));
	for (int i = 0; i < H; i++)
	{
	    cudaMalloc((void **)&h_AA[i], W * sizeof(int));
	    cudaMemcpy(h_AA[i], h_A, W * sizeof(int), cudaMemcpyHostToDevice);
	}

	int	**d_AA;
	cudaMalloc(&d_AA, H * sizeof(int*));
	cudaMemcpy(d_AA, h_AA, H * sizeof(int*), cudaMemcpyHostToDevice);

	dim3 dimBlock(H, W);
	dim3 dimGrid(100, 100);
	helloCUDA<<<dimGrid, dimBlock>>>(d_AA);
	printf("%s\n", "END");
	cudaDeviceReset();
	return 0;
}
//nvcc -arch=sm_20 test.cu -run