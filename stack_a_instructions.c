/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:10:18 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 15:18:21 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps, int is_print)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (ps->a_size < 2)
		return ;
	first = ps->stack_a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	ps->stack_a = second;
	ps->a_first = *(int *)ps->stack_a->content;
	if (is_print)
		ft_printf("sa\n");
}

void	pa(t_ps *ps, int is_print)
{
	t_list	*tmp;

	if (ps->b_size < 1)
		return ;
	tmp = ps->stack_b;
	ps->stack_b = ps->stack_b->next;
	ft_lstadd_front(&ps->stack_a, tmp);
	ps->b_size--;
	ps->a_size++;
	ps->a_first = *(int *)ps->stack_a->content;
	if (ps->b_size > 0)
		ps->b_first = *(int *)ps->stack_b->content;
	if (is_print)
		ft_printf("pa\n");
}

void	ra(t_ps *ps, int is_print)
{
	t_list	*last;

	if (ps->a_size < 2)
		return ;
	last = ft_lstlast(ps->stack_a);
	last->next = ps->stack_a;
	ps->stack_a = ps->stack_a->next;
	last->next->next = NULL;
	ps->a_first = *(int *)ps->stack_a->content;
	if (is_print)
		ft_printf("ra\n");
}

void	rra(t_ps *ps, int is_print)
{
	t_list	*penultimate;
	t_list	*last;

	if (ps->a_size < 2)
		return ;
	last = ft_lstlast(ps->stack_a);
	penultimate = ft_lst_getindex(ps->stack_a, ps->a_size - 2);
	last->next = ps->stack_a;
	ps->stack_a = last;
	penultimate->next = NULL;
	ps->a_first = *(int *)ps->stack_a->content;
	if (is_print)
		ft_printf("rra\n");
}
