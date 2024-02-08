/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:12 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 15:18:47 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps *ps, int is_print)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (ps->b_size < 2)
		return ;
	first = ps->stack_b;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	ps->stack_b = second;
	ps->b_first = *(int *)ps->stack_b->content;
	if (is_print)
		ft_printf("sb\n");
}

void	pb(t_ps *ps, int is_print)
{
	t_list	*first;

	if (ps->a_size < 1)
		return ;
	first = ps->stack_a;
	ps->stack_a = ps->stack_a->next;
	ft_lstadd_front(&ps->stack_b, first);
	ps->a_size--;
	ps->b_size++;
	ps->b_first = *(int *)ps->stack_b->content;
	if (ps->a_size > 0)
		ps->a_first = *(int *)ps->stack_a->content;
	if (is_print)
		ft_printf("pb\n");
}

void	rb(t_ps *ps, int is_print)
{
	t_list	*last;

	if (ps->b_size < 2)
		return ;
	last = ft_lstlast(ps->stack_b);
	last->next = ps->stack_b;
	ps->stack_b = ps->stack_b->next;
	last->next->next = NULL;
	ps->b_first = *(int *)ps->stack_b->content;
	if (is_print)
		ft_printf("rb\n");
}

void	rrb(t_ps *ps, int is_print)
{
	t_list	*penultimate;
	t_list	*last;

	if (ps->b_size < 2)
		return ;
	last = ft_lstlast(ps->stack_b);
	penultimate = ft_lst_getindex(ps->stack_b, ps->b_size - 2);
	last->next = ps->stack_b;
	ps->stack_b = last;
	penultimate->next = NULL;
	ps->b_first = *(int *)ps->stack_b->content;
	if (is_print)
		ft_printf("rrb\n");
}
