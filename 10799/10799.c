#include <stdio.h>
#include <string.h>

int main()
{
    char input[100000], stack[100000];
    int point = 0, cnt=0;
    scanf("%s", input);
    for(int i=0; i<strlen(input); i++){
        if(input[i] =='('){
            stack[point] = '(';
            point++;
        }
        else{
            if(input[i-1]=='('){
                // 레이저
                cnt += point-1;
            }
            else{
                // 파이프 끝
                cnt += 1;
            }
            point--;
        }
    }
    printf("%d\n", cnt);
}