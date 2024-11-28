/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:02:28 by rogarci2          #+#    #+#             */
/*   Updated: 2024/11/11 14:04:46 by rogarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comma(int count)
{
	if (count != 9899)
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;
	int		count;

	count = 0;
	while (count <= 9999)
	{
		a = '0' + (count / 1000);
		b = '0' + (count / 100) % 10;
		c = '0' + (count / 10) % 10;
		d = '0' + (count / 1) % 10;
		if (a * 10 + b < c * 10 + d)
		{
			write (1, &a, 1);
			write (1, &b, 1);
			write (1, " ", 1);
			write (1, &c, 1);
			write (1, &d, 1);
			ft_print_comma(count);
		}
		count ++;
	}
}
