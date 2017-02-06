/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:16:29 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/13 16:16:31 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void			make_thread(t_data *data)
{
	pthread_t	thread[THREAD];
	t_thread	t_th[THREAD];
	int			t;

	t = 0;
	while (t < THREAD)
	{
		t_th[t].d = data;
		t_th[t].s.start = -(W_W / 2) + (t * (W_W / THREAD));
		t_th[t].s.len = (W_W / THREAD) + t_th[t].s.start;
		pthread_create(&thread[t], NULL, print_screen, &t_th[t]);
		t++;
	}
	t = 0;
	while (t < THREAD)
	{
		pthread_join(thread[t], NULL);
		t++;
	}
}

int					ftl_expose_hook(t_data *data)
{
	data->img = mlx_new_image(data->mlx, W_W, W_H);
	data->pixel_img = mlx_get_data_addr(data->img, &(data->bpp),
		&(data->img_line), &(data->ed));
	make_thread(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}
