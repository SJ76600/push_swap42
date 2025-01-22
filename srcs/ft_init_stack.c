/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:36:43 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/17 08:34:57 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**init_stack(char **argv)
{
	int		i;
	char	*args;
	char	**splited;
	char	*tmp;

	i = 0;
	args = NULL;
	while (argv[++i])
	{
		if (!args)
			args = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(args, " ");
			free (args);
			args = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
	}
	if (!args)
		return (NULL);
	splited = ft_split(args, ' ');
	free(args);
	return (splited);
}

t_list	*a(char **str)
{
	int		i;
	t_list	*first;
	t_list	*temp;
	t_list	*last;

	i = 1;
	first = (t_list *)malloc(sizeof(t_list));
	if (!first || !str[0])
		return (NULL);
	first->data = ft_atol(str[0]);
	first->next = NULL;
	last = first;
	while (str[i])
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			return (NULL);
		temp->data = ft_atol(str[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		i++;
	}
	return (first);
}

t_list	*b(void)
{
	return (NULL);
}

int	sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
