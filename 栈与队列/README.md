【课后题】顺序表相关

```cpp
#include<bits/stdc++.h>
using namespace std; 

#define INT_MAX 0x7fffffff;
#define INT_MIN 0x80000000;
const int N = 100010;

typedef struct{
    int data[N];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool empty(SqStack &S){
    if(S.top == -1) return 1;
    else return 0;
}


bool push(SqStack &S, int x){
    if(S.top == N - 1) return 0;
    S.data[++S.top] = x; return 1;
}

bool pop(SqStack &S, int &x){
    if(empty(S)) return 0;
    x = S.data[S.top--]; return 1;
}

bool top(SqStack S, int &x){
    if(empty(S)) return 0;
    x = S.data[S.top]; return 1;
}

/////////////////链栈//////////////////////


typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkStack;

void InitStack(LinkStack &S){
    S = (LinkStack)malloc(sizeof(LNode));
    S->next = NULL;
}

bool empty(LinkStack &S){
    if(S->next == NULL) return 1;
    else return 0;
}


void push(LinkStack &S, int x){
    LNode tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = x;
    
    tmp->next = S->next;
    S->next = tmp;
}

bool pop(LinkStack &S, LNode &x){
    if(empty(S)) return 0;
    x = S->next;
    S->next = x->next;
    return 1;
}

bool top(LinkStack &S, LNode &x){
    if(empty(S)) return 0;
    x = S->next;
    return 1;
}

//////////////////共享栈S1 + S2/////////////////////////////
/*标准写法
typede struct{ 
    int stack[N];
    int top[2];
}ShareStack;

*/



int Data[N];

void initShare(SqStack &s1, SqStack &s2){
    s1.top = -1;
    s2.top = N;
}

bool empty_s1(SqStack s1){
    if(s1.top == -1) return 1;
    else return 0;
}

bool empty_s1(SqStack s1){
    if(s2.top == N) return 1;
    else return 0;
}

bool push_s1(SqStack &s1, SqStack &s2, int x){
    if(s2.top - s1.top == 1) return 0;
    Data[++s1.top] = x; return 1;
}

bool push_s2(SqStack &s1, SqStack &s2, int x){
    if(s2.top - s1.top == 1) return 0;
    Data[++s2.top] = x; return 1;
}

bool pop_s1(SqStack &s1, int &x){
    if(empty_s1(s1)) return 0;
    x = Data[s1.top--]; return 1;
}


bool pop_s2(SqStack &s2, int &x){
    if(empty_s2(s2)) return 0;
    x = Data[s2.top++]; return 1;
}

```





/////////////////////队列//////////////////////////////


///////////////顺序队列（循环队列）///////////
```cpp
typedef struct{
    int data[N];
    int head, rear;
}Queue;


void init(Queue &q){
    q.head = 0; // 头指针指向队头元素
    q.rear = 0; // 尾指针指向队尾元素的下一位
}   

bool empty(Queue &q){
    if(rear == head) return 1;
    else return 0;
    

}
bool enQueue(Queue &q, int x){
    if((rear + 1) % N == head) return 0;
    q.data[q.rear] = x; // rear即是目标入队位置
    q.rear = (q.rear + 1) % N;
    return 1;
}

bool DeQueue(Queue &q, int &x){
    if(rear == head) return 0;
    x = q.data[q.head] // head即是(头元素)目标出队位置
    q.head = (q.head - 1) % N;
    return 1;
}



//////////////链队//////////////////
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *head, *rear;
}LinkQueue;



void init(LinkQueue &q){
    q.head = (QNode*)malloc(sizeof(QNode));
    q.rear = (QNode*)malloc(sizeof(QNode)); 
    q.head->next = q.rear->next = NULL;
}

bool empty(LinkQueue &q){
    if(q.rear == q.head) return 1;
    else 0;
}

void EnQueue(LinkQueue &q, int x){
    QNode* tmp = (QNode*)malloc(sizeof(QNode));
    tmp->data = x;
    
    //链队入队尾插（链栈入队头插）
    tmp->next = q.rear->next;
    q.rear->next = tmp;
    q.rear = tmp;

}

bool DeQueue(LinkQueue &q, QNode *x){
    if(empty(q))return 0;   
    x = q.head->next;
    q.head->next = x->next;
    
    /*特殊情况, 仅剩一个元素时,还要额外修改队尾指针(next置为NULL)*/
    if(q.head->next == x){
        q.rear = q.head;
    }
    
    return 1;

}



```



```cpp
/*
 * Q是一个队列S是一个空栈，实现队列中元素逆置
 */

void reverse(SqQueue& q, SqStack &st){
    int val; 
    
    while(!empty(q)){
        val = pop(q)
        push(st, val);
    }
    
    while(!empty(st)){
        val = pop(st);
        push(q, val);
    }
    return; 
    
}



/*
 *使用两个栈，模拟一个队列（push,pop,empty,oversize）
 */
typedef struct StNode{
    int data;
    struct Node *top;
}Stack;

Stack s1, s2;

bool Enqueue(Stack &s1, Stack &s2, int val){
    if(oversize(s1) && !empty(s2)){
        cout << "queue is full" << endl; 
        return 0; 
    }
    
    if(oversize(s1) && empty(s2)){
        int x; 
        while(!empty(s1)){
            pop(s1, x);
            push(s2, x);
        }
        push(s1, val);
    }
    
    if(!oversize(s1)){
        Push(s1, val);
        return 1; 
    }
    
    push(s1, val);
}

bool Dequeue(Stack &s1, Stack &s2, int val){
    if(!empty(s2)){
        pop(s2, val);
        return 1;
    }
    
    if(empty(s2) && !empty(s1)){
        int x;
        while(!empty(s1)){
            pop(s1, x);
            push(s2, x);
        }
        pop(s2, val);
        
        return 1;
    }
    if(empty(s2) && empty(s1)){
        cout << "queue is empty" << endl;
        return 0;
    }

    
}

    





```


