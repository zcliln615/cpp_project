/*------------------------------------------------------------*/
/// @author:李林
/// @date:2024-10-23
/// @brief:一个简单的计算器，支持加减乘除四则运算
/// @version:0.0
/// @version_note:@v0.0 实现了基本功能,数据类型统一为double，且未完成封装
/*------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAX 20

char command_buff[MAX];

int main()
{
    auto num1 = 0, num2 = 0, result = 0;
    char operator= '0';
    int c_count = 0;

    // 读取指令
    /*------------------------------------------------------------*/
    scanf("%c", command_buff);
    while (command_buff[c_count] != ' ')
    {
        scanf("%c", command_buff + c_count + 1);
        c_count++;
    }
    if (memcmp(command_buff, "./calculator", 12) != 0)
    {
        printf("Invalid command\n");
        return 1;
    }
    /*------------------------------------------------------------*/

    // 读取表达式
    // scanf会返回成功读取的参数个数，如果不等于3，说明输入的不是两个数和一个运算符
    if (scanf("%lf %c %lf", &num1, &operator, & num2) != 3)
    {
        printf("The input cannot be interpret as numbers!");
        return 1;
    }

    // 计算
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%lf %c %lf = %lf\n", num1, operator, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%lf %c %lf = %lf\n", num1, operator, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%lf %c %lf = %lf\n", num1, operator, num2, result);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("A number cannot be divied by zero.");
            return 1;
        }
        result = num1 / num2;
        printf("%lf %c %lf = %lf\n", num1, operator, num2, result);
        break;
    default:
        printf("Invalid operator");
        return 1;
    }

    return 0;
}