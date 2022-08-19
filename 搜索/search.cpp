#include<bits/stdc++.h>
using namespace std;

#define INT_MIN = 0x80000000;
#define INT_MAX = 0x79999999;



 
/////////////////////顺序查找////////////////
int SqSearch(int data[], int size, int val){ 
	for(int i = 0; i < size; i++){
		if(data[i] == val)
			return i;
	}
}

/*
 * ASL成功：1/n * n(n+1) / 2 = (n+1)/2 ; ASL失败：1/n * (1+2+...+n) = n+1
 * 适用性：顺序or链式，有序or无序都无要求。
		tip：线性链式存储只能顺序查找
 */

///////////////////基于有序表的顺序查找//////////////////
int SqSortSearch(int sortData[], int size, int  val){
	for(int i = 0; i < size; i++){
		if(sortData[i] == val)
			return i;
		if(sortData[i] > val)
			return -1;
	}
	return -1;
}


/*有序顺序查找判定树p259， tip：n个成功节点， n+1个失败节点
 * ASL成功：1/n * n(n+1) / 2 = (n+1)/2; ASL失败：1/n+1  * （1+2+...+n+n) = n/2 + n/n+1.  时间复杂度O(n)
 */


////////////////////折半查找//////////////////
int binarySearch(int sortData[], int size, int val){
	int low = 0, high = size-1;
	int mid;
	while(low < high){
		mid = (low + high) / 2;
		if(sortData[mid] == val) return mid;
		else if(sortData[mid] > val) high = mid+1;
		else low = mid-1;
	}
	return -1;
}

/*折半查找的判定树p261，为平衡二叉树(根节点为mid)
  *ASL成功：约为log n+1 。 成功或失败都可画出判别树数各层节点路径长度之和       时间复杂度O(logn)
  *适用性：为了随机存取，且有有下(mid low high)，只能用于 顺序+有序
  */



///////////////////基于分块表 辅以索引表的分块查找///////


/* 分块表的特点：块间有序(由索引表管理)，块内无序
  *ASL：ASL索引表 + ASL分块表：
在均匀分块（b个块，每个块s个）
 1、若索引表，分块表中都采用顺序查找：(1+b)/2 + (1+s)/2 , 当块元素个数s = 根号n时ASL最小 = 根号n - 1
 2、若索引表采用折半查找，分块表中采用顺序查找 ASL = log(b+1) + (s+1)/2
  *
  */



/*

B树  可以看作是【节点是有序表的】 二叉查找 tip：超平衡的多路平衡二叉树
B+树 可以看作是【基于链式分块表 辅以树状索引表】的 分块查找


【核心区别】--- B在树里查找，B+用树辅助在链式分块表中查找 
基于核心区别，易于理解B与B+的所有差异，例如：
1，B树 1个关键字2个分叉 --- 关键字为了划分出大小子树
  B+树 1个关键字一个分叉 --- 关键字为了标记出孩子节点中最大值

2，B树 在非叶节点找到关键字即停止 --- 因为在树上找
  B+树 在非叶节点找到关键字不停止，在叶节点找到停止  --- 树是辅助的索引表，最终是在分块表上找
*/