#include <stdio.h>
#include <stdlib.h>




#include <stdio.h>
#include <string.h>


#include <stdio.h>


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 // our struct is in this file
  // this file includes all our functions

#include <stdio.h>
#include <stdlib.h>

typedef struct contact {
    char first_name [20] ;
    char last_name [20] ;
    char street_adress [28] ;
    //char city [24]  ;
    char phone_number [16] ;
    //char date_of_birth [12] ;
    char year [12] ;
    char month [12] ;
    char day [12] ;

    char e_mail[24] ;
    }contact;

int validate_year(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 || Name[index] >57)
            return 0;
        index++;

        }

    int Day = atoi(Name);
    if (Day <= 1900 || Day > 2018 )
        return 0;

    return 1;

    }
int validate_street(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 && Name[index] != 32 && Name[index] != 35 )
            return 0;

        if (Name[index] >57 && Name[index] <65 )
            return 0;
        if (Name[index] >90 && Name[index] <97)
            return 0;

        if (Name[index] >122)
            return 0;

        index++;

        }

    return 1;

    }

int validate_number(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 || Name[index] >57)
            return 0;
        index++;

        }
    if (index != 11)
        return 0;

    if (Name[0] != '0')
        return 0;

    if (Name[1] != '1')
        return 0;

    return 1;

    }
int validate_normal_number(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 || Name[index] >57)
            return 0;
        index++;

        }

    return 1;

    }
int validate_name(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <65)
            return 0;
        if (Name[index] >90 && Name[index] <97)
            return 0;

        if (Name[index] >122)
            return 0;

        index++;

        }

    return 1;

    }
int validate_month(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 || Name[index] >57)
            return 0;
        index++;

        }

    int Day = atoi(Name);
    if (Day <= 0 || Day > 12 )
        return 0;

    return 1;

    }
int validate_email(char Name[]){
    int index =0;

    while(Name[index] != '@')
    {
// allowed before @ are a-z , A-Z , 0-9 , _ , . , + , -
// may be & , ' ,*,/,=,^,{},~

        if(Name[index +1] == '\0')
            return 0;

        if (Name[index] <48 && Name[index] != 43 && Name[index] != 45 && Name[index] != 46)
            return 0;
        if (Name[index] >57 && Name[index] <65)
            return 0;

        if (Name[index] >90 && Name[index] <96 && Name[index] != 95 )
            return 0;

        if (Name[index] >122)
            return 0;

         if (Name[index+1] == '@' && Name[index+2] == '.')
            return 0;



        index++;
        }

    index++;
    while(Name[index] != '.')
    {
        if(Name[index +1] == '\0')
            return 0;

        if(Name[index] < 97 || Name[index] >122)
            return 0;

        index++;
        }

    index++;

    if(Name[index++] != 'c')
        return 0;
    if(Name[index++] != 'o')
        return 0;
    if(Name[index++] != 'm')
        return 0;

    if (Name[0] == '@')
        return 0;
    return 1;

    }
int validate_city(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <65 && Name[index] != 32 )
            return 0;
        if (Name[index] >90 && Name[index] <97)
            return 0;

        if (Name[index] >122)
            return 0;

        index++;

        }

    return 1;

    }

    int validate_date(char Date[]){
    int index =0;

    while(Date[index] != '\0')
    {
        if (index == 2 || index == 5)
        { if (Date[index] != 95) return 0;}

        else if(Date[index] < 48 || Date[index] > 57 ) return 0;
        index ++;
                    }
    char day[4] = "\0";
    char month[4] = "\0";
    char year[8] = "\0";

    day[0]=Date[0];
    day[1]=Date[1];

    month[0]=Date[3];
    month[1]=Date[4];

    year[0]=Date[6];
    year[1]=Date[7];
    year[2]=Date[8];
    year[3]=Date[9];

    int days = atoi(day);
    int months = atoi(month);
    int years = atoi(year);


    if(days > 31 || days ==0)
        return 0;

    if(months > 12 || months ==0)
        return 0;

    if(years  > 2018 || years < 1900)
        return 0;


    return 1;

    }

    int validate_day(char Name[]){
    int index =0;

    while(Name[index] != '\0')
    {
        if (Name[index] <48 || Name[index] >57)
            return 0;
        index++;

        }

    int Day = atoi(Name);
    if (Day <= 0 || Day > 31 )
        return 0;

    return 1;

    }


void sort_by_names(contact *lptr , int index)
{
        int i=0;
        int j=0;
        contact temp;
        while(i<index)
        {
            j=0;
            while(j<index-1)
            {
                int compare =strcasecmp(lptr[j].last_name,lptr[j+1].last_name);

                if(compare > 0)
                {
                    temp = lptr[j];
                    lptr[j] = lptr[j+1];
                    lptr[j+1] = temp;
                }

                 if (compare == 0)
                 {
                     int compare =strcasecmp(lptr[j].first_name,lptr[j+1].first_name);

                        if(compare > 0)
                    {
                    temp = lptr[j];
                    lptr[j] = lptr[j+1];
                    lptr[j+1] = temp;
                    }

                        if (compare == 0)
                        {
                             int compare =strcasecmp(lptr[j].phone_number,lptr[j+1].phone_number);

                        if(compare > 0)
                            {
                                temp = lptr[j];
                                lptr[j] = lptr[j+1];
                                lptr[j+1] = temp;
                            }

                        }



                    }

                j++;
                }
            i++;
            }

    }
void sort_by_dates(contact *lptr , int index)
{
        int i=0;
        int j=0;
        contact temp;
        char date1[12];
        char date2 [12];
        while(i<index)
        {
            j=0;
            while(j<index-1)
            {
               if (strcmp(lptr[j].year,lptr[j+1].year)>0)
                {
                    temp = lptr[j];
                    lptr[j] = lptr[j+1];
                    lptr[j+1] = temp;
                    }

                 if (strcmp(lptr[j].year,lptr[j+1].year) == 0  )
                {
                    if(strcmp(lptr[j].month,lptr[j+1].month)>0)
                    {
                    temp = lptr[j];
                    lptr[j] = lptr[j+1];
                    lptr[j+1] = temp;
                    }
                    if (strcmp(lptr[j].month,lptr[j+1].month) == 0  )
                    {
                        if(strcmp(lptr[j].day,lptr[j+1].day)>0){
                         temp = lptr[j];
                    lptr[j] = lptr[j+1];
                    lptr[j+1] = temp;
                        }
                        }
                        }









                j++;
                }



            i++;
            }

    }

int sort(contact *lptr , int index)
{
    system("cls");
    printf("Press\na)Sort by last name then first then phone number\nb)Sort by date of birth\nc)Go Back");
    while(1)
    {
        char choice;
        choice = getch();

        if(choice == 'c')
            break;

        if (choice == 'a')
        {
            sort_by_names(lptr,index);
            system("cls");
            printf("Data Sorted Successfully\nPress\na)Print\nb)Retrun to Main Menue");
            char choice2;
            while(1){
            choice2 = getch();
                if(choice2 == 'b') return 0;
                if(choice2 == 'a') {print(lptr,index);return 0;}
                }
        }


        if (choice == 'b')
        {
            sort_by_dates(lptr,index);
            system("cls");
            printf("Data Sorted Successfully\nPress\na)Print\nb)Retrun to Main Menue");
            char choice2;
            while(1){
            choice2 = getch();
                if(choice2 == 'b') return 0;
                if(choice2 == 'a') {print(lptr,index);return 0;}
                }
        }

        }


    }

void search(contact p1[],int n)
{   system("cls");
    char last_name[30];
    last_name[0]= '\0' ;
    char first_name[30];
    first_name[0]= '\0' ;
    char day[30];
    day[0]= '\0' ;
    char month[30];
    month[0]= '\0' ;
    char year[30];
    year[0]= '\0' ;
    char city[30];
    city[0]= '\0' ;
    char Adress[30];
    Adress[0]= '\0' ;
    char phone[30];
    phone[0]= '\0' ;
    char email[30];
    email[0]= '\0' ;

    int i=0;

//////////////////////////////////////////////////////////////////////
    int trials =0;
    int is_valid =0;
    char temp[24];
    temp [0]= '\0';
    printf("Enter Information for contact you wish to search for , if u wish not to use a criteria in search just press enter");

     while(1)
    {
        temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nFirst name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(first_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nLast name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(last_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
         temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Day of Birth");
        }
        printf("\nDay of Birth:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_day(temp);
         if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(p1[i].day,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
         temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Month of Birth ");
        }
        printf("\nMonth of Birth: ");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_month(temp);
         if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(p1[i].month,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
         temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Year of Birth");
        }
        printf("\nYear of Birth:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_year(temp);
         if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(p1[i].year,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

//    while(1)
//    {
//        temp [0]= '\0';
//        if(trials){
//            system("cls");
//        printf("Invalid Entry , Please Input a valid Date of Birth in DD-MM-YYYY format");
//        }
//        printf("\nDate of Birth DD/MM/YYYY:");
//        scanf("%[^\n]",&temp);
//        while ((getchar()) != '\n');
//        is_valid = validate_date(temp);
//        if (temp[0] == '\0') is_valid = 1;
//        if (is_valid) {strcpy(date,temp);break;}
//        else trials ++;
//    }
//
//    trials =0;
//    is_valid =0;
//
//    while(1)
//    {
//        temp [0]= '\0';
//        if(trials){
//            system("cls");
//        printf("Invalid Entry , Please Input a valid City Name");
//        }
//        printf("\nCity:");
//        scanf("%[^\n]",&temp);
//        while ((getchar()) != '\n');
//        is_valid = validate_city(temp);
//        if (temp[0] == '\0') is_valid = 1;
//        if (is_valid) {strcpy(city,temp);break;}
//        else trials ++;
//    }

    trials =0;
    is_valid =0;

    while(1)
    {
        temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Street adress Name");
        }
        printf("\nStreet Adress:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_street(temp);
        if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(Adress,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Phone Number");
        }
        printf("\nPhone Number:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_number(temp);
        if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(phone,temp);break;}
        else trials ++;
    }


    trials =0;
    is_valid =0;

    while(1)
    {
        temp [0]= '\0';
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid E-mail");
        }
        printf("\nE-mail:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_email(temp);
        if (temp[0] == '\0') is_valid = 1;
        if (is_valid) {strcpy(email,temp);break;}
        else trials ++;
    }







//////////////////////////////////////////////////////////////////////





//    ///////////////////////////////////////////////////////////////////////////////
//    printf("\nenter the last name you want to search\nInput>> ");
//    scanf("%[^\n]",&last_name);
//    while ((getchar()) != '\n');
//    printf("\nenter the first name you want to search\nInput>> ");
//    scanf("%[^\n]",&first_name);
//    while ((getchar()) != '\n');
//    printf("\nenter the Date  of birth you want to search\nInput>> ");
//    scanf("%[^\n]",&date);
//    while ((getchar()) != '\n');
//    printf("\nenter the City you want to search\nInput>> ");
//    scanf("%[^\n]",&city);
//    while ((getchar()) != '\n');
//    printf("\nenter the Adress you want to search\nInput>> ");
//    scanf("%[^\n]",&Adress);
//    while ((getchar()) != '\n');
//    printf("\nenter the phone you want to search\nInput>> ");
//    scanf("%[^\n]",&phone);
//    while ((getchar()) != '\n');
//    printf("\nenter the e-mail want to search\nInput>> ");
//    scanf("%[^\n]",&email);
//    while ((getchar()) != '\n');
//    system("cls");
//    ///////////////////////////////////////////////////////////////////////////////


    system("cls");
    for (i=0; i<n; i++)

        if (  (strcasecmp(last_name,p1[i].last_name)==0 || last_name[0] =='\0' ) && (strcasecmp(first_name,p1[i].first_name)==0 || first_name[0] =='\0' )
        && (strcasecmp(day,p1[i].day)==0 || day[0] =='\0' ) && (strcasecmp(month,p1[i].month)==0 || month[0] =='\0' ) && (strcasecmp(year,p1[i].year)==0 || year[0] =='\0' ) /*&& (strcasecmp(city,p1[i].city)==0 || city[0] =='\0' )*/
        && (strcasecmp(Adress,p1[i].street_adress)==0 || Adress[0] =='\0' ) &&(strcasecmp(phone,p1[i].phone_number)==0 || phone[0] =='\0' ) && (strcasecmp(email,p1[i].e_mail)==0 || email[0] =='\0' )   )
        {

    printf("\n--------------------------------------------");
   printf("\nLast Name:%s",p1[i].last_name);
   printf("\nFirst Name:%s ",p1[i].first_name);



     printf("\nBorn in : %d-%d-%d ",atoi(p1[i].day),atoi(p1[i].month),atoi(p1[i].year));



     //printf("\nCity:%s",p1[i].city);


     printf("\nAddress:%s",p1[i].street_adress);



     printf("\nPhone number:%s\n",p1[i].phone_number);

      printf("\nE-mail:%s\n",p1[i].e_mail);
        }
         printf("\n Printed all contacts , press any key to continue");
    getch();
    system("cls");

}
int save(char filename[] , int index, contact *lptr,int changes){
    system("cls");
    int flag =1;
    if (filename[0] == '\0')
        flag=0;
    printf("\nPress:\n");
    if (flag==1)
    printf("\na)Save in same file");
    printf("\nb)Save in a new file");
    printf("\nc)Do not Save");

    while(1){
    char choice = getch();
        if(choice == 'a' && flag == 1)
    {
        system("cls");
        FILE *fptr = fopen(filename,"w");
        int print_index=0;
        while(print_index<index){
        fprintf(fptr,"%s,", lptr[print_index].last_name);
        fprintf(fptr,"%s,", lptr[print_index].first_name);
        //fprintf(fptr,"%s,", lptr[print_index].date_of_birth);
        fprintf(fptr,"%s-", lptr[print_index].day);
        fprintf(fptr,"%s-", lptr[print_index].month);
        fprintf(fptr,"%s,", lptr[print_index].year);
        fprintf(fptr,"%s,", lptr[print_index].street_adress);
        //fprintf(fptr,"%s,", lptr[print_index].city);
        fprintf(fptr,"%s,", lptr[print_index].e_mail);
        fprintf(fptr,"%s", lptr[print_index].phone_number);
        fprintf(fptr,"\n");
        print_index++;
        }

        printf("\nFile successfuly saved");
        printf("\nPress any key to continue");
        fclose(fptr);
        getch();
        return 0;
        }

    if (choice == 'b') {

        system("cls");
        printf("What name should be given to new file (please include extenstion ex:contacts.txt)");
        char file_name[20];
        printf("\nInput>> ");
        scanf("%s",file_name);
        strcpy(filename,file_name);
        FILE *fptr2;
        fptr2 = fopen(file_name,"a");
        int print_index=0;
        while(print_index<index){
        fprintf(fptr2,"%s,", lptr[print_index].last_name);
        fprintf(fptr2,"%s,", lptr[print_index].first_name);
        //fprintf(fptr2,"%s,", lptr[print_index].date_of_birth);
        fprintf(fptr2,"%s-", lptr[print_index].day);
        fprintf(fptr2,"%s-", lptr[print_index].month);
        fprintf(fptr2,"%s,", lptr[print_index].year);

        fprintf(fptr2,"%s,", lptr[print_index].street_adress);
        //fprintf(fptr2,"%s,", lptr[print_index].city);
        fprintf(fptr2,"%s,", lptr[print_index].e_mail);
        fprintf(fptr2,"%s", lptr[print_index].phone_number);
        fprintf(fptr2,"\n");
        print_index++;
        }
        fclose(fptr2);
        printf("\nFile by name %s successfuly created and saved",file_name);
        printf("\nPress any key to continue");
        getch();
        system("cls");
        return 0;
        }
     if (choice == 'c') {system("cls");
    return changes;}
    }
}


int quit(int changes,char filename[] , int index, contact *lptr){
    system("cls");
    if (changes == 0)
        return -1;
    else {
        printf("Some changes have not yet been saved\nPress\na)Save Changes\nb)Dont save and Quit\nc)Go Back");
        while(1){
        char choice = getch();
        if (choice == 'a')
            {changes = save(filename,index,lptr,changes);
            return -1;
            }


        if (choice == 'b')
            return -1;

        if (choice == 'c')
            return changes;



            }
        }

    return 0;
    }


int read_file(contact *lptr , FILE *fptr )
{
    int index=0;
    if (fptr == NULL) // no file was found
        return index;
    while(!feof(fptr)){

        fscanf(fptr,"%[^,],", &lptr[index].last_name);
        fscanf(fptr,"%[^,],", &lptr[index].first_name);
        //fscanf(fptr,"%[^,],", &lptr[index].date_of_birth);
        fscanf(fptr,"%[^-]-", &lptr[index].day);
        fscanf(fptr,"%[^-]-", &lptr[index].month);
        fscanf(fptr,"%[^,],", &lptr[index].year);
        fscanf(fptr,"%[^,],", &lptr[index].street_adress);
        //fscanf(fptr,"%[^,],", &lptr[index].city);
        fscanf(fptr,"%[^,],", &lptr[index].e_mail);
        fscanf(fptr,"%s", &lptr[index].phone_number);
        fscanf(fptr,"\n", NULL);
        index++;

}
    fclose(fptr);
    return index;
    }

void print(contact *p1,int n)
{int i;
  system("cls");
    for(i=0;i<n;i++)
    {

   printf("\n--------------------------------------------");
   printf("\nLast Name:%s",p1[i].last_name);
   printf("\nFirst Name:%s ",p1[i].first_name);



     printf("\nBorn in : %d-%d-%d ",atoi(p1[i].day),atoi(p1[i].month),atoi(p1[i].year));


     //printf("\nCity:%s",p1[i].city);


     printf("\nAddress:%s",p1[i].street_adress);



     printf("\nPhone number:%s",p1[i].phone_number);

      printf("\nE-mail:%s\n",p1[i].e_mail);

    }
    printf("\n Printed all contacts , press any key to continue");
    getch();
    system("cls");
}
FILE *open_folder(char filename[])
    {
    printf("--------------------------");
    printf("\nWelcome to Phonebook\n");
    printf("--------------------------");
    printf("\npress any key to continue");
    getch();
    system("cls");
    FILE *fptr=NULL;
    char file_name [60];
    int flag=0;

    while(1){
        flag =0;
        system("cls");
        printf("Do you have a file u wish to open ?\nPress\na)Yes\nb)No");
         char choice2 =getch();
        if (choice2 == 'b'){
            system("cls");
            return fptr;}

        while(1)
        {


        if(choice2 == 'a')
        {
            system("cls");
            printf("Please Enter File Name:\n");
            printf("Input>> ");
            scanf("%s",file_name);
            while ((getchar()) != '\n');
            strcpy(filename,file_name);
            system("cls");

            fptr = fopen(file_name,"r");
            if (fptr == NULL)
            {
                printf("file not found \nPress\na)Go back\nb)Enter file name again");
                while(1){

                char choice = getch();
                if (   choice == 'a')
                {
                    flag=1;
                    break;
                    }
            if (choice == 'b') {system("cls");break;}}
            if (flag==1) break;


            }
            else {
                printf("%s successfully opened",file_name);
                printf("\nPress any key to go to main menue ");
                getch();
                system("cls");
                return fptr;    }
        }
        else break;
        }
    }
    printf("\nPress any key to go to main menue ");
    getch();
    system("cls");
    return fptr;
    }


int Delete(contact p[],int *n)
{
    system("cls");
    int changes =0;
    char f[30];
    char l[30];
    int j, i,count=0;
    printf("\nenter the first name and the last name you want to delete their data\n");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    int trials =0;
    int is_valid =0;
    char temp[24];

     while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nFirst name:");
        scanf("%[^\n]",&temp);
      while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(f,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nLast name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(l,temp);break;}
        else trials ++;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////
//    printf("\nenter the first name: ");
//    scanf("%s",&f);
//    printf("\nenter the last name: ");
//    scanf("%s",&l);

    for(i=0; i<*n; i++)
    {
         system("cls");
        if(((strcasecmp(l,p[i].last_name))==0)&&(strcasecmp(f,p[i].first_name))==0)
        {
            system("cls");
    printf("\n--------------------------------------------");



    printf("\nLast Name:%s",p[i].last_name);
   printf("\nFirst Name:%s ",p[i].first_name);



     printf("\nBorn in : %d-%d-%d ",atoi(p[i].day),atoi(p[i].month),atoi(p[i].year));


     //printf("\nCity:%s",p[i].city);


     printf("\nAddress:%s",p[i].street_adress);



     printf("\nPhone number:%s\n",p[i].phone_number);

      printf("\nE-mail:%s\n",p[i].e_mail);
      printf("\n--------------------------------------------");
      printf("\n\nA match was found , Do u wish to Delete\nPress:\na)Delete\nb)Do not Delete");
      char choice = getch();
      while(1){
    if (choice == 'a'){
            *n=*n-1;
            for(j=i; j<*n; j++)
            {
                p[j]=p[j+1];
            }
            changes +=1;
            i=i-1;
            break;
    }
    else if  (choice == 'b'){break;}
        }
        }
    }

    system("cls");
    printf("\nFinished Processing Data , Press any key to continue");
    getch();

    return changes;
    }
void add_contact(contact  p[],int*n)
{
    system("cls");
    int x,i;
    char temp[24];
    int is_valid=0;
    int trials =0;
//    printf("Enter how many persons you want to add: ");
//    scanf("%d",&x);


    while(1)
    {
        system("cls");
        if(trials)
            printf("Invalid Entry , Please input a valid Number\n");
        printf("Enter how many persons you want to add: ");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_normal_number(temp);
        if (is_valid) break;
        else trials ++;
    }

    x = atoi(temp);

        for (i=*n;i<*n+x;i++)
    {
    system("cls");

    trials =0;
    is_valid =0;
    printf("Enter Information for contact number %d",i-*n+1);

     while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nFirst name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(p[i].first_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nLast name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(p[i].last_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Day of Birth");
        }
        printf("\nDay of Birth:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_day(temp);
        if (is_valid) {strcpy(p[i].day,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Month of Birth ");
        }
        printf("\nMonth of Birth: ");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_month(temp);
        if (is_valid) {strcpy(p[i].month,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Year of Birth");
        }
        printf("\nYear of Birth:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_year(temp);
        if (is_valid) {strcpy(p[i].year,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;
//    while(1)
//    {
//        if(trials){
//            system("cls");
//        printf("Invalid Entry , Please Input a valid Date of Birth in DD/MM/YYYY format");
//        }
//        printf("\nDate of Birth DD-MM-YYYY:");
//        scanf("%[^\n]",&temp);
//        while ((getchar()) != '\n');
//        is_valid = validate_date(temp);
//        if (is_valid) {strcpy(p[i].date_of_birth,temp);break;}
//        else trials ++;
//    }
//
//    trials =0;
//    is_valid =0;

//    while(1)
//    {
//        if(trials){
//            system("cls");
//        printf("Invalid Entry , Please Input a valid City Name");
//        }
//        printf("\nCity:");
//        scanf("%[^\n]",&temp);
//        while ((getchar()) != '\n');
//        is_valid = validate_city(temp);
//        if (is_valid) {strcpy(p[i].city,temp);break;}
//        else trials ++;
//    }
//
//    trials =0;
//    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Street adress Name");
        }
        printf("\nStreet Adress:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_street(temp);
        if (is_valid) {strcpy(p[i].street_adress,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Phone Number");
        }
        printf("\nPhone Number:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_number(temp);
        if (is_valid) {strcpy(p[i].phone_number,temp);break;}
        else trials ++;
    }


    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid E-mail");
        }
        printf("\nE-mail:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_email(temp);
        if (is_valid) {strcpy(p[i].e_mail,temp);break;}
        else trials ++;
    }



    }
    *n=*n+x;
}
int Modify(contact p[],int n)
{
    system("cls");
    int changes =0;
    char l[20];
    int i;

///////////////////////////////////////////////////////////////
printf("enter the last name  of contact you want to Modify");
int trials =0;
    int is_valid =0;
    char temp[24];

     while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nLast name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(l,temp);break;}
        else trials ++;
    }
////////////////////////////////////////////////


for (i=0;i<n;i++)
{   system("cls");

    if(strcasecmp(l,p[i].last_name)==0)
    {
        while(1){
    system("cls");
    printf("\n--------------------------------------------");
   printf("\nLast Name:%s",p[i].last_name);
   printf("\nFirst Name:%s ",p[i].first_name);



    printf("\nBorn in : %d-%d-%d ",atoi(p[i].day),atoi(p[i].month),atoi(p[i].year));


     printf("\nAddress:%s",p[i].street_adress);



     printf("\nPhone number:%s\n",p[i].phone_number);

      printf("\nE-mail:%s\n",p[i].e_mail);
      printf("\n--------------------------------------------");

    printf("\nA match was found , Do u wish to modify\nPress:\na)Modify\nb)Do not Modify");
      char choice = getch();
    if (choice == 'a')
    {
    printf("\n\nEnter new information of contact:");
/////////////////////////////////////////////////////////////
    trials =0;
    char temp[24];
    is_valid =0;

     while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nFirst name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(p[i].first_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Name");
        }
        printf("\nLast name:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_name(temp);
        if (is_valid) {strcpy(p[i].last_name,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Day of Birth");
        }
        printf("\nDay of Birth:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_day(temp);
        if (is_valid) {strcpy(p[i].day,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Month of Birth ");
        }
        printf("\nMonth of Birth");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_month(temp);
        if (is_valid) {strcpy(p[i].month,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Year of Birth");
        }
        printf("\nYear of Birth: ");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_year(temp);
        if (is_valid) {strcpy(p[i].year,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Street adress Name");
        }
        printf("\nStreet Adress:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_street(temp);
        if (is_valid) {strcpy(p[i].street_adress,temp);break;}
        else trials ++;
    }

    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid Phone Number");
        }
        printf("\nPhone Number:");

        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_number(temp);
        if (is_valid) {strcpy(p[i].phone_number,temp);break;}
        else trials ++;
    }


    trials =0;
    is_valid =0;

    while(1)
    {
        if(trials){
            system("cls");
        printf("Invalid Entry , Please Input a valid E-mail");
        }
        printf("\nE-mail:");
        scanf("%[^\n]",&temp);
        while ((getchar()) != '\n');
        is_valid = validate_email(temp);
        if (is_valid) {strcpy(p[i].e_mail,temp);break;}
        else trials ++;
    }


    changes +=1;
    break;
    }
   if (choice =='b') {break;}
    }

    }


}
printf("\nFinished Processing Data ,Press any key to continue");
getch();
system("cls");
return changes;
}



int main()
{
	//-------------------------------------------------------------------------------------------------------------------------------------
    // first we initialise the variables we need

    contact list [100]; // array of structs of contacts
    contact *lptr;  // pointer pointing to array of structs of contacts
    lptr=&list;    // get each pointer to point to its correspondig struct

    int index =0;   // index
    int * iptr =&index;   // pointer to index

    int changes =0;   // variable changes , need to check if there are changes made befroe quitting in order to tell user to save
    int * cptr =&changes;   // pointer to change

    char filename [60];   // saves name of file we wish to open
    filename[0] = '\0' ;  // sets first elemnt to \0 instead of having garbage




    FILE *fptr;  // pointer to the file that we will use

    // All variables are now initialised
    //-------------------------------------------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------------------------------------------
    // now to open file and store data in our struct array

    fptr = open_folder(filename);  // this opens file and puts it in fptr , if no file is opened the fptr has NULL value , so fptr == NULL is true
    index = read_file(lptr , fptr);  // this reads data from file , puts it in struct , then returns the index

    // finally we loaded the file
    //-------------------------------------------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------------------------------------------
    // now lets begin our code
    while(1)
    {
            printf("\n----------");
            printf("\nMain Menue");
            printf("\n----------");
            printf("\nPress:\na)Add Contact\nb)Print all Contacts\nc)Search\nd)Modify\ne)Delete\nf)Save\ns)Sort\nq)Quit");

            char choice = getch();   // gets the letter pressed by user on keyboard and saves it in choice

            if (choice == 'a')   // if the user pressed a this means that he wants to add a contact
            {
                add_contact(lptr,iptr);   // calls Rashads function to add contact
                changes = 1;  // this means that changes have been made since new contacts have been made , doesnt matter how many changes have been made , changes is either 0 for nochanges or 1 for changes made
                }

            if (choice == 'b')   // if the user pressed b this means that he wants to print all contact
            {
                print(lptr,index);   // calls Rashads function to print contacts
                }

            if (choice == 'c')   // if the user pressed c this means that he wants to search
            {
                search(lptr,index);   // calls Abdos function to search contacts
                }

            if (choice == 'd')   // if the user pressed d this means that he wants to Modify
            {
                changes = Modify(lptr,index);   // calls Rashads function to Modify contacts , also Modify returns a value greater than 0 if any contacts are modified
                }

            if (choice == 'e')   // if the user pressed e this means that he wants to Delete
            {
                changes = Delete(lptr,iptr);   // calls Abdos function to Delete contacts , also Delete returns a value greater than 0 if any contact was deleted
                }


            if (choice == 'f')   // if the user pressed f this means that he wants to Save
            {
                changes = save(filename,index,lptr,changes);   // calls the save function , return a value of 0 if user saved
                }

             if (choice == 'q')   // if the user pressed q this means that he wants to Quit
            {
                changes = quit(changes,filename,index,lptr);   // calls the quit function , return a value of 0 if user saved , and -1 if user wants to quit
                if (changes == -1)
                    {system("cls");break;} // gets out of loop end program
                }

            if (choice == 's')   // if the user pressed s this means that he wants to Sort
            {
                sort(lptr,index);
                }



        system("cls");  // this deletes everything off our screen
        }
    // this ends our code
    //-------------------------------------------------------------------------------------------------------------------------------------
	return 0;
}

