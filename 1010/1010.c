#include <stdio.h>
 
int main() {
    int dp[31][31] = { 0 };
    int n, N, M;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &N, &M);
            for (int i = 1; i <= M; i++) {
                dp[1][i] = i;
                for (int j = 2; j <= i; j++) {
                    dp[j][i] = dp[j - 1][i - 1] + dp[j][i - 1];
                }
            }
        printf("%d\n", dp[N][M]);
    }
 
    return 0;
}