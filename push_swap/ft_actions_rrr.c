/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:22 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:35:23 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int x)
{
	t_stack	*last;
	t_stack	*start;

	last = *stack_a;
	while ((*stack_a)->next->next)
		(*stack_a) = (*stack_a)->next;
	start = (*stack_a)->next;
	start->next = last;
	(*stack_a)->next = NULL;
	*stack_a = start;
	if (x == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b, int x)
{
	t_stack	*last;
	t_stack	*start;

	last = *stack_b;
	while ((*stack_b)->next->next)
		(*stack_b) = (*stack_b)->next;
	start = (*stack_b)->next;
	start->next = last;
	(*stack_b)->next = NULL;
	*stack_b = start;
	if (x == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
