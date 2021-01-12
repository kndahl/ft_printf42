/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:34:52 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:36:54 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_digit_res(char *str, int digit, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.dot >= 0 && digit < 0 && digit != -2147483648)
		ft_putchar_fd('-', 1);
	if (flag.dot >= 0)
		counter += ft_width_handler(flag.dot - 1, ft_strlen(str) - 1, 1);
	counter += ft_print(str, ft_strlen(str));
	return (counter);
}

static int	ft_digit_flag(char *str, int digit, t_flags flag)
{
	int counter;

	counter = 0;
	if (flag.space == 1)
	{
		ft_putchar_fd(' ', 1);
		counter++;
	}
	if (flag.minus == 1)
		counter += ft_digit_res(str, digit, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter += ft_width_handler(flag.width, 0, 0);
	}
	else
		counter += ft_width_handler(flag.width, ft_strlen(str), flag.zero);
	if (flag.minus == 0)
		counter += ft_digit_res(str, digit, flag);
	return (counter);
}

int			ft_digit_handler(int arg, t_flags flag)
{
	char	*str;
	int		counter;
	int		digit;

	counter = 0;
	digit = arg;
	if (flag.dot == 0 && arg == 0)
	{
		counter += ft_width_handler(flag.width, 0, 0);
		return (counter);
	}
	if (arg < 0 && (flag.dot >= 0 || flag.zero == 1) && digit != -2147483648)
	{
		if (flag.dot <= -1 && flag.zero == 1)
			ft_print("-", 1);
		arg *= -1;
		flag.zero = 1;
		flag.width--;
		counter++;
	}
	str = ft_itoa(arg);
	counter += ft_digit_flag(str, digit, flag);
	free(str);
	return (counter);
}
