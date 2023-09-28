/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:36:51 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 18:40:02 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	hexadecimal(int nb, int x)
{
	char	*s;
	int		length;
	int		rem;
	char	*str;

	s = "0123456789ABCDEF";
	if (x == 'x')
		s = "0123456789abcdef";
	length = len(nb);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (0);
	str[length] = '\0';
	while (nb != 0)
	{
		rem = nb % 16;
		nb /= 16;
		str[--length] = s[rem];
	}
	while (str[length])
	{
		print(str[length]);
		length++;
	}
	return (length);
}
