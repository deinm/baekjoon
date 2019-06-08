#include<stdio.h>

int main()
{
	int arr[5001] = { 0, };
	int n, m, count =0, total_count, i=1;

	scanf("%d %d", &n, &m);
	total_count =  n;

	printf("<");
	while (1) {
		if (i > n) i = i - n ;

		if (arr[i] == 0) { 
			count++;
		}

		if (arr[i] == 0 && count == m) {
			printf("%d", i);
			arr[i] = 1;
			count = 0;
			total_count--;
			if (total_count != 0)
				printf(", ");
			else {
				printf(">");
				break;
			}
		}
		i++;
	}
}