#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>





int ft_strlen(char *str)
{
    int i;

    while(str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strcat(char *str, char c)
{
    
	int i;
	char *new;

	i = 0;
	if(!str)
		new = malloc(sizeof(char) * 2);
	else
	{
		new = malloc(sizeof(char) * (ft_strlen(str) + 2));
		while(str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = c;
	new[i + 1] = 0;
	free(str);
	return (new);
}


void printstr(char c)
{


	static char *chaine;

	if(c == 0)
	{
		printf("%s\n", chaine);
        free(chaine);
		chaine = NULL;
	}
	else
		chaine = ft_strcat(chaine, c);

    
}

void converter(char *str)
{
    static int i;
    char c;
   
    while(str[i])
    {
        if(str[i] == '1')
        {
            c = c * 2 + 1;
            i++; 
        }
        else if(str[i] == '0')
        {
            c = c * 2;
            i++;
        }
    }
    i = 0;
    printstr(c);
    
}

void user1(int ref)
{
    static int i;
    static char str[8];

    if(i < 8)
    {
        
        if(ref == SIGUSR1)
        {
            str[i] = '1';
            i++;
        }
        else if(ref == SIGUSR2)
        {
            str[i] = '0';
            i++;
        }
       
    }
    if(i == 8)
        {
            
            i = 0;
            converter(str);
        }   
}
int main()
{
    signal(SIGUSR1, user1);
    signal(SIGUSR2, user1);
    printf("%d\n", getpid());
    
    while (1)
    {
        pause();
    }
    return 0;
}