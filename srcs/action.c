/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 04:26:54 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:35:58 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				ft_mouse_action(int button, int x, int y, t_data *data)
{
	if (button == 3 && data->move == 1)
		data->move = 0;
	else if (button == 3 && data->move == 0)
		data->move = 1;
	if (button == 5)
		data->zoom = data->zoom * 2;
	if (button == 4 && data->zoom > 1)
		data->zoom = data->zoom / 2;
	if (button == 4 || button == 5)
	{
		ftl_expose_hook(data);
	}
	return (0);
}

int				ft_mouse_motion(int x, int y, t_data *data)
{
	if (data->move == 1)
	{
		data->c_point.real = data->r_point.real + (double)x / 50000;
		data->c_point.imag = data->r_point.imag + (double)x / 50000;
		ftl_expose_hook(data);
	}
	return (0);
}

int				get_key_action(int key, t_data *data)
{
	if ((key == 53 || key == 65307))
		exit(EXIT_SUCCESS);
	if (key == 126 || key == 65362)
		data->ref_y -= 50 / data->zoom;
	if (key == 125 || key == 65364)
		data->ref_y += 50 / data->zoom;
	if (key == 124 || key == 65361)
		data->ref_x += 50 / data->zoom;
	if (key == 123 || key == 65363)
		data->ref_x -= 50 / data->zoom;
	if (key == 126 || key == 125 || key == 124 || key == 123
		|| key == 65362 || key == 65364 || key == 65361 || key == 65363)
	{
		ftl_expose_hook(data);
	}
	return (0);
}
