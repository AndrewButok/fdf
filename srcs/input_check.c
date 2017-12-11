/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:35:41 by abutok            #+#    #+#             */
/*   Updated: 2017/12/06 18:42:25 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h

bool	checkz(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '+'
				&& *str != '-')
			return (false);
		str++;
	}
	return (true);
}

bool	checkcolorhex(char *str)
{
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		if (!ft_isdigit(*str) && !(*str >= 'a' && *str <= 'f')
				&& !(*str >= 'A' && *str <= 'F'))
			return (false);
		str++;
	}
	return (true);
}
