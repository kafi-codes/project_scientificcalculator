#include <stdio.h>
#include <math.h>

int main()
{
    int operation;
    double Number1, Number2, Result;
    int Number;

    do
    {
        printf("\n It is a normal Scientific Calculator \n");
        printf("1. addition\n 2. Subtraction\n 3. 4. Multiplication (multi-numbers)\n Divison\n 5. Exit\n");
        printf("Enter what operation you want: ");

        scanf("%d", &operation);

        switch (operation)
        {

        case 3:

            printf(" How many numbers do you like to multiply? ");
            scanf("%d", &Number);
            Result = 1;
            printf(" Enter %d numbers : \n", Number);

            for (int i = 1; i <= Number; i++)
            {

                scanf("%lf", &Number1);
                Result *= Number1;
            }
            printf("Multiplication result is  %.4lf \n", Result);
            break;
        }

    } while (operation != 5);

    return 0;
}
