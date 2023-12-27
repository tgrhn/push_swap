/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:38:03 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:38:04 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long	ft_get_min(t_stack **stack_a)
{
	t_stack		*tmp;
	long long	min;

	tmp = *stack_a;
	min = tmp->data;
	while (*stack_a)
	{
		if ((*stack_a)->data < min)
			min = (*stack_a)->data;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (min);
}

int	ft_smallest(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = (*stack_a)->data;
	while (*stack_a)
	{
		if ((*stack_a)->data < min)
			min = (*stack_a)->data;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (min);
}

long long	ft_max(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack_a;
	max = (*stack_a)->data;
	while (*stack_a)
	{
		if ((*stack_a)->data > max)
			max = (*stack_a)->data;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (max);
}

int	ft_get_distance(t_stack **stack_a, int min)
{
	t_stack	*tmp;
	int		distance;

	tmp = *stack_a;
	distance = 0;
	while (*stack_a)
	{
		if (min == (*stack_a)->data)
			break ;
		distance++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (distance);
}
