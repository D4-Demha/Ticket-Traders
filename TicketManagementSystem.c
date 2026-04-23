#include<stdio.h>
#include<string.h>
#include<unistd.h>

char *chooseEvent();
char *chooseTicketType();
int chooseTicketsAmount();
int spreeTotal(char *ticketChoice, int ticketAmount, int total);
int checkout(int grandTotal);
void logo();


char *chooseEvent()
{
    int eventChoice;
    printf("\n-------------------------------------------------------\n");
    printf("  > Which event would you like to buy ticket(s) of? <\n\n");
    printf("   1. Movie in a theatre\n   2. Concert\n   3. Circus");
    printf("\n\n\t >> Your choice: "); scanf("%d", &eventChoice);

    if(eventChoice != 1 && eventChoice != 2 && eventChoice != 3){
        printf("\n  > Invalid input! Enter again.\n");
        return chooseEvent();
    }
    
    else if(eventChoice == 1)
        return "movies";
    else if(eventChoice == 2)
        return "concert";
    else 
        return "circus";
}

char *chooseTicketType()
{
    int ticketChoice;
    printf("\n-----------------------------------------------\n");
    printf("  > Which type of ticket(s) would you like? <\n\n");
    printf("   1. Standard  ($5)\n   2. Premium  ($8)");
    printf("\n\n\t >> Your choice: "); scanf("%d", &ticketChoice);

    if(ticketChoice != 1 && ticketChoice != 2){
        printf("\n  > Invalid input! Enter again.\n");
        return chooseTicketType();
    }

    if (ticketChoice == 1)
        return "Standard";
    else
        return "Premium";
}

int chooseTicketsAmount() 
{
    int ticketAmount;
    printf("\n------------------------------------------\n");
    printf("  > How many ticket(s) would you like? <\n\n");
    printf("\n\t >> Your input: "); scanf("%d", &ticketAmount);



    if (ticketAmount < 0){
        printf("\n------------------------------------------\n");
        printf("\n\t> Invalid input! Enter again.\n");
        return chooseTicketsAmount();
    }

    printf("\n--------------------------------------------------------------\n");

    return ticketAmount;
}

int spreeTotal(char *ticketChoice, int ticketAmount, int total)
{
    
    if (ticketChoice == "Premium")
        total = ticketAmount * 8;
    else 
        total = ticketAmount * 5;

    return total;
}

int checkout(int grandTotal)
{
    int inputCash;
    int paymentChange;

    printf("    >> Your bill: $%d\n\n > Your payment($): ", grandTotal); 
    scanf("%d", &inputCash);

    if (inputCash < grandTotal){
        printf("\n   -->  Enter a sufficient amount  <--");
        printf("\n------------------------------------------\n");
        return checkout(grandTotal);
    }
    else if (inputCash > grandTotal){
        paymentChange = inputCash - grandTotal;
        printf("\n > Checkout successful! Here is your change of $%d\n", paymentChange);
    }
    else{
        paymentChange = 0;
        printf("\n > Checkout successful!\n", paymentChange);
    }

    return paymentChange;
}

void logo()
{
    char *logo={ 
        "\n\n\n  _______   _          _             _       _______                      _                    \n"  
        " |__   __| (_)        | |           | |     |__   __|                    | |                   \n"        
        "    | |     _    ___  | | __   ___  | |_       | |     _ __    __ _    __| |   ___   _ __      \n" 
        "    | |    | |  / __| | |/ /  / _ \\ | __|      | |    | '__|  / _` |  / _` |  / _ \\ | '__|   \n" 
        "    | |    | | | (__  |   <  |  __/ | |_       | |    | |    | (_| | | (_| | |  __/ | |        \n"  
        "    |_|    |_|  \\___| |_|\\_\\  \\___|  \\__|      |_|    |_|     \\__,_|  \\__,_|  \\___| |_|\n"  
    };

    printf("%s", logo);
};

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

int main()
{      
    char moreTickets;
    char anotherCustomer;
    int shoppingSpree;
    int i = 0;
    int inputCash = 0;
    int customers = 0;

    char *eventChoice[50]; // will change depending on the number of input users
    char *ticketChoice[50];
    int ticketAmount[50];
    int total[50];
    int grandTotal = 0;
    int paymentChange = 0;
    int sprees[100];

    char userName[50][20];
    char userContact[50][20];

    login();

    usleep(990000);

    system("cls");
    logo();

    do{ 
        grandTotal = 0;
        paymentChange = 0;

        purchaseMore:
        {
            eventChoice[shoppingSpree] = chooseEvent();
            ticketChoice[shoppingSpree] = chooseTicketType();
            ticketAmount[shoppingSpree] = chooseTicketsAmount();
            total[shoppingSpree] = spreeTotal(ticketChoice[shoppingSpree], ticketAmount[shoppingSpree], total[shoppingSpree]);
            grandTotal += total[shoppingSpree];
            i = 0;

            if (shoppingSpree > 0)
            {
                while(i <= shoppingSpree)
                {
                    printf("\n  >> %d %s ticket(s) to the %s, that would be $%d <<", ticketAmount[i], ticketChoice[i], eventChoice[i], total[i]);
                    
                    i++;
                }
                printf("\n\n\t >> Total: $%d\n", grandTotal);
            }
            else
                printf("  >> %d %s ticket(s) to the %s, that would be $%d <<\n", ticketAmount[i], ticketChoice[i], eventChoice[i], total[i]);

            printf("--------------------------------------------------------------");

            inputAgain:
            {
                printf("\n\n > Would you like to purchase more ticket(s)? Enter 'y' to do so, or enter 'n' to checkout\n");
                printf("\n\t >> Your input: "); scanf(" %c", &moreTickets);
            }

        }

        system("cls");

        if (moreTickets == 'y'){
            shoppingSpree++;
            sprees[customers] = shoppingSpree;
            goto purchaseMore;
        }
        else if (moreTickets == 'n'){
            sprees[customers] += 1;
            shoppingSpree = 0;

            printf("\n------------------------------------------------\n");
            printf("\n\t   >> You chose to checkout <<\n");

            printf("\n\n----| Enter the following credentials to proceed |----\n");
            getchar();
            printf("\n > Enter name: "); gets(userName[customers]); 
            printf(" > Enter contact number: "); gets(userContact[customers]);

            printf("\n\n You're all set to check out!\n");

            paymentChange = checkout(grandTotal);
            printf("\n------------------------------------------\n");
        }
        else{
            printf("\n------------------------------------------------\n");
            printf("    --> Invalid input <--\n");
            goto inputAgain;
        }
        
        repeat:
        {
            printf("\n > Is there another customer in queue?  Enter 'y' if yes, or enter 'n' if no <\n");
            printf("\n\t>> Your input: "); scanf(" %c", &anotherCustomer);
        }
        
        system("cls");
        
        if (anotherCustomer != 'y' && anotherCustomer != 'n'){
            printf("\n------------------------------------------------\n");
            printf("    --> Invalid entry <--\n");
            goto repeat;
        }
        else if (anotherCustomer == 'y'){
            customers++;
            logo();
            printf("\n\n\t\t---------------------\n");
            printf("\t\t  Customer number %d", customers+1);
        }
    }
    while(anotherCustomer == 'y');

    FILE *event;
    event = fopen("Ticket_Transcript.csv", "w");

    fprintf(event, "ID    Name          Contact no.     Event(s)     Premium | Standard\n");
    fprintf(event, "...................................................................");    
    
    int j;
    for(i = 0; i <= customers; i++)
    {
        fprintf(event, "\n\n%-6d", i+1);
        fprintf(event, "%-14s", userName[i]);
        fprintf(event, "%-16s", userContact[i]);

        for(j = 0; j < sprees[i]; j++)
        {
            fprintf(event, "%-16s", eventChoice[j]);

            if (ticketChoice[j] == "Premium")
                fprintf(event, "%d         0", ticketAmount[j]);
            else
                fprintf(event, "0         %d", ticketAmount[j]);
            
            if (j != sprees[i]-1)
                fprintf(event, "\n                                    ");
        }
        fprintf(event, "\n      .............................................................");
    }

    fclose(event);

    printf("\n...................................\n");
    printf("\n  >>  Data saved successfully!  <<");
    printf("\n\n >>>   Hope to see you again!   <<<");


    return 0;
}