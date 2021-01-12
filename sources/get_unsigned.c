/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:31:35 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:34:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_unsigned_res(char *u_int, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.dot >= 0)
		counter += ft_width_handler(flag.dot - 1, ft_strlen(u_int) - 1, 1);
	counter += ft_print(u_int, ft_strlen(u_int));
	return (counter);
}

static int	ft_unsigned_flag(char *u_int, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.minus == 1)
		counter += ft_unsigned_res(u_int, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(u_int))
		flag.dot = ft_strlen(u_int);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter += ft_width_handler(flag.width, 0, 0);
	}
	else
		counter += ft_width_handler(flag.width, ft_strlen(u_int), flag.zero);
	if (flag.minus == 0)
		counter += ft_unsigned_res(u_int, flag);
	return (counter);
}

int			ft_unsigned_handler(unsigned int arg, t_flags flag)
{
	int		counter;
	char	*u_int;

	counter = 0;
	arg = (unsigned int)(4294967295 + 1 + arg);
	if (flag.dot == 0 && arg == 0)
	{
		counter += ft_width_handler(flag.width, 0, 0);
		return (counter);
	}
	u_int = ft_itoa_unsigned(arg);
	counter = ft_unsigned_flag(u_int, flag);
	free(u_int);
	return (counter);
}
