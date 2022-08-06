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
 *1设计一个递归算法，删除不带头节点的单链表L中所以有值为x的结点
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
 *2在带头节点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法
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
 *12在一个递增有序的线性表中，有数值相同的元素存在，若存储方式为单链表，设计算法，去掉数值相同的元素，使表中不再有重复的元素
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
 *3设L为带头结点的单链表，试编写算法实现从尾到头反向输出每个结点的值
 */
void R_print(LinkList L){
    if(!L->next) R_print(L->next); //先递归叠栈
    if(!L) printf("%d", L->data);  //再输出
}

void R_print_ignoreHead(LinkList L){ // 保证递归函数功能的单一性，对于头节点的处理另起函数
    R_print(L->next);
}



/*
 *5将带头结点的单链表就地逆置
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
 *4删除带头节点的单链表中删除最小值结点的算法(最小结点唯一)
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
 *6有一个带头结点的单链表L，设计一个算法使其元素递增有序
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

// 总结：tmp-p模版适用于，需要原节点自身进场操作。eg:链表原地排序操作， t10

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
 *9给定一个带头节点的单链表，按递增次序输出单链表中各节点的数据元素，并释放节点的存储空间（不允许使用数组座位辅助空间）
 */

// 法一：先将链表整体转为递增链表， 再顺序输出并删除
void order_delete1(LinkList &L){
    LNode *pre;
    LNode *p = L;
    LNode *tmp = p->next;
    
    p = p->next;
    
    while(p){
        tmp = p->next;
    
        pre = L;
        while(pre->next && pre->next->data < p->data){pre = pre->next;}
    
        p->next = pre->next;
        pre->next = p;
    
        //Mis. p = p->next;
        p = tmp;
    }
    
    
    LNode *del;
    while(L->next){
        cout<< L->next->data << " ";
        
        del = L->next;
        L->next = del->next;
        free(del);
        
        L = L->next;    
    
    }
    
    
}


// 法二：通过min找到最小值，原地删除
void order_delete2(LinkList &L){
    LNode* p, tmp, pre;
    
    int min;    LNode* minNode;
    
    LNode* del;
    
    
    while(L->next){ // 循环到只剩下头节点
        pre = L;
        tmp = L->next;
        min = INT_MAX;  
        while(pre->next){
            if(pre->next->data < min){
                    minNode = pre; // 存储最小节点的前驱节点
                    min = pre->next->data;
                    pre = pre->next;
                }
        }
        
        cout<< minNode->next->data << " ";
        del = pre->next;
        pre->next = del->next;
        free(del);
        
        
    }
    free(L);//最后删除头节点
}

// 法三 双指针找最小值，原地删除
void order_delete3(LinkList &L){
    LNode* pre, p, del;
    while(L->next){
        pre = L;
        p = L->next; 
        while(p->next){
            if(pre->next->data > p->next->data){
                pre = p;
            }
            p=p->next; 
        }
        cout<<pre->next->data << " ";
        del = pre->next;
        pre->next  = del;
        free(del);
    }
    
    free(L);
}



/////////////////////////////////////////////////////////

/*
 *7在无序带头节点的单链表L中，删除所有介于给定两个值之间的元素( l<val<r )
 */

// pre指针标准删除
void delete_range(LinkList &L, int l, int r){
    if(l >= r) return;
    
    LNode* pre = L, p = L->next;
    while(p){
        if(l<p->data && p->data<r){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            p = p->next;
            pre = pre->next;
        }
        
    }

}



/*
 *8给定来两个链表，编写算法找出两个链表的公共节点
 */
LNode* findPublic(LinkList L1, LinkList L2){
    LNode* r;
    while(L1){
        
        r = L2;
        while(r && !(L1->next == r->next && L1->data == r->data) ){
            r = r->next;
        }
        
        if(!r) return r;
        else L1 = L1->next;
    }
    
}

// 法二：利用公共节点后链表重合一致的特点
LNode* findPublic2(LinkList L1, LinkList L2){
    int len1 = 0, len2 = 0;
    LNode* p1 = L1, p2 = L2;
    while(L1 || L2){
        if(L1) {len1++; L1 = L1->next;} 
        if(L2) {len2++; L2 = L2->next;}
    }
    
    LinkList sp = (len1 > len2)? p2 : p1;
    LinkList lp = (len1 > len2)? p1 : p2;
    int delta = (len1 > len2) ? len1-len2 : len2 - len1;
    
    while(delta) lp = lp->next;
    while(sp){
        if(sp->data == lp->data && sp->next == lp->next) return sp;
        else{
            sp = sp->next; lp = lp->next;
        }
    }
    return NULL;
    
}

/*
 * 10将带头节点的单链表分解为两个带头节点的分链表，其中分别包含原链表的奇/偶数序号节点，注意节点相对顺序不变
 */
void display(LinkList L, LinkList &L1, LinkList &L2){
    LinkList L1 = (LinkList)malloc(sizeof(LNode));
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L1->next = NULL; L2->next = NULL;
    
    int len = 1;
    LNode* r, tmp, p = L->next, p1 = L1, p2 = L2;
    while(p){

        tmp = p->next;
        
        //尾插法插入
        if(len % 2 != 0){
            p->next = p1->next;
            p1->next = p;
            p1 = p;
        }
        else{
            p->next = p2->next;
            p2->next = p;
            p2 = p;
        }
        
        p = tmp;
        len++;
    }
    return;
}


// 法二：直接串起来
void display2(LinkList L, LinkList &L1, LinkList &L2){
    LinkList L1 = (LinkList)malloc(sizeof(LNode));
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L1->next = NULL; L2->next = NULL;
    
    if(length(L) == 1) {return;}
    if(length(L) == 2) {L1 = L; return;}
    
    LNode p = L = L->next;
    while(p && p->next){
        L1->next = p; 
        L2->next = p->next; 
        p = p->next->next;
    }
    if(p) L1->next = p;
    L1->next = NULL;
    L2->next = NULL;

}


/*
 *11设线性表C = {a1,b1,a2,b2,...,an,bn},采用头节点为hc的单链表存放，设计就地算法将其分解为线性表A{a1,a2,...,an} , B{bn,...,b2,b1}(逆序)
 */
void display3(LinkList L, LinkList &L1, LinkList &L2){
    LinkList L1 = (LinkList)malloc(sizeof(LNode));
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L1->next = NULL; L2->next = NULL;
    
    int len = 1;
    LNode* r, tmp, p = L->next, p1 = L1, p2 = L2;
    while(p){

        tmp = p->next;
        
        //尾插法插入A (tip: 尾插是换头的头插)
        if(len % 2 != 0){
            p->next = p1->next;
            p1->next = p;
            p1 = p;
        }
        //头插法插入B
        else{
            p->next = p2->next;
            p2->next = p;
        }
        
        p = tmp;
        len++;
    }
    return;
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