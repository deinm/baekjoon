#include <stdio.h>

int arr[50][50] = {0,};
int w, h;

void check(int i, int j){
    //printf("CHECK i %d, j %d\n", i, j);
    arr[i][j]=0;
    int x[8] = {0,1,1,1,0,-1,-1,-1};
    int y[8] = {1,1,0,-1,-1,0,1,-1};
    int dx, dy;
    for(int k=0; k<8; k++){
        dx = i + x[k];
        dy = j + y[k];
        if(dx>=0 && dx<h && dy>=0 && dy<w && arr[dx][dy]==1){
            check(dx, dy);
        }
    }
}

int main()
{
    int i, j;
    while(1){
        scanf("%d %d", &w, &h);
        if(w==0&&h==0) break;

        for(i=0; i<h; i++){
            for(j=0; j<w; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        int cnt=0;

        for(i=0; i<h; i++){
            for(j=0; j<w; j++){
                if(arr[i][j] == 1) {
                    cnt++;
                    check(i,j);
                }
            }
        }

        printf("%d\n", cnt);
    }
}