/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:43:20 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 14:13:00 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print(char *str, int n)
{
	int	index;

	index = 0;
	while (str[index] && index < n)
	{
		ft_putchar_fd(str[index], 1);
		index++;
	}
	return (index);
}
