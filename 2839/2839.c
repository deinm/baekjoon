#include <stdio.h>

int main()
{
    int n, i, bag=0;
    scanf("%d", &n);
    while(1){
        if(n<0) {
            printf("-1");
            break;
        }
        if(n%5==0){
            bag += n/5;
            printf("%d", bag);
            break;
        }
        else{
            n -= 3;
            bag++;
        }
    }
}