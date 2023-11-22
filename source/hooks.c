/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:10:00 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/22 20:26:19 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int hook, t_fractal *fractal)
{
	(void) fractal;
	if (hook == ESC)
		exit(1);
	if (hook == UP)
		move(fractal, 0., 0.1);
	if (hook == DOWN)
		move(fractal, 0., -0.1);
	if (hook == LEFT)
		move(fractal, 0.1, 0.);
	if (hook == RIGHT)
		move(fractal, -0.1, 0.);
	render(fractal);
	return (0);
}

int	mouse_hook(int hook, int x, int y, t_fractal *fractal)
{
	if (hook == SCROLL_UP)
		zoom(fractal, x, y, 0.5);
	if (hook == SCROLL_DOWN)
		zoom(fractal, x, y, 2.);
	render(fractal);
	return (0);
}