/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complexe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:41:42 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 13:40:09 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	ft_cplx_add(t_complex z1, t_complex z2)
{
	t_complex		r;

	r.real = z1.real + z2.real;
	r.imag = z1.imag + z2.imag;
	return (r);
}

t_complex	ft_cplx_pow(t_complex z1, int p)
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
			r = ft_cplx_mul(r, z1);
			loop++;
		}
	}
	return (r);
}

t_complex	ft_cplx_mul(t_complex z1, t_complex z2)
{
	t_complex		r;

	r.real = z1.real * z2.real - z1.imag * z2.imag;
	r.imag = z1.real * z2.imag + z1.imag * z2.real;
	return (r);
}

double		ft_cabs(t_complex z)
{
	double			r;

	r = z.real * z.real + z.imag * z.imag;
	return (r);
}
