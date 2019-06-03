#include <stdio.h>
#include <ctype.h>
#include <string.h>

double cal(double a, double b, char c){
    if(c=='+'){
        return a+b;
    }
    else if(c=='-'){
        return a-b;
    }
    else if(c=='/'){
        return a/b;
    }
    else if(c=='*'){
        return a*b;
    }
}

int main()
{
    int num;
    int match[26] = {0,};
    char sample[100];
    double stack[100], num1, num2;
    int pointer = 0, stack_pointer = 0;

    scanf("%d", &num);
    scanf("%s", sample);

    for(int i=0;i<num; i++){
        scanf("%d", &match[i]);
    }

    for(int i=0; i<strlen(sample); i++){
        if(isalpha(sample[pointer])){
            stack[stack_pointer] = match[sample[pointer]-65];
            stack_pointer++;
            pointer++;
        }
        else{
            num1 = stack[stack_pointer-2];
            num2 = stack[stack_pointer-1];
            double calculate = cal(num1, num2, sample[pointer]);
            stack[stack_pointer-2] = calculate;
            pointer++;
            stack_pointer -= 1;
        }
    }

    printf("%.2f\n", stack[0]);
}