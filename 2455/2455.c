#include <stdio.h>

int main()
{
    int i, current, input, arr[5] = {0,}, max=0;
    for(i=0; i<4; i++){
        scanf("%d %d", &current, &input);
        arr[i+1] = arr[i]+input-current;
    }
    for(i=0; i<5; i++){
        if(arr[i]>max) max = arr[i];
    }
    printf("%d", max);
}