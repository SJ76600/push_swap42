/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:33:11 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:57:30 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	sa_bonus(t_data *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	first = stack->a;
	second = stack->a->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
}

void	sb_bonus(t_data *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	first = stack->b;
	second = stack->b->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
}

void	ss_bonus(t_data *stack_a, t_data *stack_b)
{
	sa_bonus(stack_a);
	sb_bonus(stack_b);
}

void	pa_bonus(t_data *stack)
{
	t_list	*a_first;
	t_list	*b_first;

	if (stack->b == NULL)
		return ;
	a_first = stack->a;
	b_first = stack->b;
	stack->b = stack->b->next;
	b_first->next = a_first;
	stack->a = b_first;
}

void	pb_bonus(t_data *stack)
{
	t_list	*a_first;
	t_list	*b_first;

	if (stack->a == NULL)
		return ;
	a_first = stack->a;
	b_first = stack->b;
	stack->a = stack->a->next;
	a_first->next = b_first;
	stack->b = a_first;
}
