/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:37:20 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:57:08 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rra_bonus(t_data *stack)
{
	t_list	*first;
	t_list	*prev;
	t_list	*last;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	first = stack->a;
	while (stack->a->next->next != NULL)
		stack->a = stack->a->next;
	prev = stack->a;
	last = stack->a->next;
	last->next = first;
	prev->next = NULL;
	first = last;
	stack->a = first;
}

void	rrb_bonus(t_data *stack)
{
	t_list	*first;
	t_list	*prev;
	t_list	*last;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	first = stack->b;
	while (stack->b->next->next != NULL)
		stack->b = stack->b->next;
	prev = stack->b;
	last = stack->b->next;
	last->next = first;
	prev->next = NULL;
	first = last;
	stack->b = first;
}

void	rrr_bonus(t_data *stack_a, t_data *stack_b)
{
	rra_bonus(stack_a);
	rrb_bonus(stack_b);
}
