/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/22 19:09:08 by tafocked         ###   ########.fr       */
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
		dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = 0x00FFFFFF;
		x++;
	}
	x = 960;
	y = 1;
	while (y < HEIGHT)
	{
		dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
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
		px = data->addr + ((y + offset_y) * data->size_line + (x + offset_x) * (data->bits_per_pixel / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		px = data->addr + ((-y + offset_y) * data->size_line + (x + offset_x) * (data->bits_per_pixel / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		x++;
	}
}

void	draw_fractal(t_fractal	*fractal)
{
	(void) fractal;
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!args_check(argc, argv))
		return (-1);
	init_fractal(&fractal, argc, argv);
	mlx_key_hook(fractal.window, key_hook, &fractal);
	draw_fractal(&fractal);
	my_axis(&fractal);
	my_circle(&fractal, 50);
	mlx_put_image_to_window(fractal.mlx, fractal.window, fractal.image, 0, 0);
	mlx_loop(fractal.mlx);
}
/*
int win(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_circle(&img, 50);
	my_circle(&img, 100);
	my_circle(&img, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/