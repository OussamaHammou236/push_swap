#include "push_swap.h"

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
                 printf("pb\n");
            }
            else if(data->x > ft_lstsize(*stac_a) / 2)
            {
                while(data->i > 0)
                {
                    rra(stac_a);
                    printf("rra\n");
                    data->i--;
                }
                pb(stac_a,stac_b);
                printf("pb\n");
            } 
            else
            {
                while(data->x > 0)
                {
                    ra(stac_a);
                    printf("ra\n");
                    data->x--;
                }
                pb(stac_a,stac_b);
                printf("pb\n");
            }
            walo = *stac_a;
        }
        else
            walo = walo->next;
   }
   free_stac(&walo);
}