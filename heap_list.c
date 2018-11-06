#include<stdio.h>

#define LEFT_CHILD(x) (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x) ((x-1)/2)
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

void HeapSort(int *base, int n);
void ViewArr(int *arr, int n);
void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);
int FindMaxIndex(int *base, int n, int now);

struct Node {
	struct Node *next;
	int data;
	int num;//순서
};

void AddNode(struct Node *head, int data){
	struct Node *nodePtr = head;
	struct Node *newNode = malloc(sizeof(struct Node));

	int prevNum;

	while (nodePtr->next != NULL) {
		nodePtr = nodePtr->next;
		prevNum = nodePtr->num;
	}

	newNode->data = data;
	newNode->next = NULL;
	newNode->num = nodePtr->num + 1;

	nodePtr->next = newNode;
}

void MakeListNode(struct Node *head, int *numList, int n) {
	int i;
	for (i = 0; i < n; i++) {
		AddNode(head, numList[i]);
	}
}

//void SwapNode(struct Node *head, )

void PrintList(struct Node *head) {
	struct Node *nodePtr = head->next;
	
	while (nodePtr != NULL) {
		printf("%d(%d) ", nodePtr->data, nodePtr->num);
		nodePtr = nodePtr->next;
	}
}

int main(void) {
	/*struct Node *head = malloc(sizeof(struct Node));
	struct Node *head2 = malloc(sizeof(struct Node));
	head2->next = NULL;
	head2->num = 0;

	struct Node *node1 = malloc(sizeof(struct Node));
	head->next = node1;
	node1->data = 10;
	node1->next = NULL;

	AddNode(head, 20);
	AddNode(head, 30);

	int arr[3] = { 40,50,60 };
	MakeListNode(head2, arr, 3);

	PrintList(head2);

	/*
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	ViewArr(arr, 10);
	HeapSort(arr, 10);
	ViewArr(arr, 10);
	*/

	int a[10] = { 4, 2, 7, 6, 8, 5, 10, 1, 3, 9 };

	ViewArr(a, 10);
	HeapSort(a, 10);
	ViewArr(a, 10);
	
	return 0;
}

void HeapSort(int *base, int n) {
	printf("초기 힙 생성 과정\n");
	InitHeap(base, n);
	n--;
	SWAP(base[0], base[n]);

	printf("정렬과정\n");
	while (n > 1) {
		MakeHeap(base, n);
		ViewArr(base, n + 1);
		n--;
		SWAP(base[0], base[n]);
	}
	ViewArr(base, n + 1);
}

void InitHeap(int *base, int n) {
	int pa = 0;
	int now;
	int i;
	for (i = 1; i < n; i++) {
		now = i;
		while (now > 0) {
			pa = PARENT(now);
			if (base[now] > base[pa]) {
				SWAP(base[now], base[pa]);
				now = pa;
			}
			else {
				break;
			}

			ViewArr(base, i + 1);
		}
		ViewArr(base, i + 1);
	}
}

void MakeHeap(int *base, int n) {
	int now = 0;
	int mp = 0;

	while (LEFT_CHILD(now) < n) {
		int mp = FindMaxIndex(base, n, now);
		if (mp == now) {
			break;
		}
		if (base[mp] > base[now]) {
			SWAP(base[mp], base[now]);
		}
		now = mp;
	}
}

int FindMaxIndex(int *base, int n, int now) {
	int lc = LEFT_CHILD(now);
	int rc = RIGHT_CHILD(now);

	if (rc >= n) {
		if (base[now] < base[lc]) {
			return lc;
		}
		return now;
	}

	if (base[lc] < base[rc]) {
		return rc;
	}
	return lc;
}

void ViewArr(int *arr, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}