#include <iostream>
using namespace std;

//打印数组
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//合并排序
void Merge(int *a,int left,int mid,int right);
void MergeSort(int *a,int left,int right){
	if(left<right){
		int mid=(left+right)/2;	//分解 
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right);	//合并 
	}
}
void Merge(int *a,int left,int mid,int right){	//合并
	int*b=new int[right-left+1];
	int i=left,j=mid+1,k=left;
	while((i<=mid)&&(j<=right)){
		if(a[i]<=a[j])	b[k++]=a[i++];
		else	b[k++]=a[j++];
	}
	if(i>mid){
		while(j<=right)
			b[k++]=a[j++];
	}
	else{
		while(i<=mid)
			b[k++]=a[i++];
	}
	for(i=left;i<=right;i++)	//复制回数组a
		a[i]=b[i];
}

int main(int argc, char** argv) {
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	cout<<" 原数组为：";
	print(a,0,10);
	cout<<" 合并排序后的数组为：";
	MergeSort(a,0,10);
	print(a,0,10);
	return 0;
}
