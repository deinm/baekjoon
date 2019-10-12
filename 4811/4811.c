#include <stdio.h>
 
int N;
long long dp[31][31]={0};
long long dfs(int W,int H){
    
    if(dp[W][H])
        return dp[W][H];
    
    if(W==0)
        return 1;
    
    dp[W][H] = dfs(W-1,H+1);
    if(H>0)
        dp[W][H] += dfs(W,H-1);
    
    return dp[W][H];
}
 
int main(){
    
    while(1){
        scanf("%d", &N);
        if(N==0)
            break;
        printf("%lld\n", dfs(N,0));
    }
    return 0;
}
