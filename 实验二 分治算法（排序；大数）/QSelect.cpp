#include<iostream>
using namespace std;   
/*以5为基，五数取分的线性选择法*/

const int maxm=100;	//以5划分 
int mid[maxm];	//用于存放中位数 

//对每组的5个元素进行插入排序
void InsertSort(int *a,int left,int right){
	int i,j; 
	for(i=left+1;i<=right;i++){	//从第二个数开始插入排序，因为第一个数已排好序 
		for(j=left;j<i;j++){  //第二层循环对已排好序的序列进行扫描，和要插入的数进行比较，决定插入到哪里 
			if(a[j]>a[i])
				swap(a[i],a[j]);
		}
	}
}

//查找中位数的中位数
int FindMedian(int *a,int left,int right){
	if(left==right)
		return a[left];
	int i,j;
	//对每个5个一组的元素进行插入排序，找出中位数 
	if(right-left+1>=5){
		for(i=left;i<=right-4;i+=5){
			InsertSort(a,left+i,left+i+5);
			int num=i-left;
			
			mid[num/5]=a[i+2];	//保存到中位数数组中 
		}
	}
	//处理剩下的不足5个的元素
	int remain=right-i+1;	//剩下的元素个数 
	if(remain>0){
		InsertSort(a,left+i,right);
		int num=i-left;
		mid[num/5]=a[i+(remain>>1)];	//保存到中位数数组中 
	} 
	int cnt=(right-left+1)/5;	//有几组5个一组的数      
    if((right-left+1)%5==0) {        
        cnt--;	//下标是从0开始，所以需要-1    
    }
    if(cnt==0)      
        return mid[0];      
    else       
        return FindMedian(mid,0,cnt);	//递归查找中位数的中位数 
}

//线性快速查找第k小的数 
int QSelect(int a[],int left,int right,int k){
	int x=FindMedian(a,left,right);	//查找中位数的中位数 
	int i=left-1,j=right+1;
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//两个都为false跳出循环
		if(i>=j)	break;
		swap(a[i],a[j]); 
	}
	int remain=i-left+1;	//剩下的数 
	if(k==remain)
		return a[i];
	else if(k<remain)
		return QSelect(a,left,i-1,k);
	else	
		return QSelect(a,i+1,right,k-remain);
}

int main() {
	int a[]={4,59,7,23,61,55,46};
    cout<<" 数组a的元素分别为：4,59,7,23,61,55,46"<<endl; 
    cout<<" 在数组a中最大的元素为："<<QSelect(a,0,6,7)<<endl;
    cout<<" 在数组a中第二大的元素为："<<QSelect(a,0,6,6)<<endl;
    cout<<" 在数组a中第四大的元素为："<<QSelect(a,0,6,4)<<endl;
	return 0;
}
