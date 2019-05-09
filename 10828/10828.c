#include <stdio.h>
#include <string.h>

int main()
{
    int stack[10000] = {0,}, num, i, put, current=0;
    char tell[6];

    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%s", tell);
        if(strcmp(tell,"push")==0){
            scanf("%d", &put);
            stack[current] = put;
            current++;
        }
        else if(strcmp(tell,"pop")==0){
            if(current-1<0) printf("-1\n");
            else {
                printf("%d\n", stack[current-1]);
                stack[current-1] = 0;
                current--;
            }
        }
        else if(strcmp(tell,"size")==0) {
            printf("%d\n",current);
        }
        else if(strcmp(tell,"empty")==0){
            if (current==0) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if(strcmp(tell,"top")==0) {
            if (current-1<0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", stack[current-1]);
            }
        }
    }
}