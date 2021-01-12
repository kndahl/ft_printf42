/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:39:15 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:24:09 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_skip_flags(const char *str, int index, t_flags *flag, va_list args)
{
	while (str[index])
	{
		if (!ft_ismagicsymb(str[index]) && !ft_isdigit(str[index])
										&& !ft_isflag(str[index]))
			break ;
		if (str[index] == '0' && flag->width == 0 && flag->minus == 0)
			flag->zero = 1;
		if (str[index] == ' ')
			flag->space = 1;
		if (str[index] == '*')
			*flag = ft_flag_width(args, *flag);
		if (str[index] == '.')
			index = ft_flag_dot(str, index, flag, args);
		if (str[index] == '-')
			*flag = ft_flag_minus(*flag);
		if (ft_isdigit(str[index]))
			*flag = ft_flag_digit(str[index], *flag);
		if (ft_ismagicsymb(str[index]))
		{
			flag->type = str[index];
			break ;
		}
		index++;
	}
	return (index);
}
