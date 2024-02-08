/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:53:02 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 13:54:00 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int		number;
	t_list	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	number = *(int *)tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (*(int *)tmp->content < number)
			return (0);
		number = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (1);
}

int	get_index(t_list *lst, int nb)
{
	t_list	*tmp;
	int		index;

	tmp = lst;
	if (!tmp)
		return (0);
	index = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == nb)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}
