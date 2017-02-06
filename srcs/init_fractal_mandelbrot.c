/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:45:57 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:26:09 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_data		ftl_init_mandelbrot(t_data data)
{
	data.ref_x = 0;
	data.ref_y = 0;
	data.c_point.real = 0;
	data.c_point.imag = 0;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_mandelbrot;
	return (data);
}

t_data		ftl_init_mandelbrot1(t_data data)
{
	data.ref_x = 0;
	data.ref_y = 0;
	data.c_point.real = 0;
	data.c_point.imag = 0;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_mandelbrot1;
	return (data);
}

t_data		ftl_init_mandelbrot2(t_data data)
{
	data.ref_x = 0;
	data.ref_y = 0;
	data.c_point.real = 0;
	data.c_point.imag = 0;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_mandelbrot2;
	return (data);
}
