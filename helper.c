/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:35 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/13 12:54:12 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

int ft_len(char *str)
{
    int i;
    
    i = 0;
      while (str[i] != '\0')
        i++;
    return (i);
}

int ft_longest_digit(char **numbers, int size)
{
   int  i;
   int  temp;
   
   i = 1;
   temp = ft_len(numbers[1]);
   while (i < size + 1)
   {
    if (ft_len(numbers[i]) > temp)
       {
            temp = ft_len(numbers[i]);
            if (numbers[i][0] == '-')
                temp -= 1;
       }
    i++;
   } 
   return (temp);
}

void    ft_print(int *stak, int size)
{
   int  i;
   
   i = 0;
   while (i < size)
    {
        ft_printf("%d\n", stak[i]);
        i++;
    } 
}