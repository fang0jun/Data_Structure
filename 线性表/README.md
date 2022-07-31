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

/*
 *
 */

```