/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:33:26 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:21:10 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*if_zero(void)
{
	char	*str;

	str = malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_putaddr(unsigned long long n)
{
	long int	div;
	char		*temp;
	int			index;

	temp = malloc(16);
	div = 16;
	index = 0;
	if (n == 0)
		return (temp = if_zero());
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp[index] = '0' + n / div;
		if (temp[index] > '9')
			temp[index] += 39;
		n %= div;
		div /= 16;
		index++;
	}
	temp[index] = '\0';
	return (temp);
}

static int	ft_ptr_res(char *str, t_flags flag)
{
	int	counter;

	counter = 0;
	counter += ft_print("0x", 2);
	if (flag.dot >= 0)
	{
		counter += ft_width_handler(flag.dot, ft_strlen(str), 1);
		counter += ft_print(str, flag.dot);
	}
	else
		counter += ft_print(str, ft_strlen(str));
	return (counter);
}

int			ft_pointer_handler(unsigned long long arg, t_flags flag)
{
	char	*ptr;
	int		counter;

	counter = 0;
	if (!arg && flag.dot == 0)
	{
		if (flag.width >= 0 && flag.minus == 0)
			(((counter += ft_width_handler(flag.width - 2, 0, 0)) || 1)
			&& ((counter += ft_print("0x", 2)) || 1));
		else
			(((counter += ft_print("0x", 2)) || 1)
			&& ((counter += ft_width_handler(flag.width - 2, 0, 0)) || 1));
		return (counter);
	}
	ptr = ft_putaddr(arg);
	if ((size_t)flag.dot < ft_strlen(ptr))
		flag.dot = ft_strlen(ptr);
	if (flag.minus == 1)
		counter += ft_ptr_res(ptr, flag);
	counter += ft_width_handler(flag.width, ft_strlen(ptr) + 2, 0);
	if (flag.minus == 0)
		counter += ft_ptr_res(ptr, flag);
	free(ptr);
	return (counter);
}
