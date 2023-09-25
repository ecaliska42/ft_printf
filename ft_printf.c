/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:44 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/25 18:58:43 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>


void	print(char c)
{
	write(1, &c, 1);
}

void	arguments(const char *s);
{
	if (*s == 'c')
	{
			write(1, *s, 1);
			return ()
	}
	else if (*s == 's')
			return ;
	else if (*s == 'p')
    		return ;
    else if (*s == 'd')
            return ;
    else if (*s == 'i')
            return ;
    else if (*s == 'u')
            return ;
    else if (*s == 'x')
            return ;
    else if (*s == 'X')
            return ;
    else if (*s == '%')
            return ;
}

int	percentes(const char *s)
{
	int	i;
	int	perc;

	perc = 0;
	i = 0;
	while (s[i])
			if (s[i] == '%' && s[i + 1])
}

int	ft_printf(const char *s, ...)
{
	int	i;

	i = 0;		
	va_list	my_list;
	va_start (my_list, s);
	while (s[i])
	{
		print(s[i]);
		i++;
	}
	va_end (my_list);
}	
