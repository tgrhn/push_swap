/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:32 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 18:38:56 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	long long		data;
	struct stack	*next;
}	t_stack;

long		ft_list_size(t_stack **stack);
long long	ft_atoi(const char *str);
void		ft_error_codes(int error_code);
void		ft_error_code(t_stack **stack_a, t_stack **stack_b, int x);
int			ft_sorted(t_stack **stack_a);
int			ft_swap(t_stack **stack);
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_b, t_stack **stack_a);
void		ft_push(t_stack **stack_to, t_stack **stack_from);
void		ft_ra(t_stack **stack_a, int x);
void		ft_rb(t_stack **stack_b, int x);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a, int x);
void		ft_rrb(t_stack **stack_b, int x);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
char		**ft_split(char const *s, char c);
int			ft_get_distance(t_stack **stack_a, int min);
int			ft_smallest(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_two(t_stack **stack_a);
long long	ft_max(t_stack **stack_a);
void		ft_radix(t_stack **stack_a, t_stack **stack_b);
long		ft_max_bits(t_stack **stack_a);
void		free_stack(t_stack **stack);
void		ft_free(char **str);
void		ft_sort_algorithm(t_stack **stack_a, t_stack **stack_b);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_deoffset(t_stack **stack_a, long long min);
void		ft_offset(t_stack **stack_a, long long min);
long		ft_get_min(t_stack **stack_a);
void		ft_free_first(t_stack **stack_a, t_stack **stack_b);
void		ft_max_min_checker(t_stack **stack_a, t_stack **stack_b);
int			ft_strlen(const char *s);
#endif 
