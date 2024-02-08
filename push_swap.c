/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:48:13 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 13:26:26 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;

	ps = parse_entries(&ps, ac, av);
	if (ps.a_size == 2 && !is_sorted(ps.stack_a))
		sa(&ps, 1);
	while (ps.b_size != 0 || !is_sorted(ps.stack_a))
	{
		if (ps.a_size == 3)
		{
			sort_three(&ps);
			assemble(&ps);
		}
		else
			sort(&ps);
	}
	unleak(&ps);
	return (0);
}
