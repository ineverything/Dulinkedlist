#include "duLinkedList.h"
#include <stdio.h>
#include<stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!(*L))
	  return OVERFLOW;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS; 
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	while(*L){
		p = (*L)->next;
		free(*L);
		*L = p;
		if(p)
			p->prior = NULL;
	}	
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {	
	if(!p)
		return ERROR;
	if(p->prior){
		p->prior->next = q;
		q->prior = p->prior;
	}
	q->next = p;
	p->prior = q;
	return SUCCESS;	
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(!p)
		return ERROR;
	if(p->next){
		p->next->prior = q;
		q->next = p->next;
	}
	q->prior = p;
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {   //删除结点p后的第一个结点
	if(p == NULL|| p->next == NULL)
		 return ERROR;
	*e = p->next->data;
	DuLNode *q = p->next;
	p->next = p->next->next;
	q->next->prior = p;
	free(q);
	return SUCCESS;									 
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {  
	DuLNode *p = L->next;
	printf("链表里的元素有：");
	while(p){
		visit(p->data);
		p = p->next;
	}
	printf("\n"); 
}
