#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//��ӡ����
void print(int *a,int left,int right){
	int i;
	for(i=left;i<=right;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

//��������
void InsertSort(int *a,int left,int right){
	int i,j; 
	for(i=left+1;i<=right;i++){
		for(j=left;j<i;j++){  //�ڶ���ѭ�������ź�������н���ɨ�裬��Ҫ����������бȽϣ��������뵽���� 
			if(a[j]>a[i])
				swap(a[i],a[j]);
		}
	}
}

int main(int argc, char** argv) {
	int a[]={3,2,5,7,8,9,5,0,1,3,4};
	cout<<" ԭ����Ϊ��";
	print(a,0,10);
	cout<<" ��������������Ϊ��";
	InsertSort(a,0,10);print(a,0,10);
	return 0;
}
