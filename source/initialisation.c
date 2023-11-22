/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:58:06 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/22 20:02:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	argv_check(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '.')
		i++;
	if (!str[i])
		return (1);
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	args_check(int argc, char **argv)
{
	double	a;
	double	b;

	if (argc == 2 && (!ft_strncmp(argv[1], "M", 2)
					|| !ft_strncmp(argv[1], "Mandelbrot", 11)
					|| !ft_strncmp(argv[1], "J", 2)
					|| !ft_strncmp(argv[1], "Julia", 6)
					|| !ft_strncmp(argv[1], "B", 2)
					|| !ft_strncmp(argv[1], "Burning Ship", 13)))
		return (1);
	if (argc == 4 && (!ft_strncmp(argv[1], "J", 2)
					|| !ft_strncmp(argv[1], "Julia", 6)))
	{
		if (!argv_check(argv[2]) || !argv_check(argv[3]))
			return (print_params()); 
		a = ft_atof(argv[2]);
		b = ft_atof(argv[3]);
		if (a >= -2. && a <= 2. && b >= -2. && b <= 2.)
			return (1);
	}
	return (print_params());
}

void	init_fractal(t_fractal *fractal, int argc, char **argv)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fract'ol");
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (argc == 4)
	{
		fractal->set = 'J';
		fractal->julia1 = ft_atof(argv[2]);
		fractal->julia2 = ft_atof(argv[3]);
	}
	else
	{
		fractal->set = argv[1][0];
		fractal->julia1 = 0.;
		fractal->julia2 = 0.;
	}
}