/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:13:28 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 13:44:46 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		put_pixel_to_img(double px[2], t_data *e, int color)
{
	int i;

	i = ((int)px[0] * 4) + ((int)px[1] * e->img_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}

static int		get_color_px(t_complex z[2],
				void (*fract)(t_complex z[2]), int max_c)
{
	int				c;
	int				d;
	int				g;

	d = 0;
	g = 0;
	c = 0x000000;
	while (ft_cabs(z[1]) < 4 && c < max_c)
	{
		fract(z);
		if (d < 50)
		{
			c += 0x00800;
			d = 0;
		}
		if ((g % 3) == 0)
			c += 0x060000;
		c += 0x000015;
		d++;
		g++;
	}
	return (c);
}

static void		ft_put_pixel(t_data *data, int px[2])
{
	t_complex		z[2];
	double			px2[2];

	z[0].real = data->c_point.real;
	z[0].imag = data->c_point.imag;
	z[1].real = ((px[0] / data->zoom) + data->ref_x);
	z[1].imag = ((px[1] / data->zoom + data->ref_y));
	px2[0] = px[0] + (W_W / 2);
	px2[1] = px[1] + (W_H / 2);
	put_pixel_to_img(px2, data, get_color_px(z, data->ft_fract, 0xFFFFFF));
}

void			*print_screen(void *s_data)
{
	int			px[2];
	t_thread	*data;

	data = (t_thread*)s_data;
	px[0] = data->s.start;
	while (px[0] < data->s.len)
	{
		px[1] = -(W_H / 2);
		while (px[1] < W_H / 2)
		{
			ft_put_pixel(data->d, px);
			px[1]++;
		}
		px[0]++;
	}
	pthread_exit(NULL);
}
