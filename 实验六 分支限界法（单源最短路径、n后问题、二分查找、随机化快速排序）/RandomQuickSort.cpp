#include <iostream>
#include<algorithm>
using namespace std;
/*随机化快速排序*/ 

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
int num=1;

void RandomQuickSort(int *a,int left,int right){
	if(left<right){
		int q=RandomPartition(a,left,right);
		RandomQuickSort(a,left,q-1);	//对左半段排序
		RandomQuickSort(a,q+1,right);	//对右半段排序
		cout<<"   第"<<num++<<"次快速排序的基准为："<<a[q]<<endl; 
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
	int n=sizeof(a)/sizeof(a[0])-1;	//n=10
	cout<<" 原数组为：";
	print(a,0,n);
	RandomQuickSort(a,0,n);
	cout<<endl;
	cout<<" 随机化快速排序后的数组为：";
	print(a,0,n);
	return 0;
}
