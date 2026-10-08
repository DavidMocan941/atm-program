#include <stdio.h>
const int pin = 1234;
double openingBalance = 2500.00;
void operation();
void deposit(int amount);
void status();
void withdraw(int amount);
void beginTransaction();

int main()
{
    beginTransaction();
    return 0;
}
void beginTransaction()
{
    printf("Introduce the PIN code for this ATM \n");
    int i;
    scanf("%i", &i);
    if (i != pin)
    {
        printf("The introduced PIN is incorect \n");
        beginTransaction();
    }
    operation();
}
void operation()
{
    printf("ATM \n");
    printf("Type S to see the Status \n");
    printf("Type R to Withdraw from ATM \n");
    printf("Type D to Deposit in ATM \n");
    printf("Print E to exit \n");

    char operation;
    scanf(" %c", &operation);

    int amount;
    switch (operation)
    {
    case 'D':
        printf("Indicate the amount you want to deposit: \n");
        scanf(" %i", &amount);
        deposit(amount);
        break;
    case 'S':
        status();
        break;
    case 'R':
        printf("Indicate the amount you want to withdraw: \n");
        scanf(" %i", &amount);
        withdraw(amount);
        break;
    case 'E':
        return;
    default:
        printf("Invalid operation \n");
        beginTransaction();
    }
}
void deposit(int amount)
{
    if (amount >= 1 && amount < 10000)
    {
        openingBalance += amount;
        printf("Deposit amount: %i lei \n", amount);
        printf("New Balance: %.2f lei \n", openingBalance);
    }
    else
    {
        printf("Amount is invalid \n");
    }
    beginTransaction();
}
void status()
{
    printf("Current balance : %.2f lei \n", openingBalance);
}
void withdraw(int amount)
{
    double commision = amount / 100.0;
    if (commision < 2)
    {
        commision = 2;
    }
    if (amount > 0)
    {
        if (amount % 10 == 0)
        {
            if (amount < 3000)
            {
                if (amount + commision < openingBalance)
                {
                    openingBalance -= amount + commision;
                    printf("Withdrawed: %i lei \n", amount);
                    printf("Commision: %.2f lei \n", commision);
                    printf("New balance: %.2f lei \n", openingBalance);
                }
                else
                {
                    printf("Insuficient funds \n");
                }
            }
            else
            {
                printf("The amount must not exceed 3000 \n");
            }
        }
        else
        {
            printf("The amount has to be multiple of 10 \n");
        }
    }
    else
    {
        printf("Invalid amount \n");
    }
    beginTransaction();
}
