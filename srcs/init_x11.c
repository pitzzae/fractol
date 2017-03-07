/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:42:05 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 13:39:52 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				init_x11(char *str)
{
	t_data			data;

	data.zoom = 200;
	data.move = 1;
	data = select_fractol(data, scan_fractol(str));
	if ((data.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.win = mlx_new_window(data.mlx, W_W, W_H, "Fractol")) == NULL)
		return (EXIT_FAILURE);
	ft_putendl(str);
	mlx_expose_hook(data.win, ftl_expose_hook, &data);
	mlx_mouse_hook(data.win, &ft_mouse_action, &data);
	mlx_hook(data.win, 2, (1L << 0), &get_key_action, &data);
	mlx_hook(data.win, 6, (1L << 6), &ft_mouse_motion, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
