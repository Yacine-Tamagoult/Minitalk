#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "/home/soleil/Desktop/Minitalk/ft_printf/ft_printf.h"

int	ft_strlen(char *str);
char	*ft_strcat(char *str, char c);
void	printstr(char c);
void	converter(char *str);
void	user1(int ref, siginfo_t *siginfo, void *context);
void master(int code,char *str);
void send(int code,char *str);
char *calcul(int c);
void swap(char *str);
int ft_strlen(char *str);
void test(int ref);
char *zero(char *tab);


#endif