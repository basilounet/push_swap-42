/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shared_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:20:56 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 13:15:42 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps *ps, int is_print)
{
	sa(ps, 0);
	sb(ps, 0);
	if (is_print)
		ft_printf("ss\n");
}

void	rr(t_ps *ps, int is_print)
{
	ra(ps, 0);
	rb(ps, 0);
	if (is_print)
		ft_printf("rr\n");
}

void	rrr(t_ps *ps, int is_print)
{
	rra(ps, 0);
	rrb(ps, 0);
	if (is_print)
		ft_printf("rrr\n");
}
