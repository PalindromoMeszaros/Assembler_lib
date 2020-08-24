/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <pablomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:13:25 by pablomar          #+#    #+#             */
/*   Updated: 2020/08/18 11:56:19 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "ft_libasm.h"

#define GREEN   "\033[0;32m"
#define BGREEN  "\033[1;32m"
#define RED     "\033[1;31m"
#define CYAN    "\033[0;36m"
#define BCYAN   "\033[1;36m"
#define WHITE	"\033[0m"

void    check_ft_strlen(char *str)
{
    int		origin;
    int     ft;

    printf(GREEN);
    printf(" str = \"%s\"\n",str);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	printf("%d", (ft = ft_strlen(str)));
	printf("%s	ORIGINAL:   ", CYAN);
	printf(WHITE);
	printf("%d", (origin = (int)strlen(str)));
	if (ft == origin)
		printf("%s\t[OK]\n\n", GREEN);
	else
		printf("%s\t[KO]\n\n", RED);
}

void    check_ft_strcpy(char *dst,char *src)
{
    char	*a, *b, *c, *d;

	a = strdup(dst);
	b = strdup(dst);
	c = strdup(src);
	d = strdup(src);
    int i;

    printf(GREEN);
    printf(" dst = \"%s\"\n",dst);
    printf(" src = \"%s\"\n",src);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	printf("%s", ft_strcpy(a,c));
	printf("%s\tORIGINAL:   ", CYAN);
	printf(WHITE);
	printf("%s", strcpy(b,d));
    i = strcmp(a,b);
	if (i == 0)
		printf("\tcmp return value = %d %s\t[OK]\n\n",i,GREEN);
	else
		printf("\tcmp value = %d %s\t[KO]\n\n",i,RED);
}

void    check_ft_strcmp(char *s1, char *s2)
{
    int origin;
    int ft;

    printf(GREEN);
    printf(" s1 = \"%s\"\n",s1);
    printf(" s2 = \"%s\"\n",s2);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	printf("%d", ft = ft_strcmp(s1,s2));
	printf("%s\tORIGINAL:   ", CYAN);
	printf(WHITE);
	printf("%d", origin = strcmp(s1,s2));

	if ((s1 == 0 && s2 == 0) || (s1 > 0 && s2 > 0) || (s1 < 0 && s2 < 0))
		printf("\t%s\t[OK]\n\n",GREEN);
	else
		printf("\t%s\t[KO]\n\n",RED);
}

void    check_ft_write(int fd, void *buf, size_t nbyte)
{
    int origin_bytes;
    int ft_bytes;
    printf(GREEN);
    printf("fd = \"%d\" str = \"%s\" size = \"%zu\"\n",fd,buf,nbyte);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	fflush( stdout );
	ft_bytes = ft_write(fd,buf,nbyte);
	printf("\t%d",ft_bytes); 
	fflush( stdout );
	if (ft_bytes == -1)
    {
        fprintf(stderr, "\tft_errno: %d", errno);
        perror(" Error printed by perror");
    }
	printf("%s	ORIGINAL:   ", CYAN);
	printf(WHITE);
	fflush( stdout );
	origin_bytes = write(fd,buf,nbyte);
	printf("\t%d",origin_bytes);
	fflush( stdout );
	if (origin_bytes == -1)
    {
        fprintf(stderr, "\toriginal errno: %d", errno);
        perror(" Error printed by perror");
    }
	if (ft_bytes == origin_bytes)
		printf("%s\t[OK]", GREEN);
	else
		printf("%s\t[KO]", RED);
    printf("\n\n");   
}

void	check_ft_read(int fd, void *buf, size_t nbyte)
{
	int origin_bytes;
    int ft_bytes;
    printf(GREEN);
    printf("fd = \"%d\" size = \"%zu\"\n",fd,nbyte);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	fflush( stdout );
	ft_bytes = ft_read(fd,buf,nbyte);
	((char*)buf)[ft_bytes] = '\0';
	if (ft_bytes != -1)
		printf("\"%s\"",buf);
	printf("\t%d",ft_bytes); 
	fflush( stdout );
	if (ft_bytes == -1)
    {
        fprintf(stderr, "\tft_errno: %d", errno);
        perror(" Error printed by perror");
    }
	printf("%s\tORIGINAL:   ", CYAN);
	printf(WHITE);
	fflush( stdout );
	origin_bytes = read(fd,buf,nbyte);
	((char*)buf)[origin_bytes] = '\0';
	if (origin_bytes != -1)
		printf("\"%s\"",buf);
	printf("\t%d",origin_bytes);
	fflush( stdout );
	if (origin_bytes == -1)
    {
        fprintf(stderr, "\toriginal errno: %d", errno);
        perror(" Error printed by perror");
    }
	if (ft_bytes == origin_bytes)
		printf("%s\t[OK]", GREEN);
	else
		printf("%s\t[KO]", RED);
    printf("\n\n");   	
}

void	check_ft_strdup(char *str)
{
	char *ft;
	char *origin;
	int i;

	printf(GREEN);
    printf(" str = \"%s\"\n",str);
	printf("%s\tFT_LIBASM:  ", CYAN);
	printf(WHITE);
	printf("%s", ft = ft_strdup(str));
	printf("%s\tORIGINAL:   ", CYAN);
	printf(WHITE);
	printf("%s", origin = strdup(str));

	i = strcmp(ft,origin);
	if (i == 0)
		printf("\tcmp return value = %d %s\t[OK]\n\n",i,GREEN);
	else
		printf("\tcmp value = %d %s\t[KO]\n\n",i,RED);

	free(origin);
	free(ft);
}


int     main(void)
{
    printf("%s\n-------LIBASM TESTER-------\n\n",BCYAN);

    printf("%sFT_STRLEN:\n", RED);

	check_ft_strlen("");
	check_ft_strlen("42istheanswer");
	check_ft_strlen("H O L A");
	check_ft_strlen("\t\t");


    printf("%s\nFT_STRCPY:\n", RED);

    check_ft_strcpy("", "Marvin");
	check_ft_strcpy("Hello", "World!");
	check_ft_strcpy("MasLargoQueLaVida", "SmallWord");
	check_ft_strcpy("\t", "\a\a");


    printf("%s\nFT_STRCMP:\n", RED);

    check_ft_strcmp("Marvin", "Marvin");
	check_ft_strcmp("Hello", "HELLO");
	check_ft_strcmp("S P A ", "SPA");
    check_ft_strcmp("SPA ", "SPA");
	check_ft_strcmp("\t", "\a\a");
    check_ft_strcmp("", "");
    check_ft_strcmp("", " ");


    printf("%s\nFT_WRITE:\n", RED);

    check_ft_write(1,"Anaxagoras",10);
    check_ft_write(-1,"Platon",4);
	check_ft_write(1, "", 0);
	check_ft_write(1, NULL, 6);
	check_ft_write(12, "Socrates", 16);
	check_ft_write(1, "Aristoteles", 2);
	

	printf("%s\nFT_READ:\n", RED);

	int fd1 = open("text.txt", O_RDONLY);
	char buffer[50];
    check_ft_read(fd1,buffer,30);
	check_ft_read(-1,buffer,30);
	check_ft_read(14,buffer,30);
	//check_ft_read(0,buffer,30);
	close(fd1);


	printf("%s\nFT_STRDUP:\n", RED);

	check_ft_strdup("HOLA");
	check_ft_strdup("M\1\1M");
	check_ft_strdup("1 O  \\");
	check_ft_strdup("/\\\"2");

	return(0);
}