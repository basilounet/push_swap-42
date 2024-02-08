/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:31:51 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:20 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	biggest_index;

	biggest_index = get_index(ps->stack_a, get_biggest(ps->stack_a));
	if (is_sorted(ps->stack_a))
		return ;
	if (biggest_index == 2)
		sa(ps, 1);
	else if (biggest_index == 1)
	{
		rra(ps, 1);
		sort_three(ps);
	}
	else if (biggest_index == 0)
	{
		ra(ps, 1);
		sort_three(ps);
	}
}

void	assemble(t_ps *ps)
{
	while (ps->b_size)
	{
		if (ps->b_first > get_biggest(ps->stack_a))
			move_x_bottom_a(ps, get_biggest(ps->stack_a));
		else if (get_closest_biggest(ps->b_first, ps->stack_a) != ps->a_first)
			move_x_top_a(ps, get_closest_biggest(ps->b_first, ps->stack_a));
		pa(ps, 1);
	}
	move_x_top_a(ps, ps->smallest);
}

void	get_move_counts(t_ps *ps)
{
	t_cost	cost;
	size_t	index;

	index = 0;
	ft_lstclear(&ps->costs, &free);
	while (index < ps->a_size)
	{
		costs_init(ps, &cost);
		cost.c_s_i = get_index(ps->stack_b, get_closest_smallest(ps->stack_b,
					*(int *)ft_lst_getindex(ps->stack_a, index)->content));
		while ((index - *cost.total_price > 0 && cost.c_s_i
				- *cost.total_price > 0) && (index
				+ *cost.total_price < ps->a_size && cost.c_s_i
				+ *cost.total_price < ps->b_size))
			(*cost.total_price)++;
		while (index - cost.a_price - *cost.total_price > 0 && index
			+ cost.a_price + *cost.total_price < ps->a_size)
			cost.a_price++;
		while (cost.c_s_i - cost.b_price - *cost.total_price > 0 && cost.c_s_i
			+ cost.b_price + *cost.total_price < ps->b_size)
			cost.b_price++;
		*cost.total_price += cost.a_price + cost.b_price + 1;
		ft_lstadd_back(&ps->costs, ft_lstnew("", cost.total_price));
		index++;
	}
}

static void	rotate_both(t_ps *ps, size_t index)
{
	t_data	data;

	data.c_s_i = get_index(ps->stack_b, get_closest_smallest(ps->stack_b,
				*(int *)ft_lst_getindex(ps->stack_a, index)->content));
	data.a_value = *(int *)ft_lst_getindex(ps->stack_a, index)->content;
	data.b_value = *(int *)ft_lst_getindex(ps->stack_b, data.c_s_i)->content;
	if (index <= ps->a_size / 2 && data.c_s_i <= ps->b_size / 2)
		while (ps->a_first != data.a_value && ps->b_first != data.b_value)
			rr(ps, 1);
	else if (index > ps->a_size / 2 && data.c_s_i > ps->b_size / 2)
		while (ps->a_first != data.a_value && ps->b_first != data.b_value)
			rrr(ps, 1);
	if (index <= ps->a_size / 2)
		while (ps->a_first != data.a_value)
			ra(ps, 1);
	else
		while (ps->a_first != data.a_value)
			rra(ps, 1);
	if (data.c_s_i <= ps->b_size / 2)
		while (ps->b_first != data.b_value)
			rb(ps, 1);
	else
		while (ps->b_first != data.b_value)
			rrb(ps, 1);
}

void	sort(t_ps *ps)
{
	if (ps->b_size < 2)
	{
		pb(ps, 1);
		return ;
	}
	get_move_counts(ps);
	rotate_both(ps, get_index(ps->costs, get_smallest(ps->costs)));
	pb(ps, 1);
}
