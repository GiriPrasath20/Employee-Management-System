#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void userlogin(void);
void adminlogin(void);
void manage_per_info();
void manage_per_infou();
void salaryu();
void events_a(int);

struct user{
    char username[20];
    char password[10];
}*pUser;

struct employee
{
	char empid[50];
	int rem;
	int tot,gra,index;
}ploy1[50];
int Leave(int y)
    {
        printf("Total number of days remaining: %d\n",ploy1[y].tot);
        printf("Enter the number of days of leave required:");
        scanf("%d",&ploy1[y].gra);
        printf("Request has be raised to admin department\n");
        return 0;
    }
// Structure of the employee
struct emp {
    char name[50];
    float salary;
    int age;
    int id;
};
struct emp e;
  
// size of the structure
long int size = sizeof(e);
  
int size_e;
struct employee_e
{
    char date[50],time[50],desc[50];
    int empid;
}ploy[50];

  
FILE *fp, *ft;

struct sal {
    char name[50];
    float payment;
    int allowance;
    int loan;
};
struct sal s;
  
// size of the structure
long int size1 = sizeof(s);
  

  
FILE *fp4, *ft1;

// Function to add the records
void addsrecord()
{
    system("cls");
    fseek(fp4, 0, SEEK_END);
    char another1 = 'y';
  
    while (another1 == 'y') {
        printf("\nEnter Name : ");
        scanf("%s", s.name);
  
        printf("\nEnter payment : ");
        scanf("%f", &s.payment);
  
        printf("\nEnter allowance : ");
        scanf("%d", &s.allowance);
  
        printf("\nEnter loan : ");
        scanf("%d", &s.loan);
  
        fwrite(&s, size1, 1, fp4);
  
        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);
  
        scanf("%c", &another1);
    }
}
  
// Function to delete the records
//void deleterecord()
//{
//    system("cls");
//    char empname[50];
//    char another = 'y';
//  
//    while (another == 'y') {
//        printf("\nEnter employee "
//               "name to delete : ");
//        scanf("%s", empname);
//  
//        ft1 = fopen("temp1.txt", "wb");
//        rewind(fp4);
//  
//        while (fread(&s, size,
//                     1, fp4)
//               == 1) {
//            if (strcmp(s.name,
//                       empname)
//                != 0)
//                fwrite(&s, size, 1, ft1);
//        }
//  
//        fclose(fp4);
//        fclose(ft1);
//        remove("data1.txt");
//        rename("temp1.txt", "data1.txt");
//        fp4 = fopen("data1.txt", "rb+");
//  
//        printf("\nWant to delete another"
//               " record (Y/N) :");
//        fflush(stdin);
//       scanf("%c", &another);
//    }
//}

void netsal(){
	system("cls");
  
    // sets pointer to start
    // of the file
    char empname[50];
    char another = 'y';
  printf("\n========================="
           "==========================="
           "======");
    printf("\n NET SALARY ");
    printf("==========================="
           "==========================="
           "====\n");
    while (another == 'y') {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
  
        rewind(fp4);
  
        // While File is open
        while (fread(&s, size1, 1, fp4) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(s.name, empname) == 0) {
                printf("\n%f",(float )s.payment-s.allowance-s.loan);
                break;
            }
        }
  
        // Ask for modifying another record
        printf("\nWant to see one more employee salary another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}
  
// Function to display the record
void displaysrecord()
{
    system("cls");
  
    // sets pointer to start
    // of the file
    rewind(fp4);
  
    printf("\n========================="
           "==========================="
           "======");
    printf("\nNAME\t\tPAYMENT\t\tALLOWANCE\t\t"
           "\tLOAN\n",
           s.name, s.payment,
           s.allowance, s.loan);
    printf("==========================="
           "==========================="
           "====\n");
  
    while (fread(&s, size1, 1, fp4) == 1)
        printf("\n%s\t\t%.2f\t\t%d\t%10d",
               s.name, s.payment, s.allowance, s.loan);
  
    printf("\n\n\n\t");
    system("pause");
}
  
// Function to modify the record
void modifysrecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
  
        rewind(fp4);
  
        // While File is open
        while (fread(&s, size1, 1, fp4) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(s.name, empname) == 0) {
                printf("\nEnter new name:");
                scanf("%s", s.name);
                printf("\nEnter new payment :");
                scanf("%f", &s.payment);
                printf("\nEnter new allowance :");
                scanf("%d", &s.allowance);
                printf("\nEnter new loan :");
                scanf("%d", &s.loan);
  
                fseek(fp4, -size1, SEEK_CUR);
                fwrite(&s, size1, 1, fp4);
                break;
            }
        }
  
        // Ask for modifying another record
        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}
  
// Function to add the records
void addrecord()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter Name : ");
        scanf("%s", e.name);
  
        printf("\nEnter Age : ");
        scanf("%d", &e.age);
  
        printf("\nEnter Salary : ");
        scanf("%f", &e.salary);
  
        printf("\nEnter EMP-ID : ");
        scanf("%d", &e.id);
  
        fwrite(&e, size, 1, fp);
  
        printf("\nWant to add another record (Y/N) : ");
        fflush(stdin);
  
        scanf("%c", &another);
    }
}
  
// Function to delete the records
void deleterecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee "
               "name to delete : ");
        scanf("%s", empname);
  
        ft = fopen("temp.txt", "wb");
        rewind(fp);
  
        while (fread(&e, size,
                     1, fp)
               == 1) {
            if (strcmp(e.name,
                       empname)
                != 0)
                fwrite(&e, size, 1, ft);
        }
  
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("temp.txt", "rb+");
  
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
       scanf("%c", &another);
    }
}
  
// Function to display the record
void displayrecord()
{
    system("cls");
  
    // sets pointer to start
    // of the file
    rewind(fp);
  
    printf("\n========================="
           "==========================="
           "======");
    printf("\nNAME\t\tAGE\t\tSALARY\t\t"
           "\tID\n",
           e.name, e.age,
           e.salary, e.id);
    printf("==========================="
           "==========================="
           "====\n");
  
    while (fread(&e, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t\t%.2f\t%10d",
               e.name, e.age, e.salary, e.id);
  
    printf("\n\n\n\t");
    system("pause");
}
  
// Function to modify the record
void modifyrecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
  
        rewind(fp);
  
        // While File is open
        while (fread(&e, size, 1, fp) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(e.name, empname) == 0) {
                printf("\nEnter new name:");
                scanf("%s", e.name);
                printf("\nEnter new age :");
                scanf("%d", &e.age);
                printf("\nEnter new salary :");
                scanf("%f", &e.salary);
                printf("\nEnter new EMP-ID :");
                scanf("%d", &e.id);
  
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }
  
        // Ask for modifying another record
        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}



int main()
{
	
	printf("\n\n\t\t\tEMPLOYEE MANAGEMENT SYSTEM :)\n");
	int s;
	
	printf("1 --> userpanel\n2 --> admin panel");
	scanf("%d",&s);
	if(s==1){
		userlogin ( );
	}
	else{
		adminlogin();
	}
    

    return 0;
}
int leave(){
	int ch,ch2,ach2,i=0,pct=0,ach3,flag=0,pflag=0;
    char mainch='y',admin,apwd[50],field[20],emid[10],pass[50];
    char defa[]="password";
    for(int i=0;i<50;i++){
        ploy1[i].index=i;
        ploy1[i].gra=0;
    }
    printf("Manage leave :\n");
    while(mainch=='Y'||mainch=='y')
    {
     umjump:
 scanf("%d",&ch2);
 if(ch2==6){Leave(i);goto umjump;}
 else{return 0;
 }
}
}
void userlogin(void){
    FILE *fp1;
    char uName[10], pwd[10], newpwd[10],oldpwd[10];int i,d;char c;
    int ch;

    pUser=(struct user *)malloc(sizeof(struct user));
    
    printf("1. Login Through An Existing Account\n2. Create New account\n");
    scanf("%d",& i);
    //system("cls");
    
    	
	
    switch(i){
        case 1:
            if ( ( fp1=fopen("user.txt", "r+")) == NULL) {
                if ( ( fp1=fopen("user.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",uName);
            x:
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp1) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        
                        	printf("\n1.Update password \n2.Manage Personal Information \n3.View Salary \n");
					    printf("4.Manage Attendance \n5.View Events \n6.Manage Leave \n7.Logout \nEnter Your Choice\n");
					    scanf("%d",&ch);
                        	switch(ch)
					{
						case 1:
							    printf("enter the old password");
							    scanf("%9s",oldpwd);
	                            rewind(fp1);
	                            while ( fread (pUser, sizeof(struct user), 1, fp1) == 1) {
                                if( strcmp ( pUser->password, oldpwd) == 0){
                                	printf("Enter The New Password");
	                                scanf("%9s",newpwd);
	                                strcpy(pUser->password,newpwd);
	                                int i=sizeof(oldpwd);
	                                fseek(fp1,-i, SEEK_CUR);
                                    fwrite(&(pUser->password),i, 1, fp1);
								} 
							}
								break;
						case 2:
								manage_per_infou();
								break;
						case 3:
								salaryu();
								break;
						case 4:
								//attendance();
								break;
						case 5:
								events_a(2);
								break;
						case 6:
								leave();
								break;
						case 7:
							main();
							break;
						default:
								break;
					}
						
                        
					
					
                    }else{
                    	 printf("if you want to reenter the password enter 1\n");
                    	 scanf("%d",&d);
                      if(d==1){
                	  goto x;
                }
					}                  
                }
            }
            break;

        case 2:
            do
            {
                if ( ( fp1=fopen("user.txt", "a+")) == NULL) {
                    if ( ( fp1=fopen("user.txt", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp1);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
    }
    free ( pUser);//free allocated memory
    fclose(fp1);
}
void manage_per_infou(){
	int choice;
  
    fp = fopen("data.txt", "rb+");
  
    if (fp != NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    while (1) {
        
        system("cls");
       
        printf("\n1. ADD RECORD\n");
        
        //printf("\n2. DELETE RECORD\n");
        
        printf("\n3. DISPLAY RECORDS\n");
        
        printf("\n4. MODIFY RECORD\n");
        
        printf("\n5. EXIT\n");
        
        printf("\nENTER YOUR CHOICE...\n");
       
        scanf("%d", &choice);
  
        
        switch (choice) {
        case 1:
  
            // Add the records
            addrecord();
            break;
  
        case 2:
  
            // Delete the records
            //deleterecord();
            break;
  
        case 3:
  
            // Display the records
            displayrecord();
            break;
  
        case 4:
  
            // Modify the records
            modifyrecord();
            break;
  
        case 5:
            fclose(fp);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}

void manage_per_info(){
	int choice;
  
    fp = fopen("data.txt", "rb+");
  
    if (fp != NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    while (1) {
        
        system("cls");
       
        printf("\n1. ADD RECORD\n");
        
        printf("\n2. DELETE RECORD\n");
        
        printf("\n3. DISPLAY RECORDS\n");
        
        printf("\n4. MODIFY RECORD\n");
        
        printf("\n5. EXIT\n");
        
        printf("\nENTER YOUR CHOICE...\n");
       
        scanf("%d", &choice);
  
        
        switch (choice) {
        case 1:
  
            // Add the records
            addrecord();
            break;
  
        case 2:
  
            // Delete the records
            deleterecord();
            break;
  
        case 3:
  
            // Display the records
            displayrecord();
            break;
  
        case 4:
  
            // Modify the records
            modifyrecord();
            break;
  
        case 5:
            fclose(fp);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}

void salaryu(void){
	int choice;
  
    fp4 = fopen("data1.txt", "rb+");
  
    if (fp4 != NULL) {
        fp4 = fopen("data1.txt", "wb+");
        if (fp4 == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    while (1) {
        
        system("cls");
       
        //printf("\n1. ADD RECORD\n");
        
        printf("\n1. net salary\n");
        
        printf("\n2. DISPLAY RECORDS\n");
        
        //printf("\n4. MODIFY RECORD\n");
        
        printf("\n3. EXIT\n");
        
        printf("\nENTER YOUR CHOICE...\n");
       
        scanf("%d", &choice);
  
        
        switch (choice) {
        	
        case 1:
  
            netsal();
            
            break;
  
        case 2:
  
            // Display the records
            displaysrecord();
            break;
  
        case 3:
            fclose(fp4);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}


void salary(void){
	int choice;
  
    fp4 = fopen("data1.txt", "rb+");
  
    if (fp4 != NULL) {
        fp4 = fopen("data1.txt", "wb+");
        if (fp4 == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    while (1) {
        
        system("cls");
       
        printf("\n1. ADD RECORD\n");
        
        printf("\n2. net salary\n");
        
        printf("\n3. DISPLAY RECORDS\n");
        
        printf("\n4. MODIFY RECORD\n");
        
        printf("\n5. EXIT\n");
        
        printf("\nENTER YOUR CHOICE...\n");
       
        scanf("%d", &choice);
  
        
        switch (choice) {
        case 1:
  
            // Add the records
            addsrecord();
            break;
  
        case 2:
  
            netsal();
            
            break;
  
        case 3:
  
            // Display the records
            displaysrecord();
            break;
  
        case 4:
  
            // Modify the records
            modifysrecord();
            break;
  
        case 5:
            fclose(fp4);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}

int train_record(void){
	FILE *file;
  int i,n;
  char course[32];
  int duration;
  char intstructor[32];

  // Open the file for writing
  file = fopen("emp_records.txt", "a+");
  if (!file)
  {
    printf("File could not be opened\n");
    getchar();
    return -1;
  }

  // Read and save data
  printf("enter no.of employees training records to add ");
  scanf("%d",&n);
  for (i = 0; i < n;++i)
  {
    // Read data
    printf("Record #%d\n", i + 1);
    printf("Enter the course that the employee trained in: "); 
    scanf("%s", course);
    printf("\n");
    printf("Enter the duration of the training period ");
    scanf("%d",&duration);
    printf("\n");
    printf("Enter the intstructor name for training period:  ");
    scanf("%s", intstructor);
    printf("\n");
    printf("\n");

    // Save data
    fprintf(file, "%s\t%d\t%s\n", course,duration,intstructor);
  }

  // Close the file
  fclose(file);

  // Open the file for reading
//  file = fopen("emp_records.txt", "r+");
//  if (!file)
//  {
//    printf("File could not be opened\n\a\a");
//    return -1;
//  }
//
//  // Load and display data
//  i = 0;
//  while(!feof(file))
//  {
//    ++i;
//    
//    fscanf(file, "%s\t%d\t%s\n\n", course, duration,intstructor);
//    printf("%s\t%d\t%s\n\n", course, duration,intstructor);
//    
//  }
// 
//  // Close the file
//  fclose(file);

  return 0;
}
static int m;
void events_a(int k){
	int ch,ch2,ach2,i=0,pct=0,ach3,flag=0,pflag=0;
    char mainch='y',admin,apwd[50],field[20],emid[10],pass[50];
    if(k==1){
    	 ch6:
             flag=0;
            m=1;
             printf("enter number of employees you are going to assign events");
             scanf("%d",&size_e);
                   printf("Enter the employee id to add events: ");
                   scanf("%d",&emid);
                   for(int i=0;i<size_e;i++)
                   {
                     //if(!strcmp(emid,ploy[i].empid))
                       //{
                           flag=1;
                           printf("Enter the time of the event: ");
                           scanf("%s",ploy[i].time);
                           printf("Enter the date of the event: ");
                           scanf("%s",ploy[i].date);
                           printf("Enter a short description of the event: ");
                           scanf("%s",ploy[i].desc);
                       //}
                       //else if(flag==0)
                       //{
                         //  printf("Employee not found!\n");
                           //goto ch6;
                       //}
                   }
                   
                   
	}
	else if(k==2&&m==1){
		printf("Date of the event: %s\n",ploy[1].date);
        printf("Time of the event: %s\n",ploy[1].time);
        printf("Description of the event: %s\n",ploy[1].desc);
	}
	else{
		printf("\nthe admin didn't assinged work for you\n");
	}
            
                
    return ;
}

void leave_a(){
	char emid[10];
	int flag=0;
	size=5;
ch7:
	               flag=0;
                   printf("Enter the employee id to check leave details: ");
                   scanf("%s",emid);
                   for(int i=0;i<size;i++)
                   {
                       if(!strcmp(emid,ploy1[i].empid))
                       {
                       	   flag=1;
                           if(ploy1[i].gra==0)
                           {printf("Enter the requested number of leave days: ");
                           scanf("%d",&ploy1[i].gra);}
                           ploy1[i].rem=(ploy1[i].tot)-(ploy1[i].gra);
                           ploy1[i].tot=ploy1[i].rem;
                           printf("Total number of days available for leave annually:50\n");
                           printf("Total number of days remaining for leave: %d\n",ploy1[i].tot);

                       }
                       else if(flag==0)
                       {
                           printf("Employee not found!\n");
                           goto ch7;
                       }
                   }
                }

void adminlogin(void){
	
	FILE *fp2;
	FILE *fp3;
    char aName[10], pwd[10];int i,d;char c;
    int ch;

    pUser=(struct user *)malloc(sizeof(struct user));

    printf("1. Login Through An Existing Account\n2. if you are the new administrator and you want to create New account\n");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp2=fopen("admin.txt", "r+")) == NULL) {
                if ( ( fp2=fopen("admin.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",aName);
            x:
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp2) == 1) {
                if( strcmp ( pUser->username, aName) == 0) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        a:
                        	
                        	do{
                        		printf(" press 1 to add new user\n press 2 to manage employee personal information\n press 3 to manage employee finance\n press 4 to manage employee attandance\n");
                        printf(" press 5 to manage employee events\n press 6 to manage employee leave\n press 7 to manage employee training record\n");
                        printf(" press 8 to log out\n");
					    scanf("%d",&ch);
                        		switch(ch)
					{
						case 1:
							   do
                                 {
                                   if ( ( fp3=fopen("user.txt", "a+")) == NULL) {
                                   if ( ( fp3=fopen("user.txt", "w+")) == NULL) {
                                          printf ("Could not open file\n");
                                          exit ( 1);
                                    }
                                 }
                                      printf("Choose A Username: ");
                                      scanf("%9s",pUser->username);
                                      printf("Choose A Password: ");
                                      scanf("%9s",pUser->password);
                                      fwrite (pUser, sizeof(struct user), 1, fp3);
                                      printf("Add another account? (Y/N): ");
                                      scanf(" %c",&c);//skip leading whitespace
                                 }while(c=='Y'||c=='y');
                                 goto a;
								break;
						case 2:
								manage_per_info();
								goto a;
								break;
						case 3:
								salary();
								goto a;
								break;
						case 4:
								//attendance();
								break;
						case 5:
								events_a(1);
								goto a;
								break;
						case 6:
								leave_a();
								break;
						case 7:
							train_record();
							goto a;
							break;
						case 8:
							main();
							break;
						default:
								break;
					}
							}while(ch!=8);
                        
					
					
                    }
//                    printf("if you want to reenter the password enter 1\n");
//                    if(d==1){
//                    	goto x;
//					}
                }
            }
            break;
        case 2:
            do
            {
                if ( ( fp2=fopen("admin.txt", "a+")) == NULL) {
                    if ( ( fp2=fopen("admin.txt", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp2);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
            
        	
    }
    free ( pUser);//free allocated memory
    //fclose(fp1);
    fclose(fp2);
}
