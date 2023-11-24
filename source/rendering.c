/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:52:21 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/24 22:21:58 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractal *f)
{
	int	x_pix;
	int	y_pix;
	int	i;
	double x_real;
	double y_imag;

	y_pix = -1;
	while (++y_pix < HEIGHT)
	{
		x_pix = -1;
		while (++x_pix < WIDTH)
		{
			x_real = 2. * f->max_r * (double)x_pix / (double)WIDTH - f->max_r + f->offset_x;
			y_imag = 2. * f->max_i * (double)y_pix / (double)HEIGHT - f->max_i + f->offset_y;
			i = calculate_set(f, x_real, y_imag);
			color_pixel(f, x_pix, y_pix, i);
		}
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
}

void	zoom(t_fractal *f, int x, int y, double scale)
{
	(void) f;
	(void) x;
	(void) y;
	(void) scale;

	f->max_r *= scale;
	f->max_i = f->max_r * HEIGHT / WIDTH;
	render(f);
}

void	move(t_fractal *f, double x, double y)
{
	f->offset_x += x * f->max_r;
	f->offset_y += y * f->max_r;
	render(f);
}

void	color_pixel(t_fractal *f, int x_pix, int y_pix, int color)
{
	char	*addr;

	addr = f->addr + (y_pix * f->size_line + x_pix * f->bpp / 8);
	if (color == f->max_iter)
		*(unsigned int*)addr = 0x00000000;
	else if (color <= 1)
		*(unsigned int*)addr = 0x00FFFFFF;
	else
	//	*(unsigned int*)addr = 0x00000000 + color * 0x00020000;
		*(unsigned int*)addr = 0x00000000 + color * 1000;
}