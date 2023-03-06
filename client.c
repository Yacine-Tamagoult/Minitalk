#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int controle = 0;

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
   
        while(str[i] && controle == 0)
        {
            //printf("controle est egqle q : %d\n",controle);
            if (str[i] == '1')
            {
                controle = 1;
                kill(code, SIGUSR1); 
                pause();  
            }
            else if (str[i] == '0')
            {
                controle = 1;
                kill(code, SIGUSR2);
                pause();
                
            }
            
             i++;
        }
}

void master(int code,char *str)
{
    int i;
    int j;

    j = 0;
    i = 0;
    //printf("controle est egqle q : %d\n",controle);
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


void test(int ref)
{
    //printf("azazaazazaz : %d\n",controle);
    if(ref == SIGUSR1)
    {
        controle = 0;

    }
        
}

int main(int ac, char **av)
{

     struct sigaction ba;
    ba.sa_handler = test;
    
    sigaction(SIGUSR1, &ba, NULL); 
    
    
    if(ac > 2)
    {
        master(atoi(av[1]),av[2]);
        
        return (0);
    }
    else if(ac < 3)
    {
        printf("Error");
        return 0;
    }
    return (0);
}