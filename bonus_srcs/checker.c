/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:05:01 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:56:19 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/push_swap.h"
#include "../includes/checker.h"

void	ft_free(t_data *stack)
{
	t_list	*next_node;

	while (stack->a != NULL)
	{
		next_node = stack->a->next;
		free(stack->a);
		stack->a = next_node;
	}
	while (stack->b != NULL)
	{
		next_node = stack->b->next;
		free(stack->b);
		stack->b = next_node;
	}
}

int	print_error(void)
{
	write (1, "Error\n", 6);
	return (1);
}

int	valid_instruct(char *str, t_data *stack)
{
	if (!str || ft_strlen(str) < 2)
		return (0);
	if (str[0] == 'p' && (str[1] == 'a' || str[1] == 'b')
		&& push_bonus(stack, str))
		return (1);
	else if (str[0] == 's' && (str[1] == 'a' || str[1] == 'b')
		&& swap_bonus(stack, str))
		return (1);
	else if (str[0] == 'r' && rotate_bonus(stack, str))
		return (1);
	else if (str[0] == 'r' && str[1] == 'r' && reverse_bonus(stack, str))
		return (1);
	print_error();
	return (0);
}

int	read_instructs(t_data *stack)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (valid_instruct(str, stack) == 0)
		{
			free (str);
			get_next_line(-1);
			return (0);
		}
		free(str);
	}
	get_next_line(-1);
	return (1);
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
		stack.b = NULL;
		free_split(elements);
		indexation(&stack);
		if (read_instructs(&stack) == 0)
			return (ft_free(&stack), 1);
		if (sorted(stack.a))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
		ft_free(&stack);
	}
	return (0);
}
