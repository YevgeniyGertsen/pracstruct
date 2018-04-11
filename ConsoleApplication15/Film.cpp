#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include "Film.h"
#define len 5
int i, j;
void FDate()
{
	Film film[len];
	for ( i = 0; i < len; i++)
	{
		printf("Названия фильма:\n ");
		scanf("%s",film[i].NameFilm);

		printf("Жанр:\n ");
		scanf("%s", film[i].Janr);

		film[i].budjet = 1200 + rand() % 45000;
		printf("Бюджет составляет: %lf", film[i].budjet);

		film[i].start.h= 1 + rand() % 23;
		film[i].start.m= 10 + rand() % 59;
		printf("Начало сеанса---%d.%d", film[i].start.h, film[i].start.m);

		film[i].end.h = 1 + rand() % 23;
		film[i].end.m = 10 + rand() % 59;
		printf("завершение сеанса---%d.%d", film[i].end.h, film[i].end.m);

	}
}