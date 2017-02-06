/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:48:27 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/19 15:27:42 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			scan_fractol(char *frac)
{
	if (ft_strcmp(frac, "julia") == 0)
		return (1);
	if (ft_strcmp(frac, "julia1") == 0)
		return (2);
	if (ft_strcmp(frac, "julia2") == 0)
		return (3);
	if (ft_strcmp(frac, "julia3") == 0)
		return (4);
	if (ft_strcmp(frac, "julia4") == 0)
		return (5);
	if (ft_strcmp(frac, "mandelbrot") == 0)
		return (6);
	if (ft_strcmp(frac, "mandelbrot1") == 0)
		return (7);
	if (ft_strcmp(frac, "mandelbrot2") == 0)
		return (8);
	return (0);
}

t_data		select_fractol(t_data data, int frac)
{
	if (frac == 1)
		data = ftl_init_julia(data);
	if (frac == 2)
		data = ftl_init_julia1(data);
	if (frac == 3)
		data = ftl_init_julia2(data);
	if (frac == 4)
		data = ftl_init_julia3(data);
	if (frac == 5)
		data = ftl_init_julia4(data);
	if (frac == 6)
		data = ftl_init_mandelbrot(data);
	if (frac == 7)
		data = ftl_init_mandelbrot1(data);
	if (frac == 8)
		data = ftl_init_mandelbrot2(data);
	return (data);
}

void		ft_error_print(int argc, char *str)
{
	if (argc != 2 || scan_fractol(str) == 0)
	{
		ft_putendl("Argv error:");
		ft_putstr("-option:\njulia\njulia1\njulia2\njulia3\njulia4\n");
		ft_putendl("mandelbrot\nmandelbrot1\nmandelbrot2");
	}
}

int			main(int argc, char **argv)
{
	char		*error;

	error = ft_strdup("Argv error-option:juliajulia1julia2");
	if (argc == 2 && scan_fractol(argv[1]) != 0)
	{
		ft_putstr("Fractol selected ");
		ft_putendl(argv[1]);
		init_x11(argv[1]);
	}
	ft_error_print(argc, argv[1]);
	return (0);
}
