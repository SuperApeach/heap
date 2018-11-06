#include<stdio.h>

#define LEFT_CHILD(x) (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x) ((x-1)/2)
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

void PrintArr(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InitHeap(int *source, int n) {
	int i;
	int cur;
	for (i = 0; i < n; i++) {
		cur = i;
		while (cur > 0) {
			if (source[cur] > source[PARENT(cur)]) {
				SWAP(source[cur], source[PARENT(cur)]);
				cur = PARENT(cur);
			}
			else {
				break;
			}
			PrintArr(source, i + 1);
		}
		PrintArr(source, i + 1);
	}
}

void MakeHeap(int *source, int n) {
	int i = 0;
	int cur = 0;
	int fm = 0;
	while (LEFT_CHILD(cur) < n) {
		fm = FindMaxIndex(source, n, cur);
		if (source[cur] < source[fm]) {
			SWAP(source[cur], source[fm]);
		}
		if (cur == fm) {
			break;
		}
		cur = fm;
	}
}

void HeapSort(int *source, int n) {
	InitHeap(source, n);
	n--;
	SWAP(source[0], source[n]);

	while (n > 1) {
		MakeHeap(source, n);
		PrintArr(source, n + 1);
		n--;
		SWAP(source[0], source[n]);
	}
	PrintArr(source, n + 1);
}

int FindMaxIndex(int *source, int n, int cur) {
	
	if (RIGHT_CHILD(cur) >= n) {
		if (source[cur] < source[LEFT_CHILD(cur)]) {
			return LEFT_CHILD(cur);
		}
		else
			return cur;
	}
	
	if (source[LEFT_CHILD(cur)] > source[RIGHT_CHILD(cur)]) {
		if (source[cur] < source[LEFT_CHILD(cur)]) {
			return LEFT_CHILD(cur);
		}
		else {
			return cur;
		}
	}
	else {
		if (source[cur] < source[RIGHT_CHILD(cur)]) {
			return RIGHT_CHILD(cur);
		}
		else
			return cur;
	}
}



int main() {
	int a[10] = { 4, 2, 7, 6, 8, 5, 10, 1, 3, 9 };

	int b[3] = { 1,2,3 };
	int c[3] = { 3,1,2 };
	int d[3] = { 2,3,1 };
	int e[3] = { 2,2,1 };
	int f[2] = { 1,2 };
	int g[2] = { 2,1 };
	int aa;
	aa=FindMaxIndex(b, 3, 0);
	printf("%d\n", aa);
	aa=FindMaxIndex(c, 3, 0);
	printf("%d\n", aa);
	aa = FindMaxIndex(d, 3, 0);
	printf("%d\n", aa);
	aa = FindMaxIndex(e, 3, 0);
	printf("%d\n", aa);
	aa = FindMaxIndex(f, 2, 0);
	printf("%d\n", aa);
	aa = FindMaxIndex(g, 2, 0);
	printf("%d\n", aa);

	PrintArr(a, 10);

	HeapSort(a, 10);

	PrintArr(a,10);

	return 0;
} 