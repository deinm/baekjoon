#include <stdio.h>

int arr[64][64] = { 0, };

void quad(int n, int start_i, int start_j) {
	int value = arr[start_i][start_j];
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[start_i + i][start_j + j] != value) {
				flag = 1;
			}
		}
	}

	if (flag == 0) printf("%d", value);
	else {
		printf("(");
		quad(n / 2, start_i, start_j);
		quad(n / 2, start_i, start_j + n/2);
		quad(n / 2, start_i + n/2, start_j);
		quad(n / 2, start_i + n/2, start_j + n/2);
		printf(")");
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	quad(n, 0, 0);
}