#include<iostream>

using namespace std;


// 静态顺序表
const int N = 100010;
typedef struct{
    int data[N];
    int length;
}SqList;

// 动态顺序表
typedef struct{
    int *data;
    int length, MaxSize;
}SqList_D;
SqList_D l2;
l2.data = (int *)malloc(sizeof(int)  * 100010); // C风格
l2.data = new int[N];                           // C++风格



/////////////////////////////////operator////////////////////////////
bool Insert(SqList &L, int pos, int val){
    if(pos <= 0 || pos >= L.length+2) return false;

    for(int i = L.length; i >= pos; i--){
        L.data[i] = L.data[i-1];
    }

    L.data[pos-1] = val;
    L.length++;

    return true;
}

bool Delete(SqList &L, int pos, int& ret){
    if(pos <= 0 || pos >= L.length+2) return false;

    ret = L.data[pos-1];
    for(int i = pos; i <= L.length - 1; i++){
        L.data[i-1] = L.data[i];
    }

    L.length--;

    return true;
}



int main(){
    int n; cin >> n;
    SqList l1;
    for(int i = 0; i< n; i++){
        cin >> l1.data[i];
        l1.length ++;
    }

    
    for(int i = 0; i < n;i++){
        cin >> l1.data[i];
    }
}