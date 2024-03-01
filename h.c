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
void sort_a(t_list **stac_b,t_list **stac_a,t_data *data)
{
   t_list *walo;
   walo = *stac_a;
   while (walo)
   {
        if(wach_kbir(stac_a,walo->content) == 1)
        {
            data->i = chehal(stac_a,walo->content);
            data->x =  pos_of_nb(stac_a,walo->content);
            if(data->x == 0)
            {
                pb(stac_a,stac_b);
                printf("pa\n");
            }
            else if(data->x > ft_lstsize(*stac_a) / 2)
            {
                while(data->i > 0)
                {
                    rra(stac_a);
                    printf("rrb\n");
                    data->i--;
                }
                pb(stac_a,stac_b);
                printf("pa\n");
            } 
            else
            {
                while(data->x > 0)
                {
                    ra(stac_a);
                    printf("rb\n");
                    data->x--;
                }
                pb(stac_a,stac_b);
                printf("pa\n");
            }
            walo = *stac_a;
        }
        else
            walo = walo->next;
   }
   free_stac(&walo);
}
