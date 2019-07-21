#include <stdio.h>
#include <string.h>
#include <ctype.h>

// +, -, *, /, (, )

int priority(char op){
    if(op=='+'){
        return 1;
    }
    else if(op=='-'){
        return 1;
    }
    else if(op=='*'){
        return 2;
    }
    else if(op=='/'){
        return 2;
    }
    else if(op=='('){
        return 0;
    }
}

int main()
{
    char stack[100] = {0,};
    char input[100] = {0,};
    int pointer = 0, pri, cur;

    scanf("%s", input);

    for(int i=0; i<strlen(input); i++){
        if(isalpha(input[i])){
            // 알파벳
            printf("%c", input[i]);
        }
        else{
            // 기호
            if(pointer==0){
                stack[pointer] = input[i];
                pointer++;
            }
            else{
                if(input[i]=='('){
                    stack[pointer] = '(';
                    pointer++;
                    continue;
                }

                if(input[i]==')'){
                    while(stack[pointer-1]!='('){
                        printf("%c", stack[pointer-1]);
                        pointer--;
                    }
                    pointer--;
                    continue;
                }

                pri = priority(stack[pointer-1]);
                cur = priority(input[i]);
                // printf("\n%d %c %d %c\n", pri, stack[pointer-1], cur, input[i]);

                if(cur>pri){
                    stack[pointer] = input[i];
                    pointer++;
                }
                else{
                    while(1){
                        if(pointer==0) break;
                        pri = priority(stack[pointer-1]);
                        cur = priority(input[i]);
                        if(pri<cur) break;

                        if(stack[pointer-1]!='('){
                            printf("%c", stack[pointer-1]);
                        }
                        pointer--;
                    }
                    stack[pointer] = input[i];
                    pointer++;
                }
            }
        }
    }

    while(pointer!=0){
        printf("%c", stack[pointer-1]);
        pointer--;
    }
}