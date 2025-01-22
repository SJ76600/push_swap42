/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:03:55 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/08 14:31:02 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_data *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	first = stack->a;
	second = stack->a->next;
	while (stack->a->next)
		stack->a = stack->a->next;
	stack->a->next = first;
	stack->a = second;
	first->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(t_data *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	first = stack->b;
	second = stack->b->next;
	while (stack->b->next)
		stack->b = stack->b->next;
	stack->b->next = first;
	stack->b = second;
	first->next = NULL;
	write (1, "rb\n", 3);
}

void	rr(t_data *stack_a, t_data *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
