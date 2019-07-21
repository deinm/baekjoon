#include <stdio.h>

int graph[101][101] = {0,};
int num;

void search(int start, int target){
    if(start==target) graph[0][start]=2;
    else graph[0][start]=1;

    for(int i=1; i<=num; i++){
        if(graph[start][i]==1&&graph[0][i]!=1){
            graph[target][i] = 1;
            if(graph[0][i]==0) search(i, target);
        }
    }
}

int main()
{
    scanf("%d", &num);
    int tmp;

    for(int i=1; i<=num; i++){
        for(int j=1; j<=num; j++){
            scanf("%d", &tmp);
            if(tmp==1){
                graph[i][j]=1;
            }
        }
    }

    for(int i=1; i<=num; i++){
        for(int j=0; j<=num; j++) graph[0][j]=0;
        search(i, i);
    }

    for(int i=1; i<=num; i++){
        for(int j=1; j<=num; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}