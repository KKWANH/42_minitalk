/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:07 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/25 19:17:58 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_handler(int _num, siginfo_t *_inf, void *_Ucontext)
{
	(void)_Ucontext;
	if (_num == SIGUSR1)
		g_bites._sym += g_bites._bit;
	g_bites._bit >>= 1;
	if (!g_bites._bit)
	{
		if (!g_bites._sym)
			ft_putchar('\n');
		else
			ft_putchar(g_bites._sym);
		g_bites._bit = 0b10000000;
		g_bites._sym = 0;
	}
	usleep(50);
	kill(_inf->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	_act;

	g_bites._sym = 0;
	g_bites._bit = 0b10000000;
	sigemptyset(&_act.sa_mask);
	_act.sa_flags = SA_SIGINFO;
	_act.sa_sigaction = &ft_server_handler;
	sigaction(SIGUSR1, &_act, 0);
	sigaction(SIGUSR2, &_act, 0);
	ft_putstr(ANSI_BLU "[SERVER PID] " ANSI_RES
		"enter this code to first parameter of client program. " ANSI_GRE "[");
	ft_putnbr(getpid());
	ft_putstr(ANSI_GRE "]\n" ANSI_RES);
	while (1)
		pause();
}
