/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:38:29 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/25 17:12:48 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_ft_client_bitChanger
(int _num)
{
	(void)_num;
	g_bites._bit >>= 1;
}

struct sigaction	ft_client_option
(unsigned long int *_len, char **_arv)
{
	struct sigaction	_act;

	*_len = ft_strlen(_arv[2]) + 1;	
	sigemptyset(&_act.sa_mask);
	_act.sa_flags = 0;
	_act.sa_handler = &_ft_client_bitChanger;
	g_bites._pid = ft_atoi(_arv[1]);
	return (_act);
}

int	main
(int _arc, char **_arv)
{
	struct sigaction	_act;
	unsigned long int	_len;

	if (_arc < 3)
		return (-1);
	_act = ft_client_option(&_len, _arv);
	sigaction(SIGUSR1, &_act, 0);
	while (_len--)
	{
		g_bites._bit = 0b10000000;
		while (g_bites._bit)
		{
			if (*_arv[2] & g_bites._bit)
				kill(g_bites._pid, SIGUSR1);
			else
				kill(g_bites._pid, SIGUSR2);
			pause();
			usleep(50);
		}
		++_arv[2];
	}
	return (0);
}