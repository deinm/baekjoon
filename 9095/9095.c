#include <stdio.h>

int cnt;

void check(int num){
    if(num==0) {
        cnt++;
        return;
    }
    if(num>=1){
        check(num-1);
    }
    if(num>=2){
        check(num-2);
    }
    if(num>=3){
        check(num-3);
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        int num;
        cnt = 0;
        scanf("%d", &num);
        check(num);
        printf("%d\n", cnt);
    }
}