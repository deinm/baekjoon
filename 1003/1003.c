#include <stdio.h>

int main()
{
    int num, i, input;
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        scanf("%d", &input);
        int cnt = 1;
        int zero1 = 1, zero2 = 0, one1 = 0, one2 = 1;
        if(input==0){
            printf("%d %d\n", zero1, zero2);
            continue;
        }
        else if(input==1){
            printf("%d %d\n", one1, one2);
            continue;
        }

        for(int j=0; j<(input+1)/2; j++){
            zero1 += one1;
            zero2 += one2;
            cnt++;
            if(cnt==input) {
                printf("%d %d\n", zero1, zero2);
                break;
            }
            one1 += zero1;
            one2 += zero2;
            cnt++;
            if(cnt==input) {
                printf("%d %d\n", one1, one2);
                break;
            }
        }
    }
}