/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:35:15 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 18:36:21 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	adress(void *point)
{
	char				*s;
	int					length;
	long long			rem;
	char				*str;
	unsigned long long	p;

	if (point == NULL)
		return (write(1, "(nill)", 5));
	p = (unsigned long long) point;
	write (1, "0x", 2);
	s = "0123456789abcdef";
	length = len(p) + 1;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (0);
	str[length] = '\0';
	while (p != 0)
	{
		rem = p % 16;
		p /= 16;
		str[--length] = s[rem];
	}
	while (str[length])
	{
		print(str[length]);
		length++;
	}
	return (length + 1);
}
