/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <ptraba-d@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:03:05 by ptraba-d          #+#    #+#             */
/*   Updated: 2024/11/10 21:43:54 by smelo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	line(char left, char middle, char right, int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
		{
			ft_putchar(left);
		}
		else if (j < x - 1)
		{
			ft_putchar(middle);
		}
		else if (j == x - 1)
		{
			ft_putchar(right);
		}
		j++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0 || x * y >= 2147483647)
	{
		write (1, "Input is invalid or too big\n", 28);
		return ;
	}
	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			line('A', 'B', 'C', x);
		}
		else if (i < y - 1)
		{
			line('B', ' ', 'B', x);
		}
		else if (i == y - 1)
		{
			line('C', 'B', 'A', x);
		}
		ft_putchar('\n');
		i++;
	}
}
