/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:32:46 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:23:41 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_str_res(char *str, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.dot >= 0)
	{
		counter += ft_width_handler(flag.dot, ft_strlen(str), 0);
		counter += ft_print(str, flag.dot);
	}
	else
		counter += ft_print(str, ft_strlen(str));
	return (counter);
}

int			ft_str_handler(char *str, t_flags flag)
{
	int	counter;

	counter = 0;
	if (!str)
		str = "(null)";
	if (flag.dot >= 0 && (size_t)flag.dot > ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		counter += ft_str_res(str, flag);
	if (flag.dot >= 0)
		counter += ft_width_handler(flag.width, flag.dot, 0);
	else
		counter += ft_width_handler(flag.width, ft_strlen(str), 0);
	if (flag.minus == 0)
		counter += ft_str_res(str, flag);
	return (counter);
}
