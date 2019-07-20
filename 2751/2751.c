#include<stdio.h>
#define MAX 1000000    // 데이터 개수의 MAX 범위
#define qSWAP(x, y) { int t = x; x = y; y = t; }  // 간단한 SWAP 함수
int N, arr[MAX]; // 데이터 개수와 저장할 배열
 
void qSort(int *array, int left, int right) {
    int mLeft = left, mRight = right;
    int pivot = array[(left + right) / 2];
    
    while(mLeft <= mRight) {
        while(pivot > array[mLeft]) mLeft++;
        while(pivot < array[mRight]) mRight--;
        
        if(mLeft <= mRight) {
            qSWAP(array[mLeft], array[mRight]);
            printf("\n");
            mLeft++, mRight--;
        }
    }
 
    if(left < mRight) qSort(arr, left, mRight);
    if(mLeft < right) qSort(arr, mLeft, right);
}
 
int main() {
    int i;
    
    // 입력    
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    qSort(arr, 0, N - 1);    // 배열 인덱스 0 ~ N-1 까지 퀵소트
    
    // 출력
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0; 
}