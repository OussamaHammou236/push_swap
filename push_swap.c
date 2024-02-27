/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/27 18:03:57 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int pos_of_nb(t_list **stac_a,int nb)
{
    int i;
    void *tmp;
    tmp = *stac_a;
    i = 0;
    while(*stac_a)
    {
        if((*stac_a)->content == nb)
            break;
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
void copy_stac_to_arry(t_list *copy,t_data *data)
{
   data->lst_size = ft_lstsize(copy);
   data->size = data->lst_size;
   data->sort = malloc(data->lst_size * sizeof(int));
   int i;
   i = data->lst_size;
   i--;
   while(i >= 0)
   {
        data->sort[i] = copy->content;
        copy = copy->next;
        i--;
   }

}
void sort_b(t_list **stac_b,t_list **stac_a,t_data *data)
{
   t_list *walo;
   walo = *stac_a;

   while (walo)
   {
        if(whach_sghir(stac_a,walo->content) == 1)
        {
            data->i = chehal(stac_a,walo->content);
            data->x =  pos_of_nb(stac_a,walo->content);
            if(data->x == 0)
                 pb(stac_a,stac_b);
            else if(data->x > ft_lstsize(*stac_a) / 2)
            {
                while(data->i > 0)
                {
                    rra(stac_a);
                    data->i--;
                }
                pb(stac_a,stac_b);
            } 
            else
            {
                while(data->x > 0)
                {
                    ra(stac_a);
                    data->x--;
                }
                pb(stac_a,stac_b);
            }
            walo = *stac_a;
        }
        else
            walo = walo->next;
   }
   copy_stac_to_arry(*stac_b,data);
   free_stac(&walo);
}
int wach_kayn(t_data *data,t_list **stac_a)
{
    int start;
    start = data->start;

    while(start < data->end)
    {
        if(check_repeat_nb(*stac_a,data->sort[start]) == 1)
            return 1;
        start++;
    }
    return 0;
}
int j(t_data *data,t_list **stac_a)
{
    int start;
    start = data->start; 
    while(start < data->end)
    {
        if((*stac_a)->content == data->sort[start])
            return 1;
        start++;
    }
    return 0;
}
void ra_or_rra(t_data *data,t_list **stac_b)
{
    int i;
    int j;

    i = pos_of_nb(stac_b,data->sort[data->end]);
    if(i <= ft_lstsize(*stac_b) / 2)
    {
            ra(stac_b);
            printf("rb\n");
    }
    else
    {
        rra(stac_b);
        printf("rrb\n");
    }
}
void algo(t_data *data,t_list **stac_a, t_list **stac_b)
{
    data->offset =  data->ac / 11;
    data->mid = (data->size / 2) - 1;
    data->start = data->mid - data->offset;
    data->end  = data->mid + data->offset;
    t_list *d;
    d = *stac_a;
    while(*stac_a)
    {
        if(j(data,stac_a) == 1)
        {
            pb(stac_a,stac_b);
            printf("pb\n");
        }
        else
        {
            if(wach_kayn(data,stac_a) == 1)
            {
                 if(pos_of_nb(stac_a,(*stac_a)->content) >= ft_lstsize(*stac_a) / 2)
                 {
                     rra(stac_a);
                     printf("rra\n");
                }
                else
                {
                     ra(stac_a);
                     printf("ra\n");
                }
            }
            else
            {
                if(data->start - data->offset >= 0)
                   data->start -= data->offset;
                else
                    data->start--;
                if(data->end + data->offset < data->lst_size)
                    data->end += data->offset;
                else
                    data->end++;
                if(data->start < 0)
                    data->start = 0;
                if(data->end > data->lst_size)
                    data->end = data->lst_size;
            }
        }
        
    }
    
}
void stac_a_to_b(t_data *data,t_list **stac_a, t_list **stac_b)
{
    int i;
    int nb;
    i = 0;
    data->end--;
    while(*stac_b)
    {
        if((*stac_b)->content == data->sort[data->end])
        {
           pa(stac_a,stac_b);
           printf("pa\n");
           data->end--;
        }
        else
        {
            if(i == 0)
            {
               nb = (*stac_a)->content;
               pa(stac_a,stac_b);
               printf("pa\n");
               ra(stac_a);
               printf("ra\n");
               i = 1;
            }
            else if(check_repeat_nb(*stac_b,data->sort[data->end]) == 0 && i == 1)
            { 
                if (ft_lstlast(*stac_a)->content == nb)
                    i = 0;
                rra(stac_a);
                data->end--;
                printf("rra\n");
            }
            else if((*stac_b)->content > ft_lstlast(*stac_a)->content && i == 1)
            {
               pa(stac_a,stac_b);
               printf("pa\n");
               ra(stac_a);
               printf("ra\n");
            }
            else
               ra_or_rra(data,stac_b);
        }
    }
    // i = 0;
    // while (i <= 23)
    // {
    //     rra(stac_a);
    //     printf("rra\n");
    //     i++;
    // }
    if(i == 1)
    {
        rra(stac_a);
        printf("rra\n");
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
    sort_b(&test,&test1,&data);
    algo(&data,&stac_a,&stac_b);
    stac_a_to_b(&data,&stac_a,&stac_b);
    free_stac(&test);
    free_stac(&test1);
    //printf("------------stac_b----------\n"); 
    //print_stac(stac_b);
    // printf("------------stac_a----------\n");
    // print_stac(stac_a);

    return 0;
}