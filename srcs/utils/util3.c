/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 02:17:59 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/10/28 02:26:19 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/minitalk.h"
#include "../base/minitalk_bonus.h"

static int	ft_get_size(long *ln)
{
	int	size;
	int	i;

	size = 1;
	i = *ln;
	while (i / 10 != 0)
	{
		size++;
		i /= 10;
	}
	if (*ln < 0)
	{
		*ln *= -1;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		size;
	int		i;
	long	ln;

	ln = n;
	size = ft_get_size(&ln);
	c = malloc(size + 1);
	if (c == NULL)
		return (NULL);
	c[size] = '\0';
	c[0] = '-';
	if (n == 0)
		c[0] = '0';
	i = 1;
	while (i < size + 1 && ln != 0)
	{
		c[size - i] = (ln % 10) + '0';
		ln /= 10;
		i++;
	}
	return (c);
}

void	ft_count(int *i, int *neg, const char *str)
{
	*i = 0;
	*neg = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg *= -1;
		*i += 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
}
