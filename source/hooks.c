/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:10:00 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/24 22:01:15 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int hook, t_fractal *f)
{
	if (hook == ESC)
		exit(1);
	if (hook == UP)
		move(f, 0., -0.01);
	if (hook == DOWN)
		move(f, 0., 0.01);
	if (hook == LEFT)
		move(f, -0.01, 0.);
	if (hook == RIGHT)
		move(f, 0.01, 0.);
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
