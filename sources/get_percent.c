/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:34:16 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:49:41 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_percent_handler(t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.minus == 1)
		counter += ft_print("%", 1);
	counter += ft_width_handler(flag.width, 1, flag.zero);
	if (flag.minus == 0)
		counter += ft_print("%", 1);
	return (counter);
}
