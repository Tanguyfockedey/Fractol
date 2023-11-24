/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:58:06 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/24 22:18:25 by tafocked         ###   ########.fr       */
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

void	init_fractal(t_fractal *f, int argc, char **argv)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->image, &f->bpp, &f->size_line, &f->endian);
	if (argc == 4)
	{
		f->set = 'J';
		f->jr = ft_atof(argv[2]);
		f->ji = ft_atof(argv[3]);
	}
	else
	{
		f->set = argv[1][0];
		f->jr = -0.1;
		f->ji = 0.651;
	}
	f->max_iter = 50;
	f->max_r = 5.;
	f->max_i = f->max_r * HEIGHT / WIDTH;
}