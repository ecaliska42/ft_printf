/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:44 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 18:14:55 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0 && nb > -2147483648)
	{
		i += print('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else if (nb < 10 && nb >= 0)
		i += print(nb + '0');
	return (i);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_unsigned_putnbr(nb / 10);
		i += ft_unsigned_putnbr(nb % 10);
	}
	else if (nb < 10)
		i += print(nb + '0');
	return (i);
}

int	str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		print(s[i]);
		i++;
	}
	return (i);
}

int	len(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

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

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	my_list;

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
				length += str(va_arg(my_list, char *));
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
