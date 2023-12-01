/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/01 17:25:16 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!args_check(argc, argv))
		return (-1);
	if (!init_fractal(&f, argc, argv))
		return (-1);
	print_commands();
	mlx_key_hook(f.window, key_hook, &f);
	mlx_mouse_hook(f.window, mouse_hook, &f);
	mlx_hook(f.window, 17, 0, event_hook, &f);
	render(&f);
	mlx_loop(f.mlx);
	return (0);
}
