#include <stdio.h>

int main()
{
    int n, k, arr[10] = {0,}, cnt=0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        if(k==0) break;
        while(1){
            if(k-arr[i]>=0){
                k -= arr[i];
                cnt++;
            }
            else break;
        }
    }
    printf("%d\n", cnt);
}