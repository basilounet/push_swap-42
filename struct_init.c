/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:07:10 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:52:44 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init(t_ps *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->a_size = 0;
	ps->b_size = 0;
	ps->a_first = 0;
	ps->b_first = 0;
	ps->costs = NULL;
	ps->split = NULL;
	ps->array = NULL;
}

void	costs_init(t_ps *ps, t_cost *cost)
{
	cost->total_price = ft_calloc(sizeof(int), 1);
	if (!cost->total_price)
		error(ps, MALLOC_ERROR);
	cost->a_price = 0;
	cost->b_price = 0;
	cost->c_s_i = 0;
}
