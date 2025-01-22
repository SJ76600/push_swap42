/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:53:27 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:34 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h" 
# include "../includes/get_next_line.h"

/*--------------------- checker ---------------------------*/

int				valid_instruct(char *str, t_data *stack);
int				read_instructs(t_data *stack);
void			ft_free(t_data *stack);
int				main(int argc, char **argv);

/*------------------- checker utils ---------------------*/

int				push_bonus(t_data *stack, char *str);
int				swap_bonus(t_data *stack, char *str);
int				rotate_bonus(t_data *stack, char *str);
int				reverse_bonus(t_data *stack, char *str);
int				print_error(void);

/*----------------- checker operators -----------------*/

void			sa_bonus(t_data *stack);
void			sb_bonus(t_data *stack);
void			ss_bonus(t_data *stack_a, t_data *stack_b);
void			rr_bonus(t_data *stack_a, t_data *stack_b);
void			ra_bonus(t_data *stack);
void			rb_bonus(t_data *stack);
void			rra_bonus(t_data *stack);
void			rrb_bonus(t_data *stack);
void			rrr_bonus(t_data *stack_a, t_data *stack_b);
void			pa_bonus(t_data *stack);
void			pb_bonus(t_data *stack);

#endif
