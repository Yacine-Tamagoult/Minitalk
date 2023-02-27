#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

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

char *calcul(int c)
{
    int num;
    int i;
    char *tab;

    tab = malloc(sizeof(char) * 8);
    i = 0;
    num = c;
    while(num != 0)
    {
        
        tab[i] = num % 2 + '0';
        num = num / 2;
        i++;
    }

    if(c <= 63)
    {
        tab[i] = '0';
        i++;
    }
    if(c == 0)
    {
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        tab[i] = '0';
        i++;
        return(tab);
    }
    tab[i] = '0';
    i++;
    tab[i] = '\0';
    swap(tab);
    return (tab);
}

void send(int code,char *str)
{
    int i;

    i = 0;


    while(str[i])
    {
        if (str[i] == '1')
        {
            kill(code, SIGUSR1);
            usleep(1);
        }
        else if (str[i] == '0')
        {
            kill(code, SIGUSR2);
            usleep(1);
        }
        i++;
    }
}

void master(int code,char *str)
{
    int i;
    char fin[2];
    int j;

    j = 0;
    i = 0;
    
    while(str[i])
    {
        send(code,calcul(str[i]));
        i++;
    
        if(str[i] == '\0')
        {
            send(code,calcul(j));
        }
    }
}

int main(int ac, char **av)
{
    if(ac > 2)
    {
        master(atoi(av[1]),av[2]);
        //printf("Le message a bien été envoyer :)\n");
        return (0);
    }
    else if(ac < 3)
    {
        printf("Error");
        return 0;
    }
    return (0);
}