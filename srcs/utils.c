/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:43 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/16 14:17:43 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **splited)
{
	size_t	i;

	if (!splited)
		return ;
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

long long int	ft_atol(char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*strj;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	strj = (char *)malloc(sizeof(char) * len);
	if (!strj)
		return (NULL);
	while (str1[i])
	{
		strj[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		strj[i + j] = str2[j];
		j++;
	}
	strj[i + j] = '\0';
	return (strj);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}
