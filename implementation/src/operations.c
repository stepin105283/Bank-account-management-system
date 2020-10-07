void bankpage()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t******************************************************************************************\n\n");
    printf("                                                BANK ACCOUNT MANAGEMENT SYSTEM                                      \n\n");
    printf("\t\t******************************************************************************************\n\n\n");
    printf("Press any key to access the system:\n");
    getch();
    menu_page();
}
void menu_page()
{
    system("cls");
    int choice;
    printf("\n\n");
    printf("\t\t\t\t\t***********************************\n");
    printf("\t\t\t\t\t                  MENU PAGE             \n");
    printf("\t\t\t\t\t***********************************\n\n");
    printf("1.Open an account\n");
    printf("2.Deposit money into an account\n");
    printf("3.Withdraw money from an account\n");
    printf("4.Get account details\n");
    printf("5.Close an account\n");
    printf("0.Exit\n");
    printf("\n\nEnter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            open();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            details();
            break;
        case 5:
            close();
            break;
        case 0:
            printf("\n\n\t\t\tTHANK YOU FOR USING THE SYSTEM\n\n");
            exit(1);
        default:
            {
                printf("\n\n\t\t\t\tYOUR CHOICE IS NOT VALID!!Try again.Press any key to continue....");
                getch();
                menu_page();
            }

    }
}
void back_page()
{
    int choice;
    fflush(stdin);
    printf("\n\n\nEnter 1 to return to menu page or Enter 0 to exit ...");
    scanf("%d",&choice);
    if(choice==1)
    {
        menu_page();
    }
    else if(choice==0)
    {
        exit(1);
    }
    else
    {
        printf("\nINVALID CHOICE!!!Try again.Press any key....");
        back_page();
    }
}
void open()
{
    system("cls");
    printf("\n\t\t\t********************OPEN AN ACCOUNT********************\n");
    FILE *fp;
    fp=fopen("add.txt","a+");
    find.acc_bal=0;
    account:
    printf("\nEnter the account number:");
    scanf("%d",&find.acc_no);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF )
    {
        if(find.acc_no==bank.acc_no)
        {
            printf("\n\n\nAccount number is already available.Try again.\n\nPress any key....");
            fflush(stdin);
            getch();
            goto account;
        }
    }
    bank.acc_no=find.acc_no;
    printf("\nEnter your name:");
    scanf("%s",&bank.acc_name);
    printf("\nEnter your phone number:");
    scanf("%lf",&bank.phone_no);
    printf("\nEnter the branch number:");
    scanf("%s",bank.branch_name);
    printf("\nEnter your date of birth(dd/mm/yy):");
    scanf("%d/%d/%d",&bank.dob.date,&bank.dob.month,&bank.dob.year);
    bank.acc_bal=find.acc_bal;
    fprintf(fp,"\n%d %s %lf %s %d/%d/%d %f ",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
    fclose(fp);
    printf("\n\nACCOUNT CREATED SUCCESSFULLY!!!");
    back_page();


}
void deposit()
{
    system("cls");
    printf("\n\t\t\t*******************DEPOSIT MONEY INTO AN ACCOUNT********************");
    int flag=0;
    FILE *fp,*update;
    fp=fopen("add.txt","r");
    update=fopen("modern.txt","w");
    printf("\nEnter your account number:");
    scanf("%d",&up.acc_no);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF)
    {
        if(bank.acc_no==up.acc_no)
        {
            flag=1;
            printf("\nThe available balance in the account:%f",bank.acc_bal);
            printf("\nEnter the amount you want to deposit:");
            scanf("%f",&up.acc_bal);
            bank.acc_bal=bank.acc_bal+up.acc_bal;
            printf("\n\n\t\t                   Deposition details           ");
            printf("\nAccount number                 :%d",bank.acc_no);
            printf("\nAccount Holder name            :%s",bank.acc_name);
            printf("\nThe balance after deposition is:%f",bank.acc_bal);
            fprintf(update,"\n%d %s %lf %s %d/%d/%d %f",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
            printf("\n\nDEPOSITION IS SUCCESSFULL!!!");

        }
        else
        {
            fprintf(update,"\n%d %s %lf %s %d/%d/%d %f",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
        }
    }
    fclose(fp);
    fclose(update);
    remove("add.txt");
    rename("modern.txt","add.txt");
    if(flag==0)
    {
        printf("\n\nAccount number is not available.Try again.\nPress any key to continue...");
        getch();
        fflush(stdin);
        deposit();
    }
    back_page();

}
void withdraw()
{
    system("cls");
    printf("\n\t\t\t*******************WITHDRAW MONEY FROM AN ACCOUNT********************");
    int flag=0;
    FILE *fp,*update;
    fp=fopen("add.txt","r");
    update=fopen("modern.txt","w");
    printf("\nEnter your account number:");
    scanf("%d",&with.acc_no);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF)
    {
        if(bank.acc_no==with.acc_no)
        {
            flag=1;
            printf("\nThe available balance in the account:%f",bank.acc_bal);
            printf("\nEnter the amount you want to withdraw:");
            scanf("%f",&with.acc_bal);
            bank.acc_bal=bank.acc_bal-with.acc_bal;
            printf("\n\n\t\t\t                   Withdrawal Details          ");
            printf("\nAccount number                 :%d",bank.acc_no);
            printf("\nAccount Holder Name            :%s",bank.acc_name);
            printf("\nThe balance after withdrawal is:%f",bank.acc_bal);
            fprintf(update,"\n%d %s %lf %s %d/%d/%d %f",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
            printf("\nWITHDRAWAL IS SUCCESSFULL!!!");

        }
        else
        {
            fprintf(update,"\n%d %s %lf %s %d/%d/%d %f",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
        }
    }
    fclose(fp);
    fclose(update);
    remove("add.txt");
    rename("modern.txt","add.txt");
    if(flag==0)
    {
        printf("\n\nAccount number is not available.Try again.\nPress any key to continue...");
        getch();
        fflush(stdin);
        deposit();
    }
    back_page();
}

void details()
{
    system("cls");
    printf("\n\t\t\t*******************DETAILS OF THE ACCOUNT********************");
    int flag=0;
    FILE *fp;
    fp=fopen("add.txt","r");
    printf("\nEnter your account number to display your details:");
    scanf("%d",&find.acc_no);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF)
        {
            if(bank.acc_no==find.acc_no)
            {
                flag=1;
                printf("\n\nAccount Number            :%d",bank.acc_no);
                printf("\nAccount Holder Name       :%s",bank.acc_name);
                printf("\nPhone Number              :%lf",bank.phone_no);
                printf("\nBranch                    :%s",bank.branch_name);
                printf("\nDate of Birth(dd/mm/yyyy) :%d/%d/%d",bank.dob.date,bank.dob.month,bank.dob.year);
                printf("\nAccount Balance           :%f",bank.acc_bal);
            }
        }
    fclose(fp);
    if(flag==0)
    {
        printf("\n\nAccount number not available.Try again.Press any key to continue...");
        fflush(stdin);
        getch();
        details();
    }
    back_page();
}
void close()
{
    system("cls");
    printf("\n\t\t\t*******************CLOSE AN ACCOUNT********************");
    char c;
    int flag=0;
    FILE *fp,*update;
    fp = fopen("add.txt","r");
    update=fopen("modern.txt","w");

    printf("\nEnter the account number to be deleted: ");
    scanf("%d",&find.acc_no);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF)

        {
            if(bank.acc_no==find.acc_no)
            {
                flag=1;
                printf("\nACCOUNT WILL BE CLOSED\n");
                break;
            }

        }
    fclose(fp);
    fp=fopen("add.txt","r");
    rewind(fp);
    while(fscanf(fp,"\n%d %s %lf %s %d/%d/%d %f",&bank.acc_no,bank.acc_name,&bank.phone_no,bank.branch_name,&bank.dob.date,&bank.dob.month,&bank.dob.year,&bank.acc_bal)!=EOF)
   {
                if(bank.acc_no!=find.acc_no)
                {
                    fprintf(update,"\n%d %s %lf %s %d/%d/%d %f",bank.acc_no,bank.acc_name,bank.phone_no,bank.branch_name,bank.dob.date,bank.dob.month,bank.dob.year,bank.acc_bal);
                }
    }
    fclose(fp);
    fclose(update);
    remove("add.txt");
    rename("modern.txt","add.txt");

    if(flag==0)
    {
        printf("\n\nAccount number not available.Try again.Press any key to continue.....");
        fflush(stdin);
        getch();
        close();
    }

    back_page();
}

