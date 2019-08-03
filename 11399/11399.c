#include <stdio.h>

int main()
{
    int n, arr[1000] = {0,};
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]<arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int sum=0, ans=0;
    // 1 2 3 3 4
    for(int i=0; i<n; i++){
        sum += arr[i];
        ans += sum;
    }
    printf("%d",ans);
}