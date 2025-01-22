/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:33:59 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:59:53 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../includes/get_next_line.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

/*------------------------ utils -----------------------------*/

size_t			ft_strlen(char *str);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(char *str);
int				ft_strcmp(char *str1, char *str2);
long long int	ft_atol(char *str);
int				list_size(t_list *node);
char			**ft_split(char *s, char c);

/*----------------------- parsing ---------------------------*/

int				check_digit(char **str);
int				check_duplicate(char **str);
int				check_min_max_num(char **str);
int				ft_errors(char **str);

/*------------------ initialize stack ------------------*/

char			**init_stack(char **argv);
t_list			*a(char **str);
t_list			*b(void);
int				sorted(t_list *stack);
void			init_index(t_data *stack, t_list *first, t_list *min);
void			indexation(t_data *stack);
void			free_stack(t_list *stack);
void			free_split(char **splited);

/*--------------------- operators -------------------------*/

void			sa(t_data *stack);
void			sb(t_data *stack);
void			ss(t_data *stack_a, t_data *stack_b);
void			rr(t_data *stack_a, t_data *stack_b);
void			ra(t_data *stack);
void			rb(t_data *stack);
void			rra(t_data *stack);
void			rrb(t_data *stack);
void			rrr(t_data *stack_a, t_data *stack_b);
void			pa(t_data *stack);
void			pb(t_data *stack);

/*--------------------- algorithm ------------------------*/
/*----------- mix quick sort/merge sort --------------*/

/*-------------------- small sorts ----------------------*/

void			sort_by_3(t_data *stack);
void			sorting3(t_data *stack, t_list *node);
void			sort_by_4(t_data *stack, int n);
void			sorting4(t_data *stack, t_list *node);
void			sort_by_5(t_data *stack);

/*--------------------- big sorts ------------------------*/

int				count_nb_steps(int size);
int				median_stack_b(t_data *stack);
int				max_of_b(t_data *stack);
void			push_a2b(t_data *stack);
void			push_b2a(t_data *stack);
void			push_max_elements(int i, int size, t_data *stack, t_list *b);
void			main_sort(t_data *stack);

#endif
