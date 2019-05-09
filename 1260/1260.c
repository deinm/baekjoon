#include <stdio.h>

int graph1[1001][1001] = {0,};
int graph2[1001][1001] = {0,};
int queue[1001] = {0,};

void dfs(int n, int first){
    int i;
    graph1[0][first] = 1;
    printf("%d ", first);
    for(i=1; i<=n; i++){
        if(graph1[first][i]==1 && graph1[0][i]==0) dfs(n,i);
    }
    return;
}

void bfs(int n, int first){
   int front = 0, rear = 0, i;
   graph2[0][first] = 1;
   printf("%d ", first);
   queue[0] = first;
   rear++;

   while(front<rear){
       first = queue[front];
       front++;
       for(i=1; i<=n; i++){
           if(graph2[first][i]==1 && graph2[0][i]==0){
               printf("%d ", i);
               queue[rear] = i;
               rear++;
               graph2[0][i] = 1;
           }
       }
   }
   
   return;
}

int main()
{
    int n, m ,v, i, x, y;
    scanf("%d %d %d", &n, &m, &v);
    for(i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        graph1[x][y] = 1;
        graph2[x][y] = 1;
        graph1[y][x] = 1;
        graph2[y][x] = 1;
    }

    dfs(n,v);
    printf("\n");
    bfs(n,v);
}