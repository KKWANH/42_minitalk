/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:38:47 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/25 19:27:47 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
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

int	ft_strlen(char *_str);
int	ft_atoi(char *_str);
void	ft_putstr(char *_str);
void	ft_putchar(char _chr);
void	ft_putnbr(int _num);

typedef struct s_signal
{
	unsigned int	_bit;
	char			_sym;
	int				_pid;
}					t_signal;

t_signal			g_bites;

#endif