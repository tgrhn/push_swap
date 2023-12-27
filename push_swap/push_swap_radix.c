/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:05 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:36:06 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_max_bits(t_stack **stack_a)
{
	t_stack		*tmp;
	long long	max;
	long long	max_bit;
	long long	i;

	tmp = *stack_a;
	max = tmp->data;
	max_bit = 0;
	while (*stack_a)
	{
		if ((*stack_a)->data > max)
			max = (*stack_a)->data;
		(*stack_a) = (*stack_a)->next;
	}
	while (max >> max_bit != 0)
		max_bit++;
	*stack_a = tmp;
	return (max_bit);
}

void	ft_offset(t_stack **stack_a, long long min)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (min < 0)
	{
		while (*stack_a)
		{
			(*stack_a)->data = (*stack_a)->data - min;
			(*stack_a) = (*stack_a)->next;
		}
	}
	*stack_a = tmp;
}

void	ft_deoffset(t_stack **stack_a, long long min)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (min < 0)
	{
		while (*stack_a)
		{
			(*stack_a)->data = (*stack_a)->data + min;
			(*stack_a) = (*stack_a)->next;
		}
	}
	*stack_a = tmp;
}

void	ft_radix_cont(t_stack **stack_a, t_stack **stack_b, long size, int i)
{
	int		j;
	t_stack	*head_a;
	int		control;

	j = 0;
	control = 0;
	while (j < size)
	{
		head_a = *stack_a;
		if (((head_a->data >> i) & 1) == 1)
			ft_ra(stack_a, 0);
		else
		{
			ft_pb(stack_a, stack_b);
			control++;
		}
		j++;
	}
	while (control > 0)
	{
		ft_pa(stack_a, stack_b);
		control--;
	}
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	long	i;
	long	j;
	long	size;
	long	max_bits;

	i = 0;
	size = ft_list_size(stack_a);
	max_bits = ft_max_bits(stack_a);
	while (i < max_bits)
	{
		ft_radix_cont(stack_a, stack_b, size, i);
		i++;
	}
}
