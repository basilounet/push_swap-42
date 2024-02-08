/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:11:47 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:27:26 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unleak(t_ps *ps)
{
	ft_lstclear(&ps->stack_a, &free);
	ft_lstclear(&ps->stack_b, &free);
	if (ps->costs)
		ft_lstclear(&ps->costs, &free);
	if (ps->split)
		ft_free_map(ps->split, ft_maplen(ps->split));
	if (ps->array)
		free(ps->array);
}
