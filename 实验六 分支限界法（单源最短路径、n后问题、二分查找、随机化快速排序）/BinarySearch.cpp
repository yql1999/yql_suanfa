#include<iostream>
#include<string>
using namespace std;
/*二分搜索 (要先排好序)*/

int BinarySearch(int array[],int x,int n){
    int left,right,mid,count=1;
    left=0,right=n-1;
    while(left<=right){
        mid=(left+right)/2;
    	cout<<"  第"<<count++<<"次比较的基准数为："<<array[mid]<<endl;
        if (array[mid]==x)
        	return mid;
        else if(array[mid]>x)
        	right=mid-1;
        else
        	left=mid+1;
    }
    return -1;	//未找到 
}

int main(){
    int array[]={6,9,13,15,25,33,45};
    int size=sizeof(array)/sizeof(array[0]);
    int x;	//要查找的数 
    cout<<"原数组为：";
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	cout<<endl; 
    while(true){
    	cout<<"请输入要查找的数 x = ";
    	cin>>x;
    	if(BinarySearch(array,x,size)==-1){
    		cout<<"未找到数"<<x<<endl; 
		}
		else
    		cout<<"找到数"<<x<<"的下标为："<<BinarySearch(array,x,size)<<endl;
		cout<<endl;
	}
    return 0;
}
