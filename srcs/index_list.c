/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:44:55 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/08 14:27:45 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_data *stack, t_list *first, t_list *min)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(stack->a);
	while (i < size)
	{
		min = first;
		while (min)
		{
			if (min->index != -1)
				min = min->next;
			else
				break ;
		}
		while (first)
		{
			if (first->data < min->data && first->index == -1)
				min = first;
			first = first->next;
		}
		min->index = i++;
		first = stack->a;
	}
}

void	indexation(t_data *stack)
{
	t_list	*first;
	t_list	*min;

	first = stack->a;
	min = first;
	while (first)
	{
		first->index = -1;
		first = first->next;
	}
	first = stack->a;
	init_index(stack, first, min);
}
