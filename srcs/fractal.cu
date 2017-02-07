/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.cu                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:44:36 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:26:41 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include "fractol.h"
}

#include <stdio.h>

__device__
t_complex	ft_cplx_add_cuda(t_complex z1, t_complex z2)
{
	t_complex		r;

	r.real = z1.real + z2.real;
	r.imag = z1.imag + z2.imag;
	return (r);
}

__device__
t_complex	ft_cplx_mul_cuda(t_complex z1, t_complex z2)
{
	t_complex		r;

	r.real = z1.real * z2.real - z1.imag * z2.imag;
	r.imag = z1.real * z2.imag + z1.imag * z2.real;
	return (r);
}

__device__
t_complex	ft_cplx_pow_cuda(t_complex z1, int p)
{
	t_complex		r;
	int				loop;

	loop = 0;
	r.real = z1.real;
	r.imag = z1.imag;
	if (p > 0)
	{
		while (loop < p)
		{
			r = ft_cplx_mul_cuda(r, z1);
			loop++;
		}
	}
	return (r);
}

__global__
void ft_cplx_cuda(double *i, double *j)
{
	t_complex		z[2];

	z[0].real = i[0];
	z[0].imag = i[1];
	z[1].real = j[0];
	z[1].imag = j[1];
	z[1] = ft_cplx_add_cuda(ft_cplx_mul_cuda(z[1], z[1]), z[0]);
	j[0] = z[1].real;
	j[1] = z[1].imag;
}

double				*convert_cplx(t_complex z)
{
	double			*c;

	c = (double*)malloc(2*sizeof(double));
	c[0] = z.real;
	c[1] = z.imag;
	return(c);
}

void				fractal_julia(t_complex z[2])
{
	double			*i;
	double			*j;
	double			*res;
	int				N;
	int 			size;

	double *test1;
	double *test2;

	test1 = convert_cplx(z[0]);
	test2 = convert_cplx(z[1]);

	N = 2;
	size = N*sizeof(double);
	cudaMalloc((void**)&i, size);
	cudaMalloc((void**)&j, size);
	res = (double*)malloc(2*sizeof(double));

	cudaMemcpy(i, test1, size, cudaMemcpyHostToDevice);
	cudaMemcpy(j, test2, size, cudaMemcpyHostToDevice);

	dim3 dimBlock(1, 1);
	dim3 dimGrid(1, 1);
	ft_cplx_cuda<<<dimGrid, dimBlock>>>(i, j);

	cudaMemcpy(res, j, size, cudaMemcpyDeviceToHost);
	cudaFree(i);
	cudaFree(j);
	free(test1);
	free(test2);
}

void				fractal_julia1(t_complex z[2])
{
	z[1] = ft_cplx_add(ft_cplx_pow(z[1], 3), z[0]);
}

void				fractal_mandelbrot(t_complex z[2])
{
	z[1] = ft_cplx_add(ft_cplx_pow(z[1], 3), z[1]);
}

void				fractal_mandelbrot1(t_complex z[2])
{
	z[1] = ft_cplx_add(ft_cplx_pow(z[1], 5), z[1]);
}

void				fractal_mandelbrot2(t_complex z[2])
{
	z[1] = ft_cplx_add(ft_cplx_pow(z[1], 8), z[1]);
}
