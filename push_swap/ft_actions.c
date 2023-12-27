/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:32 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:35:33 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*tmp;
	int		tempo;

	if (ft_list_size(stack) < 2)
		return (-1);
	tmp = *stack;
	tempo = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = tempo;
	return (0);
}

void	ft_sa(t_stack **stack_a)
{
	if (ft_swap(stack_a) != -1)
		write(1, "sa\n", 3);
	else
		ft_error_codes(0);
}

void	ft_sb(t_stack **stack_b)
{
	if (ft_swap(stack_b) != -1)
		write(1, "sb\n", 3);
	else
		ft_error_codes(0);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(stack_a) != -1 && ft_swap(stack_b) != -1)
		write(1, "ss\n", 3);
	else
		ft_error_codes(0);
}

void	ft_push(t_stack **from_list, t_stack **to_list)
{
	t_stack	*new_node;

	new_node = *from_list;
	(*from_list) = (*from_list)->next;
	new_node->next = (*to_list);
	(*to_list) = new_node;
}
