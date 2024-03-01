/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/01 23:01:56 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pos(t_list **stac_a,t_data *data)
{
    int i;
    void *tmp;
    tmp = *stac_a;
    i = 0;
    while(*stac_a)
    {
        if((*stac_a)->content > data->sort[data->start] ||
            (*stac_a)->content <= data->sort[data->start])
            break;
        i++;
        *stac_a = (*stac_a)->next;
    }
    *stac_a = tmp;
    return i; 
}

int wach_kbir(t_list **stac_a,int nb)
{
    void *tmp;
    int i;
    tmp = *stac_a;
    i   =   0;
    
    
    while((*stac_a))
    {
        if(nb >= (*stac_a)->content)
            i++;
        (*stac_a) = (*stac_a)->next;
    }
    *stac_a = tmp;
    if(ft_lstsize(*stac_a) == i)
        return 1;
    return 0;
}
void copy_stac_to_arry(t_list **copy,t_data *data)
{
    void *tmp;
    int i;
    tmp = *copy;
    i = 0;
    data->lst_size = ft_lstsize(*copy);
    data->sort = malloc(data->lst_size * sizeof(int));
   
   while(i < data->lst_size)
   {
        data->sort[i] = (*copy)->content;
        (*copy) = (*copy)->next;
        i++;
   }
   *copy = tmp;
}

void ra_or_rra(t_data *data,t_list **stac_a,t_list **stac_b)
{
    int i;

  
    i = pos(stac_a,data);
    if(i <= ft_lstsize(*stac_a) / 2)
        ra(stac_a);
    else
        rra(stac_a);
}
void range(t_list **stac_a, t_data *data)
{
    int size;
    
    size = ft_lstsize(*stac_a);
    if(size  >= 6 && size  <= 16)
        data->range  =  3;
    else if(size  <= 100)
        data->range  = 13;
    else if(size  <= 500)
        data->range  = 30;
    else
        data->range  = 45;
}
void algo(t_data *data,t_list **stac_a, t_list **stac_b)
{
    range(stac_a,data);
    sort_arr(stac_a,data);
    data->start = 0;
    data->end = data->range;
    while(*stac_a)
    {
        if(data->end >= data->size_of_arr)
            data->end = data->size_of_arr - 1;
        if((*stac_a)->content > data->sort[data->start] &&  (*stac_a)->content <= data->sort[data->end])
        {
            pb(stac_a,stac_b);
            if(ft_lstsize(*stac_b) >= 2 && (*stac_b)->content < (*stac_b)->next->content)
                sb(stac_b);
            data->end++;
            data->start++;
        }
        else if((*stac_a)->content <= data->sort[data->start])
        {
            pb(stac_a,stac_b);
            rb(stac_b);
            data->end++;
            data->start++;
        }
        else
           ra_or_rra(data,stac_a,stac_b);
    }
}

int main(int ac,char **av)
{
    t_list *stac_a;
    t_list *test;
    t_list *stac_b;
    t_list *test1;
    t_data data;
    stac_b = NULL;
    test = NULL ;
    ft_check(av);
    stac_a = list(av);
    test1 =  list(av);
    data.ac = ac;
    algo(&data,&stac_a,&stac_b);
    sort_a(&stac_b,&stac_a,&data);
    free_stac(&test);
    free_stac(&test1);
    // printf("------------stac_b----------\n"); 
    // print_stac(stac_b);
    // printf("------------stac_a----------\n");
    // print_stac(stac_a);

    return 0;
}