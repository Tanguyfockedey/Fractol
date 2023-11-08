/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/10/27 19:14:51 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/libft_updated/base/libft.h"
#include "libraries/libft_updated/printf/ft_printf.h"


void main(void)
{
	int a = 0;
	int b = 2;
	int c = 4;

	a = ft_isalnum(c);
	ft_printf("%d\n", a);
}