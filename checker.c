/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:22:29 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:04:59 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_instruction(t_ps *ps, char *str)
{
	if (!str)
		return ;
	if (!ft_strncmp(str, "pa\n", 4))
		pa(ps, 0);
	else if (!ft_strncmp(str, "pb\n", 4))
		pb(ps, 0);
	else if (!ft_strncmp(str, "sa\n", 4))
		sa(ps, 0);
	else if (!ft_strncmp(str, "sb\n", 4))
		sb(ps, 0);
	else if (!ft_strncmp(str, "ra\n", 4))
		ra(ps, 0);
	else if (!ft_strncmp(str, "rb\n", 4))
		rb(ps, 0);
	else if (!ft_strncmp(str, "rr\n", 4))
		rr(ps, 0);
	else if (!ft_strncmp(str, "rra\n", 5))
		rra(ps, 0);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrb(ps, 0);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rrr(ps, 0);
	else
		error(ps, ENTRY_ERROR);
}

int	main(int ac, char **av)
{
	t_ps	ps;
	char	*line;

	if (ac < 2)
		return (0);
	ps = parse_entries(&ps, ac, av);
	line = get_next_line(0);
	while (line)
	{
		execute_instruction(&ps, line);
		if (line)
			free(line);
		line = get_next_line(0);
	}
	if (is_sorted(ps.stack_a) && ps.b_size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	unleak(&ps);
	return (0);
}
