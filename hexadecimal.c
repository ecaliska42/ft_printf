/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:35 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/27 16:57:50 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	len(int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*hexadecimal(int nb)
{
	char	*s;
	int		q;
	int		length;
	int		rem;
	char	*str;

	s = "0123456789ABCDEF";
	length = len(nb);
	str = (char *)malloc(sizeof(char) * length + 1);
	str[length] = '\0';
	while (nb)
	{
		q = nb / 16;
		rem = nb % 16;
		str[--length] = s[rem];
		nb = q;
	}
	return (str);
}

int	main(void)
{
	int	nb;

	nb = 450;
	printf("%s", hexadecimal (nb));
	return (0);
}
