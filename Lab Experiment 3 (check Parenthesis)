#include <stdio.h>
#include <string.h>
int checkBalanced(char *str)
{
    int len = strlen(str);
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            stack[++top] = ch;
        }
        else if (ch == '}' || ch == ')' || ch == ']')
        {
            if (top == -1 || ch == ')' && stack[top] != '(' || ch == '}' && stack[top] != '{' || ch == ']' && stack[top] != '[')
            {
                return 0;
            }
            else
                top--;
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    char str[100];
    printf("Enter string: ");
    gets(str);
    int result = checkBalanced(str);
    if (result)
        printf("Balanced \n");
    else
        printf("Not Balanced !!\n");
    return 0;
}
