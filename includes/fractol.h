/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:52:56 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/10 20:39:53 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_W 1024
# define W_H 768
# define THREAD 128
# define CMPLX(x, y) ((double complex)((double)(x) + I * (double)(y)))
# include <libft.h>
# include <mlx.h>
# include <pthread.h>
# include <complex.h> 

typedef struct	s_screen
{
	int				start;
	int				len;
}				t_screen;

typedef struct	s_complex
{
	double			real;
	double			imag;
}				t_complex;

typedef struct	s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel_img;
	int				ed;
	int				bpp;
	int				img_line;
	double			zoom;
	double			ref_x;
	double			ref_y;
	int				move;
	t_screen		*screen;
	t_complex		c_point;
	t_complex		r_point;
	void			*ft_fract;
}				t_data;

typedef struct	s_thread
{
	t_data			*d;
	t_screen		s;
}				t_thread;

int				init_x11(char *str);
int				get_key_action(int key, t_data *data);
int				ftl_expose_hook(t_data *data);
int				ft_mouse_action(int button, int x, int y, t_data *data);
int				ft_mouse_motion(int x, int y, t_data *data);
void			*print_screen(void *s_data);
int				ftl_expose_hook(t_data *data);
void			fractal_julia(double complex z[2]);
void			fractal_julia1(double complex z[2]);
void			fractal_mandelbrot(double complex z[2]);
void			fractal_mandelbrot1(double complex z[2]);
void			fractal_mandelbrot2(double complex z[2]);
t_data			select_fractol(t_data data, int frac);
int				scan_fractol(char *frac);
t_data			ftl_init_julia(t_data data);
t_data			ftl_init_julia1(t_data data);
t_data			ftl_init_julia2(t_data data);
t_data			ftl_init_julia3(t_data data);
t_data			ftl_init_julia4(t_data data);
t_data			ftl_init_mandelbrot(t_data data);
t_data			ftl_init_mandelbrot1(t_data data);
t_data			ftl_init_mandelbrot2(t_data data);
double			ft_cabs(t_complex z);
t_complex		ft_cplx_mul(t_complex z1, t_complex z2);
t_complex		ft_cplx_add(t_complex z1, t_complex z2);
t_complex		ft_cplx_pow(t_complex z1, int p);

#endif
