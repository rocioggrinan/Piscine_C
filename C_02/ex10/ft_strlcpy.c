/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:34:10 by rogarci2          #+#    #+#             */
/*   Updated: 2024/11/22 10:52:03 by rogarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while ((src[i] != '\0') && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (*src != '\0')
	{
		src++;
		n++;
	}
	dest[i] = '\0';
	return (n);
}
