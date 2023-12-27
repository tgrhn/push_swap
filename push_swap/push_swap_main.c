/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:55 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:35:55 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arguments(char **argv, int argc)
{
	int		i;
	int		j;

	i = 0;
	if (argc > 2)
		i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
			j = 1;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

t_stack	*ft_convert_to_list(char **argv, int size, int control)
{
	t_stack	*new_list;
	t_stack	*tmp;

	new_list = malloc(sizeof(t_stack));
	tmp = new_list;
	while (control - 3 < size)
	{
		new_list->data = ft_atoi(argv[control - 3]);
		if (argv[control - 2])
		{
			new_list->next = malloc(sizeof(t_stack));
			new_list = new_list->next;
		}
		control++;
	}
	new_list = NULL;
	new_list = tmp;
	return (new_list);
}

int	ft_checkcopy(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*control;

	tmp = *stack_a;
	control = tmp;
	while (control)
	{
		tmp = control->next;
		while (tmp)
		{
			if (control->data == tmp->data)
				return (-1);
			tmp = tmp->next;
		}
		control = control->next;
	}
	return (0);
}

int	argv_counter(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if ((argc == 1) || (argc == 2 && argv[1][0] == 0) || (argv[1][0] == 32))
		ft_error_code(stack_a, stack_b, 1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (ft_check_arguments(argv, argc) == -1 || ft_checkcopy(stack_a) == -1)
		ft_error_code(stack_a, stack_b, 0);
	if (argc == 2)
		*stack_a = ft_convert_to_list(argv, argv_counter(argv), 3);
	else
		*stack_a = ft_convert_to_list(argv, argc, 4);
	ft_max_min_checker(stack_a, stack_b);
	if (ft_checkcopy(stack_a) == -1)
		ft_error_code(stack_a, stack_b, 0);
	if (ft_sorted(stack_a) == 0)
		ft_free_first(stack_a, stack_b);
	ft_sort_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
