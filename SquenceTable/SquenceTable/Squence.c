#include<stdlib.h>
#include<stdio.h>
#define MaxSize 7
#define IncreaseSize 4
typedef struct {
	int* elem; //数组首地址
	int length; //当前线性表的长度
	int listsize; //当前给线性表分配的存储空间大小
}SqList;

void quicksort(int a[], int n) {
	int i, j;
	int pivot = a[0];	//设置基准值 
	i = 0;
	j = n - 1;
	while (i < j) {
		//大于基准值者保持在原位置 
		while (i < j && a[j] > pivot) { j--; }
		if (i < j) {
			a[i] = a[j];
			i++;
		}
		//不大于基准值者保持在原位置 
		while (i < j && a[i] <= pivot) { i++; }
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = pivot;	//基准元素归位 
	if (i > 1) {
		//递归地对左子序列 进行快速排序
		quicksort(a, i);
	}
	if (n - i - 1 > 1) {
		quicksort(a + i + 1, n - i - 1);
	}
}

int main() {
	int MergeList(SqList L1, SqList L2, SqList L3);
	int ListInsert(SqList L, int i, int ElemType);
	int ListDelete(SqList L, int i);
	SqList list1;
	SqList list2;
	SqList list3;
	list1.elem = (int)malloc(MaxSize * sizeof(int));
	list1.length = 0;
	list1.listsize = MaxSize;
	printf("list1:\n");
	for (int i = 0; i < MaxSize; i++) {
		list1.elem[i] = rand();
		list1.length++;
	}
	quicksort(list1.elem, list1.length);
	for (int I = 0; I < MaxSize; I++) {
		printf("%d\t", list1.elem[I]);
	}
	printf("\n");
	printf("list1.length = %d\n", list1.length);
	list2.elem = (int)malloc(IncreaseSize * sizeof(int));
	list2.length = 0;
	list2.listsize = IncreaseSize;
	printf("list2:\n");
	for (int j = 0; j < IncreaseSize; j++) {
		list2.elem[j] = rand();
		list2.length++;
	}
	quicksort(list2.elem, list2.length);
	for (int J = 0; J < IncreaseSize; J++) {
		printf("%d\t", list2.elem[J]);
	}
	printf("\n");
	printf("list2.length = %d\n", list2.length);
	list3.elem = (int)malloc((MaxSize + IncreaseSize) * sizeof(int));
	list3.length = 0;
	list3.listsize = MaxSize + IncreaseSize;
	list3.length = MergeList(list1, list2, list3);
	printf("list3:\n");
	for (int k = 0; k < list3.length; k++) {
		printf("%d\t", list3.elem[k]);
	}
	printf("\n");
	printf("list3.length = %d\n", list3.length);
	list3.length = ListInsert(list3, 5, 668);
	quicksort(list3.elem, list3.length);
	printf("New list3:\n");
	for (int K = 0; K < list3.length; K++) {
		printf("%d\t", list3.elem[K]);
	}
	printf("\n");
	printf("list3.length = %d\n", list3.length);
	list3.length = ListDelete(list3, 5);
	quicksort(list3.elem, list3.length);
	printf("New list3:\n");
	for (int K1 = 0; K1 < list3.length; K1++) {
		printf("%d\t", list3.elem[K1]);
	}
	printf("\n");
	printf("list3.length = %d\n", list3.length);
	return 0;
}

int MergeList(SqList L1, SqList L2, SqList L3) {
	int i = 0, j = 0, k = 0;
	while ((i < L1.length) && (j < L2.length)) {
		if (L1.elem[i] < L2.elem[j]) {
			L3.elem[k] = L1.elem[i];
			++i;
			++k;
		}
		else if (L1.elem[i] == L2.elem[j]) {
			L3.elem[k] = L1.elem[i];
			++i;
			++k;
			++j;
		}
		else if (L1.elem[i] > L2.elem[j]) {
			L3.elem[k] = L2.elem[j];
			++j;
			++k;
		}
	}
	while (i < L1.length) {
		L3.elem[k] = L1.elem[i];
		i++;
		++k;;
	}
	while (j < L2.length) {
		L3.elem[k] = L2.elem[j];
		j++;
		++k;
	}
	return k;
}

int ListInsert(SqList L, int i, int ElemType) {
	if (i < 0 || i >= L.length) {
		printf("输入不合法！");
	}
	if (L.length == L.listsize) {
		L.elem = (int)realloc(L.elem, (L.listsize + 1) * sizeof(int));
	}
	L.listsize += 1;
	for (int j = L.length - 1; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i] = ElemType;
	return L.listsize;
}

int ListDelete(SqList L, int i) {
	if (i < 0 || i >= L.length) {
		printf("输入不合法！");
	}
	for (int j = i + 1; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	return L.length - 1;
}

