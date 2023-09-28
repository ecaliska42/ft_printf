/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:44 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 19:47:48 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	my_list;
	char	*test;

	i = 0;
	length = 0;
	va_start (my_list, s);
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[++i] == 'c')
				length += print(va_arg(my_list, int));
			else if (s[i] == 's')
			{
				test = va_arg(my_list, char *);
				if (test == NULL)
					length += str("(null)");
				length += str(test);
			}
			else if (s[i] == 'p')
				length += adress(va_arg(my_list, void *));
			else if (s[i] == 'd')
				length += ft_putnbr(va_arg(my_list, int));
			else if (s[i] == 'i')
				length += ft_putnbr(va_arg(my_list, int));
			else if (s[i] == 'u')
				length += ft_unsigned_putnbr(va_arg(my_list, unsigned int));
			else if (s[i] == 'x')
				length += hexadecimal(va_arg(my_list, int), 'x');
			else if (s[i] == 'X')
				length += hexadecimal(va_arg(my_list, int), 'X');
			else if (s[i] == '%')
				length += print('%');
			else
				return (-1);
		}
		else
			length += print(s[i]);
		i++;
	}
	va_end (my_list);
	return (length);
}

/*
#include <limits.h>

int	main(void)
{
	//void	*p;
	unsigned int	i;
	//void *nb = LONG_MAX;
	i = UINT_MAX;
	//ft_printf("printf\t\t\t%p\n", i);
	printf("num:%d\n", ft_printf("%u hi", i));
	//printf("this is the printf\t%p\n", i);
	printf("orignum:%d", printf("%u hi", i));
	return (0);
}
*/
/*
•OKOK	 %c Prints a single character.
•OKOK	 %s Prints a string (as defined by the common C convention).
•OKOK	 %p The void * pointer argument has to be printed in hexadecimal format.
•OKOK	 %d Prints a decimal (base 10) number.
•OKOK	 %i Prints an integer in base 10.
•OKOK	 %u Prints an unsigned decimal (base 10) number.
•OKOK	 %x Prints a number in hexadecimal (base 16) lowercase format.
•OKOK	 %X Prints a number in hexadecimal (base 16) uppercase format.
•OKOK	 %% Prints a percent sign.
*/
