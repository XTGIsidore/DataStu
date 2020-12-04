#include<stdio.h>
int main() {
	void MergeList(int A[], int B[], int C[]);
	int array[] = { 3,5,8,11};
	int array1[] = { 2,6,8,9,11,15,20};
	int length0 = sizeof(array) / sizeof(array[0]);
	int length1 = sizeof(array1) / sizeof(array1[0]);
	int n = length0 + length1;
	int array2[20];
	int length = sizeof(array2) / sizeof(array2[0]);
	for (int j = 0; j < length; j++) {
		array2[j] = -1;
	}
	MergeList(array, array1, array2);
	for (int i = 0; i < length; i++) {
		if (array2[i] != -1) {
			printf("%d\t", array2[i]);
		}
	}
	return 0;
}

void MergeList(int A[], int B[], int C[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	while ((i < 4) && (j < 7)) {
		if (A[i] < B[j]) {
			C[k] = A[i];
			++i;
			++k;
		}
		else if (A[i] == B[j]) {
			C[k] = A[i];
			++i;
			++k;
			++j;
		}
		else if(A[i] > B[j])
		{
			C[k] = B[j];
			++j;
			++k;
		}
	}
	while (i < 4) {
		C[k] = A[i];
		i++;
		++k;
	}
	while (j < 7) {
		C[k] = B[j];
		j++;
		++k;
	}
}