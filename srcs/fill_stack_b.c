/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:44:44 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/08 14:24:04 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_size(t_list *node)
{
	int	size;

	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int	max_of_b(t_data *stack)
{
	int		max;
	t_list	*b;

	max = 0;
	b = stack->b;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

int	median_stack_b(t_data *stack)
{
	int		i;
	t_list	*b;

	i = 0;
	b = stack->b;
	while (b->index != max_of_b(stack))
	{
		i++;
		b = b->next;
	}
	if (i <= list_size(stack->b) / 2)
		return (1);
	else
		return (-1);
}
