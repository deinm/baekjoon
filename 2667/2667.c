#include <stdio.h>

int arr[25][25] = {0,};
int size;
int cnt=0;
int danzi[323]={0,};

void check(int i, int j, int count){
    arr[i][j]=0;
    danzi[count]++;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};
    int dx, dy;
    for(int k=0; k<4; k++){
        dx = i + x[k];
        dy = j + y[k];
        if(dx>=0 && dx<size && dy>=0 && dy<size && arr[dx][dy]==1){
            check(dx, dy, count);
        }
    }
}

int main()
{
    int i, j, tmp;
    scanf("%d", &size);

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(arr[i][j] == 1) {
                check(i,j,cnt);
                cnt++;
            }
        }
    }

    for(i=0; i<=(int)((size*size+1)/2); i++){
        for(j=0; j<=(int)((size*size+1)/2); j++){
            if(danzi[i]<danzi[j]){
                tmp = danzi[i];
                danzi[i] = danzi[j];
                danzi[j] = tmp;
            }
        }
    }

    printf("%d\n", cnt);
    for(i=1; i<=(int)((size*size+1)/2); i++) {
        if(danzi[i]!=0){
            printf("%d\n", danzi[i]);
        }
    }
}