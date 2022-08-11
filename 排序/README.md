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


///////////////////////简单选择排序//////////////////////////


/* 思想：
 *空间复杂度：
 *时间复杂度：
 *稳定性：
 *适用性： 
 *特点：
 */

/////////////////////////堆排序/////////////////////////////


/* 思想：
 *空间复杂度：
 *时间复杂度：
 *稳定性：
 *适用性： 
 *特点：
 */

///////////////////////【归并排序】//////////////////////////



/* 思想：
 *空间复杂度：
 *时间复杂度：
 *稳定性：
 *适用性： 
 *特点：
 */

///////////////////////【基数排序】//////////////////////////








/* 思想：
 *空间复杂度：
 *时间复杂度：
 *稳定性：
 *适用性： 
 *特点：
 */


////////////////////////////////////////////////////////
```