/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/24 19:25:02 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_axis(t_fractal *data)
{
	char	*dst;
	int		x;
	int		y;

	x = 1;
	y = 540;
	while (x < WIDTH)
	{
		dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int*)dst = 0x00FFFFFF;
		x++;
	}
	x = 960;
	y = 1;
	while (y < HEIGHT)
	{
		dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int*)dst = 0x00FFFFFF;
		y++;
	}
}

void	my_circle(t_fractal *data, int radius)
{
	char *px;
	int offset_x = WIDTH / 2;
	int offset_y = HEIGHT / 2;
	int x = -radius;
	int y;
	
	while (x <= radius)
	{
		y = (int)(sqrt(pow((double)radius, 2.) - pow((double)x, 2.)));
		px = data->addr + ((y + offset_y) * data->size_line + (x + offset_x) * (data->bpp / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		px = data->addr + ((-y + offset_y) * data->size_line + (x + offset_x) * (data->bpp / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		x++;
	}
}

void	my_square(t_fractal	*data)
{
	int x = -1;
	int y = -1;
	char *px;

	while (y++ < 10)
	{
		x = -1;
		while (x++ < 10)
		{
			px = data->addr + y * data->size_line + x * data->bpp / 8;
			*(unsigned int*)px = 0x00FFFFFF;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!args_check(argc, argv))
		return (-1);
	init_fractal(&fractal, argc, argv);
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0, event_hook, &fractal);
	render(&fractal);
	//my_axis(&fractal);
	//my_square(&fractal);
	//my_circle(&fractal, 100);
	//mlx_put_image_to_window(fractal.mlx, fractal.window, fractal.image, 0, 0);
	mlx_loop(fractal.mlx);
}
