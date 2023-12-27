/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_pr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:07 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:35:08 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ft_ra(t_stack **stack_a, int x)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_a;
	last = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->next = NULL;
	*stack_a = last;
	if (x == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b, int x)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_b;
	last = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->next = NULL;
	*stack_b = last;
	if (x == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_a, 1);
	write(1, "rr\n", 3);
}
