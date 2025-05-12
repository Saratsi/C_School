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
int intAfterCheck(char *msg)//ελεγχει αμα αυτο που πληκτρολογησε ο πελατης ειναι int
{
	char temp[STR_SIZE];
	int i, arith;
	bool flag;
	
	do
	{
		flag = 1;
		
		printf("%s", msg);
		gets(temp);
		
		if(strlen(temp)==0)	//Αν πατήσει αμέσως ENTER
			flag=0;	//η flag γίνεται false ώστε να ξαναζητήσει input
		
		else if((temp[0]=='+' || temp[0]=='-') && strlen(temp)==1)
			flag=0;
		
		else if(temp[0]!='+' && temp[0]!='-') //Αν ΔΕΝ πατήσει πρώτα + ή/και - να το δεχτεί ως επιτρεπτό
		{
			for(i=0; i<strlen(temp); i++)
			{
				if(isdigit(temp[i])!=0) //αν κάθε πλήκτρο είναι από 0 ώς και 9 τότε η flag να παραμείνει true
					flag = flag & 1;//bitwise and (κάνει and bit προς bit)
				else				//αλλιώς να γίνει false
					flag = flag & 0;//bitwise and (κάνει and bit προς bit)
			}
		}
		
		//Αν δώσει ++3 ή +-3 ή -+3 ή --3 να μην επιτραπεί
		else if((temp[0]=='+'&&temp[1]=='+')|| (temp[0]=='+'&&temp[1]=='-') || (temp[0]=='-'&&temp[1]=='+') || (temp[0]=='-'&&temp[1]=='-')) //Αν πατήσει πρώτα + ή/και - να το δεχτεί ως επιτρεπτό
			flag = 0; //η flag να γίνει false
		
		//Αν δώσει + ή - στην αρχή αλλά το δεύτερο πλήκτρο δεν είναι ούτε + ούτε -	
		else if((temp[0]=='+'&&temp[1]!='+')|| (temp[0]=='+'&&temp[1]!='-')||(temp[0]=='-'&&temp[1]!='+') || (temp[0]=='-'&&temp[1]!='-')) //Αν πατήσει πρώτα + και δεν πατήσει μετά - (ή το ανάποδο) να το δεχτεί ως επιτρεπτό 
		{	
			for(i=1; i<strlen(temp); i++)
			{
				if(isdigit(temp[i])!=0) //αν κάθε πλήκτρο είναι από 0 ώς και 9 τότε η flag να παραμείνει true
					flag = flag & 1;//bitwise and (κάνει and bit προς bit)
				else				//αλλιώς να γίνει false
					flag = flag & 0;//bitwise and (κάνει and bit προς bit)
			}
		}		
		
		if(flag==0) //Αν η flag έγινε false, τότε θα ζητήσει εκ νέου αριθμό
		{
			printf("\n\nΔεν δώσατε αριθμό!\a\nΠαρακαλώ προσπαθήστε ξανά!\n\n");
			system("pause");
			system("cls");
		}
	}while(flag==0); //Όσο η flag παραμένει false το πρόγραμμα θα ζητάει εκ νέου αριθμό
	
	return atoi(temp);//Μόλις βγει από τη while σίγουρα θα έχει πάρει αριθμούς σε όλο το string, 
					  //οπότε μετατρέπουμε το string σε αριθμό
}
float floatAfterCheck(char *msg)//ελενχει αμα αυτο που πληκτρολογησε ο πελατης ειναι float
{
	char temp[STR_SIZE];
	int i, count, flag=0;
	float arith;
	
	do
	{
		flag=1; //Η flag είναι αρχικά true
		count=0;
		
		printf("%s", msg);
		gets(temp);
		
		if(strlen(temp)==0)	//Αν πατήσει αμέσως ENTER
			flag=0;	//η flag γίνεται false ώστε να ξαναζητήσει input
		else
		{
			//έλεγχος αν υπάρχουν 2 ή περισσότερες τελείες
			for(i=0; i<strlen(temp)-1; i++)
				if(temp[i]=='.')
					count++;
			
			if (count>=2)//Αν υπάρξουν τελειές (.) περισσότερες της μίας, δηλαδή από 2 και πάνω,
				flag=0; //κάνε τη flag false
				
			if(temp[0] == '.' || temp[strlen(temp)-1] == '.')	//έλεγχος αν η είσοδος ξεκινά ή τελειώνει με τελεία(.)
				flag=0;
			
			if((temp[0]=='+' || temp[0]=='-') && strlen(temp)==1)
				flag=0;
				
			if(temp[0]!='+' && temp[0]!='-')
			{
				//έλεγχος αν όλα τα υπόλοιπα πλήκτρα είναι αριθμοί	
				if(count<=1)//αν υπάρχει ή μία ή καμμία τελεία (.)
				{
					for(i=0; i<strlen(temp); i++)
					{
						if(temp[i]=='.')//αν δεις οποιοδήποτε πλήκτρο με τελεία (.)
							continue;   //αγνόησε το
						else
						{
							if(isdigit(temp[i])!=0) //αν κάθε πλήκτρο είναι από 0 ώς και 9 τότε η flag να παραμείνει true
								flag = flag * 1;//bitwise and (κάνει and bit προς bit)
							else					//αλλιώς να γίνει false
								flag = flag * 0;//bitwise and (κάνει and bit προς bit)
						}
					}
				}	
			}
			
			//Αν δώσει ++3 ή +-3 ή -+3 ή --3 να μην επιτραπεί
			if((temp[0]=='+'&&temp[1]=='+') || (temp[0]=='+'&&temp[1]=='-') || (temp[0]=='-'&&temp[1]=='+') || (temp[0]=='-'&&temp[1]=='-')) //Αν πατήσει πρώτα + ή/και - και μετά + ή/και - να μην το δεχτεί ως επιτρεπτό
				flag = 0; //η flag να γίνει false
			
			if((temp[0]=='+'&&temp[1]=='.') || (temp[0]=='-'&&temp[1]=='.')) //Αν πατήσει πρώτα + ή/και - και μετά . να μην το επιτρέψει
				flag = 0; //η flag να γίνει false
				
			//Αν δώσει + ή - στην αρχή αλλά το δεύτερο πλήκτρο δεν είναι ούτε + ούτε -	
			if((temp[0]=='+'&&temp[1]!='+') || (temp[0]=='+'&&temp[1]!='-') || (temp[0]=='-'&&temp[1]!='+') || (temp[0]=='-'&&temp[1]!='-')) //Αν πατήσει πρώτα + και δεν πατήσει μετά - (ή το ανάποδο) να το δεχτεί ως επιτρεπτό 
			{	
				for(i=1; i<strlen(temp); i++)
				{
					if(temp[i]=='.')//αν δεις οποιοδήποτε πλήκτρο με τελεία (.)
						continue;   //αγνόησε το
					else
					{
						if(isdigit(temp[i]) != 0) //αν κάθε πλήκτρο είναι από 0 ώς και 9 τότε η flag να παραμείνει true
							flag = flag * 1;//bitwise and (κάνει and bit προς bit)
						else					//αλλιώς να γίνει false
							flag = flag * 0;//bitwise and (κάνει and bit προς bit)
					}
				}
			}
		}
		
		if(flag==0) //Αν η flag έγινε false, τότε θα ζητήσει εκ νέου αριθμό
		{
			printf("\n\nΔεν δώσατε αριθμό! \a\nΠαρακαλώ προσπαθήστε ξανά!\n\n");
			system("pause");
			system("cls");
		}
	}while(flag==0); //Όσο η flag παραμένει false το πρόγραμμα θα ζητάει εκ νέου αριθμό
	
	return atof(temp);//Μόλις βγει από τη while σίγουρα θα έχει πάρει αριθμούς σε όλο το string, 
					  //οπότε μετατρέπουμε το string σε αριθμό
}

void calculateAverage(struct Student *student)//Βρησκει τον μεσο ορο
{
	student->average = 0.4 * student->oral_grade + 0.6 * student->written_grade;
}

void displayBoard(struct Student *students,int num_students,int k)//εκτύπωση των μαθητών στην εφαρμογή
{
	if(k==0)
	{
		printf("--------------------------------------------------------\n");
		printf("\nUnsorted Student Database:\n");
		printf("--------------------------------------------------------\n");
    	printf("|Ονομα\tΕπωνυμο\t Πρ.Βαθ.\t Γρ. Βαθ.\tΜ.Ορος |\n");
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
    	printf("|Ονομα\tΕπωνυμο\t Πρ.Βαθ.\t Γρ. Βαθ.\tΜ.Ορος |\n");
		for (int i = 0; i < num_students; i++)
		{
			printf("|%4s\t%6s\t%2.2f\t\t%2.2f\t\t%2.2f\n", students[i].name, students[i].surname, students[i].oral_grade, students[i].written_grade, students[i].average); 
		}
		printf("--------------------------------------------------------\n");
	}
}

void printStudentDatabase(struct Student *students, int num_students, const char *filename,int random)//εκτύπωση των μαθητών σε αρχείο κειμένου
{
	FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
    	if(random==0)
	    {
			fprintf(file,"--------------------------------------------------------\n");
			fprintf(file,"\nUnsorted Student Database:\n");
			fprintf(file,"--------------------------------------------------------\n");
    		fprintf(file,"|Ονομα\tΕπωνυμο\t Πρ.Βαθ.\t Γρ. Βαθ.\tΜ.Ορος |\n");
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
    		fprintf(file,"|Ονομα\tΕπωνυμο\t Πρ.Βαθ.\t Γρ. Βαθ.\tΜ.Ορος |\n");
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
int isAlphabetic(const char *str)//ελενχει αμα αυτο που πληκτρολογησε ο πελατης ειναι μονο γραμματα
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isalpha(str[i]))
		return 0;
	}
	return 1;
}
void searchStudent(struct Student *students, int num_students)//αναζητα καποιον μαθητη.
{
	char search_name[50], search_surname[50];
    int found;
    char continueSearch;
    
    do
    {
    	printf("Δωσε το ονομα του μαθητη: ");
        getchar();
        fgets(search_name, sizeof(search_name), stdin);
        search_name[strcspn(search_name, "\n")] = '\0';
        printf("δωσε το επωνυμο του μαθητη: ");
        fgets(search_surname, sizeof(search_surname), stdin);
        search_surname[strcspn(search_surname, "\n")] = '\0';
        
        found = 0;
        for (int i = 0; i < num_students; i++)
        {
        	if (strcmp(students[i].name, search_name) == 0 && strcmp(students[i].surname, search_surname) == 0)
        	{
        		printf("Student found:\n\n");
                printf("Ονομα: %s\n", students[i].name);
                printf("Επωνυμο: %s\n", students[i].surname);
                printf("Προφορικος Βαθμος: %.2f\n", students[i].oral_grade);
                printf("Γραπτος Βαθμος: %.2f\n", students[i].written_grade);
                printf("Μεσος Ορος: %.2f\n", students[i].average);
                found = 1;
                break;
			}
		}
		if(!found)
		printf("Student not found.\n\n");
		printf("Δες να ψαξεις για αλλον μαθητη? (Y/N): ");
        scanf(" %c", &continueSearch);
	}while (continueSearch == 'Y' || continueSearch == 'y');
}

int main()
{
	system("CHCP 1253 > nul");
	
	int num_students,random,switcher=0;
	char answer;
	
	num_students=intAfterCheck("Ποσοι ειναι οι μαθητες: ");
	//ανοιγμα θεσεων στην ραμ με calloc
    struct Student *students = (struct Student *)calloc(num_students, sizeof(struct Student));
    //ελενχος και εκτυπωση τιμων.
    for (int i = 0; i < num_students; i++)
    {
    	printf("\nΜαθητης %d\n", i + 1);
    	printf("------------\n");
    	printf("Ονομα: ");
    	while (switcher==0)
    	{
        	scanf("%s", students[i].name);
        	if (!isAlphabetic(students[i].name))
        	{
        		printf("ΤΟ ονομα δεν μπορει να περιεχει νουμερα η χαρακτηρες παρακαλω προσπαθηστε παλι: \n\n");
        		printf("Ονομα: ");
			}
        	else
        	switcher=1;
		};
        printf("Επωνυμο: ");
        while (switcher==1)
    	{
        	scanf("%s", students[i].surname);
        	if (!isAlphabetic(students[i].surname))
        	{
        		printf("ΤΟ επωνυμο δεν μπορει να περιεχει νουμερα η χαρακτηρες παρακαλω προσπαθηστε παλι: \n\n");
        		printf("Επωνυμο: ");
			}
        	else
        	switcher=0;
    	}
        getchar();
        /*(Warning!)Βug αμα βαλω λουπα για να δω αμα η τιμη θα ειναι 0-10 η οχι το οποιο κανει freeze ολο το προγραμμα.
        Μαλλον προερχεται απο την floatAfterCheck.
        Οποτε και δεν εβαλα να τσεκαρει για τυχων λαθος αριθμο*/
        students[i].oral_grade=floatAfterCheck("Ποιος ειναι ο προφορικος βαθμος στο μάθημα της Αντικειμενοστρεφούς Γλώσσας Προγραμματισμού C++ : ");
        students[i].written_grade=floatAfterCheck("Ποιος ειναι ο γραπτος βαθμος στο μάθημα της Αντικειμενοστρεφούς Γλώσσας Προγραμματισμού C++: ");
        calculateAverage(&students[i]);
	}
	system("CLS");
	
	displayBoard(students,num_students,switcher);//αταξινομητη εκτυπωση των μαθητων
	switcher=1;
	qsort(students, num_students, sizeof(struct Student), compareStudents);
	
	displayBoard(students,num_students,switcher);//ταξινομημενη εκτυπωση των μαθητων
	
	srand(time(NULL));
    random = rand() % 2;
    //Τυχαια εκτύπωση των μαθητών σε αρχείο κειμένου(αταξινομητη / ταξινομημενη)
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
	printf("Θελεις να αναζητησεις καποιον μαθητη στο συστημα;AN ναι πατα 'Y' η 'y': ");
	scanf("%c",&answer);
	//Ρωταει τον χρηστη αμα θελει να αναζητησει καποιον μαθητη και καλει συναρτηση.
	if(answer=='y' || answer=='Y')
	{
		searchStudent(students, num_students);
	}	
	
	//Ελευθερωση χωρου στην ραμ
    free(students);

    return 0;
}
