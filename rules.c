/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:03:22 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/27 18:44:02 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stac_a)
{
    if(ft_lstsize(*stac_a) <= 1)  
        return ;
    void *tmp;
    tmp = (*stac_a)->next->next;
    (*stac_a)->prev = (*stac_a)->next;
    (*stac_a)->next->next = (*stac_a);
    (*stac_a)->next->prev = NULL;
    (*stac_a)->next = tmp;
    (*stac_a) = (*stac_a)->prev;
    (*stac_a)->next->next->prev = (*stac_a)->next;
}

void sb(t_list **stac_b)
{
    if(ft_lstsize(*stac_b) <= 1)  
        return ;
    void *tmp;
    tmp = (*stac_b)->next->next;
    (*stac_b)->prev = (*stac_b)->next;
    (*stac_b)->next->next = (*stac_b);
    (*stac_b)->next->prev = NULL;
    (*stac_b)->next = tmp;
    (*stac_b) = (*stac_b)->prev;
    (*stac_b)->next->next->prev = (*stac_b)->next;
}

void pa(t_list **stac_a,t_list **stac_b)
{
    t_list *new_node;

    new_node = ft_lstnew((*stac_b)->content);
    if(!*stac_b)
        return ;
    if(ft_lstsize(*stac_b) == 1)
    {
        
        ft_lstadd_front(stac_a,new_node);
        (*stac_a)->next->prev = new_node;
        *stac_b = NULL;
        return ;
    }
    (*stac_b)->next->prev = NULL;
    (*stac_b) = (*stac_b)->next;
    ft_lstadd_front(stac_a,new_node);
    if((*stac_a)->next)
         (*stac_a)->next->prev = (*stac_a);
}
void free_stac(t_list **stac)
{
    if(!*stac)
        return ;
    while((*stac)->next)
    {
        (*stac) = (*stac)->next;
        free((*stac)->prev);
    }
    free(*stac);
    *stac = NULL;
}

void pb(t_list **stac_a,t_list **stac_b)
{
    t_list *new_node;
    
    new_node = ft_lstnew((*stac_a)->content);
    if(!*stac_a)
        return ;
    if(ft_lstsize(*stac_a) == 1)
    {
        ft_lstadd_front(stac_b,new_node);
        (*stac_b)->next->prev = new_node;
        *stac_a = NULL;
        return ;
    }
    (*stac_a)->next->prev = NULL;
    (*stac_a) = (*stac_a)->next;
    ft_lstadd_front(stac_b,new_node);
    if((*stac_b)->next)
        (*stac_b)->next->prev = (*stac_b);
}

void ra(t_list **stac_a)
{
    t_list *new_node;
    if(ft_lstsize(*stac_a) <= 1)
        return ;
    new_node = ft_lstnew((*stac_a)->content);
    ft_lstadd_back(stac_a,new_node);
    (*stac_a) = (*stac_a)->next;
    free((*stac_a)->prev);
    (*stac_a)->prev = NULL;
}
void rb(t_list **stac_b)
{
    t_list *new_node;
    
    new_node = ft_lstnew((*stac_b)->content);
    if(ft_lstsize(*stac_b) <= 1) 
        return ;
    ft_lstadd_back(stac_b,new_node);
    (*stac_b) = (*stac_b)->next;
    free((*stac_b)->prev);
    (*stac_b)->prev = NULL;
}
void rra(t_list **stac_a)
{
    t_list *new_node;
    void *tmp;

    if(ft_lstsize(*stac_a) <= 1) 
        return ;
    new_node = ft_lstnew(ft_lstlast(*stac_a)->content);
    tmp = ft_lstlast(*stac_a);
    ft_lstlast(*stac_a)->prev->next = NULL;
    ft_lstadd_front(stac_a,new_node);
    (*stac_a)->next->prev = *stac_a;
    free(tmp);
}

void rrb(t_list **stac_b)
{
    t_list *new_node;
    void *tmp;

    if(ft_lstsize(*stac_b) <= 1) 
        return ;
    new_node = ft_lstnew(ft_lstlast(*stac_b)->content);
    ft_lstadd_front(stac_b,new_node);
    (*stac_b)->next->prev = *stac_b;
    tmp = ft_lstlast(*stac_b);
    ft_lstlast(*stac_b)->prev->next = NULL;
    free(tmp);
}
void rrr(t_list **stac_a,t_list **stac_b)
{
    rra(stac_a);
    rrb(stac_b);
}
void rr(t_list **stac_a,t_list **stac_b)
{
    ra(stac_a);
    rb(stac_b);
}
void ss(t_list **stac_a,t_list **stac_b)
{
    sa(stac_a);
    sb(stac_b);
}