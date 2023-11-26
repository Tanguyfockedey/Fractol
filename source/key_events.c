/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:43:27 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inc_iter(t_fractal *f)
{
	f->max_iter *= 2;
	ft_printf("max_iter = %d\n", f->max_iter);
	render(f);
}

void	dec_iter(t_fractal *f)
{
	f->max_iter /= 2;
	if (f->max_iter == 0)
		f->max_iter = 1;
	ft_printf("max_iter = %d\n", f->max_iter);
	render(f);
}

void	reset(t_fractal *f)
{
	f->jr = f->jr_copy;
	f->ji = f->ji_copy;
	f->max_iter = 32;
	f->max_r = 2.;
	f->max_i = f->max_r * HEIGHT / WIDTH;
	f->offset_x = 0.;
	f->offset_y = 0.;
	f->color_start = 0;
	f->color_step = 1000;
	render(f);
}

void	rand_julia(t_fractal *f)
{
	f->jr = ((double)rand() / (double)RAND_MAX * 4.) - 2.;
	f->ji = ((double)rand() / (double)RAND_MAX * 4.) - 2.;
	ft_printf("---\n");
	ft_printf("jr = %d\n", (int)(f->jr * 1000));
	ft_printf("ji = %d\n", (int)(f->ji * 1000));
	f->max_iter = 32;
	f->max_r = 2.;
	f->max_i = f->max_r * HEIGHT / WIDTH;
	f->offset_x = 0.;
	f->offset_y = 0.;
	render(f);
}

void	color_change(t_fractal *f)
{
	f->color_start = rand();
	f->color_step = rand();
	render(f);
}