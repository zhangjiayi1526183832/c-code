﻿//双链表的实现
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
//定义双链表结点类型
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;	//指向前驱结点
	struct DNode* next;		//指向后继结点
} DLinkNode;

//定义双链表结点类型
void CreateListF(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));//创建新结点
		s->data = a[i];
		s->next = L->next;			//将结点s插在原开始结点之前,头结点之后
		if (L->next != NULL) L->next->prior = s;
		L->next = s; s->prior = L;
	}
}
//尾插法建双链表
void CreateListR(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior = L->next = NULL;
	r = L;					//r始终指向终端结点,开始时指向头结点
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));//创建新结点
		s->data = a[i];
		r->next = s; s->prior = r;	//将结点s插入结点r之后
		r = s;
	}
	r->next = NULL;				//尾结点next域置为NULL
}
//初始化链表
void InitList(DLinkNode*& L)
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior = L->next = NULL;
}

//销毁链表
void DestroyList(DLinkNode*& L)
{
	DLinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//判空
bool ListEmpty(DLinkNode* L)
{
	return(L->next == NULL);
}
//获取链表长度
int ListLength(DLinkNode* L)
{
	DLinkNode* p = L;
	int i = 0;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return(i);
}
//打印链表
void DispList(DLinkNode* L)
{
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//获取指定位置元素
bool GetElem(DLinkNode* L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0) return false;		//i错误返回假
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}
//获取指定元素位置
int LocateElem(DLinkNode* L, ElemType e)
{
	int n = 1;
	DLinkNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		n++;
		p = p->next;
	}
	if (p == NULL)
		return(0);
	else
		return(n);
}
//插入指定元素
bool ListInsert(DLinkNode*& L, int i, ElemType e)
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0) return false;		//i错误返回假
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//未找到第i-1个结点
		return false;
	else						//找到第i-1个结点p
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));	//创建新结点s
		s->data = e;
		s->next = p->next;		//将结点s插入到结点p之后
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}
//删除指定元素
bool ListDelete(DLinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L, * q;
	if (i <= 0) return false;		//i错误返回假
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//未找到第i-1个结点
		return false;
	else						//找到第i-1个结点p
	{
		q = p->next;				//q指向要删除的结点
		if (q == NULL)
			return false;		//不存在第i个结点
		e = q->data;
		p->next = q->next;		//从单链表中删除*q结点
		if (p->next != NULL) p->next->prior = p;
		free(q);				//释放q结点
		return true;
	}
}


//测试双链表
int main() {

	return 0;
}