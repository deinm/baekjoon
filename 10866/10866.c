#include <stdio.h>
#include <string.h>

int main()
{
    int deque[10000] = {0,}, num, i, j, put, current=0;
    int tmp = 0;
    char tell[10];

    scanf("%d", &num);
    for(i=0; i<num; i++){
        tmp = deque[0];
        scanf("%s", tell);
        if(strcmp(tell,"push_back")==0){
            scanf("%d", &put);
            deque[current] = put;
            current++;
        }
        else if(strcmp(tell,"push_front")==0){
            scanf("%d", &put);
            for(j=current; j>0; j--){
                deque[j] = deque[j-1];
            }
            deque[1] = tmp;
            deque[0] = put;
            current++;
        }
        else if(strcmp(tell,"pop_front")==0){
            if(current==0) printf("-1\n");
            else {
                printf("%d\n", deque[0]);
                for(j=0; j<current-1; j++){
                    deque[j] = deque[j+1];
                }
                current--;
            }
        }
        else if(strcmp(tell,"pop_back")==0){
            if(current==0) printf("-1\n");
            else {
                printf("%d\n", deque[current-1]);
                deque[current-1] = 0;
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
        else if(strcmp(tell,"front")==0) {
            if (current==0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", deque[0]);
            }
        }
        else if(strcmp(tell,"back")==0) {
            if (current==0) {
                printf("-1\n");
            }
            else {
                //printf("CURRENT %d", deque[1]);
                printf("%d\n", deque[current-1]);
            }
        }
        else if(strcmp(tell,"printall")==0) {
            for(j=0; j<current; j++){
                printf("%d\n", deque[j]);
            }
        }
    }
}