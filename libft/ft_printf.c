/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:14:18 by micheng           #+#    #+#             */
/*   Updated: 2023/06/05 15:30:25 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse(args, str[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_parse(va_list args, char s)
{
	int		count;
	char	*unsigned_str;

	count = 0;
	if (s == 'X' || s == 'x')
		count += ft_hexdec(va_arg(args, unsigned int), s);
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == '%')
		count += ft_putchar('%');
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		count += ft_pointer(va_arg(args, void *));
	else if (s == 'u')
	{
		unsigned_str = ft_itoa_base(va_arg(args, unsigned int), BASE_10);
		count += ft_putstr(unsigned_str);
		free(unsigned_str);
	}
	return (count);
}

/*
int	main(void)
{
 	int i = 42;
	int	j = 41;
	int	*ptr;

	ptr = &i;
    char *str = "Hello world!";
	ft_printf("Testing ft_printf\n");
	ft_printf("Integer: %d\n", i);
	ft_printf("Integer: %i\n", j);
	ft_printf("Integer: %u\n", j);
    ft_printf(" NULL %s NULL \n", NULL);
	ft_printf(" %X | %X\n", 10, 10);
	//printf(" %X | %X\n", 1, 1);
	ft_printf("Character: %c\n", '0');
	ft_printf("Percent sign: %%\n");
	ft_printf("Integer: %d | String: %s\n", i, str);
	ft_printf("Pointer: %p\n", ptr);
	printf("Pointer real: %p\n", ptr);
    return (0);
}
*/