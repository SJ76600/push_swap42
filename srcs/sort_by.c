/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:27:24 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:49:51 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_by_3(t_data *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->a;
	second = stack->a->next;
	last = stack->a->next->next;
	if (sorted(first) == 1)
		return ;
	else if (first->index < second->index && first->index < last->index)
	{
		rra(stack);
		sa(stack);
	}
	else if (first->index < second->index && first->index > last->index)
		rra(stack);
	else if (first->index > second->index && first->index < last->index)
		sa(stack);
	else
	{
		ra(stack);
		if (second->index > last->index)
			sa(stack);
	}
}

void	sorting3(t_data *stack, t_list *node)
{
	if (sorted(node) == 0)
	{
		pb(stack);
		sort_by_3(stack);
		pa(stack);
	}
	else
		return ;
	if (node->index > node->next->index)
		sa(stack);
}

void	sort_by_4(t_data *stack, int n)
{
	t_list	*first;
	int		i;

	first = stack->a;
	i = 0;
	while (first)
	{
		if (first->index == n)
			break ;
		i++;
		first = first->next;
	}
	first = stack->a;
	while (first->index != n)
	{
		if (i < 2)
			ra(stack);
		else
			rra(stack);
		first = stack->a;
	}
	sorting3(stack, first);
}

void	sorting4(t_data *stack, t_list *node)
{
	if (sorted(node) == 0)
	{
		pb(stack);
		sort_by_4(stack, 1);
		pa(stack);
	}
}

void	sort_by_5(t_data *stack)
{
	int		i;
	t_list	*first;

	i = 0;
	first = stack->a;
	while (first)
	{
		if (first->index == 0)
			break ;
		i++;
		first = first->next;
	}
	first = stack->a;
	while (first->index != 0)
	{
		if (i < 2)
			ra(stack);
		else
			rra(stack);
		first = stack->a;
	}
	sorting4(stack, first);
}
