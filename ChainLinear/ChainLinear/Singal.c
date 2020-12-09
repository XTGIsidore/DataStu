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
//尾插法创建单链表
LinkList CreateList_R(LinkList L, int n) {
	LNode* r = (LNode*)malloc(sizeof(LNode));
	int i = 0;
	//尾指针r指向头节点
	r = L;
	int data;
	for (i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &data);
		p->data = data;
		p->next = NULL;
		//插入到表尾
		r->next = p;
		//r指向新的尾结点
		r = p;
	}
	return L;
}
//输出单链表
void ListVisit(LinkList head) {
	while (head->next != NULL) {
		printf("%d\t", head->next->data);
		head->next = head->next->next;
	}
	printf("\n");
}
//插入(在第i个元素之后)
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
//删除
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
//销毁
//销毁单链表L
void DestroyList(LinkList L) { //销毁单链表L
	LinkList p; //或LNode *p;
	while (L->next != NULL) { // 或 while(L)
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

