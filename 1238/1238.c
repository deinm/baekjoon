#include <stdio.h>

// 정점의 수가 최대 20000개이므로 일반 배열, 즉 20000 * 20000의 int형 배열로는 메모리 초과
int arr[1001][1001] = { 0, }, arr2[1001][1001] = { 0, };;
int min[1001] = { 0, }, min2[1001] = { 0, }, visit[1001] = { 0, }, visit2[1001] = { 0, };

int main()
{
	int v, e, k, u, w, x;
	int index = 0;
	scanf("%d %d %d", &v, &e, &k);

	// 배열 INF 초기화
	for (int i = 0; i <= v; i++) {
		for (int j = 0; j <= v; j++) {
			arr[i][j] = 200000;
			arr2[i][j] = 200000;
		}
	}

	for (int i = 0; i<e; i++) {
		scanf("%d %d %d", &u, &x, &w);
		arr[u][x] = w;
		arr2[x][u] = w;
	}

	// 첫 번째 노드랑 연결된 값들로 초기화
	for (int i = 0; i <= v; i++) {
		if (arr[k][i] != 0) min[i] = arr[k][i];
	}

	// 첫번째 노드 방문 완료
	visit[k] = 1;
	min[k] = 0;

	for (int k = 0; k<v; k++) {
		int min_value = 200000;

		// min 배열에서 제일 작은 값의 인덱스 찾기
		for (int i = 1; i <= v; i++) {
			if (min[i]<min_value&&visit[i] == 0) {
				min_value = min[i];
				index = i;
			}
		}

		for (int i = 1; i <= v; i++) {
			int temp = arr[index][i] + min_value;
			if (temp<min[i]) min[i] = temp;
		}
		visit[index] = 1;
	}

	// 첫 번째 노드랑 연결된 값들로 초기화
	for (int i = 0; i <= v; i++) {
		if (arr2[k][i] != 0) min2[i] = arr2[k][i];
	}

	// 첫번째 노드 방문 완료
	visit2[k] = 1;
	min2[k] = 0;

	for (int k = 0; k<v; k++) {
		int min_value = 200000;

		// min 배열에서 제일 작은 값의 인덱스 찾기
		for (int i = 1; i <= v; i++) {
			if (min2[i]<min_value&&visit2[i] == 0) {
				min_value = min2[i];
				index = i;
			}
		}

		for (int i = 1; i <= v; i++) {
			int temp = arr2[index][i] + min_value;
			if (temp<min2[i]) min2[i] = temp;
		}
		visit2[index] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= v; i++) {
		if (min[i] + min2[i]>ans) ans = min[i] + min2[i];
	}
	printf("%d", ans);
}