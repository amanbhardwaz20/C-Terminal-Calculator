#include <stdio.h>
#include <math.h>

int main(void) {
    int choice;
    double num1, num2, result;

    while (1) {
        printf("\n--- Terminal Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Remainder (fmod)\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        if (choice == 7) {
            printf("Exiting... Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &num1, &num2) != 2) {
            printf("Invalid numbers.\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                break;

            case 2:
                result = num1 - num2;
                break;

            case 3:
                result = num1 * num2;
                break;

            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;

            case 5:
                if (num2 == 0) {
                    printf("Error: Remainder by zero.\n");
                    continue;
                }
                result = fmod(num1, num2);
                break;

            case 6:
                result = pow(num1, num2);
                break;
        }

        printf("Result: %.2lf\n", result);
    }

    return 0;
}