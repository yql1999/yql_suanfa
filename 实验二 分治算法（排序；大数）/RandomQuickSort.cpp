#include <iostream>
#include<algorithm>
using namespace std;

//打印数组
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//快速排序
int Partition(int *a,int left,int right);
int RandomPartition(int *a,int left,int right);

void RandomQuickSort(int *a,int left,int right){
	if(left<right){
		int q=RandomPartition(a,left,right);
		RandomQuickSort(a,left,q-1);	//对左半段排序
		RandomQuickSort(a,q+1,right);	//对右半段排序
	}
}

int RandomPartition(int *a,int left,int right){	//产生随机划分
	int q=left+rand()%(right-left);
	swap(a[q],a[left]);
	return Partition(a,left,right);
}

int Partition(int *a,int left,int right){
	int i=left,j=right+1;
	int x=a[left];	//基准
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//两个都为false跳出循环
		if(i>=j)	break;
		swap(a[i],a[j]); 
	} 
	a[left]=a[j];
	a[j]=x;
	return j;
}

int main(int argc, char** argv) {
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	cout<<" 原数组为：";
	print(a,0,10);
	cout<<" 快速排序后的数组为：";
	RandomQuickSort(a,0,10);
	print(a,0,10);
	return 0;
}
