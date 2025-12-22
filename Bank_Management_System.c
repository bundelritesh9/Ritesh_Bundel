#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct account
{
    char name[100];
    char accountNumber[13];
    int age;
    long long int balance;
    char phone[11];
    int PIN;
} a;

int main()
{
    srand(time(0));
    while (1)
    {
        int user;
        printf("\nMENU\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Update account details\n");
        printf("6. Delete account\n");
        printf("7. exit\n");

        printf("Please select one\n");
        scanf("%d", &user);
        if (user == 1)
        {
            a N;
            printf("Enter your full name: ");
            scanf(" %[^\n]", (N.name));
            printf("Enter your age: ");
            scanf(" %d", &(N.age));
            if (N.age >= 18)
            {
                char temp_phone[20];

                while (1)
                {
                    printf("Enter your phone number: ");
                    scanf("%s", temp_phone);

                    if (strlen(temp_phone) == 10)
                    {
                        int valid = 1;
                        for (int i = 0; i < 10; i++)
                        {
                            if (temp_phone[i] < '0' || temp_phone[i] > '9')
                            {
                                valid = 0;
                                break;
                            }
                        }

                        if (valid)
                        {
                            strcpy(N.phone, temp_phone);
                            break;
                        }
                        else
                        {
                            printf("Phone number must contain only digits!\n");
                        }
                    }
                    else if (strlen(temp_phone) < 10)
                    {
                        printf("You entered less than 10 digits. Try again!\n");
                    }
                    else
                    {
                        printf("You entered more than 10 digits. Try again!\n");
                    }
                }

                int temp;
                while (1)
                {
                    printf("Create 4 digit PIN: ");
                    scanf("%d", &temp);
                    if (temp > 999 && temp < 10000)
                    {
                        N.PIN = temp;
                        break;
                    }
                    else
                    {
                        if (temp <= 999)
                        {
                            printf("Sorry! PIN is too short. Try Again!\n");
                        }
                        else if (temp >= 10000)
                        {
                            printf("Sorry! PIN is too Long. Try Again!\n");
                        }
                    }
                }
                int unique;
                do
                {
                    unique = 1;

                    for (int i = 0; i < 12; i++)
                        N.accountNumber[i] = '0' + rand() % 10;

                    N.accountNumber[12] = '\0';

                    FILE *ptr = fopen("Bank_Management_System_File.txt", "r");
                    if (ptr != NULL)
                    {
                        a temp;
                        while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n",
                                      temp.name, &temp.age, temp.phone,
                                      temp.accountNumber, &temp.balance, &temp.PIN) != EOF)
                        {
                            if (strcmp(temp.accountNumber, N.accountNumber) == 0)
                            {
                                unique = 0;
                                break;
                            }
                        }
                        fclose(ptr);
                    }

                } while (!unique);

                printf("\nCongratulations!!, You have successfully created your account in our bank\n");
                printf("Name : %s\n", N.name);
                printf("Age : %d\n", N.age);
                printf("Phone Number : %s\n", N.phone);
                printf("Account Number is : %s\n", N.accountNumber);
                N.balance = 2000;
                printf("Current Balance : Rs. %lld\n", N.balance);

                FILE *ptr;
                ptr = fopen("Bank_Management_System_File.txt", "a");
                fprintf(ptr, "%s|%d|%s|%s|%lld|%d\n", N.name, N.age, N.phone, N.accountNumber, N.balance, N.PIN);
                fclose(ptr);
            }
            else
            {
                printf("According to bank rules, you must be at least 18 years old to create and account.\n");
            }
        }
        else if (user == 2)
        {
            a N;
            int found = 0;
            int pin;
            int attempt = 0;
            char acc_no[100];
            long long int update_balance;
            FILE *ptr, *ptr2;
            ptr = fopen("Bank_Management_System_File.txt", "r");
            ptr2 = fopen("temp.txt", "w");
            if (!ptr)
            {
                printf("No records found.\n");
                continue;
            }
            else
            {
                printf("Enter your account number\n");
                scanf("%s", acc_no);
                while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n", N.name, &N.age, N.phone, N.accountNumber, &N.balance, &N.PIN) != EOF)
                {

                    if (strcmp(N.accountNumber, acc_no) == 0)
                    {
                        while (attempt < 3)
                        {
                            printf("Enter Your PIN\n");
                            scanf("%d", &pin);
                            if (pin == N.PIN)
                            {
                                long long int dep;
                                printf("Enter The Amount To Deposit\nRs.");
                                scanf("%lld", &dep);
                                N.balance = N.balance + dep;
                                update_balance = N.balance;
                                found = 1;
                                break;
                            }
                            else
                            {
                                attempt++;
                                if (attempt < 3)
                                {
                                    printf("Wrong PIN, try again\n");
                                }
                                else
                                {
                                    printf("Maximum PIN attempts exceeded. Transaction Cancelled.\n");
                                }
                            }
                        }
                    }
                    fprintf(ptr2, "%s|%d|%s|%s|%lld|%d\n", N.name, N.age, N.phone, N.accountNumber, N.balance, N.PIN);
                }
                if (found)
                {
                    printf("Amount successfully deposited.\n");
                    printf("Remaining Account Balance : Rs. %lld\n", update_balance);
                }
                else if (!found && attempt < 3)
                {
                    printf("Account not found!\n");
                }
                fclose(ptr);
                fclose(ptr2);
                remove("Bank_Management_System_File.txt");
                rename("temp.txt", "Bank_Management_System_File.txt");
            }
        }
        else if (user == 3)
        {

            a N;
            int pin;
            int found = 0;
            int attempt = 0;
            long long int update_balance;
            char acc_no[100];
            FILE *ptr, *ptr2;
            ptr = fopen("Bank_Management_System_File.txt", "r");
            ptr2 = fopen("temp.txt", "w");
            if (!ptr)
            {
                printf("No records found.\n");
                continue;
            }
            else
            {

                printf("Enter account number\n");
                scanf("%s", acc_no);
                while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n", N.name, &N.age, N.phone, N.accountNumber, &N.balance, &N.PIN) != EOF)
                {
                    if (strcmp(N.accountNumber, acc_no) == 0)
                    {
                        while (attempt < 3)
                        {
                            printf("Enter PIN\n");
                            scanf("%d", &pin);
                            if (pin == N.PIN)
                            {
                                long long int wdr;
                                printf("Enter Amount To Withdraw\nRs. ");
                                scanf("%lld", &wdr);
                                if (wdr > N.balance)
                                {
                                    printf("Insufficient balance!");
                                }
                                else
                                {
                                    N.balance = N.balance - wdr;
                                    update_balance = N.balance;
                                    found = 1;
                                    break;
                                }
                            }
                            else
                            {
                                attempt++;
                                if (attempt < 3)
                                {
                                    printf("Wrong PIN, try again\n");
                                }
                                else
                                {
                                    printf("Maximum PIN attempts exceeded. Transaction Cancelled.\n");
                                }
                            }
                        }
                    }

                    fprintf(ptr2, "%s|%d|%s|%s|%lld|%d\n", N.name, N.age, N.phone, N.accountNumber, N.balance, N.PIN);
                }

                if (found)
                {
                    printf("Amount successfully withdrawn.\n");
                    printf("Remaining Account Balance : Rs. %lld", update_balance);
                }
                else if (!found && attempt < 3)
                {
                    printf("Account not Found!");
                }

                fclose(ptr);
                fclose(ptr2);
                remove("Bank_Management_System_File.txt");
                rename("temp.txt", "Bank_Management_System_File.txt");
            }
        }
        else if (user == 4)
        {
            a N;
            int pin;
            int attempt = 0;
            int found = 0;
            char acc_no[100];
            FILE *ptr;
            ptr = fopen("Bank_Management_System_File.txt", "r");
            if (!ptr)
            {
                printf("No records found.\n");
                continue;
            }
            else
            {
                printf("Enter Account Number\n");
                scanf("%s", acc_no);
                while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n", N.name, &N.age, N.phone, N.accountNumber, &N.balance, &N.PIN) != EOF)
                {
                    if (strcmp(N.accountNumber, acc_no) == 0)
                    {
                        while (attempt < 3)
                        {

                            printf("Enter PIN\n");
                            scanf("%d", &pin);
                            if (pin == N.PIN)
                            {
                                printf("Balance : Rs. %lld", N.balance);
                                found = 1;
                                break;
                            }
                            else
                            {
                                attempt++;
                                if (attempt < 3)
                                {
                                    printf("Wrong PIN\n");
                                }
                                else
                                {
                                    printf("Maximum PIN attempts exceeded. Transaction Cancelled.\n");
                                    break;
                                }
                            }
                        }
                    }
                }
                if (!found && attempt < 3)
                {
                    printf("Account not Found!");
                }
                fclose(ptr);
            }
        }
        else if (user == 5)
        {
            a N;
            char acc_no[100];
            int choice;
            int attempt = 0;
            int found = 0;
            int pin;
            FILE *ptr, *ptr2;
            ptr = fopen("Bank_Management_System_File.txt", "r");
            ptr2 = fopen("temp.txt", "w");
            if (!ptr)
            {
                printf("No records found.\n");
                continue;
            }
            else
            {
                printf("Enter account number\n");
                scanf("%s", acc_no);

                while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n", N.name, &N.age, N.phone, N.accountNumber, &N.balance, &N.PIN) != EOF)
                {

                    if (strcmp(N.accountNumber, acc_no) == 0)
                    {
                        while (attempt < 3)
                        {
                            printf("Enter PIN\n");
                            scanf("%d", &pin);
                            if (pin == N.PIN)
                            {
                                printf("1. Name\n");
                                printf("2. Age\n");
                                printf("3. Phone Number\n");
                                printf("Enter Your Choice\n");
                                scanf("%d", &choice);
                                found = 1;
                                if (choice == 1)
                                {
                                    printf("Enter your full name\n");
                                    scanf(" %[^\n]", N.name);

                                    printf("Name updated Successfully!\n");
                                    break;
                                }
                                else if (choice == 2)
                                {
                                    printf("Enter age\n");
                                    scanf("%d", &N.age);

                                    printf("Age updated Successfully!\n");
                                    break;
                                }
                                else if (choice == 3)
                                {
                                    char temp_phone[20];

                                    while (1)
                                    {
                                        printf("Enter phone number : ");
                                        scanf("%s", temp_phone);

                                        if (strlen(temp_phone) == 10)
                                        {
                                            int valid = 1;
                                            for (int i = 0; i < 10; i++)
                                            {
                                                if (temp_phone[i] < '0' || temp_phone[i] > '9')
                                                {
                                                    valid = 0;
                                                    break;
                                                }
                                            }

                                            if (valid)
                                            {
                                                strcpy(N.phone, temp_phone);
                                                printf("Phone Number updated Successfully!\n");
                                                break;
                                            }
                                            else
                                            {
                                                printf("Phone number must contain only digits!\n");
                                            }
                                        }
                                        else if (strlen(temp_phone) < 10)
                                        {
                                            printf("You entered less than 10 digits. Try again!\n");
                                        }
                                        else
                                        {
                                            printf("You entered more than 10 digits. Try again!\n");
                                        }
                                    }
                                    break;
                                }
                            }
                            else
                            {
                                attempt++;
                                if (attempt < 3)
                                {
                                    printf("Wrong PIN, try again!\n");
                                }
                                else
                                {
                                    printf("Maximum PIN attempts exceeded. Try Again Later!.\n");
                                }
                            }
                        }
                    }
                    fprintf(ptr2, "%s|%d|%s|%s|%lld|%d\n", N.name, N.age, N.phone, N.accountNumber, N.balance, N.PIN);
                }
                if (!found && attempt < 3)
                {
                    printf("Account not Found!");
                }
                fclose(ptr);
                fclose(ptr2);
                remove("Bank_Management_System_File.txt");
                rename("temp.txt", "Bank_Management_System_File.txt");
            }
        }
        else if (user == 6)
        {
            a N;
            char acc_no[100];
            int attempt = 0;
            int pin;
            int found = 0;
            FILE *ptr, *ptr2;
            ptr = fopen("Bank_Management_System_File.txt", "r");
            ptr2 = fopen("temp.txt", "w");
            if (!ptr)
            {
                printf("No records found.\n");
                continue;
            }
            else
            {
                printf("Enter account number\n");
                scanf("%s", acc_no);
                while (fscanf(ptr, "%[^|]|%d|%[^|]|%[^|]|%lld|%d\n", N.name, &N.age, N.phone, N.accountNumber, &N.balance, &N.PIN) != EOF)
                {

                    if (strcmp(N.accountNumber, acc_no) == 0)
                    {
                        while (attempt < 3)
                        {
                            printf("Enter PIN\n");
                            scanf("%d", &pin);
                            if (pin == N.PIN)
                            {

                                found = 1;
                                attempt = 4;
                                continue;
                            }
                            else
                            {
                                attempt++;
                                if (attempt < 3)
                                {
                                    printf("Wrong PIN, try again!\n");
                                }
                                else
                                {
                                    printf("Maximum PIN attempts exceeded. Transaction Cancelled.\n");
                                }
                            }
                        }
                        if (found)
                        {
                            continue;
                        }
                    }
                    fprintf(ptr2, "%s|%d|%s|%s|%lld|%d\n", N.name, N.age, N.phone, N.accountNumber, N.balance, N.PIN);
                }
                if (found)
                {
                    printf("Account has been deleted successfully.\n");
                }
                else if (!found && attempt < 3)
                {
                    printf("Account not Found!");
                }
                fclose(ptr);
                fclose(ptr2);
                remove("Bank_Management_System_File.txt");
                rename("temp.txt", "Bank_Management_System_File.txt");
            }
        }
        else if (user == 7)
        {
            break;
        }
    }
    return 0;

}




