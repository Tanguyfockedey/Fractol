/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/15 18:26:42 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_axis(t_data *data)
{
	char	*dst;
	int		x;
	int		y;

	x = 1;
	y = 540;
	while (x < 1920)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = 0x00FFFFFF;
		x++;
	}
	x = 960;
	y = 1;
	while (y < 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = 0x00FFFFFF;
		y++;
	}
}

void	my_circle(t_data *data, int radius)
{
	char *px;
	int offset_x = 960;
	int offset_y = 540;
	int x = -radius;
	int y;
	
	while (x <= radius)
	{
		y = (int)(sqrt(pow((double)radius, 2.) - pow((double)x, 2.)));
		px = data->addr + ((y + offset_y) * data->line_length + (x + offset_x) * (data->bits_per_pixel / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		px = data->addr + ((-y + offset_y) * data->line_length + (x + offset_x) * (data->bits_per_pixel / 8));
		*(unsigned int*)px = 0x00FFFFFF;
		x++;
	}
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_axis(&img);
	my_circle(&img, 50);
	my_circle(&img, 100);
	my_circle(&img, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}