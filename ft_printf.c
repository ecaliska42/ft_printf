/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:44 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/26 17:54:31 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


void    print(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	if (nb < 0 && nb > -2147483648)
	{
		print('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 10 && nb >= 0)
	{
		print(nb + '0');
	}
}

void	ft_unsigned_putnbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_unsigned_putnbr(nb / 10);
		ft_unsigned_putnbr(nb % 10);
	}
	else if (nb < 10)
	{
		print(nb + '0');
	}
}

void	str(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		print(s[i]);
		i++;
	}
}


int	ft_printf(const char *s, ...)
{
	int	i;

	i = 0;        
	va_list	my_list;
	va_start	(my_list, s);
	while (*s != '\0')
	{
		if (*s == '%')
			{
				if (*++s == 'c')
					print (va_arg (my_list, int));
				 else if (*s == 's')
				 	str (va_arg (my_list, char*));
				// else if (s[i] == 'p')
				// 	va_arg (my_list, char);
				 else if (s[i] == 'd')
				 	ft_putnbr (va_arg (my_list, int));
				// else if (s[i] == 'i')
				// 	ft_putnbr (va_arg (my_list, int));
				 else if (s[i] == 'u')
				 	ft_unsigned_putnbr (va_arg (my_list, unsigned int));
				// else if (s[i] == 'x')
				// 	va_arg (my_list, char);
				// else if (s[i] == 'X')
				// 	va_arg (my_list, char);
				else if (*s == '%')
					write (1, "%", 1);
			}
			else
				print(*s);
		s++;
	}
	va_end (my_list);
	return i;
}    


int main(void)
{
	unsigned int i = -1515;
	ft_printf("printf %u\n", i);
	printf("this is the printf %u\n", i);
	return 0;
}



/*
•OK		 %c Prints a single character.
•OK		 %s Prints a string (as defined by the common C convention).
•		 %p The void * pointer argument has to be printed in hexadecimal format.
•OK		 %d Prints a decimal (base 10) number.
•OK		 %i Prints an integer in base 10.
•OK		 %u Prints an unsigned decimal (base 10) number.
•		 %x Prints a number in hexadecimal (base 16) lowercase format.
•		 %X Prints a number in hexadecimal (base 16) uppercase format.
•OK		 %% Prints a percent sign.
*/