
#include <stdio.h>
#include <string.h>

struct Customer
{
    int id;
    char name[50];
    int units;
    float bill;
};

float calculateBill(int units)
{
    float bill = 0;

    if (units <= 100)
    {
        bill = units * 1.50;
    }
    else if (units <= 200)
    {
        bill = (100 * 1.50) +
               (units - 100) * 2.50;
    }
    else if (units <= 300)
    {
        bill = (100 * 1.50) +
               (100 * 2.50) +
               (units - 200) * 4.00;
    }
    else
    {
        bill = (100 * 1.50) +
               (100 * 2.50) +
               (100 * 4.00) +
               (units - 300) * 6.00;
    }

    return bill;
}

void displayBill(struct Customer c)
{
    printf("\n====================================");
    printf("\n       ELECTRICITY BILL");
    printf("\n====================================");
    printf("\nCustomer ID   : %d", c.id);
    printf("\nCustomer Name : %s", c.name);
    printf("\nUnits Consumed: %d", c.units);
    printf("\nBill Amount   : Rs. %.2f", c.bill);
    printf("\n====================================\n");
}

int main()
{
    struct Customer c[100];
    int choice, count = 0, i;

    do
    {
        printf("\n\n===== ELECTRICITY BILL SYSTEM =====");
        printf("\n1. Add Customer");
        printf("\n2. Calculate Electricity Bill");
        printf("\n3. Display All Customers");
        printf("\n4. Search Customer");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(count >= 100)
                {
                    printf("\nCustomer limit reached!");
                    break;
                }

                printf("\nEnter Customer ID: ");
                scanf("%d", &c[count].id);

                printf("Enter Customer Name: ");
                scanf(" %[^\n]", c[count].name);

                printf("Enter Units Consumed: ");
                scanf("%d", &c[count].units);

                if(c[count].units < 0)
                {
                    printf("\nInvalid units!");
                    break;
                }

                c[count].bill =
                    calculateBill(c[count].units);

                count++;

                printf("\nCustomer Added Successfully!");
                break;

            case 2:
                if(count == 0)
                {
                    printf("\nNo customer records found!");
                    break;
                }

                for(i = 0; i < count; i++)
                {
                    displayBill(c[i]);
                }
                break;

            case 3:
                if(count == 0)
                {
                    printf("\nNo customer records found!");
                }
                else
                {
                    printf("\n===== CUSTOMER DETAILS =====");

                    for(i = 0; i < count; i++)
                    {
                        printf("\n\nID: %d", c[i].id);
                        printf("\nName: %s", c[i].name);
                        printf("\nUnits: %d", c[i].units);
                        printf("\nBill: Rs. %.2f",
                               c[i].bill);
                    }
                }
                break;

            case 4:
            {
                int searchId, found = 0;

                printf("\nEnter Customer ID to Search: ");
                scanf("%d", &searchId);

                for(i = 0; i < count; i++)
                {
                    if(c[i].id == searchId)
                    {
                        displayBill(c[i]);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("\nCustomer Not Found!");
                }
                break;
            }

            case 5:
                printf("\nThank You for Using the System!");
                break;

            default:
                printf("\nInvalid Choice! Try Again.");
        }

    } while(choice != 5);

    return 0;
}
