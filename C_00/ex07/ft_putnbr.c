/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:09 by rogarci2          #+#    #+#             */
/*   Updated: 2024/11/12 13:37:54 by rogarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
	}
	return (n);
}

void	ft_putnbr(int nb)
{
	char	array[11];
	int		counter;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	counter = 0;
	array[counter++] = abs(nb % 10) + '0';
	nb = nb / 10;
	while (nb != 0)
	{
		array[counter++] = abs(nb % 10) + '0';
		nb = nb / 10;
	}
	while (counter)
	{
		write(1, &array[--counter], 1);
	}
}
