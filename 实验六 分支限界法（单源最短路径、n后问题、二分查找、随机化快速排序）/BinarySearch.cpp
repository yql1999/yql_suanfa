#include<iostream>
#include<string>
using namespace std;
/*�������� (Ҫ���ź���)*/

int BinarySearch(int array[],int x,int n){
    int left,right,mid,count=1;
    left=0,right=n-1;
    while(left<=right){
        mid=(left+right)/2;
    	cout<<"  ��"<<count++<<"�αȽϵĻ�׼��Ϊ��"<<array[mid]<<endl;
        if (array[mid]==x)
        	return mid;
        else if(array[mid]>x)
        	right=mid-1;
        else
        	left=mid+1;
    }
    return -1;	//δ�ҵ� 
}

int main(){
    int array[]={6,9,13,15,25,33,45};
    int size=sizeof(array)/sizeof(array[0]);
    int x;	//Ҫ���ҵ��� 
    cout<<"ԭ����Ϊ��";
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	cout<<endl; 
    while(true){
    	cout<<"������Ҫ���ҵ��� x = ";
    	cin>>x;
    	if(BinarySearch(array,x,size)==-1){
    		cout<<"δ�ҵ���"<<x<<endl; 
		}
		else
    		cout<<"�ҵ���"<<x<<"���±�Ϊ��"<<BinarySearch(array,x,size)<<endl;
		cout<<endl;
	}
    return 0;
}
