#include <stdio.h>
#include <stdlib.h>
 
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
 
#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

typedef struct	s_complex
{
	double			real;
	double			imag;
}				t_complex;

void		ft_cplx_mul(t_complex* a)
{
	double			tmp[2];

	tmp[0] = a[3].real;
	tmp[1] = a[3].imag;
	a[3].real = tmp[0] * tmp[0] - tmp[1] * tmp[1];
	a[3].imag = tmp[0] * tmp[1] + tmp[1] * tmp[0];
}

t_complex	ft_cplx_pow(t_complex* a, int p)
{
	int				loop;

	loop = 0;
	a[3].real = a[1].real;
	a[3].imag = a[1].imag;
	if (p > 0)
	{
		while (loop < p)
		{
			ft_cplx_mul(a);
			loop++;
		}
	}
	return (a[3]);
} 

int main()
{
	cl_device_id device_id = NULL;
	cl_context context = NULL;
	cl_command_queue command_queue = NULL;
	cl_mem memobj = NULL;
	cl_mem memobj2 = NULL;
	cl_program program = NULL;
	cl_kernel kernel = NULL;
	cl_platform_id platform_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret;
	 
	char string[MEM_SIZE];
	 
	FILE *fp;
	char fileName[] = "./hello.cl";
	char *source_str;
	size_t source_size;
	 
	/* Load the source code containing the kernel*/
	fp = fopen(fileName, "r");
	if (!fp) {
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	 
	/* Get Platform and Device Info */
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
	 
	/* Create OpenCL context */
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	 
	/* Create Command Queue */
	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	 
	/* Create Memory Buffer */
	memobj = clCreateBuffer(context, CL_MEM_READ_WRITE,MEM_SIZE * sizeof(char), NULL, &ret);
	 
	t_complex *a;
	t_complex *b;
	a = (t_complex*)malloc(sizeof(t_complex) * MEM_SIZE);
	b = (t_complex*)malloc(sizeof(t_complex) * MEM_SIZE);
	a->real = 12;
	a->imag = 24;

	b[1].real = 12;
	b[1].imag = 24;
	memobj2 = clCreateBuffer(context, CL_MEM_USE_HOST_PTR, MEM_SIZE * sizeof(t_complex), a, &ret);


	/* Create Kernel Program from the source */
	program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
	(const size_t *)&source_size, &ret);
	 
	/* Build Kernel Program */
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	 
	/* Create OpenCL Kernel */
	kernel = clCreateKernel(program, "hello", &ret);
	 
	/* Set OpenCL Kernel Parameters */
	//ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj2);
	 
	/* Execute OpenCL Kernel */
	ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
	 
	/* Copy results from the memory buffer */
	ret = clEnqueueReadBuffer(command_queue, memobj2, CL_FALSE, 0,
	MEM_SIZE * sizeof(t_complex),b, 0, NULL, NULL);
	 
	/* Display Result */
	printf("b0->real = %f b0->imag %f\n", b[0].real, b[0].imag);
	printf("b1->real = %f b1->imag %f\n", b[1].real, b[1].imag);
	printf("b2->real = %f b2->imag %f\n", b[2].real, b[2].imag);
	printf("a->real = %f a->imag %f\n", a->real, a->imag);
	 
	b[2] = ft_cplx_pow(b, 12345678);

	printf("a->real = %f a->imag %f\n", b[2].real, b[2].imag);
	/* Finalization */
	ret = clFlush(command_queue);
	ret = clFinish(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(memobj);
	ret = clReleaseMemObject(memobj2);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	 
	free(source_str);
	 
	return 0;
}