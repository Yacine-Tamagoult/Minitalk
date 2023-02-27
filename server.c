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


void printstr(char c,int count)
{
{
	static char *chaine;

	if(c == 0)
	{
		printf("%s\n", chaine);
		chaine = NULL;
	}
	else
		chaine = ft_strcat(chaine, c);
}
    
}

void user1(int ref)
{
    static int i;
    static int count;
    static char c;

    if(i < 8)
    {
        c = c << 1;
        if(ref == 10)
        {
            c = c + 1;
            i++;
        }
        else if(ref == 12)
        {
            i++;
        }
       
    }

    if(i == 8)
        {
            i = 0;
            count++;        
            printstr(c,count);
            c = 0;
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