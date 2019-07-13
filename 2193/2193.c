#include <stdio.h>
//1 1 2 3 5 8 13
int main()
{
    long long int num, a = 1, b = 1, c = 0;
    scanf("%d", &num);
    if(num==1) printf("1");
    else if(num==2) printf("1");
    else{
        for(int i=0; i<num-2; i++){
            c = a+b;
            a = b;
            b = c;
        }
        printf("%lld\n", c);
    }
}