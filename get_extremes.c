/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extremes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:23:56 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:24:12 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_list *lst)
{
	t_list	*tmp;
	int		smallest;

	tmp = lst;
	if (!tmp)
		return (-2147483648);
	smallest = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < smallest)
			smallest = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

int	get_closest_smallest(t_list *lst, int number)
{
	t_list	*tmp;
	int		closest_smallest;

	tmp = lst;
	if (!lst)
		return (-2147483648);
	closest_smallest = get_smallest(lst);
	while (tmp)
	{
		if (*(int *)tmp->content > closest_smallest
			&& *(int *)tmp->content < number)
			closest_smallest = *(int *)tmp->content;
		tmp = tmp->next;
	}
	if (number < closest_smallest)
		return (get_biggest(lst));
	return (closest_smallest);
}

int	get_biggest(t_list *lst)
{
	t_list	*tmp;
	int		biggest;

	tmp = lst;
	if (!tmp)
		return (2147483647);
	biggest = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content > biggest)
			biggest = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (biggest);
}

int	get_closest_biggest(int number, t_list *lst)
{
	t_list	*tmp;
	int		closest_bigest;

	tmp = lst;
	if (!lst)
		return (-2147483648);
	closest_bigest = get_biggest(lst);
	while (tmp)
	{
		if (*(int *)tmp->content < closest_bigest && \
			*(int *)tmp->content > number)
			closest_bigest = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (closest_bigest);
}
