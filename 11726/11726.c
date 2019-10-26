#include <stdio.h>

int arr[1001] = {0,};

int fibo(int num){
    if(num==1) return 1;
    if(num==2) return 2;
    if(arr[num]!=0) return arr[num];
    else{
        arr[num] = (fibo(num-1) + fibo(num-2))%10007;
        return arr[num];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}