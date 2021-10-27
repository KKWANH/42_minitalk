/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:38:47 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/28 02:48:04 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define ANSI_RES "\e[0;0m"
# define ANSI_BOL "\e[0;1m"
# define ANSI_ITA "\e[0;3m"
# define ANSI_BLC "\e[0;30m"
# define ANSI_RED "\e[0;31m"
# define ANSI_GRE "\e[0;32m"
# define ANSI_YEL "\e[0;33m"
# define ANSI_BLU "\e[0;34m"	
# define ANSI_MAG "\e[0;35m"
# define ANSI_CYA "\e[0;36m"

int		ft_strlen(const char *_str);
int		ft_atoi(char *_str);
int		ft_putstr(char *_str, int _rtn);
void	ft_putchar(char _chr);
void	ft_putnbr(int _num);
int		ft_is_numb(char *_str);
char	*ft_strdup(const char *_str);
void	*ft_calloc(size_t _cnt, size_t _siz);
char	*ft_char_append(char *_str, char _chr);
size_t	ft_strlcpy(char *_dst, const char *_src, size_t _siz);
char	*ft_itoa(int n);

char	*g_client;

#endif