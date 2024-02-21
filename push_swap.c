/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/21 13:20:31 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int check_sort_b(t_list **stac_b,void *tmp)
{
    // void *tmp;
    // tmp = (*stac_b);
    while ((*stac_b)->next)
    {
        if((*stac_b)->content > (*stac_b)->next->content)
        {
            (*stac_b) = tmp;
            return 0;
        }
        (*stac_b)=(*stac_b)->next;
    }
    (*stac_b) = tmp;
    return 1;
    
}
int chehal(t_list **stac_a,int nb)
{
    int i;
    void *tmp;
    tmp = *stac_a;
    i = 0;
    while(*stac_a)
    {
        if((*stac_a)->content == nb)
            break;
        *stac_a = (*stac_a)->next;
    }
    while (*stac_a)
    {
        i++;
        *stac_a = (*stac_a)->next;
    }
    *stac_a = tmp;
    return i; 
}
int whach_sghir(t_list **stac_a,int nb)
{
    void *tmp;
    int i;
    tmp = *stac_a;
    i   =   0;
    
    
    while((*stac_a))
    {
        if(nb <= (*stac_a)->content)
            i++;
        (*stac_a) = (*stac_a)->next;
    }
    *stac_a = tmp;
    if(ft_lstsize(*stac_a) == i)
        return 1;
    return 0;
}
void sort_b(t_list **stac_b,t_list **stac_a,char **av)
{
   t_list *walo;
   walo = *stac_a;
   int i;
   int j;
   while (walo)
   {
        if(whach_sghir(stac_a,walo->content) == 1)
        {
            i = chehal(stac_a,walo->content);
            j = ft_lstsize(*stac_a) - i;
            if(i >= ft_lstsize(*stac_a))
            {
                while(i > 0)
                {
                rra(stac_a);
                printf("rra\n");
                i--;
                }
            }
            else
            {
                while( j > 0)
                {
                    ra(stac_a);
                    printf("ra\n");
                    j--;
                }
            }
            pb(stac_a,stac_b);
            printf("pb\n");
            walo = *stac_a;
        }
        else
            walo = walo->next;
   }
   free_stac(&walo);
}
int main(int ac,char **av)
{
    t_list *stac_a;
    t_list *stac_b;
    void *a;
    stac_b = NULL;
    ft_check(av);
    stac_a = list(av);
    sort_b(&stac_b,&stac_a,av);
    // printf("------------stac_b----------\n"); 
    //  print_stac(stac_b);
    // printf("------------stac_a----------\n");
    print_stac(stac_a);

    return 0;
}