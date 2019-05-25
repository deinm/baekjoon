#include <stdio.h>
#include <string.h>

int main()
{
    int iter;
    scanf("%d", &iter);

    for(int i=0; i<iter; i++){
        int stack_pointer=0, flag=0;
        char input[50];

        scanf("%s", input);
    
        for(int j=0; j< strlen(input); j++){
            if(input[j]=='('){
                stack_pointer++;
            }
            else{
                stack_pointer--;
            }
            if(stack_pointer<0) {
                flag = 1;
                break;
            }
        }
        if(flag==1||stack_pointer!=0) printf("NO\n");
        else printf("YES\n");
    }
}