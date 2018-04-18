#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"
FILE * fp;
struct  struct_type
{
	int id;
	float balance;
	char name[30];
};
void main()
{
	setlocale(LC_ALL, "RUS");

	student st;

	char command[100], nameGroup[100];
	char path[150] = "\\\\dc\\Студенты\\ПКО\\SEB-172.2\\Общее\\AllStudents";
	int p;

	WorkWithFolder(nameGroup, command, path);

	clear();
	MainMenu(&p);
	clear();

	if (p == 0)
	{
		WorkWithFolder(nameGroup, command, path);
		MainMenu(&p);
	}
	else if (p == 1)
	{
		printf("Enter info about student: \n");
		puts("-------------------------------------");
		if ((fp = fopen(path, "a+")) != NULL)
		{
			printf("Enter first name: ");
			scanf("%s", st.fName);

			printf("Enter second name: ");
			scanf("%s", st.mName);

			printf("Enter last name: ");
			scanf("%s", st.lName);

			printf("Enter date of your birth(day.month.year): ");
			scanf("%d.%d.%d", &st.dateOfBirthday.d, &st.dateOfBirthday.m, &st.dateOfBirthday.y);

			printf("Enter your gender(0-male|1-female): ");
			scanf("%d", &st.gender);

			for (short int i = 0; i < 10; i++)
				st.rate[i] = 1 + rand() % 5;


			fwrite(&st, sizeof(student), 1, fp);

			clear();
			printf("Data had been saved successfully.\n");
			MainMenu(&p);
		}
		else
			printf("Database no access!\n");

		puts("-------------------------------------");
		fclose(fp);
	}
	else if (p == 2)
	{
		puts("-------------------------------------");
		printf("Info about student in group %s: \n", nameGroup);
		puts("-------------------------------------");

		if ((fp = fopen(path, "r")) != NULL)
		{
			while (fread(&st, sizeof(student), 1, fp))
				PrintInfo(&st);

			fclose(fp);
		}
		puts("-------------------------------------");
		MainMenu(&p);
		puts("-------------------------------------");
	}
	else if (p == 3)
	{
		clear();
		printf("1. Eldest student(male).\n");
		printf("2. Youngest student(male).\n");
		scanf("%d", &p);
		if (p == 1)
		{
			if ((fp = fopen(path, "r")) != NULL)
			{
				student * students;
				students = (student*)calloc(1, sizeof(student));
				int i = 0;

				while (fread((students + i), sizeof(student), 1, fp))
				{
					PrintInfo((students + i));
					i++;
					students = (student*)realloc(students, sizeof(student)*(i + 1));
				};

				student *eldest = students;
				student *youngest = students;

				for (int s = 0; s < i; s++)
				{
					if ((students + i)->dateOfBirthday.y < eldest->dateOfBirthday.y)
						eldest = students + i;
					else if ((students + i)->dateOfBirthday.y > youngest->dateOfBirthday.y)
						youngest = students + i;
				}

				puts("Most eldest: ");
				PrintInfo(eldest);

				puts("Most youngest: ");
				PrintInfo(youngest);

				/**/

				
			}
		}
		/*printf("3. Eldest student(female).\n");
		printf("4. Youngest student(female).\n");*/

	}
	return;

	//printf("Result = %d\n", result);
	puts("-------------------------------------");


	/*if ((fp = fopen("//dc/Студенты/ПКО/SEB-172.2/Общее/students.txt", "w")) != NULL)
	{
		student st;
		sprintf(st.fName, "%s", "Yevgeniy");
		sprintf(st.lName, "%s", "Gertsen");
		sprintf(st.mName, "%s", "Alexandrovich");

		st.dateOfBirthday.d = 11;
		st.dateOfBirthday.m = 1;
		st.dateOfBirthday.y = 1988;

		st.gender = 0;
		for (int i = 0; i < 10; i++)
			st.rate[i] = 1+rand()%6;

		fwrite(&st, sizeof(student), 1, fp);

		fclose(fp);
	}*/

	if ((fp = fopen("//dc/Студенты/ПКО/SEB-172.2/Общее/students.txt", "r")) != NULL)
	{
		while (fread(&st, sizeof(student), 1, fp))
		{
			printf("#%s %c.%c. (%d.%d.%d)\n",
				st.fName, st.lName[0], st.mName[0],
				st.dateOfBirthday.d, st.dateOfBirthday.m, st.dateOfBirthday.y);

			/*puts("Оценки студента:");
			for (int i = 0; i < 10; i++)
			{
				printf(" -> %d\n", st.rate[i]);
			}*/

		};
	}
}


int main3(int argc, char *argv[])
{
	char ch;
	if (argc != 2)
	{
		printf("Vi zabili vvesti imya faila!\n");
		exit(1);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Oshibka otkritiya faila\n");
		exit(1);
	}

	ch = getc(fp);//чтение 1-го символа

	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);

	return 0;
}

void main2()
{
	srand(time(NULL));

	const int layer1 = 5;
	const int layer2 = 20;
	const int outfiles = 100;

	char buffer[100];
	int i = 0;

	for (; i < layer1; i++)
	{
		int j = 0;
		for (; j < layer2; j++)
		{
			sprintf(buffer, "md folder%d\\val%d", i, j);
			system(buffer);

			int k = 0;
			for (; k < outfiles; k++)
			{
				sprintf(buffer, "folder%d/val%d/ficher%d.xml", i, j, k);
				if ((fp = fopen(buffer, "w")) != NULL)
				{
					fprintf(fp, "<xml>\n <i>%d</i></xml>", i);
					fclose(fp);
				}
			}
		}
	}

}