#include "push_swap.h"

void sort_arr(t_list **stac_a,t_data *data)
{
    int i;
    int j;
    int c;
    i    =   0;
    data->size_of_arr = ft_lstsize(*stac_a);
    copy_stac_to_arry(stac_a,data);
    while(i < data->size_of_arr)
    {
        j = i + 1;
        while(j < data->size_of_arr)
        {
            if(data->sort[i] > data->sort[j])
            {
                c = data->sort[i];
                data->sort[i] = data->sort[j];
                data->sort[j] = c;
            }
            j++;
        }
        i++;
    }
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
void lkmala(t_list **stac_b,t_list **stac_a,t_data *data,int c)
{
    if(c == 0)
    {
        while(data->i > 0)
        {
            rrb(stac_b);
            data->i--;
        }
        pa(stac_a,stac_b);
    }
    else
    {
        while(data->x > 0)
        {
            rb(stac_b);
            data->x--;
        }
        pa(stac_a,stac_b);
    }
}
void sort_a(t_list **stac_b,t_list **stac_a,t_data *data)
{
   t_list *walo;
   walo = *stac_b;
   while (walo)
   {
        if(wach_kbir(stac_b,walo->content) == 1)
        {
            data->i = chehal(stac_b,walo->content);
            data->x =  pos_of_nb(stac_b,walo->content);
            if(data->x == 0)
                pa(stac_a,stac_b);
            else if(data->x > ft_lstsize(*stac_b) / 2)
                lkmala(stac_b,stac_a,data,0); 
            else
                lkmala(stac_b,stac_a,data,1);
            walo = *stac_b;
        }
        else
             walo = walo->next;
   }
   free_stac(&walo);
}
