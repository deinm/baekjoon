#include <stdio.h>
 
void draw(int x, int y, int size){
    if((x/size)%3==1 && (y/size)%3==1) printf(" ");
    else{
        if(size/3 == 0) printf("*");
        else draw(x,y,size/3);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            draw(i,j,n);
        }
        printf("\n");
    }
    return 0;    
} 