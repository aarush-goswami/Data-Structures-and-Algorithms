#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str[10000];
    scanf("%s",str);
    int top=-1,len=strlen(str);
    char stack[len];
    for(int i=0;i<len;i++){
if(top==-1 || str[i]!=stack[top])
    stack[++top]=str[i];
        else top--;
        }
    stack[++top]='\0';
        
    printf("%s",stack);
    return 0;
}
