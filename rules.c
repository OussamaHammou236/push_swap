/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:03:22 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/04 15:39:53 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stac_a,int i)
{
    if(i == 1)
        write(1,"sa\n",3);
    if(ft_lstsize(*stac_a) <= 1)  
        return ;
    void *tmp;
    tmp = (*stac_a)->next->next;
    (*stac_a)->prev = (*stac_a)->next;
    (*stac_a)->next->next = (*stac_a);
    (*stac_a)->next->prev = NULL;
    (*stac_a)->next = tmp;
    (*stac_a) = (*stac_a)->prev;
    if((*stac_a)->next->next)
        (*stac_a)->next->next->prev = (*stac_a)->next;
}

void sb(t_list **stac_a,int i)
{
    if(i == 1)
        write(1,"sb\n",3);
    if(ft_lstsize(*stac_a) <= 1)  
        return ;
    void *tmp;
    tmp = (*stac_a)->next->next;
    (*stac_a)->prev = (*stac_a)->next;
    (*stac_a)->next->next = (*stac_a);
    (*stac_a)->next->prev = NULL;
    (*stac_a)->next = tmp;
    (*stac_a) = (*stac_a)->prev;
    if((*stac_a)->next->next)
        (*stac_a)->next->next->prev = (*stac_a)->next;
}

void pa(t_list **stac_a,t_list **stac_b,int i)
{
    t_list *new_node;

    if(i == 1)
        write(1,"pa\n",3);
    if(!*stac_b)
        return ;
    new_node = ft_lstnew((*stac_b)->content);
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

void pb(t_list **stac_a,t_list **stac_b,int i)
{
    t_list *new_node;
    
    if(i == 1)
        write(1,"pb\n",3);
    if(!*stac_a)
        return ;
    new_node = ft_lstnew((*stac_a)->content);
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

void ra(t_list **stac_a,int i)
{
    t_list *new_node;
    
    if(i == 1)
        write(1,"ra\n",3);
    if(ft_lstsize(*stac_a) <= 1)
        return ;
    new_node = ft_lstnew((*stac_a)->content);
    ft_lstadd_back(stac_a,new_node);
    (*stac_a) = (*stac_a)->next;
    free((*stac_a)->prev);
    (*stac_a)->prev = NULL;
}
void rb(t_list **stac_b,int i)
{
    t_list *new_node;
    
    if(i == 1)
        write(1,"rb\n",3);
    if(ft_lstsize(*stac_b) <= 1) 
        return ;
    new_node = ft_lstnew((*stac_b)->content);
    ft_lstadd_back(stac_b,new_node);
    (*stac_b) = (*stac_b)->next;
    free((*stac_b)->prev);
    (*stac_b)->prev = NULL;
}
void rra(t_list **stac_a,int i)
{
    t_list *new_node;
    void *tmp;
    if(i == 1)
        write(1,"rra\n",4);
    if(ft_lstsize(*stac_a) <= 1) 
        return ;
    new_node = ft_lstnew(ft_lstlast(*stac_a)->content);
    tmp = ft_lstlast(*stac_a);
    ft_lstlast(*stac_a)->prev->next = NULL;
    ft_lstadd_front(stac_a,new_node);
    (*stac_a)->next->prev = *stac_a;
    free(tmp);
}

void rrb(t_list **stac_b,int i)
{
    t_list *new_node;
    void *tmp;

    if(i == 1)
        write(1,"rrb\n",4);
    if(ft_lstsize(*stac_b) <= 1) 
        return ;
    new_node = ft_lstnew(ft_lstlast(*stac_b)->content);
    ft_lstadd_front(stac_b,new_node);
    (*stac_b)->next->prev = *stac_b;
    tmp = ft_lstlast(*stac_b);
    ft_lstlast(*stac_b)->prev->next = NULL;
    free(tmp);
}
void rrr(t_list **stac_a,t_list **stac_b,int i)
{
    if(i == 1)
        write(1,"rrr\n",4);
    rra(stac_a,0);
    rrb(stac_b,0);
}
void rr(t_list **stac_a,t_list **stac_b,int i)
{
    if(i == 1)
        write(1,"rr\n",3);
    ra(stac_a,0);
    rb(stac_b,0);
}
void ss(t_list **stac_a,t_list **stac_b,int i)
{
    if(i == 1)
        write(1,"ss\n",3);
    sa(stac_a,0);
    sb(stac_b,0);
}