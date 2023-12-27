/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:25 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:38:39 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	number;
	long long	sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

long	ft_list_size(t_stack **stack)
{
	t_stack	*tmp;
	long	length;

	tmp = *stack;
	length = 0;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

void	ft_error_codes(int error_code)
{
	if (error_code == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_free_first(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	exit (0);
}

void	ft_error_code(t_stack **stack_a, t_stack **stack_b, int x)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (x == 0)
		write(2, "Error\n", 6);
	exit(1);
}
