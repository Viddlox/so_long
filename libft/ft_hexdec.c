/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:36:17 by micheng           #+#    #+#             */
/*   Updated: 2023/06/05 15:30:12 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexdec(unsigned int num, const char conv)
{
	int		count;
	char	*str;

	count = 0;
	if (conv == 'x')
		str = ft_itoa_base(num, HEX_LOW);
	else
		str = ft_itoa_base(num, HEX_UP);
	if (!str)
		str = "(null)";
	while (str[count] != '\0')
		count += ft_putchar(str[count]);
	free(str);
	return (count);
}
