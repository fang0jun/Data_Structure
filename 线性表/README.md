【课后题】顺序表相关

```cpp
#include<bits/stdc++.h>
using namespace std; 

#define INT_MAX 0x7fffffff;
#define INT_MIN 0x80000000;
const int N = 100010;

typedef struct LNode{
    int data[N];
    int length;
}SqList;

/*
 *从顺序中删除具有最小值的元素(假设仅有一个)，函数返回被删除元素的值，空出的位置由最后一个元素填补。
 *
 *
 */

int Delete_min(SqList &L){
    if(L.length <= 0) return false;
    int Min_val = L.data[0], Min_idx;
    for(int i = 0; i < L.length; i++){
        if(Min_val > L.data[i]){
            Min_idx = i;
            Min_val = L.data[i];
        }
    }

    L.data[Min_idx] = L.data[L.length-1];
    length--;

    return Min_val;
}


/*
 *将两个有序顺序表合并为一个新的有序顺序表，并返回结果顺序表
 *
 */

SqList Combine_OrderList(SqList a, SqList b){
    SqList c;

    int i = 0, j = 0, idx = 0;
    int Min;
    while(i < a.length && j < b.length){
        if(a.data[i] < b.data[j]){
            c[idx++] = data[i++];
        }
        else{
            c[idx++] = data[j++];
        }
    }
    
    while(i <= a.length){
        c[idx++] = data[i++];
    } 
    while(i <= b.length){
        c[idx++] = data[j++];
    }

    return c;
}


/*
 * 设计一个高效算法， 将顺序表L的所有元素逆置，要求算法空间复杂度为O(1)
 *
 */
void reverse(SqList &l, int left, int right){
    int count = left - right / 2;
    while(count--){
        tmp = l[left] 
        l[left++] = l[right];
        l[right--] = tmp;
    }
    return;
}

/*
 * 若有数组包含两个线性表(a,b)，编写程序使得数组中两个线性表的顺序调换，即(b,a)；
 */

void reverse_List(SqList &c, int size_a, int size_b){
    reverse(c, 0, c.length-1);
    reverse(c, 0, size_b - 1);
    reverse(c, size_b, c.length-1);
}

/*
 *将数组中保存的序列 循环右移p个位置
 */

void removeLeft_q(SqList &c, int q){
    reverse(c, 0, c.length-1);
    reverse(c, 0, p-1);
    reverse(c, p, c.length-1);
}



/*
 *
 *对长度为n的顺序表L，编写程序删除线性表中所有值为x的数据元素。时间复杂度为O(n),空间复杂度为O(1)的
 *
 */

void Delete_val(SqList &L, int x){
    for(int i = 0, j = L.length - 1; i <= j ; ){
        if(L.data[i] == x){
            while(L.data[j] != x) j--;
            
            L.data[i++] = L.data[j--];
        }
        else i++;
    }

    L.length = j + 1 + 1;

    return; 
}


/*
 *从顺序表中删除其值在给定s与t之间(要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错结束
 */
int Deleta_range1(SqList &L, int s, int t){
    if(s>=t || s<INT_MIN || t>INT_MAX || L.length <= 0)  return 0;
    
    for(int i = 0, j = L.length - 1; i <= j ; ){
        if(s <= L.data[i] && L.data[i] <= t){
            while(s <= L.data[j] && L.data[j] <= t) j--;
            
            L.data[i++] = L.data[j--];
        }
        else i++;
    }

    L.length = j + 1 + 1;
    return 1;
    
}



/*
 *从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错结束
 */
int Deleta_range2(SqList &L, int s, int t){
    if(s>=t || s<INT_MIN || t>INT_MAX || L.length <= 0)  return 0;
    
    int i = 0, j = L.length - 1; 
    while(L.data[i] < s) i++;
    while(L.data[j] > t) j--;
    int size = j-i;
    while(j < l.length){
        L.data[i++] =  L.data[j++];
    }
    

    L.length -= size; 
    return 1;
    
}



/*
 *设计一个算法，对于有序递增顺序表，用最少时间查找数值为x的元素，若找到则将其与后继元素位置交换，若找不到则将其插入表中并保证递增有序
 */

void algorithm(SqList& L, int x){
    int flag = -1;  // flag既作为判断找到与否的标志，也作为未找到后的目标插入位置
    for(int i = 0; i<L.length-1; i++){ // 表尾元素无x，若其为x则无视
        if(L.data[i] < x && L.data[i+1] > x) flag = i;
        else if(L.data[i] == x) {
            tmp = L.data[i];
            L.data[i] = L.data[i+1];
            L.data[i+1] = tmp;

            break;
        }
    }

    if(flag>=0){
        for(int i = L.length - 1; i >= flag ; i--){
            L.data[i+1] = L.data[i];
        }
        L.data[flag] = x;
        L.length++;
    }

    return; 

}
```

【课后题】链表相关题目
```cpp
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;


/*
 *设计一个递归算法，删除不带头节点的单链表L中所以有值为x的结点
 */
void delete1_x(LinkList &L, int x){
    if(!L) return;
    // 不带头节点的时，删除目标节点的后一节点并存其值（后删法）
    if(L->data == x){
        LNode *q = L->next;
        int val = q->data;
        L->next = q->next;
        L->data = val;
        free(q);
        delete1_x(L, x) // 此时的L是删除节点过后的L
    }
    else delete1_x(L->next, x);
}

// 改进：无需后删法
void delete1_x_ver2(LinkList &L, int val){
    if(!L) return;
    if(L->data == x){
        LNode* q = L;
        L = L->next;
        free(q);
        delete1_x_ver2(L, val);
    }
    else delete1_x_ver2(L->next, val);
}



/*
 *在带头节点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法
 */
void delete2_x(LinkList &L, int x){
    LNode *pre = L, p = L->next;
    while(p){
        if(p->data == x){
            LNode* tmp = p;
            /*Fix*/p = p->next;
            pre->next = tmp->next;
            free(tmp);

            //Mis p = p->next;
            //Mis pre = pre->next;
        }
        else {
            p = p->next;
            pre = pre->next;
        }
    }
    return; 
}






/*
 *在一个递增有序的线性表中，有数值相同的元素存在，若存储方式为单链表，设计算法，去掉数值相同的元素，使表中不再有重复的元素
 */

void Clean(LinkList &L){
    LNode *p = L, aft = L->next // 注意与上题的区别，不带头节点的链表，L是头元素的具体结点
    while(aft){
        if(p->data == aft->data){
            //给当前aft结点先料理后事：存+移
            LNode* tmp = aft;
            aft = aft->next;

            p->next = tmp->next;
            free(tmp);
        }
        else{
            p = p-> next;
            aft = aft->next;
        }
    }

}


/*
 *设L为带头结点的单链表，试编写算法实现从尾到头反向输出每个结点的值
 */
void R_print(LinkList L){
    if(!L->next) R_print(L->next); //先递归叠栈
    if(!L) printf("%d", L->data);  //再输出
}

void R_print_ignoreHead(LinkList L){ // 保证递归函数功能的单一性，对于头节点的处理另起函数
    R_print(L->next);
}



/*
 *将带头结点的单链表就地逆置
 */

void R_list_ver1(LinkList p, LinkList L){ // tip:p = L->next作为工作指针, L作为头节点
    if(!p->next) R_list_ver1(p->next, L); //先递归叠栈
    if(!p){ // 在头节点处，进行尾插法  
        L->next = p;
        p->next = NULL;
        L = p;  
    }
}

void R_list_ver2(LinkList L){
    //摘出头节点,原地算法不能新创建一个新头节点
    LNode* p = L->next;
    L->next = NULL;

    // 在头节点处直接进行头插法
    while(!p){
        /*Mis,要存p->next*/ LNode* tmp = p->next;
        p->next = L->next;
        L->next = p;

        p = tmp;
    }
}



/*
 *删除带头节点的单链表中删除最小值结点的算法(最小结点唯一)
 */
void delete_min(LinkList& L){
    LNode *pre = L->next;
    while(L->next){
        if(L->next->data < pre->data) {
            //mis pre = L->next;
            pre = L;
            L = L->next;
        }
        else L = L->next;
    }

    LNode *minNode = pre->next;
    pre->next = minNode->next;
    free(minNode);
}


/*
 *有一个带头结点的单链表L，设计一个算法使其元素递增有序
 */

// 法一：时间：n^2原地
void ordeded1(LinkList &L){
    LNode *pre;

    LNode *p = L->next;
    LNode *tmp = p->next;
    p->next = NULL;

    p = tmp; 

    while(p){
        /*时刻保留的下一位以遍历*/
        tmp = p->next;
        
        /*原L表查找插入位置*/
        pre = L;
        while(pre->next && pre->next->data < p->data){pre = pre->next;}
        
        /*插入原L表*/
        p->next = pre->next;
        pre->next = p;

        p = tmp;
    }
}

// 法二：时间：nlogn非原地
const int 10010;
int arr[N]; 
void ordeded2(LinkList &L){
    int i = 0;
    L = L->next; 
    while(L){
        arr[i++] = L->data;
        L = L->next;
    }
    sort(arr, arr+i);

    LNode *p; p = (LNode *)malloc(sizeof(LNode));
    // 数组从后到前从大到小头插(有点小饶但代码简练)
    while(i--){
        LNode *tmp; tmp = (LNode *)malloc(sizeof(LNode));
        tmp->next = next;
        tmp->data = arr[i];

        tmp->next = p->next;
        p->next = tmp;
    }

}

/*
 *
 */
/*
 *
 */


/*
 *
 */
/*
 *
 */
/*
 *
 */

```