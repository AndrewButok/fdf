/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:19:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/21 12:19:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		hex_to_dec(char ch)
{
	char	*alph;
	int		i;

	alph = "0123456789abcdef";
	if (ch >= 'A' && ch <= 'F')
		ch += 'a' - 'A';
	i = 0;
	while (alph[i] != ch)
		i++;
	return (i);
}

int		ft_hexatoi(char *str)
{
	int val;

	while (*str == ' ' || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while (*str == '0')
		str++;
	val = 0;
	while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
			|| (*str >= 'A' && *str <= 'F'))
	{
		val *= 16;
		val += hex_to_dec(*str);
		str++;
	}
	return (val);
}

char	*ft_dtoa(double d)
{
	//todo
	return (NULL);
}
