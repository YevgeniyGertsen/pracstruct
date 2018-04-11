#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include "Poezd.h"
#define len 5
int i, j;
void PoezdD()
{
	setlocale(LC_ALL, "rus");
	Poezd poezd[len];
	for ( i = 0; i < len; i++)
	{
	
		poezd[i].NomerPoezda = 1 + rand() % 10;
		printf("Номер поезда: %d\n", poezd[i].NomerPoezda);

		printf("Пункт отбытия:\n ");
		scanf("%s", poezd[i].PunctOtb);

		printf("Пункт прибыьтия:\n ");
		scanf("%s", poezd[i].PunctPrib);

		poezd[i].prib.h = 1 + rand() % 23;
		poezd[i].prib.m= 5 + rand() % 59;

		printf("Время прибытия поезда: %d.%d \n", poezd[i].prib.h, poezd[i].prib.m);

		poezd[i].otb.h= 1 + rand() % 23;
		poezd[i].otb.m = 5 + rand() % 59;

		printf("Время отбытия поезда: %d.%d  \n", poezd[i].otb.h, poezd[i].otb.m);



	}

}