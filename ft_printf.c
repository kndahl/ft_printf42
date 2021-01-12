/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 22:52:22 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:29:16 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_ismagicsymb(int ch)
{
	return ((ch == 'c') || (ch == 's') || (ch == 'd')
	|| (ch == 'i') || (ch == 'p') || (ch == 'u') ||
	(ch == 'x') || (ch == 'X') || (ch == '%'));
}

int			ft_isflag(int ch)
{
	return ((ch == '0') || (ch == '.') || (ch == '*')
	|| (ch == '-') || (ch == ' '));
}

int			ft_input_handler(int ch, t_flags flag, va_list args)
{
	int	h_counter;

	h_counter = 0;
	if (ch == '%')
		h_counter += ft_percent_handler(flag);
	if (ch == 'c')
		h_counter += ft_char_handler(va_arg(args, int), flag);
	if (ch == 's')
		h_counter = ft_str_handler(va_arg(args, char *), flag);
	if (ch == 'd' || ch == 'i')
		h_counter = ft_digit_handler(va_arg(args, int), flag);
	if (ch == 'p')
		h_counter = ft_pointer_handler(va_arg(args, unsigned long long), flag);
	if (ch == 'u')
		h_counter += ft_unsigned_handler(
			(unsigned int)va_arg(args, unsigned int), flag);
	if (ch == 'x')
		h_counter += ft_hex_handler(va_arg(args, unsigned int), 0, flag);
	if (ch == 'X')
		h_counter += ft_hex_handler(va_arg(args, unsigned int), 1, flag);
	return (h_counter);
}

static int	ft_input(const char *input, va_list args)
{
	int		index;
	int		counter;
	t_flags	flag;

	index = 0;
	counter = 0;
	while (input[index])
	{
		flag = ft_init_flag();
		if (input[index] != '%')
			counter += ft_putchar_fd(input[index], 1);
		else if (input[index] == '%' && input[index + 1])
		{
			index = ft_skip_flags(input, ++index, &flag, args);
			if (ft_ismagicsymb(input[index]))
				counter += ft_input_handler((char)flag.type, flag, args);
			else if (input[index])
				counter += ft_putchar_fd(input[index], 1);
		}
		index++;
	}
	return (counter);
}

int			ft_printf(const char *s, ...)
{
	va_list		args;
	const char	*input;
	int			counter;

	if (!(input = ft_strdup(s)))
		return (-1);
	counter = 0;
	va_start(args, s);
	counter += ft_input(input, args);
	va_end(args);
	free((char *)input);
	return (counter);
}
