#include <stdio.h>

int num, arr[2187][2187], cnt[3]={0,};

void search(int n, int start_i, int start_j) {
	int value = arr[start_i][start_j];
	int flag = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[start_i + i][start_j + j] != value) {
				flag = 1;
			}
		}
	}

	if (flag == 0) cnt[value+1]++;
	else {
		search(n / 3, start_i, start_j);
		search(n / 3, start_i, start_j + n/3);
		search(n / 3, start_i, start_j + n/3 * 2);

		search(n / 3, start_i + n/3, start_j);
		search(n / 3, start_i + n/3, start_j + n/3);
		search(n / 3, start_i + n/3, start_j + n/3*2);

		search(n / 3, start_i + n/3*2, start_j);
		search(n / 3, start_i + n/3*2, start_j + n/3);
		search(n / 3, start_i + n/3*2, start_j + n/3*2);
	}
}

int main(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++) scanf("%d", &arr[i][j]);
    }
    search(num,0,0);
    for(int i=0; i<3; i++) printf("%d\n", cnt[i]);
}