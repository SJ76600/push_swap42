/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:17:46 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:56:44 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

int	push_bonus(t_data *stack, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa_bonus(stack);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_bonus(stack);
	else
		return (0);
	return (1);
}

int	swap_bonus(t_data *stack, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa_bonus(stack);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_bonus(stack);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		sa_bonus(stack);
		sb_bonus(stack);
	}
	else
		return (0);
	return (1);
}

int	rotate_bonus(t_data *stack, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra_bonus(stack);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb_bonus(stack);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		ra_bonus(stack);
		rb_bonus(stack);
	}
	else
		return (0);
	return (1);
}

int	reverse_bonus(t_data *stack, char *str)
{
	if (ft_strcmp(str, "rra\n") == 0)
		rra_bonus(stack);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_bonus(stack);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		rra_bonus(stack);
		rrb_bonus(stack);
	}
	else
		return (0);
	return (1);
}
