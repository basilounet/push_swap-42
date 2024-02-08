/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:37:35 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:47:23 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_x_top_a(t_ps *ps, int x)
{
	t_list	*tmp;
	size_t	index;

	index = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		if (*(int *)tmp->content == x || index > ps->a_size / 2)
			break ;
		index++;
		tmp = tmp->next;
	}
	if (index <= ps->a_size / 2)
		while (ps->a_first != x)
			ra(ps, 1);
	else
		while (ps->a_first != x)
			rra(ps, 1);
}

void	move_x_bottom_a(t_ps *ps, int x)
{
	t_list	*tmp;
	size_t	index;

	index = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		if (*(int *)tmp->content == x || index > ps->a_size / 2)
			break ;
		index++;
		tmp = tmp->next;
	}
	if (index <= ps->a_size / 2)
		while (*(int *)ft_lstlast(ps->stack_a)->content != x)
			ra(ps, 1);
	else
		while (*(int *)ft_lstlast(ps->stack_a)->content != x)
			rra(ps, 1);
}

void	move_x_top_b(t_ps *ps, int x)
{
	t_list	*tmp;
	size_t	index;

	index = 0;
	tmp = ps->stack_b;
	while (tmp)
	{
		if (*(int *)tmp->content == x || index > ps->b_size / 2)
			break ;
		index++;
		tmp = tmp->next;
	}
	if (index <= ps->b_size / 2)
		while (ps->b_first != x)
			rb(ps, 1);
	else
		while (ps->b_first != x)
			rrb(ps, 1);
}

void	move_x_bottom_b(t_ps *ps, int x)
{
	t_list	*tmp;
	size_t	index;

	index = 0;
	tmp = ps->stack_b;
	while (tmp)
	{
		if (*(int *)tmp->content == x || index > ps->b_size / 2)
			break ;
		index++;
		tmp = tmp->next;
	}
	if (index <= ps->b_size / 2)
		while (*(int *)ft_lstlast(ps->stack_b)->content != x)
			rb(ps, 1);
	else
		while (*(int *)ft_lstlast(ps->stack_b)->content != x)
			rrb(ps, 1);
}
