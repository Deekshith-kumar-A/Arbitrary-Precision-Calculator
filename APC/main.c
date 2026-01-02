/* 
* Name: Deekshith Kumar A.
* Date: 18/12/2025
* Project name: APC – Arbitrary Precision Calculator
* Description: The APC (Arbitrary Precision Calculator) project is a C program 
  that performs arithmetic operations on very large integers beyond the limits of built-in data types.
  It uses a doubly linked list to store each digit of a number separately.
  The project supports addition, subtraction, multiplication, and division using manual arithmetic logic.

* Supported Operations (Functions)

* Addition (addition)
  Adds two large numbers digit by digit from the least significant digit,
  handling carry and storing the result in a new linked list.

* Subtraction (subtraction)
  Subtracts one large number from another using borrow logic, 
  compares operands to handle negative results, and removes leading zeros.

* Multiplication (multiplication)
  Implements long multiplication by generating partial products, 
  adding shift zeros, and accumulating the final result using the addition function.

* Division (division)
  Performs division using repeated subtraction to compute the quotient, 
  handling division by zero and large numbers safely.
*/

#include "apc.h"
#include <stdio.h>

/* Helper: check if result is zero */
int is_zero(Dlist *head)
{
    return (head && head->data == 0 && head->next == NULL);
}

int main(int argc, char *argv[])
{   // Declare operand and result lists
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    // Variables to store sign of operands
    int sign1 = 1, sign2 = 1;
    int i = 0;

    // Operand 1 
    if (argv[1][0] == '-')  // Check sign
    {
        sign1 = -1;
        i = 1;
    }
    for (; argv[1][i] != '\0'; i++) // Convert first operand digits into linked list
    {
        insert_last(&head1, &tail1, argv[1][i] - '0');
    }

    // Operand 2
    i = 0;
    if (argv[3][0] == '-')  // Check sign
    {
        sign2 = -1;
        i = 1;
    }

    // Convert second operand digits into linked list
    for (; argv[3][i] != '\0'; i++)
    {
        insert_last(&head2, &tail2, argv[3][i] - '0');
    }

    // Extract operator from command-line argument
    char operator = argv[2][0];

    // Perform operation based on operator
    switch (operator)
    {
        case '+':
        // If both operands have same sign, perform addition
            if (sign1 == sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                // Print negative sign if result is negative
                if (sign1 == -1 && !is_zero(headR))
                    printf("-");
            }
            else
            {
                // If signs differ, perform subtraction
                if (compare(head1, head2) >= 0)
                {
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    // Result sign depends on larger operand
                    if (sign1 == -1 && !is_zero(headR))
                        printf("-");
                }
                else
                {
                    subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    if (sign2 == -1 && !is_zero(headR))
                        printf("-");
                }
            }
            print_list(headR);
            break;

        case '-':
            // A - B  ==>  A + (-B) 
            sign2 = -sign2;

            // If both operands have same sign, perform addition
            if (sign1 == sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                // Print negative sign if result is negative
                if (sign1 == -1 && !is_zero(headR))
                    printf("-");
            }
            else
            {
                // If signs differ, perform subtraction
                if (compare(head1, head2) >= 0)
                {
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    // Result sign depends on first operand
                    if (sign1 == -1 && !is_zero(headR))
                        printf("-");
                }
                else
                {
                    subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    // Result sign depends on first operand
                    if (sign2 == -1 && !is_zero(headR))
                        printf("-");
                }
            }
            print_list(headR);
            break;

        case 'x': // Perform multiplication
            multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);

            // Result sign depends on operand signs
            if (sign1 * sign2 == -1 && !is_zero(headR))
                printf("-");
            print_list(headR);
            break;

        case '/':  // Perform division
            division(&head1,&tail1,&head2,&tail2,&headR,&tailR);

            // Result sign depends on operand signs
            if (sign1 * sign2 == -1 && !is_zero(headR))
                printf("-");
            print_list(headR);
            break;

        default:  // Handle invalid operator
            printf("Invalid Input:-( Try again...\n");
    }

    return 0;
}
