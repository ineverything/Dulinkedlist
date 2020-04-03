#include "duLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
	
	
/* Status InitList_DuL(DuLinkedList *L)
void DestroyList_DuL(DuLinkedList *L)
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
Status DeleteList_DuL(DuLNode *p, ElemType *e)  */

void visit(ElemType e){
	printf("%d ",e);
} 
DuLNode* createDuLNode(ElemType data);

int main(int argc, char *argv[]) {
	
	DuLinkedList L; 
	InitList_DuL(&L);
	ElemType e; 
	//创建链表 
	DuLNode *p = createDuLNode(1); 
	DuLNode *q = createDuLNode(2);
	DuLNode *r = createDuLNode(3);
	DuLNode *s = createDuLNode(4);
	InsertAfterList_DuL(L, s);
  	InsertBeforeList_DuL(s, r);
	InsertBeforeList_DuL(r, q);
	InsertBeforeList_DuL(q, p);
	//遍历链表 
	TraverseList_DuL(L,visit);	
	
	printf("删除第一个结点后面的结点\n");
 	if(DeleteList_DuL(p, &e))
 		printf("删除成功，这个结点里元素的值是%d\n",e);
 	else 
	 	printf("删除失败");
	TraverseList_DuL(L,visit);	  
	DestroyList_DuL(&L);
	
	return 0;
}
DuLNode* createDuLNode(ElemType data)
{	
	DuLNode *newNode = (DuLNode*)malloc(sizeof(DuLNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prior = NULL;
	return newNode;
} 
