#include <iostream>
#include <string.h>
#include <Windows.h>

int main(void)
{
	system("chcp 1251");
	int i = 0;
	char cchar[20];
	int cint, prov = 1;
	struct student
	{
		char famil[20];
		char name[20];
		int Nomzach;
	} stud[3];

	for (i = 0; i < 3; i++)
	{
		printf("Введите имя студента(%d): ", i + 1);
		scanf_s("%s", &stud[i].name, 20);
		printf("Введите фамилию студента(%d): ", i + 1);
		scanf_s("%s", &stud[i].famil, 20);
		printf("Введите номер зачётной книжки студента(%d): ", i + 1);
		scanf_s("%d", &stud[i].Nomzach);
	}
	printf("\nПоиск по:\n1)Имени\n2)Фамилии\n3)Номеру зачётной книжки\n");
	i = 0;
	while (i == 0)
	{
		if (GetKeyState('1') < 0)
		{
			printf("\nвведите имя: ");
			scanf_s("%s", cchar, 20);
			while (i < 3)
			{
				prov = strcmp(cchar, stud[i].name);
				if (prov == 0) { printf("%s %s %d\n", stud[i].name, stud[i].famil, stud[i].Nomzach); }
				i++;
			}
		}
		if (GetKeyState('2') < 0)
		{
			printf("\nвведите фамилию: ");
			scanf_s("%s", cchar, 20);
			while (i < 3)
			{
				prov = strcmp(cchar, stud[i].famil);
				if (prov == 0) { printf("%s %s %d\n", stud[i].name, stud[i].famil, stud[i].Nomzach); }
				i++;
			}
		}
		if (GetKeyState('3') < 0)
		{
			printf("\nвведите номер зачётной книжки: ");
			scanf_s("%d", &cint);
			while (i < 3)
			{
				if (cint == stud[i].Nomzach) { printf("%s %s %d\n", stud[i].name, stud[i].famil, stud[i].Nomzach); }
				i++;
			}
		}
	}
}