#include <stdio.h>
#include <math.h>
#include <string.h>

//  ANS memory
double ANS = 0;

//  history file
FILE *historyFile;

// save history
void saveHistory(const char *operation, double result)
{
    historyFile = fopen("history.txt", "a");
    if (historyFile == NULL)
        return;

    fprintf(historyFile, "%s = %.4lf\n", operation, result);
    fclose(historyFile);
}

// show history
void showHistory()
{
    char line[200];
    historyFile = fopen("history.txt", "r");

    if (historyFile == NULL)
    {
        printf("\nNo history found.\n");
        return;
    }

    printf("\n---- Calculation History ----\n");
    while (fgets(line, sizeof(line), historyFile))
        printf("%s", line);

    fclose(historyFile);
}


double factorial(int n)
{
    double fact = 1.0;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}


void quadratic(double a, double b, double c)
{
    double d;

    if (a == 0)
    {
        printf("Not a quadratic equation.\n");
        return;
    }

    d = b * b - 4 * a * c;

    if (d > 0)
    {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots: %.4lf , %.4lf\n", x1, x2);
    }
    else if (d == 0)
    {
        double x = -b / (2 * a);
        printf("Root: %.4lf\n", x);
    }
    else
    {
        printf("Complex roots.\n");
    }
}
//clear history
void clearHistory()
{
    historyFile = fopen("history.txt", "w"); 
    if (historyFile != NULL)
    {
        fclose(historyFile);
        printf("History cleared successfully.\n");
    }
    else
    {
        printf("No history to clear.\n");
    }
}


int main()
{
    int operation;
    double Number1, Number2, Result;
    int Number;

    do
    {
        printf("\n---- Scientific Calculator ----\n");
        printf(" 1. Addition\n");
        printf(" 2. Subtraction\n");
        printf(" 3. Multiplication (multi-numbers)\n");
        printf(" 4. Division\n");
        printf(" 5. Square Root\n");
        printf(" 6. Power (x^y)\n");
        printf(" 7. Sin (degrees)\n");
        printf(" 8. Cos (degrees)\n");
        printf(" 9. Tan (degrees)\n");
        printf("10. Log (base e)\n");
        printf("11. Factorial\n");
        printf("12. Quadratic Equation\n");
        printf("13. Show ANS\n");
        printf("14. Show History\n");
        printf("15. Clear History\n");
        printf("16. Exit\n");
        printf("Enter operation number: ");
        scanf("%d", &operation);

        switch (operation)
        {
        // Basic arithmetic
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &Number1, &Number2);
            Result = Number1 + Number2;
            printf("Result: %.4lf\n", Result);
            saveHistory("Addition", Result);
            ANS = Result;
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &Number1, &Number2);
            Result = Number1 - Number2;
            printf("Result: %.4lf\n", Result);
            saveHistory("Subtraction", Result);
            ANS = Result;
            break;

        case 3:
            printf("How many numbers? ");
            scanf("%d", &Number);
            Result = 1;
            printf("Enter numbers:\n");
            for (int i = 1; i <= Number; i++)
            {
                scanf("%lf", &Number1);
                Result *= Number1;
            }
            printf("Result: %.4lf\n", Result);
            saveHistory("Multiplication", Result);
            ANS = Result;
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &Number1, &Number2);
            if (Number2 != 0)
            {
                Result = Number1 / Number2;
                printf("Result: %.4lf\n", Result);
                saveHistory("Division", Result);
                ANS = Result;
            }
            else
                printf("Error! Division by zero.\n");
            break;

        // Scientific functions
        case 5:
            printf("Enter number: ");
            scanf("%lf", &Number1);
            if (Number1 >= 0)
            {
                Result = sqrt(Number1);
                printf("sqrt(%.4lf) = %.4lf\n", Number1, Result);
                saveHistory("Square Root", Result);
                ANS = Result;
            }
            else
                printf("Error! Negative number.\n");
            break;

        case 6:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &Number1, &Number2);
            Result = pow(Number1, Number2);
            printf("%.4lf ^ %.4lf = %.4lf\n", Number1, Number2, Result);
            saveHistory("Power", Result);
            ANS = Result;
            break;

        case 7:
            printf("Enter angle (degrees): ");
            scanf("%lf", &Number1);
            Result = sin(Number1 * M_PI / 180.0);
            printf("sin(%.2lf) = %.4lf\n", Number1, Result);
            saveHistory("Sin", Result);
            ANS = Result;
            break;

        case 8:
            printf("Enter angle (degrees): ");
            scanf("%lf", &Number1);
            Result = cos(Number1 * M_PI / 180.0);
            printf("cos(%.2lf) = %.4lf\n", Number1, Result);
            saveHistory("Cos", Result);
            ANS = Result;
            break;

        case 9:
            printf("Enter angle (degrees): ");
            scanf("%lf", &Number1);
            Result = tan(Number1 * M_PI / 180.0);
            printf("tan(%.2lf) = %.4lf\n", Number1, Result);
            saveHistory("Tan", Result);
            ANS = Result;
            break;

        case 10:
            printf("Enter number: ");
            scanf("%lf", &Number1);
            if (Number1 > 0)
            {
                Result = log(Number1);
                printf("log(%.4lf) = %.4lf\n", Number1, Result);
                saveHistory("Log", Result);
                ANS = Result;
            }
            else
                printf("Error! Log undefined.\n");
            break;

        
        case 11:
        {
            int n;
            printf("Enter number: ");
            scanf("%d", &n);

            if (n < 0)
            {
                printf("Error! Negative number.\n");
            }
            else
            {
                Result = factorial(n);
                printf("%d! = %.0lf\n", n, Result);
                saveHistory("Factorial", Result);
                ANS = Result;
            }
            break;
        }

        case 12:
        {
            double a, b, c;
            printf("Enter a b c: ");
            scanf("%lf %lf %lf", &a, &b, &c);
            quadratic(a, b, c);
            break;
        }

      
        case 13:
            printf("ANS = %.4lf\n", ANS);
            break;

        case 14:
            showHistory();
            break;

        case 15:
                clearHistory();
                break;


      
        case 16:
            printf("Exiting calculator...\n");
            break;

        default:
            printf("Invalid option! Try again.\n");
        }

    } while (operation != 16);

    return 0;
}
