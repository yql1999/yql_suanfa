#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//打印数组
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//插入排序
void InsertSort(int *a,int left,int right){
	int i,j; 
	for(i=left+1;i<=right;i++){
		for(j=left;j<i;j++){  //第二层循环对已排好序的序列进行扫描，和要插入的数进行比较，决定插入到哪里 
			if(a[j]>a[i])
				swap(a[i],a[j]);
		}
	}
}

int main(int argc, char** argv) {
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	cout<<" 原数组为：";
	print(a,0,10);
	cout<<" 插入排序后的数组为：";
	InsertSort(a,0,10);print(a,0,10);
	return 0;
}
