/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:44:21 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:24:41 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_size(unsigned int num)
{
	unsigned int	size;

	size = 0;
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	index;
	unsigned int	size;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = (unsigned int)get_size(num);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[0] = '-'))
		size++;
	index = size - 1;
	while (num >= 10)
	{
		str[index] = (char)(num % 10 + 48);
		num /= 10;
		index--;
	}
	str[index] = (char)(num % 10 + 48);
	str[size] = '\0';
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	index;
	unsigned int	size;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = (unsigned int)get_size(num);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[0] = '-'))
		size++;
	index = size - 1;
	while (num >= 10)
	{
		str[index] = (char)(num % 10 + 48);
		num /= 10;
		index--;
	}
	str[index] = (char)(num % 10 + 48);
	str[size] = '\0';
	return (str);
}
