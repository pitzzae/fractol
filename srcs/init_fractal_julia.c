/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:45:57 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:26:22 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_data		ftl_init_julia(t_data data)
{
	data.ref_x = 0.121312;
	data.ref_y = 0.045659;
	data.c_point.real = -0.0988;
	data.c_point.imag = -0.65186;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_julia;
	return (data);
}

t_data		ftl_init_julia1(t_data data)
{
	data.ref_x = 0.121312;
	data.ref_y = 0.045659;
	data.c_point.real = -0.772691322542185;
	data.c_point.imag = 0.124281466072787;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_julia;
	return (data);
}

t_data		ftl_init_julia2(t_data data)
{
	data.ref_x = 0.121312;
	data.ref_y = 0.045659;
	data.c_point.real = -0.0688;
	data.c_point.imag = -0.65986;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_julia;
	return (data);
}

t_data		ftl_init_julia3(t_data data)
{
	data.ref_x = 0.121312;
	data.ref_y = 0.045659;
	data.c_point.real = 0.552000;
	data.c_point.imag = 0.552000;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_julia1;
	return (data);
}

t_data		ftl_init_julia4(t_data data)
{
	data.ref_x = 0.121312;
	data.ref_y = 0.045659;
	data.c_point.real = 0.5512;
	data.c_point.imag = -0.039860;
	data.r_point.real = data.c_point.real;
	data.r_point.imag = data.c_point.imag;
	data.ft_fract = fractal_julia1;
	return (data);
}
