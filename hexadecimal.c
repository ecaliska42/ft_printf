/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:35 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:58 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	hexadecimal(int nb)
{
	char *s = "0123456789ABCDEF";
	float	number = nb;
	int length;
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	number = nb;
	while (length--)
	{
		number /= 16;
		16 * 
	}
}

int	main(void)
{
	int	nb = 44252;
	printf("%d",hexadecimal (nb));
	return (0);
}