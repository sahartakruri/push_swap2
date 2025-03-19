/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:04:17 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/17 12:05:08 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int ft_cton(char *stak)
{
    int i;
    int number;
    int sign;
    
    sign = 1;
    number = 0;
    i = 0;
    if (stak[0] == '-')
    {
        sign = sign * -1;
        i++;
    }
    while (stak[i] != '\0')
    {
        number = (number * 10) + (stak[i] - '0');
        i++;
    }
    return (number * sign);
    
}
int    ft_double_check(int *stak_a, int size_a)
{
    int i;
    int k;
    
    i = 0;
    while (i < size_a)
    {
        k = i + 1;
        while(k < size_a)
        {
            if (stak_a[i] == stak_a[k])
                return (1);
            k++;
        }
        i++;
    }
    return (0);
}

void    ft_arrange(int *stak_a, int *size_a, int *stak_b, int *size_b, int r)
{
     int    i;
     int    k;
     
     k = 0;
        while (k < 10)
        {
            i = 0;
            while (i < *size_a)
            {
                if ((stak_a[0] / r) % 10 == k || stak_a[0]< 0)
                    {
                        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                        i--;
                    }
                else
                    ft_rotate_a(stak_a, *size_a);
                i++;      
            }
            k++;
        }
        i = 0;
        while (i++ < *size_b + *size_a)
            ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
}
void    ft_arrange_n(int *stak_a, int *size_a, int *stak_b, int *size_b, int r)
{
     int    i;
     int    k;
     
     k = 0;
        while (k < 10)
        {
            i = 0;
            while (i < *size_a)
            {
                if (stak_a[0] < 0)
                {
                    if (((stak_a[0] * -1)/ r)% 10 == (-k / r) % 10)
                    {
                        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                        i--;
                    }
                    else
                    ft_rotate_a(stak_a, *size_a);
                }
                else
                {
                    ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                    i--;
                }
                i++;      
            }
            k++;
        }
        i = 0;
        while (i < *size_b)
        {
            ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
        }
}

int ft_neg_no(int *stak_a, int  size_a)
{
    int i;
    int no;
    
    i = 0;
    no = 0;
    while (i < size_a)
    {
        if (stak_a[i] < 0)
            no++;
        i++;
    }
    return (no);
}
void    ft_flip_neg(int *stak_a, int *size_a, int *stak_b, int *size_b, int neg)
{
    int i;

    i = 0;
    while (i <neg)
    {
        ft_reverse_rotate_a(stak_a, *size_a);
        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
        i++;;
    }
    while (i)
    {
        ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
        i--;
    }
    //  printf("size_b = %d\n size_a= %d\n number of negative = %d\n stak_b[0]%d\n", *size_b, *size_a, neg, stak_b[0]);//
}

void    ft_stak_to_stak(int *stak_a, int *size_a, int *stak_b, int *size_b, int n)
{
    int m;
    int r;
    int neg;
    
    neg = ft_neg_no(stak_a, *size_a);
    m = n;
    r = 1;
    while (n)
    {
        ft_arrange(stak_a, size_a, stak_b, size_b, r);
        r *= 10;
        n--;
    }
    r = 1;
    while (m)
    {
        ft_arrange_n(stak_a, size_a, stak_b, size_b, r);
        r *= 10;
        m--;
    }
    if (neg > 0)
        ft_flip_neg(stak_a, size_a, stak_b, size_b, neg);
    // printf("size_b = %d\n size_a= %d\n number of negative = %d\n", *size_b, *size_a, neg);//
}


int main(int arc, char **argv)
{
    int stak_a[arc - 1];
    int stak_b[arc - 1];
    int size_a = arc -1;
    int size_b = 0;
    int n;
    int i = 1;
    n = ft_longest_digit(argv, size_a);
    // printf("n= %d\n", n);
    while (i < arc)
    {
        stak_a[i - 1] = ft_cton(argv[i]);
        i++;
    }
    if (ft_double_check(stak_a, size_a) == 1)
    {
        write (1, "error doubles found", 19);
        return (0);
    }
    ft_stak_to_stak(stak_a, &size_a, stak_b, &size_b, n);
    write(1, "stak a\n", 7);
    ft_print(stak_a, size_a);
    write(1, "stak b\n", 7);
    ft_print(stak_b, size_b);
    return (0);
}
