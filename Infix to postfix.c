#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int checkPrecedence(char operator)
{

    switch (operator)
    {
    case '-':
    case '+':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
}
char *convertInfixToPostfix(char *expression)
{
    int size = strlen(expression), top = -1, index = 0;
    char *str = (char *)malloc(size + 1);
    char stack[size];
    for (int i = 0; i < size; i++)
    {
        char ch = expression[i];
        if (isalnum(ch))
        {
            stack[++top] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top == -1)
                stack[++top] = ch;
            else
            {
                while (top != -1 && checkPrecedence(ch) <= checkPrecedence(stack[top]))
                {
                    str[index++] = stack[top--];
                }
                stack[++top] = ch;
            }
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                str[index++] = stack[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        str[index++]=stack[top--];
    }
    str[index]='\0';
    return str;
}
int main()
{
    char expression[100];
    printf("Enter infix expression : ");
    gets(expression);
    printf("Expression after Evaluation is %s",convertInfixToPostfix(expression));
    return 0;
}
