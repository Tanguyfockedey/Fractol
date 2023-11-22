/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:04:50 by tafocked          #+#    #+#             */
/*   Updated: 2023/11/22 16:07:36 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_params(void)
{
	ft_printf("List of available parameters \n");
	ft_printf("----------------------------- \n");
	ft_printf("M - Mandelbrot \n");
	ft_printf("B - Burning Ship \n");
	ft_printf("J - Julia \n");
	ft_printf("For julia you may specify two values between -2.0 and 2.0 \n\n");	
	return (0);
}

void	print_commands(void)
{
	ft_printf("List of commands \n");
	ft_printf("----------------- \n");
	ft_printf("Quit program: ESC\n");
	ft_printf("Move fractal: WASD, arrow keys\n");
	ft_printf("Zoom in/out : mouse scroll\n");
	ft_printf("Color palette: C\n");
}
