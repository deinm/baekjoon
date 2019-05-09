#include <stdio.h>
#include <string.h>

int main()
{
    int queue[10000] = {0,}, num, i, put, front=0, back=0;
    char tell[6];

    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%s", tell);
        if(strcmp(tell,"push")==0){
            scanf("%d", &put);
            queue[back] = put;
            back++;
        }
        else if(strcmp(tell,"pop")==0){
            if(front>=back) printf("-1\n");
            else {
                printf("%d\n", queue[front]);
                queue[front] = 0;
                front++;
            }
        }
        else if(strcmp(tell,"size")==0) {
            printf("%d\n",back-front);
        }
        else if(strcmp(tell,"empty")==0){
            if (front>=back) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if(strcmp(tell,"front")==0){
            if(front>=back) printf("-1\n");
            else printf("%d\n", queue[front]);
        }
        else if(strcmp(tell,"back")==0){
            if(front>=back) printf("-1\n");
            else printf("%d\n", queue[back-1]);
        }
    }
}