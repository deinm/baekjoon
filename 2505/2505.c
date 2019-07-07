#include <stdio.h>

int main()
{
	int i, j, k, n, tmp, arr[10000], arr2[10000], cnt = 0;
	int ans[10000] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr2[i] = arr[i];
	}

	for (i = 0; i < n; i++) {
		if (arr[i] != i + 1) {
			for (j = 0; j<n; j++) {
				if (arr[j] == i + 1) {

					if (i + 1<j + i) {
						ans[cnt * 2] = i + 1;
						ans[cnt * 2 + 1] = j + 1;
					}
					else {
						ans[cnt * 2 + 1] = i + 1;
						ans[cnt * 2] = j + 1;
					}

					cnt++;
					// printf("%d %d\n",i+1, j+1);
					for (k = 0; k<(int)((j - i + 1) / 2); k++) {
						tmp = arr[i + k];
						arr[i + k] = arr[j - k];
						arr[j - k] = tmp;
					}
				}
			}
		}
	}

	if (cnt>2) {
		for (i = n - 1; i >= 0; i--) {
			if (arr2[i] != i + 1) {
				for (j = 0; j<i; j++) {
					if (arr2[j] == i + 1) {
						int big, small;
						if (i + 1>j + 1) {
							big = i + 1;
							small = j + 1;
						}
						else {
							big = j + 1;
							small = i + 1;
						}
						printf("%d %d\n", small, big);
						for (k = 0; k<(int)((i - j + 1) / 2); k++) {
							tmp = arr2[j + k];
							arr2[j + k] = arr2[i - k];
							arr2[i - k] = tmp;
						}
					}
				}
			}
		}
	}
	else {
		for (i = 0; i<4; i++) {
			if (ans[i] == 0) printf("1");
			else printf("%d", ans[i]);
			if (i % 2 != 0) printf("\n");
			else printf(" ");
		}
	}
}