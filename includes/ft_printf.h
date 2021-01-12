/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:59:48 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/21 15:34:13 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
	int		space;
}				t_flags;

int				ft_printf(const char *s, ...);
int				ft_input_handler(int ch, t_flags flag, va_list args);
int				ft_isflag(int ch);
int				ft_ismagicsymb(int ch);
int				ft_print(char *str, int n);
int				ft_char_handler(char ch, t_flags flag);
int				ft_digit_handler(int arg, t_flags flag);
t_flags			ft_flag_minus(t_flags flag);
t_flags			ft_flag_digit(char ch, t_flags flag);
t_flags			ft_flag_width(va_list args, t_flags flag);
t_flags			ft_init_flag(void);
int				ft_flag_dot(const char *str, int i_begin,
t_flags *flag, va_list args);
int				ft_hex_handler(unsigned int arg, int l_case, t_flags flag);
char			*ft_puthex(unsigned int nb);
int				ft_percent_handler(t_flags flag);
int				ft_pointer_handler(unsigned long long arg, t_flags flag);
char			*ft_putaddr(unsigned long long n);
int				ft_str_handler(char *str, t_flags flag);
int				ft_unsigned_handler(unsigned int arg, t_flags flag);
int				ft_width_handler(int width,
int minus, int zero);
int				ft_skip_flags(const char *str, int index,
t_flags *flag, va_list args);

#endif
