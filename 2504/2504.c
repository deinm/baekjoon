#include <stdio.h>
#include <string.h>

int main()
{
    int sum=0, tmp = 1;
    char str[33];
    char stack[30];
    int pointer=0;

    scanf("%s", str);

    int length = strlen(str);

    for(int i=0; i<length; i++){
        if(str[i]=='('){
            tmp *= 2;
            stack[pointer] = '(';
            pointer++;
        }
        else if(str[i]=='['){
            tmp *= 3;
            stack[pointer] = '[';
            pointer++;
        }
        else if(str[i] == ')'){
            if(str[i-1]=='(') sum+=tmp;
            if(pointer==0) {
                printf("0");
                return 0;
            }
            if(stack[pointer-1]=='(') pointer--;
            tmp /= 2;
        }
        else if(str[i]==']'){
            if(str[i-1]=='[') sum+=tmp;
            if(pointer==0){
                printf("0");
                return 0;
            }
            if(stack[pointer-1]=='[') pointer--;
            tmp /= 3;
        }
    }

    printf("%d", pointer==0? sum : 0);
}