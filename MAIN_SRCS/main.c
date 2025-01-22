/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:04:24 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:37:54 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	char	**elements;
	t_data	stack;

	elements = NULL;
	if (argc > 1)
	{
		elements = init_stack(argv);
		if (!elements)
			return (1);
		if (ft_errors(elements))
			return (free_split(elements), 1);
		stack.a = a(elements);
		stack.b = b();
		if (list_size(stack.a) == 1 || sorted(stack.a) == 1)
		{
			free_stack(stack.a);
			return (free_split(elements), 0);
		}
		indexation(&stack);
		main_sort(&stack);
		free_split(elements);
		free_stack(stack.a);
		free_stack(stack.b);
	}
	return (0);
}
