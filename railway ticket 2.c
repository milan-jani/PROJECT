#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>


struct detail
{
    int train_no;
    char name[20];
    int seats;
    char coach[20];
    char berth[20];
    int fare;

}d;

/**********************************************PASSENGER DETAIL******************************************************************/

void passenger()
{

    printf("enter train no.:");
    scanf("%d",&d.train_no);
    printf("\nenter your name:");
    scanf("%s",&d.name);
    printf("\nenter no. of seats:");
    scanf("%d",&d.seats);
    printf("\nsleeper or AC:");
    scanf("%s",&d.coach);
    printf("\npreferred berth:");
    scanf("%s",&d.berth);
    charge();

    /*else
       {

       } printf("Sorry,Train Is Not Available!!");
       printf("press enter to retry");
       getch();
       goto back;*/



}
 /*************************************************WELCOME****************************************************************/
void welcome()
{

    printf("\t\t=================================================\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|           |  By Milan Jani  |                 |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t=================================================\n\n\n");


    printf("press any key to continue...");
    getch();
    system("cls");
    login();


}

/**********************************************MENU CHOICE******************************************************************/

main()
{

     welcome();
     reserve:

    system("cls");
    printf("\n=================================\n");
    printf("    TRAIN RESERVATION SYSTEM");
    printf("\n=================================\n");
    printf("1)Book ticket");
    printf("\n=================================\n");
    printf("2)cancel ticket");
    printf("\n=================================\n");
    printf("3)exit");
    printf("\n=================================\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        reservation();
        break;
    case 2:cancel();
        break;
    case 3:
        return(0);
        break;
    default:
        printf("invalid choice");

    }
goto reserve;


}

/**********************************************RESERVATION******************************************************************/


void reservation()

{ system("cls");


    printf("=================================\n");
    printf("            RESERVATION          \n");
    printf("=================================\n");
    availability();
    passenger();
    print();




}

/**********************************************AVAILIBILITY******************************************************************/


void availability()
{
    printf("Trains from RAJKOT to AHMEDABAD\n");
    printf("==============================================================================\n");
    printf("TRAIN NO.\t   NAME\t\t\tDEPARTURE\tARRIVAL\t\tFARE\n");
    printf("==============================================================================\n");
    printf("22958\t\tSOMNATH EXP\t\t 01:23\t\t05:40\t\t175\n");
    printf("19016\t\tSAURASHTRA EXP\t\t 02:52\t\t07:20\t\t200\n");
    printf("22960\t\tINTERCITY EXP\t\t 06:07\t\t10:30\t\t150\n");
    printf("22926\t\tADI VANDE BHARAT\t 06:40\t\t10:10\t\t800\n");
    printf("12268\t\tMMCT DURONTO EXP\t 21:20\t\t01:05\t\t415\n");
    printf("12263\t\tvande bharat 1\t\t 22:10\t\t11:05\t\t915\n");
    printf("12261\t\tvande bharat 2\t\t 10:10\t\t02:05\t\t1000\n\n");



}


/**********************************************PRINT TICKET******************************************************************/



void print()
{
system("cls");
	printf("-----------------------------\n");
	printf("\tTICKET PREVIEW\n");
	printf("-----------------------------\n\n");
	printf("Name:\t\t\t%s",d.name);
	printf("\ntrain no.:\t\t%d",d.train_no);
	printf("\nNo. of seats:\t\t%d",d.seats);
    printf("\ncoach:\t\t\t%s",d.coach);
	printf("\nberth:\t\t\t%s",d.berth);
	printf("\nfare:\t\t\t%d",d.fare);
    printf("\n\ndo you want to confirm ticket?(y/n)");
    char r;
    FILE *fp;
    fp=fopen("ticket.txt","a");
    scanf("\n%c",&r);
    if(r=='y')
    {

    fprintf(fp,"%s\t\t%d\t\t%d\t%s\t\t%s\t   %d\n",&d.name,d.train_no,d.seats,&d.coach,&d.berth,d.fare);

    printf("\nBOOKING TIME IS:");
    t();

     printf("\nRESERVATION DONE\n");
     printf("press any key to go back to menu...");
     getch();


    }
    else
    {
        printf("RESERVATION IS NOT DONE!!\n\n");
        printf("enter any key to go back to menu:");
        getch();
    }
    fclose(fp);

}

/**********************************************TICKET AMOUNT******************************************************************/

void charge()
{
    if(d.train_no==22958)
    {
        d.fare=(d.seats*175);
    }
    if(d.train_no==19016)
    {
        d.fare=(d.seats*200);
    }
    if(d.train_no==22960)
    {
        d.fare=(d.seats*150);
    }
    if(d.train_no==22926)
    {
        d.fare=(d.seats*800);
    }
    if(d.train_no==12268)
    {
        d.fare=(d.seats*415);
    }
     if(d.train_no==12263)
    {
        d.fare=(d.seats*915);
    }
     if(d.train_no==12261)
    {
        d.fare=(d.seats*1000);
    }
}

/**********************************************CANCELLATION******************************************************************/

void cancel()
{   system("cls");
    printf("==============================\n");
    printf("        CANCELLATION MENU    \n");
    printf("==============================\n");


  FILE *fp, *fp1;
  fp=fopen("ticket.txt","r");
  fp1=fopen("temp.txt","w");

  char n[100];

  printf("enter your name:");
  scanf("%s",&n);



  while(fscanf(fp,"%s\t\t%d\t\t%d\t%s\t\t%s\t   %d\n",&d.name,&d.train_no,&d.seats,&d.coach,&d.berth,&d.fare)!=EOF)
{
    if(strcmp(d.name,n)!=0)
    {
        fprintf(fp1,"%s\t\t%d\t\t%d\t%s\t\t%s\t   %d\n",d.name,d.train_no,d.seats,d.coach,d.berth,d.fare);
    }
}
    fclose(fp);
    fclose(fp1);
    remove("ticket.txt");
    rename("temp.txt","ticket.txt");
    //printf("data removed");

  printf("\nTICKET CANCELLED\n");
  printf("enter any key to go back to menu:");
  getch();

}

/******************************************TIME******************************************************************************/


void t()
	{
		time_t mytime;
     mytime = time(NULL);
		printf(ctime(&mytime));

		return 0;
	}



/**************************************LOGIN FORM*****************************************************************************/
void login()
{
    char user[10]="user";
    int  pass[10]= {1,0,1,1};
    char uname[10],c;
    char pword[10];
    system("cls");
login:
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf("\n                           USERNAME:-");
    scanf("%s",&uname);
    printf("\n                           PASSWORD:-");

    int i;
    for(i=0; i<4; i++)
    {
        c = getch();
        pword[i] = c;
        c = '*' ;
        printf("%c",c);
    }
    if(strcmp(uname,"user")==0 && strcmp(pword,"1011")==0)
    {
        printf("\n\nWelcome,user successfully logged in..");
        printf("\n\npress any key to continue");
        getch();
        system("cls");
    }

    else
    {
        printf("\n\tinvalid password!!\npress any key to retry..");
        getch();
        system("cls");
        goto login;
    }

}

