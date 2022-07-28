/*
问题模型：找到一个序列中，离某个数最近的(左侧/右侧), 满足条件xxx的数

维护单调栈的要领：判断(要作为结果的)栈顶有没有用
对于单调递增栈：若当前数val比栈顶top小，又因为它更靠目标，所以栈顶top无用
对于单调递减栈：若当前数val比栈顶top大，又因为它更靠目标，所以栈顶top无用

使用单调栈的要领：找小用递增，找大用递减 --- 增小减大（反增大减小）

*/



/*
给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

输入格式
第一行包含整数 N，表示数列长度。

第二行包含 N 个整数，表示整数数列。

输出格式
共一行，包含 N 个整数，其中第 i 个数表示第 i 个数的左边第一个比它小的数，如果不存在则输出 −1。

数据范围
1≤N≤105
1≤数列中元素≤109
输入样例：
5
3 4 2 7 5
输出样例：
-1 3 -1 2 2

*/

#include<iostream>
using namespace std;

const int N = 100010;

int stk[N], tt = -1;

int main(){
    int n; cin >> n;
    
    while(n--){
        int x;
        scanf("%d", &x);
        // 维护单调递增栈
        while(tt>=0 && stk[tt] >= x) tt--;
        
        // 判断
        if(tt<0) printf("-1 ");
        else printf("%d ", stk[tt]);
        
        stk[ ++ tt] = x;
    }
    
    return 0;
}