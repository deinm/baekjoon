#include <stdio.h>

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main()
{
    int size, stair[300] = {0,}, score[300] = {0,};
    scanf("%d", &size);
    for(int i=0; i<size; i++) scanf("%d", &stair[i]);   
    
    score[0] = stair[0];
    score[1] = stair[0]+stair[1];
    score[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

    for(int i=3; i<size; i++){
        score[i] = max(stair[i]+score[i-2],stair[i]+stair[i-1]+score[i-3]);
    }

    printf("%d", score[size-1]);
}