#include<iostream>

using namespace std;


typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 初始，创建头节点
LinkList L = (LinkList)malloc(sizeof(LNode));
L->next = NULL;

// 头插法,常用于插入结点(快速)
void HeadInsert(int val){
    LNode* tmp = (LNode *)malloc(sizeof(LNode));
    tmp->data = val;
    tmp->next = L->next;
    L->next = tmp;
}

// 尾插法,常用于初始化链表(耗时)
LinkList Init_HailInsert(LinkList &L){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    char val;
    LNode* hail = L;
    scanf("%c", &val )
    while(val != 'e'){
        LNode* tmp = (LNode *)malloc(sizeof(LNode));
        
        tmp->data = val-'0';
        tmp->next = NULL;
        hail->next->tmp;
        hail = r;
    }

    return L;
}

LNode* FindPos(LinkList L, int pos){
    LNode* p = L;
    int i = 0;
    while(p != NULL && i < pos++){
        p=p->next;
    }
    return p; 
}

LNode * FindElem(LinkList L, int val){
    LNode* p = L;
    while(p != NULL && p->data!=val){
        p = p->next;
    }

    returnp;
}

LinkList Inset(LinkList& L, int pos, int val){
    LNode* s = FindPos( L, pos-1); // 前插则pos-1,后插则pos

    LNode* p = (LNode*)malloc(sizeof(LNode));

    p->data = val;
    p->next = s->next;
    s->next = p;
}

LinkList Delete(LinkList& L, int pos){
    LNode* p = FindPos(L, pos-1);
    LNode* tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}