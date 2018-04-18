#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
struct dob
{
	int d;
	int m;
	int y;
};
struct student
{
	//Фамилия
	char fName[30];
	//Имя 
	char lName[30];
	//Отчество 
	char mName[30];
	//Год рождения 
	dob dateOfBirthday;
	//Пол
	int gender;
	//Массив оценок
	int rate[10];
};
void clear()
{
	system("cls");
}
void MainMenu(int *p)
{
	printf("0. Change group.\n");
	printf("1. Add record to file.\n");
	printf("2. Review of all records in file.\n");
	printf("3. Reports.\n");
	scanf("%d", p);
}
void PrintInfo(student * st)
{
	printf("%s %c. %c. (%d.%d.%d) - ",
		st->fName, st->mName, st->lName,
		st->dateOfBirthday.d, st->dateOfBirthday.m, st->dateOfBirthday.y);

	if (st->gender == 0)
		printf("Male.\n");
	else
		printf("Female.\n");
}
void WorkWithFolder(char *nameGroup, char *command, char *path)
{
	puts("-------------------------------------");
	printf("Введите название группы: ");
	scanf("%s", nameGroup);

	sprintf(command, "md %s\\%s", path, nameGroup);

	int result = system(command);

	sprintf(command, "%s\\%s", path, nameGroup);

	sprintf(path, "%s\\%s\\%s.txt", path, nameGroup, nameGroup);
	puts("-------------------------------------");
}