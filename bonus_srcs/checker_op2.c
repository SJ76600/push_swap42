/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:36:01 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:57:18 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ra_bonus(t_data *stack)
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
}

void	rb_bonus(t_data *stack)
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
}

void	rr_bonus(t_data *stack_a, t_data *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
