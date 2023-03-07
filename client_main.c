/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:38:43 by soleil            #+#    #+#             */
/*   Updated: 2023/03/07 17:48:49 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void swap(char *str)
{
    int i;
    int j;
    int a;
    char k;

    i = 0;
    j = ft_strlen(str) - 1;
    a = ft_strlen(str) / 2;
    
    while(i != a)
    {
        k = str[i];
        str[i] = str[j];
        str[j] = k;
        i++;
        j--;
    }
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while(str[i])
    {
        i++;
    }
    return (i);
}


int main(int ac, char **av)
{

     struct sigaction ba = {0};
    ba.sa_handler = test;
    
    sigaction(SIGUSR1, &ba, NULL); 
    
    
    if(ac > 2)
    {
        master(atoi(av[1]),av[2]);
        
        return (0);
    }
    else if(ac < 3)
    {
        ft_printf("Error");
        return 0;
    }
    return (0);
}