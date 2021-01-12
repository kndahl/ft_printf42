/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:26:52 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:37:13 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_init_flag(void)
{
	t_flags	flag;

	flag.width = 0;
	flag.type = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.minus = 0;
	flag.dot = -1;
	flag.space = 0;
	return (flag);
}

t_flags	ft_flag_minus(t_flags flag)
{
	flag.minus = 1;
	flag.zero = 0;
	return (flag);
}

t_flags	ft_flag_digit(char ch, t_flags flag)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = (flag.width * 10) + (ch - 48);
	return (flag);
}

t_flags	ft_flag_width(va_list args, t_flags flag)
{
	flag.star = 1;
	flag.width = va_arg(args, int);
	if (flag.width < 0)
	{
		flag.minus = 1;
		flag.width *= -1;
		flag.zero = 0;
	}
	return (flag);
}

int		ft_flag_dot(const char *str, int i_begin, t_flags *flag, va_list args)
{
	int	index;

	index = i_begin;
	index += 1;
	if (str[index] == '*')
	{
		flag->dot = va_arg(args, int);
		index += 1;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(str[index]))
		{
			flag->dot = (flag->dot * 10) + (str[index] - 48);
			index++;
		}
	}
	return (index);
}
