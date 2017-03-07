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

void			fractal_julia(double complex z[2])
{
	z[1] = (z[1] * z[1]) + z[0];
}

void				fractal_julia1(double complex z[2])
{
	z[1] = (z[1] * z[1]) + z[0];
}

void			fractal_mandelbrot(double complex z[2])
{
	z[1] = (z[1] * z[1] * z[1]) + z[1];
}

void			fractal_mandelbrot1(double complex z[2])
{
	z[1] = (z[1] * z[1] * z[1] * z[1]) + z[1];
}

void			fractal_mandelbrot2(double complex z[2])
{
	z[1] = (z[1] * z[1] * z[1] * z[1] * z[1]) + z[1];
}
