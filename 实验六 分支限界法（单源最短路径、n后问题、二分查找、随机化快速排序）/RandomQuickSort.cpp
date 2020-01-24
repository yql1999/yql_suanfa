#include <iostream>
#include<algorithm>
using namespace std;
/*�������������*/ 

//��ӡ����
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//��������
int Partition(int *a,int left,int right);
int RandomPartition(int *a,int left,int right);
int num=1;

void RandomQuickSort(int *a,int left,int right){
	if(left<right){
		int q=RandomPartition(a,left,right);
		RandomQuickSort(a,left,q-1);	//����������
		RandomQuickSort(a,q+1,right);	//���Ұ������
		cout<<"   ��"<<num++<<"�ο�������Ļ�׼Ϊ��"<<a[q]<<endl; 
	}
}

int RandomPartition(int *a,int left,int right){	//�����������
	int q=left+rand()%(right-left);
	swap(a[q],a[left]);
	return Partition(a,left,right);
}

int Partition(int *a,int left,int right){
	int i=left,j=right+1;
	int x=a[left];	//��׼
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//������Ϊfalse����ѭ��
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
	cout<<" ԭ����Ϊ��";
	print(a,0,n);
	RandomQuickSort(a,0,n);
	cout<<endl;
	cout<<" �������������������Ϊ��";
	print(a,0,n);
	return 0;
}
