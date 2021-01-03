#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char pw[10];
struct node
{
    int k;
    char date[30],time [15],name[25],place[40],duration[10],note[500];
    ///FILE *s1;
    ///int age;
    struct node *next;
};
struct node *curr=NULL,*head=NULL,*last=NULL,*var=NULL;
void feedback()
{
     FILE *fb;
    char coment[250];
    fb=fopen("FEEDBACK.txt","a");
    printf("\n\t\tENTER YOUR FEEDBACK:");
    fflush(stdin);
    gets(coment);
    fprintf(fb,"\n%s\n",&coment);

    fclose(fb);
    fb=fopen("FEEDBACK.txt","a");
    fscanf(fb,"%s",&coment);
   // printf("\n\t\t%s",coment);
   printf("\n\n\n\t\t\tTHANK YOU FOR YOUR FEEDBACK!\n\n\n");
   /// fscanf(fb,"%s",&coment);
    fclose(fb);
}

void password()
{


    char s1[10]="humayra";

     FILE *pw;
    char pass[40];
    pw=fopen("projectpassword.txt","w");
    fprintf(pw,"humayra");
    fclose(pw);

    printf("\n\t\tTO UNLOCK THE DIARY PLEASE ENTER THE PASSWORD!");
    printf("\n\n\t\t\t\tPASSWORD:");
    fflush(stdin);
    gets(pw);

    if(strcmp(s1,pw)==0)
    {
        system("cls");
        all_cases();
    }
    else
    {
        printf("\n\n\t\t\tPASSWORD IS INCORRECT!\n\n\t\t\tPLEASE TRY AGAIN LATER!\n\n\n");
    }
}
int main()
{
    password();
    return 0;
}
void delete()
{
    int k;
    if(curr==NULL)
    {
        printf("\n\t\t\tRECORD LIST EMPTY\n\t\t\tFOR EDIT PLEASE STORE SOME RECORDS!\n\n\t\t\tTHANK YOU...!!!\n\n");
    }
    else
    {
        var=head;
        int sv,i,a=0;
        printf("\n\t\tWHICH RECORD YOU WANT TO DELETE?\n\t\tPLEASE ENTER THE RECORD SERIAL:");
        fflush(stdin);
        scanf("%d",&sv);
        while(var!=NULL)
        {
            a++;
            if(var->k==sv)
            {
                printf("\n\t\tRECORD IS DELETED SUCCESSFULLY!\n");
                break;

            }
            var=var->next;
        }
        if(a==1)
        {
            head=var->next;
            free(var);
            return;
        }
        else
        {
            var=head;
            for(i=1;i<a-1;i++)
            {
                var=var->next;
            }
            curr=var->next;
            var->next=curr->next;
        }
    }
}
void search()

{
    int sedt;
    printf("\n\t\tHOW DO YOU WANT TO SEARCH?\n\t\t__________________________\n\n\t\t\t1.BY YOUR RECORD SERIAL\n\t\t\t2.BY YOUR RECORD DATE\n\n");
    printf("\n\t\tIF YOU WANT TO SEARCH BY SERIAL PRESS 1\n\t\t IF YOU WANT TO SEARCH BY DATE PRESS 2: ");
    fflush(stdin);
    scanf("%d",&sedt);
    if(sedt==1){
    if(curr==NULL)
    {
        system("cls");
        printf("\n\t\tRECORD LIST IS EMPTY!\n\t\tPLEASE STORE SOME RECORD AND THEN SEARCH!\n\n\t\t\tTHANK YOU!\n\n\n");
    }
    else
    {

        var=head;
        int sv,check=0;
         printf("\n\t\tTO SEARCH RECORD ENTER THE RECORD SERIAL:\n\t\t________________________________________\n\n ");
            ///search();
        printf("\n\t\tPLEASE ENTER THE RECORD NUMBER:");
        fflush(stdin);
        scanf("%d",&sv);
        while(var!=NULL)
        {
            if(var->k==sv)
            {
                check++;
                break;
            }
            var=var->next;
        }
        if(check!=0)
        {
            printf("\n\t\tRECORD NUMBER %d IS:\n\t\t_________________\n\n\t\tDATE:%s\n\t\tTIME: %s\n\t\tMEETING WITH: %s\n\t\tMEETING AT: %s\n\t\tDURATION: %s\n\t\tNOTE: %s\n\n",sv,var->date,var->time,var->name,var->place,var->duration,var->note);
        }
        else
        {
            printf("\n\t\tENTER VALID RECORD SERIAL!\n\n\t\t\tTHANK YOU!\n\n");
        }
    }
    }
    if(sedt==2)
    {
        if(curr==NULL)
        {
            system("cls");
            printf("\n\t\tRECORD LIST IS EMPTY!\n\t\tPLEASE STORE SOME RECORD AND THEN SEARCH!\n\n\t\t\tTHANK YOU!\n\n\n");
        }
        else
        {
            char date[10];
            var=head;
        int check=0;
        char sd[10];
         printf("\n\t\tTO SEARCH RECORD ENTER THE RECORD DATE:\n\t\t________________________________________\n\n ");
            ///search();
        printf("\n\t\tPLEASE ENTER THE RECORD DATE:");
        fflush(stdin);
        ///scanf("%c",&sd);
        gets(sd);
        while(var!=NULL)
        {
             if(strcmp(var->date,sd)==0)
             {
                 check++;
                 break;
             }
             var=var->next;
        }
        if(check!=0)
        {
             printf("\n\t\tRECORD NUMBER %d IS:\n\t\t_________________\n\n\t\tDATE:%s\n\t\tTIME: %s\n\t\tMEETING WITH: %s\n\t\tMEETING AT: %s\n\t\tDURATION: %s\n\t\tNOTE: %s\n\n",var->k,sd,var->time,var->name,var->place,var->duration,var->note);

        }
        else
        {
              printf("\n\t\tENTER VALID RECORD DATE!\n\n\t\t\tTHANK YOU!\n\n");
        }
        }
    }

}

void display()
{
    if(curr==NULL)
    {
        printf("\n\t\t\tRECORD LIST IS EMPTY....!!!\n");
    }
    else
    {
        var=head;
        while(var!=NULL)
        {
            printf("\n\t\tAll stored records are displayed below:\n\t\t______________________________________\n\n");
            printf("\n\t\tRECORD NUMBER: %d\n\t\t_______________\n\n\t\tDATE:%s\n\t\tTIME:%s\n\t\tMEETING WITH:%s\n\t\tMEETING AT:%s\n\t\tDURATION:%s\n\t\tNOTE:%s\n\n",var->k,var->date,var->time,var->name,var->place,var->duration,var->note);
            var=var->next;
        }
    }
}

void all_cases()
{
    ///password();
    ///system("cls");

    char ch;
    X:
    printf("\n\n\t\t**********************************************\n\t\t*WELCOME TO PASSWORD PROTECTED PERSONAL DIARY*\n\t\t**********************************************\n\n\n");
    printf("\t\t\t\t  MAIN MENU:\n\t\t\t\t_____________\n\n\n\t\t1.ABOUT PASSWORD PROTECTED PERSONAL DIARY\n\t\t2.ADD RECORD\n\t\t3.VIEW RECORD\n\t\t4.DELETE RECORD\n\t\t5.SEARCH RECORD\n\t\t6.FEEDBACk\n\t\t7.EXIT\n\n");
   printf("\n\t\tEnter your choice:");
   scanf("%d",&n);
   switch(n)
   {


   case 2:
       {

    A:
        system("cls");
    curr=(struct node*)malloc(sizeof(struct node));
    printf("\n\t\t**************************\n\t\t*WELCOME TO THE ADD MENU*\n\t\t***************************");
    printf("\n\n\n\t\tRECORD NUMBER:");
    fflush(stdin);
    scanf("%d",&curr->k);
    printf("\t\t______________");
    printf("\n\n\t\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");
    fflush(stdin);
    gets(curr->date);
    printf("\t\tENTER TIME:[hh:mm]:");
    fflush(stdin);
    gets(curr->time);
    printf("\t\tENTER NAME:");
    fflush(stdin);
    gets(curr->name);
    printf("\t\tENTER THE NAME OF PLACE: ");
    fflush(stdin);
    gets(curr->place);
    printf("\t\tENTER DURATION:");
    fflush(stdin);
    gets(curr->duration);
    printf("\t\tNOTE:");
    fflush(stdin);
    gets(curr->note);
    if(head==NULL)
    {
        head=curr;
    }
    else{last->next=curr;
    }
    last=curr;
    last->next=NULL;
    printf("\n\t\tYour record is saved successfully!\n\n");
    printf("\t\tDo you Want to add more notes?\n");
    printf("\t\tIf yes press (Y/y) and If you want to go main menu press (M/m):");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        system("cls");
        goto A;
    }
  if(ch=='m'||ch=='M')
    {
        system("cls");
         ///printf("\n\t\tRECORD LIST IS EMPTY.......!!!");
      goto X;
    }

}

   case 3:

       {
           B:
           system("cls");
           printf("\n\t\t\t************************\n\t\t\t*WELCOME TO DISPLAY MENU*\n\t\t\t*************************\n\n");
           ///display();
           ///printf("\n\t\tAll stored records are displayed below:\n\n");
           display();
           printf("\n\t\tDo You want to continue?");
          printf("\n\t\tIF YES PRESS (Y/y) AND IF YOU WANT TO GO MAINMENU PRESS (M/m):");
          B1:
         fflush(stdin);
          scanf("%c",&ch);
          if(ch=='y'||ch=='Y')
          {
              system("cls");
              goto B;
          }
          if(ch=='m'||ch=='M')
          {
              system("cls");
              goto X;
          }


       }
   case 4:
    {
        C:
            system("cls");
            printf("\n\t\t\t************************\n\t\t\t*WELCOME TO DELETE MENU*\n\t\t\t************************\n\n");
            delete();
            C1:
                printf("\n\t\tDO YOU WANT TO DELETE MORE RECORDS?");
                printf("\n\t\tIF YES PRESS Y AND IF YOU WANT TO GO MAINMENU PRESS (M/m):");
                fflush(stdin);
                scanf("%c",&ch);
                if(ch=='y'||ch=='Y')
                {
                    system("cls");
                    goto C;
                }
                if(ch=='M'||ch=='m')
                {
                    system("cls");
                    goto X;
                }

    }
   case 5:

    {
        D:
            system("cls");
            printf("\n\t\t\t************************\n\t\t\t*WELCOME TO SEARCH MENU*\n\t\t\t*************************\n\t\t\t");
            search();
          D1:
              printf("\n\t\tDO YOU WANT TO SEARCH MORE RECORDS?");
              printf("\n\t\tIF YES PRESS (Y/y) AND IF YOU WANT TO GO MAINMENU PRESS (M/m):");
              fflush(stdin);
              scanf("%c",&ch);
              if(ch=='y'||ch=='Y')
              {
                  system("cls");
                  goto D;
              }
              if(ch=='m'||ch=='M')
              {
                  system("cls");
                  goto X;
              }

    }

   case 7:
       {
           system("cls");
           printf("\n\n\t\t\tDIARY IS CLOSED!\n\n\n\n\n\n\n ");
           break;
       }
   case 1:
    {
        O:
            system("cls");
            FILE *abt;
            abt=fopen("ABOUT.txt","r");
            printf("\n\t\t\t*****************************************\n\t\t\t*ABOUT PASSWORD PROTECTED PERSONAL DIARY*\n\t\t\t*****************************************\n\n\n");
        fprintf(abt,"\n\t\t\t*****************************************\n\t\t\t*ABOUT PASSWORD PROTECTED PERSONAL DIARY*\n\t\t\t*****************************************\n\n\n");
        ///fclose(abt);
        printf("\n\tThis software is like a digital diary.user can keep their personal  ");
        fprintf(abt,"This software is like a digital diary.user can keep their personal  ");
        ///fclose(abt);
        printf("\t\trecord like they do in a diary.You can keep records of the important");
        fprintf(abt,"\n\t\t\t\tmrecord like they do in a diary.You can keep records of the important");
        ///fclose(abt);
        printf("\t\tthings you do in your daily life,like meetings and various other tasks.");
        fprintf(abt,"\n\t\t\t\tthings you do in your daily life,like meetings and various other tasks.");
        ///fclose(abt);
        printf("\t\tIn this diary,you need to enter a password to view,edit or delete ");
        fprintf(abt,"\n\t\t\t\tIn this diary,you need to enter a password to view,edit or delete ");
        printf(" \t\trecord.Records can be added with many information such as duration ");
        fprintf(abt,"\n\t\t\t\t record.Records can be added with many information such as duration ");
       /// fclose(abt);
       printf("\n\tof task ,name address,time and date.\n\n\n");
        fprintf(abt,"\n\t\t\t\tof task ,name address,time and date.\n\n\n");
        fclose(abt);
        O1:
            printf("\n\t\tTO CONTINUE AND GO BACK TO MAINMENU PRESS (M/m):");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='m'||'M')
            {
                system("cls");
                goto X;
            }


    }
   case 6:
    {
        G:
        system("cls");
        ///printf("\n\t\tFEEDBACK:");
         feedback();
       G1:
           printf("\n\t\tDO YOU WANT TO GIVE SOME MORE FEEFBACK?\n");
           printf("\n\t\tIF YES PRESS (Y/y) AND TO GO TO MAINMENU PRESS (M/m):");
           fflush(stdin);
              scanf("%c",&ch);
              if(ch=='y'||ch=='Y')
              {
                  system("cls");
                  goto G;
              }
              if(ch=='m'||ch=='M')
              {
                  system("cls");
                  goto X;
              }
    }


   }
   }
