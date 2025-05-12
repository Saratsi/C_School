#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#define STR_SIZE 2009999

struct Student
{
	char name[50];
    char surname[50];
    float oral_grade;
    float written_grade;
    float average;
};

int compareStudents(const void *a, const void *b)
{
	const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    if (studentA->average < studentB->average) return -1;
    if (studentA->average > studentB->average) return 1;
    return 0;
}
int intAfterCheck(char *msg)//������� ��� ���� ��� ������������� � ������� ����� int
{
	char temp[STR_SIZE];
	int i, arith;
	bool flag;
	
	do
	{
		flag = 1;
		
		printf("%s", msg);
		gets(temp);
		
		if(strlen(temp)==0)	//�� ������� ������ ENTER
			flag=0;	//� flag ������� false ���� �� ����������� input
		
		else if((temp[0]=='+' || temp[0]=='-') && strlen(temp)==1)
			flag=0;
		
		else if(temp[0]!='+' && temp[0]!='-') //�� ��� ������� ����� + �/��� - �� �� ������ �� ���������
		{
			for(i=0; i<strlen(temp); i++)
			{
				if(isdigit(temp[i])!=0) //�� ���� ������� ����� ��� 0 �� ��� 9 ���� � flag �� ���������� true
					flag = flag & 1;//bitwise and (����� and bit ���� bit)
				else				//������ �� ����� false
					flag = flag & 0;//bitwise and (����� and bit ���� bit)
			}
		}
		
		//�� ����� ++3 � +-3 � -+3 � --3 �� ��� ���������
		else if((temp[0]=='+'&&temp[1]=='+')|| (temp[0]=='+'&&temp[1]=='-') || (temp[0]=='-'&&temp[1]=='+') || (temp[0]=='-'&&temp[1]=='-')) //�� ������� ����� + �/��� - �� �� ������ �� ���������
			flag = 0; //� flag �� ����� false
		
		//�� ����� + � - ���� ���� ���� �� ������� ������� ��� ����� ���� + ���� -	
		else if((temp[0]=='+'&&temp[1]!='+')|| (temp[0]=='+'&&temp[1]!='-')||(temp[0]=='-'&&temp[1]!='+') || (temp[0]=='-'&&temp[1]!='-')) //�� ������� ����� + ��� ��� ������� ���� - (� �� �������) �� �� ������ �� ��������� 
		{	
			for(i=1; i<strlen(temp); i++)
			{
				if(isdigit(temp[i])!=0) //�� ���� ������� ����� ��� 0 �� ��� 9 ���� � flag �� ���������� true
					flag = flag & 1;//bitwise and (����� and bit ���� bit)
				else				//������ �� ����� false
					flag = flag & 0;//bitwise and (����� and bit ���� bit)
			}
		}		
		
		if(flag==0) //�� � flag ����� false, ���� �� ������� �� ���� ������
		{
			printf("\n\n��� ������ ������!\a\n�������� ����������� ����!\n\n");
			system("pause");
			system("cls");
		}
	}while(flag==0); //��� � flag ��������� false �� ��������� �� ������ �� ���� ������
	
	return atoi(temp);//����� ���� ��� �� while ������� �� ���� ����� �������� �� ��� �� string, 
					  //����� ������������ �� string �� ������
}
float floatAfterCheck(char *msg)//������� ��� ���� ��� ������������� � ������� ����� float
{
	char temp[STR_SIZE];
	int i, count, flag=0;
	float arith;
	
	do
	{
		flag=1; //� flag ����� ������ true
		count=0;
		
		printf("%s", msg);
		gets(temp);
		
		if(strlen(temp)==0)	//�� ������� ������ ENTER
			flag=0;	//� flag ������� false ���� �� ����������� input
		else
		{
			//������� �� �������� 2 � ������������ �������
			for(i=0; i<strlen(temp)-1; i++)
				if(temp[i]=='.')
					count++;
			
			if (count>=2)//�� �������� ������� (.) ������������ ��� ����, ������ ��� 2 ��� ����,
				flag=0; //���� �� flag false
				
			if(temp[0] == '.' || temp[strlen(temp)-1] == '.')	//������� �� � ������� ������ � ��������� �� ������(.)
				flag=0;
			
			if((temp[0]=='+' || temp[0]=='-') && strlen(temp)==1)
				flag=0;
				
			if(temp[0]!='+' && temp[0]!='-')
			{
				//������� �� ��� �� �������� ������� ����� �������	
				if(count<=1)//�� ������� � ��� � ������ ������ (.)
				{
					for(i=0; i<strlen(temp); i++)
					{
						if(temp[i]=='.')//�� ���� ����������� ������� �� ������ (.)
							continue;   //������� ��
						else
						{
							if(isdigit(temp[i])!=0) //�� ���� ������� ����� ��� 0 �� ��� 9 ���� � flag �� ���������� true
								flag = flag * 1;//bitwise and (����� and bit ���� bit)
							else					//������ �� ����� false
								flag = flag * 0;//bitwise and (����� and bit ���� bit)
						}
					}
				}	
			}
			
			//�� ����� ++3 � +-3 � -+3 � --3 �� ��� ���������
			if((temp[0]=='+'&&temp[1]=='+') || (temp[0]=='+'&&temp[1]=='-') || (temp[0]=='-'&&temp[1]=='+') || (temp[0]=='-'&&temp[1]=='-')) //�� ������� ����� + �/��� - ��� ���� + �/��� - �� ��� �� ������ �� ���������
				flag = 0; //� flag �� ����� false
			
			if((temp[0]=='+'&&temp[1]=='.') || (temp[0]=='-'&&temp[1]=='.')) //�� ������� ����� + �/��� - ��� ���� . �� ��� �� ���������
				flag = 0; //� flag �� ����� false
				
			//�� ����� + � - ���� ���� ���� �� ������� ������� ��� ����� ���� + ���� -	
			if((temp[0]=='+'&&temp[1]!='+') || (temp[0]=='+'&&temp[1]!='-') || (temp[0]=='-'&&temp[1]!='+') || (temp[0]=='-'&&temp[1]!='-')) //�� ������� ����� + ��� ��� ������� ���� - (� �� �������) �� �� ������ �� ��������� 
			{	
				for(i=1; i<strlen(temp); i++)
				{
					if(temp[i]=='.')//�� ���� ����������� ������� �� ������ (.)
						continue;   //������� ��
					else
					{
						if(isdigit(temp[i]) != 0) //�� ���� ������� ����� ��� 0 �� ��� 9 ���� � flag �� ���������� true
							flag = flag * 1;//bitwise and (����� and bit ���� bit)
						else					//������ �� ����� false
							flag = flag * 0;//bitwise and (����� and bit ���� bit)
					}
				}
			}
		}
		
		if(flag==0) //�� � flag ����� false, ���� �� ������� �� ���� ������
		{
			printf("\n\n��� ������ ������! \a\n�������� ����������� ����!\n\n");
			system("pause");
			system("cls");
		}
	}while(flag==0); //��� � flag ��������� false �� ��������� �� ������ �� ���� ������
	
	return atof(temp);//����� ���� ��� �� while ������� �� ���� ����� �������� �� ��� �� string, 
					  //����� ������������ �� string �� ������
}

void calculateAverage(struct Student *student)//������� ��� ���� ���
{
	student->average = 0.4 * student->oral_grade + 0.6 * student->written_grade;
}

void displayBoard(struct Student *students,int num_students,int k)//�������� ��� ������� ���� ��������
{
	if(k==0)
	{
		printf("--------------------------------------------------------\n");
		printf("\nUnsorted Student Database:\n");
		printf("--------------------------------------------------------\n");
    	printf("|�����\t�������\t ��.���.\t ��. ���.\t�.���� |\n");
		for (int i = 0; i < num_students; i++)
		{
			printf("|%4s\t%6s\t%2.2f\t\t%2.2f\t\t%2.2f\n", students[i].name, students[i].surname, students[i].oral_grade, students[i].written_grade, students[i].average); 
		}
		printf("--------------------------------------------------------\n");
	}
	else
	{
		printf("--------------------------------------------------------\n");
		printf("\nSorted Student Database:\n");
		printf("--------------------------------------------------------\n");
    	printf("|�����\t�������\t ��.���.\t ��. ���.\t�.���� |\n");
		for (int i = 0; i < num_students; i++)
		{
			printf("|%4s\t%6s\t%2.2f\t\t%2.2f\t\t%2.2f\n", students[i].name, students[i].surname, students[i].oral_grade, students[i].written_grade, students[i].average); 
		}
		printf("--------------------------------------------------------\n");
	}
}

void printStudentDatabase(struct Student *students, int num_students, const char *filename,int random)//�������� ��� ������� �� ������ ��������
{
	FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
    	if(random==0)
	    {
			fprintf(file,"--------------------------------------------------------\n");
			fprintf(file,"\nUnsorted Student Database:\n");
			fprintf(file,"--------------------------------------------------------\n");
    		fprintf(file,"|�����\t�������\t ��.���.\t ��. ���.\t�.���� |\n");
			for (int i = 0; i < num_students; i++)
			{
				fprintf(file,"|%4s\t%6s\t%2.2f\t\t%2.2f\t\t%2.2f\n", students[i].name, students[i].surname, students[i].oral_grade, students[i].written_grade, students[i].average); 
			}
			fprintf(file,"--------------------------------------------------------\n");
			fclose(file);
        	printf("Student Database saved to %s\n", filename);
	    }
		else
		{
			fprintf(file,"--------------------------------------------------------\n");
			fprintf(file,"\nSorted Student Database:\n");
			fprintf(file,"--------------------------------------------------------\n");
    		fprintf(file,"|�����\t�������\t ��.���.\t ��. ���.\t�.���� |\n");
			for (int i = 0; i < num_students; i++)
			{
				fprintf(file,"|%4s\t%6s\t%2.2f\t\t%2.2f\t\t%2.2f\n", students[i].name, students[i].surname, students[i].oral_grade, students[i].written_grade, students[i].average); 
			}
			fprintf(file,"--------------------------------------------------------\n");
			fclose(file);
        	printf("Student Database saved to %s\n", filename);
		}
	}
	else
	printf("Error opening file %s.", filename);
}
int isAlphabetic(const char *str)//������� ��� ���� ��� ������������� � ������� ����� ���� ��������
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isalpha(str[i]))
		return 0;
	}
	return 1;
}
void searchStudent(struct Student *students, int num_students)//������� ������� ������.
{
	char search_name[50], search_surname[50];
    int found;
    char continueSearch;
    
    do
    {
    	printf("���� �� ����� ��� ������: ");
        getchar();
        fgets(search_name, sizeof(search_name), stdin);
        search_name[strcspn(search_name, "\n")] = '\0';
        printf("���� �� ������� ��� ������: ");
        fgets(search_surname, sizeof(search_surname), stdin);
        search_surname[strcspn(search_surname, "\n")] = '\0';
        
        found = 0;
        for (int i = 0; i < num_students; i++)
        {
        	if (strcmp(students[i].name, search_name) == 0 && strcmp(students[i].surname, search_surname) == 0)
        	{
        		printf("Student found:\n\n");
                printf("�����: %s\n", students[i].name);
                printf("�������: %s\n", students[i].surname);
                printf("���������� ������: %.2f\n", students[i].oral_grade);
                printf("������� ������: %.2f\n", students[i].written_grade);
                printf("����� ����: %.2f\n", students[i].average);
                found = 1;
                break;
			}
		}
		if(!found)
		printf("Student not found.\n\n");
		printf("��� �� ������ ��� ����� ������? (Y/N): ");
        scanf(" %c", &continueSearch);
	}while (continueSearch == 'Y' || continueSearch == 'y');
}

int main()
{
	system("CHCP 1253 > nul");
	
	int num_students,random,switcher=0;
	char answer;
	
	num_students=intAfterCheck("����� ����� �� �������: ");
	//������� ������ ���� ��� �� calloc
    struct Student *students = (struct Student *)calloc(num_students, sizeof(struct Student));
    //������� ��� �������� �����.
    for (int i = 0; i < num_students; i++)
    {
    	printf("\n������� %d\n", i + 1);
    	printf("------------\n");
    	printf("�����: ");
    	while (switcher==0)
    	{
        	scanf("%s", students[i].name);
        	if (!isAlphabetic(students[i].name))
        	{
        		printf("�� ����� ��� ������ �� �������� ������� � ���������� �������� ����������� ����: \n\n");
        		printf("�����: ");
			}
        	else
        	switcher=1;
		};
        printf("�������: ");
        while (switcher==1)
    	{
        	scanf("%s", students[i].surname);
        	if (!isAlphabetic(students[i].surname))
        	{
        		printf("�� ������� ��� ������ �� �������� ������� � ���������� �������� ����������� ����: \n\n");
        		printf("�������: ");
			}
        	else
        	switcher=0;
    	}
        getchar();
        /*(Warning!)�ug ��� ���� ����� ��� �� �� ��� � ���� �� ����� 0-10 � ��� �� ����� ����� freeze ��� �� ���������.
        ������ ���������� ��� ��� floatAfterCheck.
        ����� ��� ��� ����� �� �������� ��� ����� ����� ������*/
        students[i].oral_grade=floatAfterCheck("����� ����� � ���������� ������ ��� ������ ��� ������������������� ������� ��������������� C++ : ");
        students[i].written_grade=floatAfterCheck("����� ����� � ������� ������ ��� ������ ��� ������������������� ������� ��������������� C++: ");
        calculateAverage(&students[i]);
	}
	system("CLS");
	
	displayBoard(students,num_students,switcher);//����������� �������� ��� �������
	switcher=1;
	qsort(students, num_students, sizeof(struct Student), compareStudents);
	
	displayBoard(students,num_students,switcher);//������������ �������� ��� �������
	
	srand(time(NULL));
    random = rand() % 2;
    //������ �������� ��� ������� �� ������ ��������(����������� / ������������)
    if (random == 0)
    {
    	printf("--------------------------------------------------------\n");
    	printStudentDatabase(students, num_students, "unsorted_db.txt",random);
	}
    else
    {
    	qsort(students, num_students, sizeof(struct Student), compareStudents);
    	printf("--------------------------------------------------------\n");
        printStudentDatabase(students, num_students, "sorted_db.txt",random);
	}
	printf("--------------------------------------------------------\n");	
	printf("������ �� ����������� ������� ������ ��� �������;AN ��� ���� 'Y' � 'y': ");
	scanf("%c",&answer);
	//������ ��� ������ ��� ����� �� ���������� ������� ������ ��� ����� ���������.
	if(answer=='y' || answer=='Y')
	{
		searchStudent(students, num_students);
	}	
	
	//���������� ����� ���� ���
    free(students);

    return 0;
}
