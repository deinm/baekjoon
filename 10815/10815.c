#include <stdio.h>
# define SWAP(x, y) {int temp = x; x=y; y=temp;}

int A[500001] = { 0, };
int m, n, num;

void q_sort(int left, int right) {
	int mid = (left + right) / 2;
	int pivot = A[left];
	int i = left, j = right;

	if (left >= right) {
		return;
	}

	while (i < j) {
		while (pivot < A[j]) {
			j--;
		}

		while (i < j && pivot >= A[i]) {
			i++;
		}

		SWAP(A[i], A[j]);
	}
	SWAP(A[left], A[i]);

	q_sort(left, i - 1);
	q_sort(i + 1, right);
}

int find(int num) {
	int left = 0;
	int right = m - 1;

	while (right >= left) {
		int mid = (right + left) / 2;

		if (A[mid] == num) return 1;
		else if (A[mid]>num) right = mid - 1;
		else left = mid + 1;
	}

	return 0;
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		scanf("%d", &A[i]);
	}
	q_sort(0, m - 1);

	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &num);
		printf("%d\n", find(num));
	}
}