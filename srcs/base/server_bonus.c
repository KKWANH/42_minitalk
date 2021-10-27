/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:07 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/28 02:46:01 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern char	*g_client;

static void	ft_del_global(void)
{
	free(g_client);
	g_client = NULL;
}

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
