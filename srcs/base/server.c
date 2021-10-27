/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:07 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/28 02:45:08 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern char	*g_client;

// resets the global variable (25 line problem)
static void	ft_del_global(void)
{
	free(g_client);
	g_client = NULL;
}

// converts binary to ascii or unicode
// returns the result as an integer
// if it's not just for comparison it prints the character
static int	ft_convert(char *_str, int _wrt)
{
	int				_pow;
	int				_chr;
	size_t			_idx;

	_pow = 1;
	_chr = 0;
	_idx = ft_strlen(_str) - 1;
	while (_idx + 1 != 0)
	{
		_chr += _pow * (_str[_idx] - '0');
		_pow *= 2;
		--_idx;
	}
	if (_wrt == 1)
	{
		write(1, &_chr, 1);
		return ((char) NULL);
	}
	return (_chr);
}

// reads every bit and appends it to bits
// if its a 8 bit ascii char or a 24 bit unicode char it converts it
// the result gets printed and the server sends the client an ack
static void	ft_confirm(int _sig)
{
	static char	*_bit;
	static int	_cnt;

	++_cnt;
	if (_bit == NULL)
	{
		_bit = ft_strdup("");
		_cnt = 1;
	}
	if (_sig == SIGUSR2)
		_bit = ft_char_append(_bit, '0');
	else
		_bit = ft_char_append(_bit, '1');
	if ((_cnt == 8 && ft_convert(_bit, 0) < 255) || _cnt == 24)
	{
		if (ft_convert(_bit, 0) == 0 && _cnt != 24)
			ft_del_global();
		else
		{
			ft_convert(_bit, 1);
			kill(ft_atoi(g_client), SIGUSR1);
		}
		free(_bit);
		_bit = NULL;
	}
}

// server.c - ft_get_pid
//
// safes all bits in a string and converts every byte to a char
// the char will get appended to the client variable (PID)
static void	ft_get_pid(int _sig)
{
	static char	*_bit;
	static int	_cnt;

	++_cnt;
	if (_bit == NULL)
	{
		_bit = ft_strdup("");
		_cnt = 1;
	}
	if (_sig == SIGUSR2)
		_bit = ft_char_append(_bit, '0');
	else
		_bit = ft_char_append(_bit, '1');
	if (_cnt == 8)
	{
		g_client = ft_char_append(g_client, ft_convert(_bit, 0));
		free(_bit);
		_bit = NULL;
	}
}

// server.c - main
//
// if it doens't have the client ID, takes 8 bytes as the client ID
// otherwise it will decode the binary string and print it
int	main(void)
{
	ft_putstr(ANSI_BLU "[MINITALK] " ANSI_RES
		"enter this to first parameter of client. " ANSI_GRE "[", 0);
	ft_putnbr(getpid());
	ft_putstr(ANSI_GRE "]\n" ANSI_RES, 0);
	while (1 == 1)
	{
		if (g_client == NULL)
		{
			g_client = ft_strdup("");
			while (ft_strlen(g_client) < 7)
			{
				signal(SIGUSR1, ft_get_pid);
				signal(SIGUSR2, ft_get_pid);
				pause();
			}
		}
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}
