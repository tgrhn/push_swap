/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:48 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:35:49 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_sa(stack_a);
}

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;
	int	distance1;

	distance = ft_get_distance(stack_a, ft_smallest(stack_a));
	distance1 = ft_get_distance(stack_a, ft_max(stack_a));
	if (distance == 0 && distance1 == 1)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a);
	}
	else if (distance == 1 && distance1 == 2)
		ft_sa(stack_a);
	else if (distance == 2 && distance1 == 1)
		ft_rra(stack_a, 0);
	else if (distance == 1 && distance1 == 0)
		ft_ra(stack_a, 0);
	else if (distance == 2 && distance1 == 0)
	{
		ft_sa(stack_a);
		ft_rra(stack_a, 0);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_smallest(stack_a));
	if (distance == 1)
		ft_ra(stack_a, 0);
	else if (distance == 2)
	{
		ft_ra(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (distance == 3)
		ft_rra(stack_a, 0);
	if (ft_sorted(stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_smallest(stack_a));
	if (distance == 1)
		ft_ra(stack_a, 0);
	else if (distance == 2)
	{
		ft_ra(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (distance == 3)
	{
		ft_ra(stack_a, 0);
		ft_ra(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (distance == 4)
		ft_rra(stack_a, 0);
	if (ft_sorted(stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	long long	min;

	min = ft_get_min(stack_a);
	if (ft_list_size(stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_list_size(stack_a) == 3)
		ft_sort_three(stack_a, stack_b);
	else if (ft_list_size(stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_list_size(stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	else if (ft_list_size(stack_a) > 5)
	{
		ft_offset(stack_a, min);
		ft_radix(stack_a, stack_b);
		ft_deoffset(stack_a, min);
	}
}
