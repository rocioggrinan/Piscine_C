/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:41:00 by rogarci2          #+#    #+#             */
/*   Updated: 2024/11/16 22:05:21 by rogarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	f;
	int	temp;

	i = 0;
	f = size - 1;
	while (i < f)
	{
		temp = tab[i];
		tab[i] = tab[f];
		tab[f] = temp;
		i++;
		f--;
	}
}
