/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:36:42 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 16:59:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_char_handler(char ch, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.minus == 1)
		counter = ft_putchar_fd(ch, 1);
	counter = ft_width_handler(flag.width, 1, 0);
	if (flag.minus == 0)
		counter = ft_putchar_fd(ch, 1);
	return (counter);
}
