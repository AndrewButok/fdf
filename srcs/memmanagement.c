/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmanagement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 00:37:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/23 00:37:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	memreg(t_mlist **mem_list, void *content)
{
	t_mlist *new;

	if (mem_list == NULL)
		return ;
	errno = 0;
	new = (t_mlist*)ft_memalloc(sizeof(t_mlist));
	if (errno != 0)
	{
		perror("The following memory management error occurred:");
		exit(-1);
	}
	new->content = content;
	new->next = *mem_list;
	*mem_list = new;
}

void	memregdel(t_mlist **mem_list, void *memtodel)
{
	t_mlist *iterator;
	t_mlist	*buff;

	if (mem_list == NULL || memtodel == NULL || *mem_list == NULL)
		return ;
	if ((*mem_list)->content == memtodel)
	{
		iterator = (*mem_list)->next;
		ft_memdel((void**)mem_list);
		*mem_list = iterator;
		return ;
	}
	iterator = *mem_list;
	while (iterator != NULL)
	{
		if (iterator->next->content == memtodel)
		{
			buff = iterator->next->next;
			ft_memdel((void**)&(iterator->next));
			iterator->next = buff;
			return ;
		}
		iterator = iterator->next;
	}
}

void	memclear(t_mlist **mem_list)
{
	t_mlist *next;

	if (mem_list != NULL && *mem_list == NULL)
		while (*mem_list != NULL)
		{
			ft_memdel(&((*mem_list)->content));
			next = (*mem_list)->next;
			ft_memdel((void**)mem_list);
			*mem_list = next;
		}
}
