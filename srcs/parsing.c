/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:17 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:35:47 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		if (ft_strcmp(str[i], "-") == 0 || ft_strcmp(str[i], "+") == 0)
			return (-1);
		if (str[i][0] == '-' || str[i][0] == '+')
			j++;
		if (str[i][j] < '0' || str[i][j] > '9')
			return (-1);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate(char **str)
{
	int	i;
	int	j;
	int	checker;

	i = 0;
	checker = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j++]))
				checker = -1;
		}
		i++;
	}
	return (checker);
}

int	check_min_max_num(char **str)
{
	int				i;
	long long int	num;
	char			*trimmed_str;

	i = 0;
	while (str[i])
	{
		num = ft_atol(str[i]);
		trimmed_str = str[i];
		while (*trimmed_str == '0' && *(trimmed_str + 1) != '\0')
			trimmed_str++;
		if (ft_strlen(str[i]) > 11)
			return (-1);
		num = ft_atol(str[i]);
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_errors(char **str)
{
	int	error;
	int	i;

	i = 0;
	error = 0;
	if (check_digit(str) == -1)
		error = 1;
	else if (check_duplicate(str) == -1)
		error = 1;
	else if (check_min_max_num(str) == -1)
		error = 1;
	else if (str[0] == NULL)
		error = 1;
	if (error == 1)
		write(2, "Error\n", 6);
	return (error);
}
