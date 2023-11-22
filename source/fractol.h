/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:43:58 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/22 19:27:45 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/libft_updated/base/libft.h"
# include "../includes/libft_updated/printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SCROLL_UP 4
# define SCROLL_DOWN 5


typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	char	set;
	double	julia1;
	double	julia2;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_fractal;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

	//initialisation
	int	argv_check(char *str);
	int	args_check(int argc, char **argv);
	void	init_fractal(t_fractal *fractal, int argc, char **argv);
	
	//hooks
	int	key_hook(int hook, t_fractal *fractal);

	//msg
	int		print_params(void);
	void	print_commands(void);

#endif