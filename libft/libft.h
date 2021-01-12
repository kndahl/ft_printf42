/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:54:27 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:25:50 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *str, size_t n);
int		ft_putchar_fd(char c, int fd);
int		ft_toupper(int ch);
int		ft_isdigit(int ch);
char	*ft_strup(char *str);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
int		get_size(unsigned int num);
size_t	ft_strlen(const char *s);

#endif
