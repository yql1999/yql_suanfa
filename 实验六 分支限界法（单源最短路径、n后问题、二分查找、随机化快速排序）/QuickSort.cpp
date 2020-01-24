#include<iostream>
#include<algorithm>
using namespace std;
/*快速排序*/
	
//打印数组
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//取首位元素作为划分基准 
int Partition(int *a,int left,int right){
	int i=left,j=right+1;
	int x=a[left];	//基准
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//两个都为false时跳出
		if(i>=j)	break;
		swap(a[i],a[j]);
	} 
	a[left]=a[j];
	a[j]=x;
	return j;	//j左侧的数都是比a[j]小的数，右侧都是比a[j]大的数 
} 
int num=1;
//快速排序 
void QuickSort(int *a,int left,int right){
	if(left<right){
		int q=Partition(a,left,right);
		QuickSort(a,left,q-1);	//对基准左侧排序
		QuickSort(a,q+1,right);	//对基准右侧排序 
		cout<<"   第"<<num++<<"次快速排序的基准为："<<a[q]<<endl; 
	}
}

int main(){
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	int n=sizeof(a)/sizeof(a[0])-1;	//n=10
	cout<<" 原数组为：";
	print(a,0,n);
	QuickSort(a,0,n);
	cout<<endl;
	cout<<" 快速排序后的数组为：";
	print(a,0,n);
	return 0;
}
