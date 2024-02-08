/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:48:44 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/08 14:52:31 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum		e_errors
{
	MALLOC_ERROR = 1,
	ENTRY_ERROR = 2,
	ARGUMENTS_COUNT_ERROR = 3,
	DUPLICATES_ERROR = 4
};

typedef struct s_cost
{
	int		*total_price;
	int		a_price;
	int		b_price;
	size_t	c_s_i;
}			t_cost;

typedef struct s_data
{
	size_t	c_s_i;
	int		a_value;
	int		b_value;
}			t_data;

typedef struct s_ps
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	a_size;
	size_t	b_size;
	int		smallest;
	int		biggest;
	int		a_first;
	int		b_first;
	t_list	*costs;
	char	**split;
	int		*array;
}			t_ps;

/*======= ERRORS =======*/

void		error(t_ps *ps, enum e_errors name);

/*======= STRUCT_INIT =======*/

void		ps_init(t_ps *ps);
void		costs_init(t_ps *ps, t_cost *cost);

/*======= PARSING =======*/

t_ps		parse_entries(t_ps *ps, int ac, char **av);

/*======= UNLEAK =======*/

void		unleak(t_ps *ps);

/*======= STACK_OPERATIONS =======*/

void		sa(t_ps *ps, int is_print);
void		sb(t_ps *ps, int is_print);
void		ss(t_ps *ps, int is_print);
void		pa(t_ps *ps, int is_print);
void		pb(t_ps *ps, int is_print);
void		ra(t_ps *ps, int is_print);
void		rb(t_ps *ps, int is_print);
void		rr(t_ps *ps, int is_print);
void		rra(t_ps *ps, int is_print);
void		rrb(t_ps *ps, int is_print);
void		rrr(t_ps *ps, int is_print);

/*======= SORT =======*/

void		assemble(t_ps *ps);
int			get_index(t_list *lst, int nb);
int			get_smallest(t_list *lst);
int			get_closest_smallest(t_list *lst, int number);
int			get_biggest(t_list *lst);
int			get_closest_biggest(int number, t_list *lst);
void		move_x_top_a(t_ps *ps, int x);
void		move_x_bottom_a(t_ps *ps, int x);
void		move_x_top_b(t_ps *ps, int x);
void		move_x_bottom_b(t_ps *ps, int x);
int			is_sorted(t_list *stack);
void		sort_three(t_ps *ps);
void		sort(t_ps *ps);

#endif