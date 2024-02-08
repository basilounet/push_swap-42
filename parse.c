/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:58:07 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 15:18:16 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_ps *ps, enum e_errors name)
{
	unleak(ps);
	write(2, "Error\n", 6);
	exit(name);
}

static void	set_values(t_ps *ps)
{
	if (ps->a_size > 0)
		ps->a_first = *(int *)ps->stack_a->content;
	ps->smallest = get_smallest(ps->stack_a);
	ps->biggest = get_biggest(ps->stack_a);
}

static void	check_split(t_ps *ps)
{
	long	number;
	int		j;
	int		i;

	i = 0;
	number = 0;
	while (ps->split[i])
	{
		j = 0;
		if (ps->split[i][j] == '+' || ps->split[i][j] == '-')
			j++;
		number = ft_atol(ps->split[i]);
		if (!(-2147483648 <= number && number <= 2147483647)
			|| ps->split[i][j] == 0)
			error(ps, ENTRY_ERROR);
		while (ps->split[i][j])
		{
			if (!ft_isdigit(ps->split[i][j]))
				error(ps, ENTRY_ERROR);
			j++;
		}
		i++;
	}
}

void	check_stack(t_ps *ps)
{
	t_list	*tmp;
	int		j;
	int		i;

	i = 0;
	tmp = ps->stack_a;
	ps->a_size = ft_lstsize(ps->stack_a);
	ps->array = ft_calloc(sizeof(int), ps->a_size);
	if (!ps->array)
		error(ps, MALLOC_ERROR);
	while (tmp)
	{
		ps->array[i++] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	i--;
	while (--i >= 0)
	{
		j = ps->a_size - 1;
		while (j > i)
			if (ps->array[j--] == ps->array[i])
				error(ps, DUPLICATES_ERROR);
	}
	set_values(ps);
}

t_ps	parse_entries(t_ps *ps, int ac, char **av)
{
	int	*number;
	int	i;
	int	j;

	i = 1;
	ps_init(ps);
	while (i < ac)
	{
		ps->split = ft_split(av[i++], ' ');
		if (!ps->split)
			error(ps, MALLOC_ERROR);
		check_split(ps);
		j = 0;
		while (ps->split[j])
		{
			number = ft_calloc(sizeof(int), 1);
			if (!number)
				error(ps, MALLOC_ERROR);
			*number = ft_atoi(ps->split[j++]);
			ft_lstadd_back(&ps->stack_a, ft_lstnew("", number));
		}
		ps->split = ft_free_map(ps->split, ft_maplen(ps->split));
	}
	check_stack(ps);
	return (*ps);
}
