/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:10:00 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/26 17:48:38 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int hook, t_fractal *f)
{
	if (hook == UP)
		move(f, 0., -0.1);
	if (hook == DOWN)
		move(f, 0., 0.1);
	if (hook == LEFT)
		move(f, -0.1, 0.);
	if (hook == RIGHT)
		move(f, 0.1, 0.);
	if (hook == INC)
		inc_iter(f);
	if (hook == DEC)
		dec_iter(f);
	if (hook == J)
		rand_julia(f);
	if (hook == C)
		color_change(f);
	if (hook == R)
		reset(f);
	if (hook == ESC)
		exit(1);
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

int	event_hook(void)
{
	exit(1);
	return (1);
}
