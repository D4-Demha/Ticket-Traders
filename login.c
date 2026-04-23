#include<stdio.h>
#include<string.h>
#include<unistd.h>

void login()
{
    char Uname[15] = "Ticket Traders", pass[6] = "12345";
    char inp_Uname[20], inp_pass[20];
    
    printf("\t-----| LOGIN |-----\n");
    
    
    printf("\n > Username: "); gets(inp_Uname);
    printf(" > Password: "); gets(inp_pass);

    if((strcmp(Uname, inp_Uname) != 0) || (strcmp(pass, inp_pass) != 0)){
        printf("\n  >> Incorrect username or password, enter again...\n");
        usleep(1999999);
        system("cls");
        return login();
    }

    printf("\n >> Login successful!\n\n");
}

void Register()
{
    char Uname[30], pass[20];

    printf("\t-----| Register |-----\n");
    printf("\n > Username: "); gets(Uname);
    printf(" > Password: "); gets(pass);

    system("cls");

    printf("\n >> Account registered successful!\n\n");

    usleep(1999999);
    system("cls");
}

void main()
{   
    int authenticate;
    
    do{
        printf("\n--------------------------------------------------\n");
        printf("\t-----| Verify Your Identity |-----\n\n1. Login\n2. Sign up");
        printf("\n\n\t >> Your choice: "); scanf("%d", &authenticate);
        system("cls");

        if (authenticate == 1)
            login();
        else if (authenticate == 2)
            Register();
        else
            printf("\n  > Invalid input! Enter again.\n");
    }
    while(authenticate != 1 || authenticate != 2);    
    
    printf("\n\nhellow");


}