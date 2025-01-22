/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:20:09 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/08 14:28:11 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *stack)
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
	write (1, "rra\n", 4);
}

void	rrb(t_data *stack)
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
	write (1, "rrb\n", 4);
}

void	rrr(t_data *stack_a, t_data *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
