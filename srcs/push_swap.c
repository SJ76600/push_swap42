/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:52:11 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/08 14:26:54 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *stack)
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
	write (1, "sa\n", 3);
}

void	sb(t_data *stack)
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
	write (1, "sb\n", 3);
}

void	ss(t_data *stack_a, t_data *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write (1, "ss\n", 3);
}

void	pa(t_data *stack)
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
	write (1, "pa\n", 3);
}

void	pb(t_data *stack)
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
	write (1, "pb\n", 3);
}
