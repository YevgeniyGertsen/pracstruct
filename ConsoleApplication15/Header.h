
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
void clear();
void MainMenu(int *p);
void PrintInfo(student * st);
void WorkWithFolder(char *nameGroup, char *command, char *path);