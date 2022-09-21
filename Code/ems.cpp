#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void userlogin(void);
void adminlogin(void);
void manage_per_info();
void manage_per_infou();
void salaryu();
void salary();
int train_record(void);
int events_u();
int events_a();
void addrecord();
void netsal();
void displaysrecord();
void modifysrecord();
void addsrecord();
void deleterecord();
void displayrecord();
void modifyrecord();

struct user{
    char username[20];
    char password[10];
}*pUser;

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
  
struct events{
	char name[30];
	char time[10];
	char date[10];
	char des[30];
}*eve;
  
FILE *fp4, *ft1;

int main()
{
	
	printf("\n\n\t\t\tEMPLOYEE MANAGEMENT SYSTEM :)\n\n\n");
	int s;
	
	printf("1 --> userpanel\n2 --> admin panel\n3 --> exit");
	scanf("%d",&s);
	if(s==1){
		userlogin ( );
	}
	else if(s==2){
		adminlogin();
	}
	else{
		exit(0);
	}
    

    return 0;
}


void userlogin(void){
    FILE *fp1;
    char uName[10], pwd[10], newpwd[10],oldpwd[10];int i,d;char c;
    int ch;

    pUser=(struct user *)malloc(sizeof(struct user));
    do{
    	printf("1. Login Through An Existing Account\n2. Create New account\n3. go back to main menu");
        scanf("%d",& i);
        //system("cls");
    
    	
	
    switch(i){
        case 1:
            if ( ( fp1=fopen("user.txt", "r+")) == NULL) {
                if ( ( fp1=fopen("user.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    return ;
                }
            }
            printf("Username: ");
            scanf("%s",uName);
            
            printf("Password: ");
            scanf("%s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp1) == 1) 
			{
                if( strcmp ( pUser->username, uName) == 0) 
				{
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) 
					{
                        printf ("Match password\n");
                            do{
                            	
                            	printf("\n1.Update password \n2.Manage Personal Information \n3.View Salary \n");
						        printf("4.View Events \n 5.Logout \nEnter Your Choice\n");
						        scanf("%d",&ch);
	                        	switch(ch)
						                  {
							                    case 1:
										                printf("enter the old password");
										                scanf("%s",oldpwd);
				                                        rewind(fp1);
							                            while ( fread (pUser, sizeof(struct user), 1, fp1) == 1) {
									                                if( strcmp ( pUser->password, oldpwd) == 0){
									                                	printf("Enter The New Password");
										                                scanf("%s",newpwd);
										                                strcpy(pUser->password,newpwd);
										                                long int i=sizeof(oldpwd);
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
														events_u();
														break;
												case 5:
														main();
														break;
												default:
														break;
											}
							}while(ch>=8||ch<=0);					
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
                scanf("%s",pUser->username);
                printf("Choose A Password: ");
                scanf("%s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp1);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
            
        case 3:
        	main();
        	break;
        	
        default:
        	printf("you have enter the wrong choice please enter the correct choice");
      }
	}while(i!=1&&i!=2&&i!=3);
    
    
    free ( pUser);//free allocated memory
    fclose(fp1);
}



void adminlogin(void){
	
	FILE *fp2;
	FILE *fp3;
    char aName[10], pwd[10];int i,d;char c;
    int ch;

    pUser=(struct user *)malloc(sizeof(struct user));
    
    do{

    printf("1. Login Through An Existing Account\n2. if you are the new administrator and you want to create New account\n3. go back to main menu");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp2=fopen("admin.txt", "r+")) == NULL) {
                if ( ( fp2=fopen("admin.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    return ;
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
                        
                        	
                        	do{
		                        		printf(" press 1 to add new user\n press 2 to manage employee personal information\n press 3 to manage employee finance\n ");
				                        printf(" press 4 to manage employee events\n  press 5 to manage employee training record\n");
				                        printf(" press 6 to log out\n");
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
							                                 
															break;
													case 2:
															manage_per_info();
															
															break;
													case 3:
															salary();
															
															break;
													case 4:
															events_a();
															
															break;
												
													case 5:
														train_record();
														
														break;
													case 6:
														main();
														break;
													default:
														printf("you have entered the wrong choice plss enter the correct choice");
															break;
												}
							}while(ch<=6||ch>=0);
                        
					
					
                    }
                    
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
        case 3:
        	main();
        	break;
        	
        default:
        	printf("you have enter the wrong choice please enter the correct choice");
        
        	
    }
    }while(i!=1||i!=2||i!=3);
    free ( pUser);//free allocated memory
    //fclose(fp1);
    fclose(fp2);
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
    printf("Enter the employee name for training period:  ");
    scanf("%s", intstructor);
    printf("\n");
    printf("\n");

    // Save data
    fprintf(file, "%s\t%d\t%s\n", course,duration,intstructor);
  }

  // Close the file
  fclose(file);

  return 0;
}


int events_u(){
	FILE *ptr;
	
	char c;
	
	char ename[30];
	
	eve=(struct events *)malloc(sizeof(events));
	
	if ( ( ptr=fopen("events.txt", "r")) == NULL) {
                    printf ("Could not open file...because the events are not assigned\n");
                    
                    return 0;
                
    }
    printf("enter the name of the employee ");
    //fgets(ename,30,stdin);
    scanf("%s",ename);
    while ( fread(eve, sizeof(struct events), 1, ptr)== 1){
    	if(strcmp(eve->name,ename)){
    		printf("the time of the event is %s\n",eve->time);
    		printf("the date of the event is %s\n",eve->date);
    		printf("the description of the event is %s\n",eve->des);
		}
	}
	
	return 0;
}

int events_a(){
		FILE *ptr;
	
	char c;
	
	eve=(struct events *)malloc(sizeof(events));
	
	if ( ( ptr=fopen("events.txt", "a+")) == NULL) {
                if ( ( ptr=fopen("events.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    
                    return 0;
                }
    }
    do{
    	system("cls");
    	fflush(stdin);
    		printf("enter the name of the employee\n");
	    	fgets(eve->name,30,stdin);
	    	printf("enter the time\n");
	    	scanf("%s",eve->time);
	    	printf("enter the date\n");
	    	scanf("%s",eve->date);
	    	printf("enter the description\n");
	    	//fgets(eve->des,30,stdin);
	    	scanf("%s",eve->des);
	    	//gets(eve->des);
	    	fflush(stdin);
	    	fwrite(&eve,sizeof(struct events),1,ptr);
	    	printf("events are added for the employee %s",eve->name);
	    	printf("\n");
	    	fflush(stdin);
		    printf("want to add new event for the new user? y/n: ");
    	    scanf("%c",&c);
	}while(c=='Y'||c=='y');
	
	return 0;
}


void manage_per_infou(){
	int choice;
  
    fp = fopen("data.txt", "r+");
  
    if (fp != NULL) {
        fp = fopen("data.txt", "w+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    while (1) {
        
        system("cls");
       
        printf("\n1. ADD RECORD\n");
        
        printf("\n2. DISPLAY RECORDS\n");
        
        printf("\n3. MODIFY RECORD\n");
        
        printf("\n5. EXIT\n");
        
        
       do{
       	
       	printf("\nENTER YOUR CHOICE...\n");
       
       	scanf("%d", &choice);
  
        
        switch (choice) {
						        case 1:
						  
						            // Add the records
						            addrecord();
						            break;
						  
						        case 2:
						  
						            // Display the records
						            displayrecord();
						            break;
						  
						        case 3:
						  
						            // Modify the records
						            modifyrecord();
						            break;
						  
						        case 4:
						            fclose(fp);
						            return;
						            break;
						  
						        default:
						            printf("\nINVALID CHOICE...\n");
                        }
       	   
	   }while(choice>=5||choice<=0);
        
    }
  
           return ;
}


void manage_per_info(){
	int choice;
  
    fp = fopen("data.txt", "r+");
  
    if (fp != NULL) {
        fp = fopen("data.txt", "w+");
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
			        
			        do{
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
											            return ;
											            break;
											  
											        default:
											            printf("\nINVALID CHOICE...\n");
											    }
					}while(choice>=6||choice<=0);
					
		    	}
  
    return ;
}


void salaryu(void){
	int choice;
  
    fp4 = fopen("data1.txt", "r+");
  

        if (fp4 == NULL) {
            printf("\nCannot open file... because your file is empty");
            return ;
        }
    
  
    while(1){
        
        system("cls");
        
        printf("\n1. net salary\n");
        
        printf("\n2. DISPLAY RECORDS\n");
        
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
            return ;
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}


void salary(void){
	int choice;
  
    fp4 = fopen("data1.txt", "r+");
  
    if (fp4 != NULL) {
        fp4 = fopen("data1.txt", "w+");
        if (fp4 == NULL) {
            printf("\nCannot open file...");
            return ;
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
            return ;
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return ;
}

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
