/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:52:38 by rogarci2          #+#    #+#             */
/*   Updated: 2024/11/21 11:30:47 by rogarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && p != 1)
			str[i] = str[i] + 32;
		else if (((str[i] >= 'a' && str[i] <= 'z') && p == 1))
			str[i] = str[i] - 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			p = 0;
		else
			p = 1;
		i++;
	}
	return (str);
}
