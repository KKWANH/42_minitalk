/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:38:29 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/28 02:39:16 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern char	*g_client;

// client_bonus.c - ft_signal
//
// always called when the server sends a signal
// appends a to the global g_client so it can compare the length in the main
static void	ft_signal(int _sig)
{
	char	*_tmp;

	if (_sig == SIGUSR1)
	{
		_tmp = ft_char_append(g_client, 'a');
		g_client = _tmp;
	}
}

// client_bonus.c - ft_send_msg
//
// send the binary message to the server
// when 8 has sent, checks server response
// waits. so the signals won't get ignored
static void	ft_send_msg(int _pid, char *_str)
{
	size_t	_idx;

	_idx = 1;
	while (_str[_idx - 1] != '\0')
	{
		if (_str[_idx - 1] == '1')
			kill(_pid, SIGUSR1);
		else
			kill(_pid, SIGUSR2);
		if (_idx % 8 == 0)
			signal(SIGUSR1, ft_signal);
		_idx++;
		usleep(160);
	}
}

// client_bonus.c - ft_to_bit
//
// convert the string to bit
// puts binary number at the end of result string
// Q. why it is unsigned char?
// A. to handle unicode.
static char	*ft_to_bit(char *_str, size_t _idx, size_t _jdx)
{
	char	*_rst;
	int		_chr;
	int		_byt;

	_idx = ft_strlen(_str);
	_rst = ft_calloc(_idx * 8 + 1, sizeof(unsigned char));
	if (_rst == NULL)
		return (NULL);
	while (_idx + 1 != 0)
	{
		_chr = (unsigned char) _str[_idx - 1];
		_byt = 8;
		while (_byt > 0)
		{
			if (_chr % 2 == 1)
				_rst[ft_strlen(_str) * 8 - _jdx - 1] = '1';
			else
				_rst[ft_strlen(_str) * 8 - _jdx - 1] = '0';
			_chr /= 2;
			++_jdx;
			--_byt;
		}
		--_idx;
	}
	return (_rst);
}

// client_bonus.c - ft_send_pid
//
// get client's pid and turn that to bit (free cid)
// kill SIGUSR1 or SIGUSR2 as the bit
// if the PID less than 8 chars, send 0/1 till it gets 8
static void	ft_send_pid(int _pid, int _idx)
{
	char	*_cid;
	char	*_bit;

	_cid = ft_itoa(getpid());
	_bit = ft_to_bit(_cid, 0, 0);
	free(_cid);
	while (_bit[_idx] != '\0')
	{
		if (_bit[_idx] == '1')
			kill(_pid, SIGUSR1);
		else
			kill(_pid, SIGUSR2);
		_idx++;
		usleep(80);
	}
	while (_idx < 56)
	{
		kill(_pid, SIGUSR2);
		usleep(80);
		kill(_pid, SIGUSR1);
		usleep(80);
		_idx += 2;
	}
	free(_bit);
}


// client_bonus.c - main
//
// check the arguments
// get bits, pid from the arguments
// set g_clients
// send pid, message
// after that, send 00000000 to check
// compare sended message's length and the argument string
// print result alert and free other things
int	main(int _arc, char **_arv)
{
	int		_pid;
	char	*_str;
	char	*_bit;

	if (_arc != 3 || ft_is_numb(_arv[1]) == -1)
		return (ft_putstr(ANSI_BLU "[MINITALK] " ANSI_RED "[ERROR] " ANSI_YEL
			"./client [Server Pid] [Text]\n" ANSI_RES, -1));
	_pid = ft_atoi(_arv[1]);
	_str = ft_strdup(_arv[2]);
	_bit = ft_to_bit((_str = ft_char_append(_str, '\n')), 0, 0);
	if (_bit == NULL)
		return (ft_putstr(ANSI_BLU "[MINITALK] " ANSI_RED "[ERROR] " ANSI_YEL
			"in bit allocation\n" ANSI_RES, 0));
	g_client = ft_strdup("");
	ft_send_pid(_pid, 0);
	ft_send_msg(_pid, _bit);
	ft_send_msg(_pid, "00000000");
	if (ft_strlen(_str) == ft_strlen(g_client))
		ft_putstr(ANSI_BLU "[MINITALK] " ANSI_GRE "[SUCCESS]" ANSI_RES "\n", 0);
	else
		ft_putstr(ANSI_BLU "[MINITALK] " ANSI_RED "[ERROR] " ANSI_RES
			"couldn't be sended\n", 0);
	free(_bit);
	free(g_client);
	return (0);
}
