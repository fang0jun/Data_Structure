【排序算法】
```cpp
#include<bits/stdc++.h>
using namespace std; 

#define INT_MAX 0x7fffffff;
#define INT_MIN 0x80000000;
const int N = 100010;


/////////////////////【插入排序】/////////////////////////

/////////////////////直接插入排序/////////////////////////
void InsertSort1(int Arr[], int length){
	int i, j, tmp;
	for(i = 1; i < length; i++){
		if(Arr[i] < Arr[i-1]){
			tmp = Arr[i]; //记得存储，否则覆盖消失
			for(j = i-1; j > 0; j--){
				if(Arr[i] < Arr[j]){					Arr[j+1] = Arr[j];
				}
				else{
					Arr[j] = tmp;
					break;
				}
			}//for
		
		}
	}

}
/* 思想：将待排序的元素插入前面已排序好的子序列中（插入方式：依此比较依次移动）
 *空间复杂度：O(1)
  *时间复杂度：平均：O(n^2) 最好：基本有序的情况下接近O(n)只需比较无需移动
 *稳定性：稳定（line19决定）
  *适用性：顺序和链式线性表，特别适用于基本有序表
  *其他特点：前面局部有序性
  */


/////////////////////折半插入排序/////////////////////////
void InsertSort(int Arr[], int length){
	int i, j, tmp;
	int low, high, mid;
	for(i = 1; i < length; i++){
		tmp = Arr[i];
		low = 0, high = i-1;
		
		/*折半查找*/
		while(low <= high){
			mid = (low + high) / 2;
			if(tmp < Arr[mid]) high = mid - 1;
			else low = mid + 1;
		}
		
		//最后的情况是： high在左 low在右，插入到high-low之间
		for(j = i-1; j >= high + 1; j--)
			Arr[j+1] = Arr[j];
		Arr[high+1] = tmp;
	}

}




/* 思想： 折半查找+插入（插入方式：折半比较，找到位置后依次次移动）
 *空间复杂度：O(1)
 *时间复杂度：平均：仍为O(n^2)   最好：基本有序的情况下接近O(n)只需比较无需移动
 *稳定性：稳定
 *适用性：顺序和链式线性表，特别适用于基本有序表
  *其他特点：前面局部有序
 */

/////////////////////希尔(插入)排序/////////////////////////
void shellSort(int Arr[], int length){
	//增量分组，分组插排
	for(int dk = n/2; dk >= 1; dk /= 2){
		for(i = dk+1; i < length; i++){
			if(Arr[i] < Arr[i-dk]){
				int tmp = Arr[i];
				for(j = i-dk; j > 0; j -= dk){
					if(tmp < Arr[j]) Arr[j+dk] = Arr[j];
					else{ Arr[j] = tmp; break;}
				}
			}//if
		}///for
	}//for
}





/* 思想：缩小增量d分组，分组插排。至基本有序(d=1)后再次插排
 *空间复杂度：O(1)
 *时间复杂度：平均：O(n^1.3) 最坏：O(n^2)
 *稳定性: 【不】稳定
 *适用性：顺序和链式线性表
 */












////////////////////【交换排序】///////////////////////////////


//交换操作 ：基于比较的结果 对换元素的位置
//特点：都分趟

//////////////////////冒泡排序////////////////////////////////
void bubbleSort(int Arr[], int length){
	for(int i = 0; i < length; i++){
		flag = false;
		for(int j = length - 1; j > 0; j--){
			if(A[j-1] > A[j]){
				int tmp = A[j-1];
				A[j-1] = A[j];
				A[j] = tmp;
				flag = true;
			}
		}
		if(!false) return;
	}

}





/*思想：每趟冒泡从后往前两两比较元素值，若逆序则交换位置（小元素向首部逼近）直至某趟冒泡时一次交换都没有发生
 *空间复杂度： O(1)
 *时间复杂度：平均：O(n^2) 最好：O(n) 最坏：
 *稳定性：稳定（line123决定）
 *适用性：
  *特点：前面全局有序性
 */

///////////////////////快速排序//////////////////////////
void quickSort(int Arr[], int low, int high){
	if(low < high){ // 此处交汇之意：划分到最小，每组只剩下0/1个
		int flagpos = Partition(Arr, low, high);
		quickSort(Arr, low, flagpos-1)		quickSort(Arr, flagpos+1, high);	}
}

int Partition(int Arr[], int low, int high){
	int flag = Arr[0];
	while(low < high){// 此处交汇之意：一趟快排完成，此趟左右派划分完毕
			while(low < high && Arr[high] >= flag) --high;
			Arr[low] =  Arr[high];
			while(low < high && Arr[low] <= flag) ++low;
			Arr[high] = Arr[low];
	}
	
	
	Arr[high] = flag; // 此时high 与 low相等
	return high 

}





/* 思想：每趟快排选一个基准(多为首)，low指针和high指针分工找出左派右派互相【丢皮球】，划分出左派右派。
重复在左派和右派再快排，直至最终所有的左右派都只有0/1个元素(搞内斗搞到分崩离析)
 *空间复杂度：平均：O(logn)；。在递归叠栈中  最好：O(logn) n节点树的最小高度 最坏：O(n)
 *时间复杂度：平均：稳定O(nlogn)
 *稳定性：丢来丢去不稳定
 *适用性： 不适用于基本有序或基本逆序(基准选取导致分派极不对称)
 *特点：不到最后都是一直无序，每轮快排后基准元素会被排到最终位置上
 */








///////////////////////【选择排序】//////////////////////////

//思想：每一趟选出一个最小值后再移动

///////////////////////简单选择排序//////////////////////////
void seleteSort(int Arr[], int length){
	for(int i = 0; i < length - 1; i++){ // 注意：只进行n-1趟，非n趟（最后一趟不需要选择）
		int minval = Arr[i], minid = i;
		for(int j = i; j < length; j++){
			if(minval > Arr[j]){
				minval = Arr[j];
				minid = j;
			}
		}
		
		int tmp = Arr[i];
		Arr[i] = minval;
		Arr[minid] = tmp;
	}
	
	return;

}


/* 思想：第i趟选择排序在表的未排序部分L[i, n]中挑选出最小值，放入L[i]
 *空间复杂度：O(1)
 *时间复杂度：O(n^2)
 *稳定性：不稳定(可能移动替换的时候，恰好把同值元素替换到后面去)
 *适用性： 
 *特点：复杂度恒定，与序列初始状态无关(选排主要操作就是比较，移动很简单。任一序列都需要n(n-1) / 2次比较，0～3(n-1)次移动)
 */

/////////////////////////堆排序/////////////////////////////
void	 BuildMaxHeap(int Arr[], int len){
	for(int i = len/2; i > 0; i++){
		HeapAdjust(Arr, len, i);
	}
}

void HeapAdjust(int Arr[], int k, int len){ // 功能：把一个根节点k下移到这棵子树的正确位置
	int top = Arr[k];
	for(i = 2*k; i <= len; i*=2){ //以k为根子树中，层层遍历的某节点的孩子节点
		if(i < len && A[i] < A[i+1]) i++; // 默认先取左孩子，在若右孩子更大则更换为右孩子
		
		if(top > Arr[i]) break;
		else{ // 交换父子
			Arr[k] = Arr[i]; 
			Arr[i] = top;
			k = i;  //记录此时根节点所在位置 
		}
	}
	

}

void heapSort(int Arr[], int len){
	BuildMaxHeap(Arr, len);
	for(i = len; i > 1; i--){
		Swap(A[i], A[0]);
		HeadAdjust(Arr, 1, i-1); // 删除后长为i-1，排除位于尾部的原先堆顶值
	}
}


/* 思想：(大根)堆排序的方法是要基于大根堆数据结构的，因此堆排序算法包含两个操作：创建堆，输出堆顶
 tip: 1、原序列制成堆序列，而代表堆的序列是无序的，创建堆后要依次输出堆顶(最值)才能达到排序的目的。
 tip: 2、堆排序所有操作都从最后一个带孩子的子树开始看起 （第[ｎ/2」个 节点为根的子树）
 *空间复杂度：O(1)
 *时间复杂度：建堆时间O(n), 输出调整时间n个节点，每个平均下调整logn层 O(n*logn)
 *稳定性：不稳定(值相等的左右孩子，默认在左的左孩子先调整到堆顶先输出故后续处在序列更尾处)
 *适用性： 数据大，找排名前x个值
 *特点：
 */

///////////////////////【(二路)归并排序】//////////////////////////
int* B = (int*)malloc(sizeof(int)*(n+1));

void Merge(int A[], int low, int high, int mid){ // 将有序的表A[low, mid],和A[mid+1, high]合并为一个新表
	for(int i = low; i <= high； i++) B[i] = A[i]; // 将A中元素存在B中
	for(int i = low, j = mid + 1, k = low; j<=high && i <= mid; ){
		if(B[i] <= B[j]) A[k++] = B[i];
		else A[k++] = B[j++]
	}
	
	while(i<=mid) A[k++] = B[i];
	while(j<=high) A[k++] = B[j];
}

void mergeSort(int A, int low, int high){
	//Mis if(len <= 1) return;
	if(low <= high){
		mergeSort(A, 0, (high+low)/2);
		mergeSort(A, (high+low)/2 + 1, high); //利用递归叠栈，得到最小序列进行合并操作
		Merge(A, low, mid, high)
	}
	
}


/* 思想：一趟归并排序会将n个长为h的有序序列，合并为n/2个长为2h有序序列
 *空间复杂度：O(n)
 *时间复杂度：一次归并O(n)共logn趟归并，O(nlogn)
 *稳定性：稳定 (line271决定)
 *适用性： 
 *特点：
 */

//tip: 有树结构的排序都是logn：快排树，堆，归并树

///////////////////////【基数排序】//////////////////////////




/* 思想(举例)：第一趟基数排序为个位进行排序(分配+收集)，
分配：个位上数字一样的连在一个链式队列上 ； 收集：合并为按个位有序的序列
为每个位进行一趟基数排序
位数k - 趟数(每趟包含分配和收集)；位数取值范围r - 链表数；元素总数n
 *空间复杂度：O(n)
 *时间复杂度：一共k趟，每趟中一次分配O(n)，一次收集O(r) ==> 总共 O(k(n+r))
 *稳定性：超稳定
 *适用性： 
 *特点：
 */


////////////////////////////////////////////////////////
```