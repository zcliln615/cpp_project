#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_error(const char *message)
{
    printf("%s\n", message);
}

int is_number(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        print_error("Usage: ./calculator <num1> <operator> <num2>");
        return 1;
    }

    if (!is_number(argv[1]) || !is_number(argv[3]))
    {
        print_error("The input cannot be interpreted as numbers!");
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char operator= argv[2][0];

    switch (operator)
    {
    case '+':
        printf("%s %c %s = %lf\n", argv[1], operator, argv[3], num1 + num2);
        break;
    case '-':
        printf("%s %c %s = %lf\n", argv[1], operator, argv[3], num1 - num2);
        break;
    case '*':
        printf("%s %c %s = %lf\n", argv[1], operator, argv[3], num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            print_error("A number cannot be divided by zero.");
        }
        else
        {
            printf("%s %c %s = %lf\n", argv[1], operator, argv[3], num1 / num2);
        }
        break;
    default:
        print_error("Unknown operator. Use +, -, * or /.");
        return 1;
    }

    return 0;
}