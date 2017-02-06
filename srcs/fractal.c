/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:44:36 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:26:41 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void				fractal_julia(t_complex z[2])
{
	z[1] = ft_cplx_add(ft_cplx_mul(z[1], z[1]), z[0]);
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
