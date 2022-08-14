【KMP字符串匹配算法】
```cpp
#include<bits/stdc++.h>
using namespace std; 

#define INT_MAX 0x7fffffff;
#define INT_MIN 0x80000000;
const int N = 100010;


///////////////////【暴力匹配算法】//////////////////////////
//若A中包含字子串B，返回匹配的第一个位置

/*O(n^2)*/
int Index(String A, String B){
	int n = length(A), m = length(B);
	int i, j;
	for(i = 0; i < n-m+1; i++){
		if(A[i] == B[0]){
			bool flag = true;
			for(j = 1; j < m; j++){
				if(A[i+j] == B[j]) continue;
				else{
					flag = false;
					break;	
				}
			}
		}
		if(flag) return i;
	
	}
	return -1;
}

/* O(n*m) */
int Index(String A, String B){
	int i = 1, j = 1;
	while(i <= length(A) && j <= length(B)){
		if(A[i] == B[j]){ 
			i++; j++；
		}
		else{
			i = i - j + 1;
			j = 1;
		}
	}
	if(j > length(B)) return i - T.length;
	else return 0;

}


////////////////////////KMP算法//////////////////////


/*使用next数组进行KMP模式匹配的相关原理：O(n+m)
next数组的用法：表明在匹配时，若主串与子串的某个字符失配，子串的回退到哪个位置的字符送到到此处与主串继续匹配
*/

int KMP(String S, String T, int next[]){
	int i = 1, j = 1;
	while(i<=S.length && j <= T.length){
//错:if(S[i] == T[j] ){ i++;  j++;}
		if(S[i] == T[j] || j == 0){ 
			i++;  j++;
		}
		else{ // 在主串位置i处失配
			j = next[j]; 
		}
	}
	if(j > T.length) return i - T.length;
	else return 0;
}


/*
如果先理解KMP算法再反过来看next数组的话：
next数组构建算法 可以看作是 【子串和子串进行KMP模式匹配】
next数组        可以看作是 【子串每个字符与该字符前面序列相似度的数值所组成的数组】

tip：关于【必然有next[0]=0,next[1]=1】: next[0]必然是0, 即主串与子串的第一个字符即失配时，子串无法回退出合适字符传送至此处匹配； （因此遇到next数组值为0时，主串与从失配位置的下一位开始，与子串第一个位置重新匹配 即i++j++，综上next[1]也必然是1）
*/
void get_next(Strign T, int next[]){
	int i = 1， j = 0;
	next[1] = 0;
	while(i < T.length){
		// 在子串位置i处匹配，则说明在原来已匹配序列的基础上多出一个已匹配字符数，较上一个next值+1
		if(T[i] == T[j] || j == 0){ 
			++i; ++j;
			next[i] = j; // !记录!
		}
		// 在子串位置i处失配
		else{ 
			j = next[j];
		}
	}
	
}



