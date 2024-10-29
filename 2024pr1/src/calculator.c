#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
/// @brief 检查数组的数字类型
/// @param str
/// @return flag
/// 0:不是数字 1:可以用整形储存 2:利用浮点数储存
int is_what_number(const char *str)
{
    int check[MAX] = {}, i = 0, flag = 0;
    int point_sum = 0, e_sum = 0, sub_sum = 0, num_sum = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
            check[i] = 1;
        else if (str[i] == '.')
            check[i] = 2;
        else if (str[i] == 'e' || str[i] == 'E')
            check[i] = 3;
        else if (str[i] == '-')
            check[i] = 4;
        else
            return 0;
    }
    for (int j = 0; j < i; j++)
    {
        switch (check[j])
        {
        case 1:
            num_sum++;
            break;
        case 2:
            point_sum++;
            break;
        case 3:
            e_sum++;
            break;
        case 4:
            sub_sum++;
            break;
        }

        if (point_sum > 1 || e_sum > 1 || sub_sum > 2)
        {
            flag = 0;
            return flag;
        }
    }
    if ((num_sum == i - 1 && sub_sum == 1) || (num_sum == i))
        flag = 1;
    else
        flag = 2;
    return flag;
}

typedef enum _num_type
{
    intn = 1,
    doublen = 2,
} num_type;
typedef struct _autonum
{
    union
    {
        int intn;
        double doublen;
    } numbox;
    num_type flag;
} autonum;

int main(int argc, char *argv[])
{
    autonum num1, num2, result;
    // 检查命令参数是否完整
    if (argc != 4)
    {
        printf("Usage: ./calculator <num1> <operator> <num2>");
        return 1;
    }
    
    // 检查输入是否为数字
    if (is_what_number(argv[1]) == 0 || is_what_number(argv[3]) == 0)
    {
        printf("The input cannot be interpreted as numbers!");
        return 1;
    }

    // 检查运算符
    if (strlen(argv[2]) != 1 || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/'))
    {
        printf("Unknown operator. Use +, -, * or /.");
        return 1;
    }
    if (argv[2][0] == '/' && atof(argv[3]) == 0)
    {
        printf("A number cannot be divied by zero.");
        return 1;
    }

    // 将字符串转换为数字,并打印
    char operator= argv[2][0];
    if (is_what_number(argv[1]) == 1)
    {
        num1.numbox.intn = atoi(argv[1]);
        num1.flag = intn;
        printf("%d ", num1.numbox.intn);
    }
    else
    {
        num1.numbox.doublen = atof(argv[1]);
        num1.flag = doublen;
        printf("%f ", num1.numbox.doublen);
    }
    printf("%c ", operator);
    if (is_what_number(argv[3]) == 1)
    {
        num2.numbox.intn = atoi(argv[3]);
        num2.flag = intn;
        printf("%d = ", num2.numbox.intn);
    }
    else
    {
        num2.numbox.doublen = atof(argv[3]);
        num2.flag = doublen;
        printf("%f = ", num2.numbox.doublen);
    }

    // 打印结果

    if (num1.flag == intn)
    {
        if (num2.flag == intn)
        {
            switch (operator)
            {
            case '+':
                result.numbox.intn = num1.numbox.intn + num2.numbox.intn;
                printf("%d", result.numbox.intn);
                break;
            case '-':
                result.numbox.intn = num1.numbox.intn - num2.numbox.intn;
                printf("%d", result.numbox.intn);
                break;
            case 'x':
                result.numbox.intn = num1.numbox.intn * num2.numbox.intn;
                printf("%d", result.numbox.intn);
                break;
            case '/':
                result.numbox.doublen = (double)num1.numbox.intn / num2.numbox.intn;
                printf("%f", result.numbox.doublen);
                break;
            }
        }
        else
        {
            switch (operator)
            {
            case '+':
                result.numbox.doublen = num1.numbox.intn + num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case '-':
                result.numbox.doublen = num1.numbox.intn - num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case 'x':
                result.numbox.doublen = num1.numbox.intn * num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case '/':
                result.numbox.doublen = num1.numbox.intn / num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            }
        }
    }
    else
    {
        if (num2.flag == intn)
        {
            switch (operator)
            {
            case '+':
                result.numbox.doublen = num1.numbox.doublen + num2.numbox.intn;
                printf("%f", result.numbox.doublen);
                break;
            case '-':
                result.numbox.doublen = num1.numbox.doublen - num2.numbox.intn;
                printf("%f", result.numbox.doublen);
                break;
            case 'x':
                result.numbox.doublen = num1.numbox.doublen * num2.numbox.intn;
                printf("%f", result.numbox.doublen);
                break;
            case '/':
                result.numbox.doublen = num1.numbox.doublen / num2.numbox.intn;
                printf("%f", result.numbox.doublen);
                break;
            }
        }
        else
        {
            switch (operator)
            {
            case '+':
                result.numbox.doublen = num1.numbox.doublen + num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case '-':
                result.numbox.doublen = num1.numbox.doublen - num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case 'x':
                result.numbox.doublen = num1.numbox.doublen * num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            case '/':
                result.numbox.doublen = num1.numbox.doublen / num2.numbox.doublen;
                printf("%f", result.numbox.doublen);
                break;
            }
        }
    }

    return 0;
}