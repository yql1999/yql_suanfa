#include <iostream>
using namespace std;

//��ӡ����
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//�ϲ�����
void Merge(int *a,int left,int mid,int right);
void MergeSort(int *a,int left,int right){
	if(left<right){
		int mid=(left+right)/2;	//�ֽ� 
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right);	//�ϲ� 
	}
}
void Merge(int *a,int left,int mid,int right){	//�ϲ�
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
	for(i=left;i<=right;i++)	//���ƻ�����a
		a[i]=b[i];
}

int main(int argc, char** argv) {
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	cout<<" ԭ����Ϊ��";
	print(a,0,10);
	cout<<" �ϲ�����������Ϊ��";
	MergeSort(a,0,10);
	print(a,0,10);
	return 0;
}
