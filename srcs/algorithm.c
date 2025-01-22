/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:17:04 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/16 14:15:16 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_nb_steps(int size)
{
	int	n;

	if (size <= 100)
		n = size * 15 / 100;
	else
		n = size * 30 / 500;
	return (n);
}

void	push_a2b(t_data *stack)
{
	int		counter;
	int		n;
	t_list	*a;

	counter = 0;
	n = count_nb_steps(list_size(stack->a));
	a = stack->a;
	while (a != NULL)
	{
		if (a->index <= counter)
		{
			pb(stack);
			rb(stack);
			counter++;
		}
		else if (a->index <= counter + n)
		{
			pb(stack);
			counter++;
		}
		else
			ra(stack);
		a = stack->a;
	}
}

void	push_max_elements(int i, int size, t_data *stack, t_list *b)
{
	while (i < size)
	{
		if (b->index == max_of_b(stack))
		{
			pa(stack);
			b = stack->b;
		}
		else
		{
			while (b->index != max_of_b(stack))
			{
				if (median_stack_b(stack) == 1)
					rb(stack);
				else
					rrb(stack);
				b = stack->b;
			}
			pa(stack);
			b = stack->b;
		}
		i++;
	}
}

void	push_b2a(t_data *stack)
{
	int		i;
	int		size;
	t_list	*b;

	i = 0;
	b = stack->b;
	size = list_size(stack->b);
	push_max_elements(i, size, stack, b);
}

void	main_sort(t_data *stack)
{
	if (list_size(stack->a) == 2)
	{
		if (stack->a->data > stack->a->next->data)
			sa(stack);
		return ;
	}
	else if (list_size(stack->a) == 3)
		sort_by_3(stack);
	else if (list_size(stack->a) == 4)
		sort_by_4(stack, 1);
	else if (list_size(stack->a) == 5)
		sort_by_5(stack);
	else
	{
		push_a2b(stack);
		push_b2a(stack);
	}
}
