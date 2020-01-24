#include<iostream>
#include<algorithm>
using namespace std;
/*��������*/
	
//��ӡ����
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//ȡ��λԪ����Ϊ���ֻ�׼ 
int Partition(int *a,int left,int right){
	int i=left,j=right+1;
	int x=a[left];	//��׼
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//������Ϊfalseʱ����
		if(i>=j)	break;
		swap(a[i],a[j]);
	} 
	a[left]=a[j];
	a[j]=x;
	return j;	//j���������Ǳ�a[j]С�������Ҳ඼�Ǳ�a[j]����� 
} 
int num=1;
//�������� 
void QuickSort(int *a,int left,int right){
	if(left<right){
		int q=Partition(a,left,right);
		QuickSort(a,left,q-1);	//�Ի�׼�������
		QuickSort(a,q+1,right);	//�Ի�׼�Ҳ����� 
		cout<<"   ��"<<num++<<"�ο�������Ļ�׼Ϊ��"<<a[q]<<endl; 
	}
}

int main(){
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	int n=sizeof(a)/sizeof(a[0])-1;	//n=10
	cout<<" ԭ����Ϊ��";
	print(a,0,n);
	QuickSort(a,0,n);
	cout<<endl;
	cout<<" ��������������Ϊ��";
	print(a,0,n);
	return 0;
}
