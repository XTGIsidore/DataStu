#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;

}LNode, * LinkList;
LinkList CreatListHead() {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}
//β�巨����������
LinkList CreateList_R(LinkList L, int n) {
	LNode* r = (LNode*)malloc(sizeof(LNode));
	int i = 0;
	//βָ��rָ��ͷ�ڵ�
	r = L;
	int data;
	for (i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &data);
		p->data = data;
		p->next = NULL;
		//���뵽��β
		r->next = p;
		//rָ���µ�β���
		r = p;
	}
	return L;
}
//���������
void ListVisit(LinkList head) {
	while (head->next != NULL) {
		printf("%d\t", head->next->data);
		head->next = head->next->next;
	}
	printf("\n");
}
//����(�ڵ�i��Ԫ��֮��)
void InsertList(LinkList head, int i, int elem) {
	LNode* node;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	node = head->next;
	int j = 0;
	while (node != NULL && j < i) {
		node = node->next;
		j++;
	}
	s->data = elem;
	s->next = node->next;
	node->next = s;
}
//ɾ��
void DeleteList(LinkList head, int i) {
	LNode* node = head->next;
	LNode* temp;
	int j = 0;
	while (node != NULL && j < i) {
		node = node->next;
		j++;
	}
	temp = node->next;
	node->next = node->next->data;
	node->next = temp->next;
	free(node);
}
//����
//���ٵ�����L
void DestroyList(LinkList L) { //���ٵ�����L
	LinkList p; //��LNode *p;
	while (L->next != NULL) { // �� while(L)
		p = L;
		L = L->next;
		free(p);
	}
}
int main() {
	LinkList L = CreatListHead();
	L = CreatList_R(L, 10);
	ListVisit(L);
}

