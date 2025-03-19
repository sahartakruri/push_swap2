/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:21:58 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/13 16:14:30 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int     ft_len(char *str);
int     ft_longest_digit(char **numbers, int size);
void    ft_swap_a(int *stak, int n);
void    ft_swap_b(int *stak_b, int size_b);
void    ft_push_a_to_b(int *stak_a, int *size_a, int *stak_b,int *size_b);
void    ft_push_b_to_a(int *stak_a, int *size_a, int *stak_b,int *size_b);
void    ft_rotate_a(int *stak_a, int size);
void    ft_rotate_b(int *stak_b, int size);
void    ft_reverse_rotate_a(int *stak_a, int size);
int     ft_cton(char *stak);
int     ft_double_check(int *stak_a, int size_a);
void    ft_stak_to_stak(int *stak_a, int *size_a, int *stak_b, int *size_b, int n);
void    ft_print(int *stak, int size);
int		ft_printf(const char *str, ...);

#endif