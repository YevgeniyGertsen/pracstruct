
struct dob
{
	int d;
	int m;
	int y;
};
struct student
{
	//�������
	char fName[30];
	//��� 
	char lName[30];
	//�������� 
	char mName[30];
	//��� �������� 
	dob dateOfBirthday;
	//���
	int gender;
	//������ ������
	int rate[10];
};
void clear();
void MainMenu(int *p);
void PrintInfo(student * st);
void WorkWithFolder(char *nameGroup, char *command, char *path);