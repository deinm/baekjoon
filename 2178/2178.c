#include <stdio.h>

int map[101][101] = {0,};
int w,h;

void bfs(int x, int y, int value){
    if(x==w-1&&y==h-1) {
        if(map[x][y]==1) map[x][y] = value;
        else if(map[x][y]>value) map[x][y]=value;
        return;
    }

    if(map[x][y]==1) map[x][y] = value;
    else if(map[x][y]!=1&&map[x][y]>value){
        map[x][y] = value;
    }
    else return;

    int xdir[4] = {0,0,1,-1};
    int ydir[4] = {1,-1,0,0};
    int dx, dy;
    for(int i=0; i<4; i++){
        dx = x + xdir[i];
        dy = y + ydir[i];
        if(dx>=0&&dx<w&&dy>=0&&dy<h&&map[dx][dy]>=1){
            bfs(dx,dy, map[x][y]+1);
        }
    }
}

int main()
{
    int i,j;
    scanf("%d %d", &w, &h);
    for(i=0;i<w;i++){
        for(j=0;j<h;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(0,0, 2);

    printf("%d\n", map[w-1][h-1]-1);
}