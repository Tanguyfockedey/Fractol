/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:43:58 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/26 18:08:52 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/libft_updated/base/libft.h"
# include "../includes/libft_updated/printf/ft_printf.h"
# include <mlx.h>

# define WIDTH 1000
# define HEIGHT 1000

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define DEC 78
# define INC 69
# define R 15
# define J 38
# define C 8

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	char	set;
	double	jr;
	double	jr_copy;
	double	ji;
	double	ji_copy;
	int		bpp;
	int		size_line;
	int		endian;
	int		max_iter;
	double	max_r;
	double	max_i;
	double	offset_x;
	double	offset_y;
	int		color_start;
	int		color_step;
}	t_fractal;

	//hooks
int	key_hook(int hook, t_fractal *f);
int	mouse_hook(int hook, int x, int y, t_fractal *f);
int	event_hook(void);

	//initialisation
int	argv_check(char *str);
int	args_check(int argc, char **argv);
void	init_fractal(t_fractal *fractal, int argc, char **argv);

	//key_events
void	inc_iter(t_fractal *f);
void	dec_iter(t_fractal *f);
void	reset(t_fractal *f);
void	rand_julia(t_fractal *f);
void	color_change(t_fractal *f);

	//msg
int		print_params(void);
void	print_commands(void);

	//rendering
void	render(t_fractal *f);
void	zoom(t_fractal *f, int x, int y, double scale);
void	move(t_fractal *f, double x, double y);
void	color_pixel(t_fractal *f, int x_pix, int y_pix, int color);

	//sets
int	calculate_set(t_fractal *f, double cr, double ci);
int	mandelbrot(t_fractal *f, double cr, double ci);
int	julia(t_fractal *f, double zr, double zi);
int	burning_ship(t_fractal *f, double cr, double ci);

#endif