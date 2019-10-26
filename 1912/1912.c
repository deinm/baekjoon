#include <stdio.h>

int MAX(int a, int b){
    if(a>b) return a;
    else return b;
}
 
int main(void){
    
    int N, max = -1001;
    int Dp[100010] = {0,};
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++) {
        scanf("%d", &Dp[i]);
        Dp[i] = MAX(Dp[i], Dp[i]+Dp[i-1]);
        max = MAX(Dp[i], max);
        printf("%d\n",max);
    }
 
    printf("%d\n", max);
}