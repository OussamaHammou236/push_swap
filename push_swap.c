/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/16 19:48:49 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int check_sort_b(t_list **stac_b)
{
    void *tmp;
    tmp = (*stac_b);
    while ((*stac_b)->next)
    {
        if((*stac_b)->content < (*stac_b)->next->content)
        {
            (*stac_b) = tmp;
            return 0;
        }
        (*stac_b)=(*stac_b)->next;
    }
    (*stac_b) = tmp;
    return 1;
    
}
int chehal(t_list **stac_b)
{
    int i;
    void *tmp;
    
    tmp = *stac_b;
    i   =   0;
    while ((*stac_b)->next)
    {
        i++;
        *stac_b = (*stac_b)->next;
    }
    *stac_b = tmp;
    return i; 
}

void sort_b(t_list **stac_b,t_list **stac_a)
{
    void *tmp;
    void *s;
    int i;
    tmp = (*stac_b);
    while(*stac_b)
    {
        
        if(check_sort_b(stac_b) == 1)
        {
             (*stac_b) = tmp; 
             return ;
        }
        if((*stac_b)->next->content > (*stac_b)->content  && (*stac_b)->prev != NULL)
        {
            printf("1\n");
            (*stac_b) = tmp; 
            i = chehal(stac_b);
            while(i > 0)
                rra(stac_b);
            sa(stac_b);
            tmp =(*stac_b);
        }
        *stac_b = (*stac_b)->next;
    }
    (*stac_b) = tmp;
    while(*stac_b)
    {
        if(check_sort_b(stac_b) == 1)
             return ;
        else if((*stac_b)->next->content > (*stac_b)->content)
                 sb(stac_b);
        else
            rra(stac_b);
    }
}
int main(int ac,char **av)
{
    t_list *stac_a;
    t_list *stac_b;
    void *a;
    stac_b = NULL;
    ft_check(av);
    stac_a = list(av);
    while(stac_a->next->next)
         pb(&stac_a,&stac_b);
    sort_b(&stac_b,&stac_b);
    printf("------------stac_b----------\n");
    print_stac(stac_b);
    printf("------------stac_a----------\n");
    print_stac(stac_a);
    
    
    return 0;
}