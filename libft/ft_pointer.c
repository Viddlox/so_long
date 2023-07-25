/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:29 by micheng           #+#    #+#             */
/*   Updated: 2023/06/05 15:30:21 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(void *ptr)
{
	int					i;
	int					count;
	unsigned long		address;
	char				*str;

	count = 0;
	i = 0;
	address = (unsigned long)ptr;
	count += ft_putstr("0x");
	str = ft_itoa_base(address, HEX_LOW);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
		count += ft_putchar(str[i++]);
	free(str);
	return (count);
}
