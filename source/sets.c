/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:54:12 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/26 18:13:05 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_set(t_fractal *f, double cr, double ci)
{
	int	i;

	if (f->set == 'B')
		i = burning_ship(f, cr, ci);
	if (f->set == 'J')
		i = julia(f, cr, ci);
	if (f->set == 'M')
		i = mandelbrot(f, cr, ci);
	return (i);
}

int	mandelbrot(t_fractal *f, double cr, double ci)
{
	int	i;
	double	zr;
	double	zi;
	double	temp;

	zr = 0.;
	zi = 0.;
	i = 0;
	while (++i < f->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.)
			break;
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	return (i);
}

int	julia(t_fractal *f, double zr, double zi)
{
	int	i;
	double	cr;
	double	ci;
	double	temp;

	cr = f->jr;
	ci = f->ji;
	i = 0;
	while (++i < f->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.)
			break;
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	return (i);
}

int	burning_ship(t_fractal *f, double cr, double ci)
{
	int	i;
	double	zr;
	double	zi;
	double	temp;

	zr = 0.;
	zi = 0.;
	i = 0;
	while (++i < f->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.)
			break;
		if (zr < 0)
			zr = -zr;
		if (zi < 0)
			zi = -zi;
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	return (i);
}

