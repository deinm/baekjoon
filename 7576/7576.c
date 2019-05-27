#include <stdio.h>

int w, h, map[1000][1000];
int xqueue[1000000], yqueue[1000000];
int xfront=0, yfront=0, xrear = 0, yrear = 0;

int main()
{
    int i,j; 
    scanf("%d %d", &w, &h);

    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==1) {
                xqueue[xrear] = i;
                yqueue[yrear] = j;
                xrear++;
                yrear++;
            }
        }
    }
    
    while(xfront<xrear){
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        int checkx, checky;
        checkx = xqueue[xfront];
        checky = yqueue[yfront];
        for(int i=0; i<4; i++){
            int move_x;
            int move_y;
            move_x = checkx + dx[i];
            move_y = checky + dy[i];
            if(move_x>=0&&move_y>=0&&move_x<h&&move_y<w&&map[move_x][move_y]==0){
                map[move_x][move_y] = map[checkx][checky]+1;
                xqueue[xrear] = move_x;
                yqueue[yrear] = move_y;
                xrear++;
                yrear++;
            }
        }
        xfront++;
        yfront++;
    }

    int max = 0;
    
    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            if(map[i][j]==0){
                printf("-1\n");
                return 0;
            }
            if(map[i][j]>max) max = map[i][j];
        }
    }

    printf("%d\n", max-1);
}