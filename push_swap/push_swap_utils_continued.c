/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_continued.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:15 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:36:16 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}

void	ft_max_min_checker(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->data > 2147483647 || (*stack_a)->data < -2147483648)
			ft_error_code(stack_a, stack_b, 0);
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = tmp;
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
