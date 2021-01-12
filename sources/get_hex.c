/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:35:29 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/22 23:44:28 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_revstr(const char *hex, int index)
{
	char	*rev_hex;
	int		ri;

	ri = 0;
	rev_hex = malloc(16);
	while (index--)
	{
		rev_hex[ri] = hex[index];
		ri++;
	}
	rev_hex[ri] = '\0';
	free((char *)hex);
	return (rev_hex);
}

char		*ft_puthex(unsigned int nb)
{
	char	*hex;
	int		tmp;
	int		i;

	hex = malloc(16);
	if (nb == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	ft_bzero(hex, 16);
	i = 0;
	while (nb && i < 8)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('a' - 10) : '0'));
		nb /= 16;
		i++;
	}
	hex = ft_revstr(hex, i);
	return (hex);
}

static int	ft_printhex(char *hex, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.dot >= 0)
		counter += ft_width_handler(flag.dot - 1, ft_strlen(hex) - 1, 1);
	counter += ft_print(hex, ft_strlen(hex));
	return (counter);
}

static int	ft_hex_flag(char *hex, t_flags flag)
{
	int	counter;

	counter = 0;
	if (flag.minus == 1)
		counter += ft_printhex(hex, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(hex))
		flag.dot = ft_strlen(hex);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter += ft_width_handler(flag.width, 0, 0);
	}
	else
		counter += ft_width_handler(flag.width, ft_strlen(hex), flag.zero);
	if (flag.minus == 0)
	{
		counter += ft_printhex(hex, flag);
	}
	return (counter);
}

int			ft_hex_handler(unsigned int arg, int l_case, t_flags flag)
{
	char	*hex;
	int		counter;

	counter = 0;
	if (flag.dot == 0 && arg == 0)
	{
		counter += ft_width_handler(flag.width, 0, 0);
		return (counter);
	}
	hex = ft_puthex(arg);
	if (l_case == 1)
		hex = ft_strup(hex);
	counter += ft_hex_flag(hex, flag);
	free(hex);
	return (counter);
}
