/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:18:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/21 16:18:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*merge(t_list *list, size_t len)
{
	t_list	*r;
	t_list	*buf;

	r = list;
	while (len--)
		r = r->next;
	buf = r->next;
	r->next = NULL;
	r = buf;
	return (r);
}

t_list	*spush(t_list *l, t_list *r)
{
	if (l != NULL && (r == NULL ||
			((t_point*)l->content)->z > ((t_point*)r->content)->z))
		return (l);
	if (r != NULL && (l == NULL ||
			((t_point*)l->content)->z <= ((t_point*)r->content)->z))
		return (r);
}

t_list	*push(t_list *l, t_list *r)
{
	t_list	*rv;
	t_list	*start;
	t_list	*n;

	while (l != NULL || r != NULL)
	{
		n = spush(l, r);
		l = n == l ? l->next : l;
		r = n == r ? r->next : r;
		if (rv == NULL)
		{
			rv = n;
			start = n;
		}
		else
		{
			rv->next = n;
			rv = rv->next;
		}
	}
	rv->next = NULL;
	return (start);
}

void	merge_sort(t_list **list, size_t len)
{
	t_list *l;
	t_list *r;
	size_t ll;
	size_t lr;

	l = *list;
	r = *list;
	lr = len / 2;
	ll = len - ll;
	r = merge(l, ll);
	if (ll > 1)
		merge_sort(l, ll);
	if (lr > 1)
		merge_sort(r, lr);
	*list = push(l, r);
}
