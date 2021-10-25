/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:20:19 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/25 19:16:57 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *_str)
{
	int	_cnt;

	_cnt = 0;
	while (_str[_cnt])
		++_cnt;
	return (_cnt);
}

int	ft_atoi(char *_str)
{
	int	_mns;
	int	_rst;

	_rst = 0;
	_mns = 1;
	while (*_str == '\t' || *_str == '\n' || *_str == '\v' || *_str == '\f'
		|| *_str == '\r' || *_str == ' ')
		++_str;
	if (*_str == '-' || *_str == '+')
	{
		if (*_str == '-')
			_mns = -1;
		++_str;
	}
	while (*_str >= '0' && *_str <= '9')
		_rst = _rst * 10 + _mns * (*_str++ - 48);
	return (_rst);
}

void	ft_putstr(char *_str)
{
	if (!_str)
		return ;
	write(1, _str, ft_strlen(_str));
}

void	ft_putchar(char _chr)
{
	write(1, &_chr, 1);
}

void	ft_putnbr(int _num)
{
	unsigned int	_unm;

	if (_num < 0)
	{
		ft_putchar('-');
		_unm = -(unsigned int)_num;
	}
	else
		_unm = (unsigned int)_num;
	if (_num >= 10)
	{
		ft_putnbr((int)(_unm / 10));
		ft_putnbr((int)(_unm % 10));
	}
	else
		ft_putchar((char)(_unm % 10 + '0'));
}
