#include <stdio.h>
#include <string.h>
#include <math.h>
#include<ctype.h> // for isalpha,isnum,isalnum
char operator[100];
int operand[100], top1 = -1, top2 = -1;
void Process()
{
    int z;
    int x = operand[top1--];
    int y = operand[top1--];
    char opr = operator[top2--];
    switch (opr)
    {
    case '+':
        z = y + x;
        break;
    case '-':
        z = y - x;
        break;
    case '*':
        z = y * x;
        break;
    case '/':
        z = y / x;
        break;
    case '^':
        z = pow(y, x);
        break;
    }
    operand[++top1] = z;
}
int precedence(char opr)
{
    switch (opr)
    {
    case '+': 
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
int Infix_Evaluation(char *str)
{
    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];
        if(isdigit(ch)){
            int num=0;
            while(isdigit(str[i])){
                num=num*10+str[i]-48;
                i++;
            }
            i--; // to avoid skipping 
            operand[++top1]=num; 
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
           if(top2==-1){
             operator[++top2]=ch;
           }
           else {
            while(top2!=-1 && precedence(ch)<=precedence(operator[top2])){
                Process();
            }
            operator[++top2]=ch;
           }
        }
        else if(ch=='('){
            operator[++top2]=ch;
        }
        else if (ch==')'){
            while(operator[top2]!='('){
                Process();
            }
            top2--;
        }
    }
    while (top2!= -1)
    {
        Process();
    }
    return operand[top1--];
}
int postfix_Evaluation(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        if(isdigit(ch)){
            int num=0;
            while(isdigit(exp[i])){
                num=num*10+exp[i]-48;
                i++;
            }
            i--;
            operand[++top1]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int z;
            int x=operand[top1--];
            int y=operand[top1--];
            char opr=ch;
            switch(opr){
                case'+':
                z=y+x;
                break;
                case'-':
                z=y-x;
                break;
                case'*':
                z=y*x;
                break;
                case'/':
                z=y/x;
                break;
                case'^':
                z=pow(y,x);
                break;
            }
            operand[++top1]=z;
        }     
    }
    return operand[top1--];
}
int prefix_Evaluation(char *exp){
    int len=strlen(exp);
    for(int i=len-1;i>=0;i--){
        char ch=exp[i];
        if(isdigit(ch)){
            int num=0,base=1;
            while(i>=0 && isdigit(exp[i])){
                num=num+(exp[i]-'0')*base;
                base*=10;
                i--;
            }
            i++;
            operand[++top1]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int z;
            int x=operand[top1--];
            int y=operand[top1--];
            char opr=ch;
            switch(opr){
                case'+':
                z=y+x;
                break;
                case'-':
                z=y-x;
                break;
                case'*':
                z=y*x;
                break;
                case'/':
                z=y/x;
                break;
                case'^':
                z=pow(y,x);
                break;
            }
            operand[++top1]=z;
        }     
    }
    return operand[top1--];
}
int main()
{
    char str[100];
    printf("Enter Infix Expression : ");
    gets(str);
    printf("Result : %d\n",Infix_Evaluation(str));
    printf("Enter Postfix Expression : ");
    gets(str);
    printf("Result : %d\n",postfix_Evaluation(str));
    printf("Enter Prefix Expression : ");
    gets(str);
    printf("Result : %d\n",prefix_Evaluation(str));
    return 0;
}
