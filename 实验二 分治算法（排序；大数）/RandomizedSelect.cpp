#include <iostream>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
/* 随机生成10000个数，要求找出其中第4999小的数 */
  
//寻找基准并进行划分 
template <class Type>  
int Partition(Type a[],int p,int r)  {  
    int i = p,j = r + 1;  
    Type x = a[p];  
    while(true)  
    {  
    	//两个while循环都为false时跳出 
        while(a[++i]<x && i<r);  
        while(a[--j]>x);  
        if(i>=j)  
            break;  
        swap(a[i],a[j]);  
    }  
    a[p] = a[j];  
    a[j] = x;  
    return j;	//返回基准元素的位置 
}  
  
//随机选择基准位置 
template<class Type>  
int RandomizedPartition(Type a[],int p,int r)  {  
    int i = p+rand()%(r-p);  
    swap(a[i],a[p]);	//让基准位于第一个 
    return Partition(a,p,r);  
}  

//查找第k小的元素 
template <class Type>  
Type RandomizedSelect(Type a[],int p,int r,int k)  {  
    if(p == r)  {  
        return a[p];  
    }  
    int i = RandomizedPartition(a,p,r);  
    int j = i - p + 1;  
    if(k <= j)  {  
        return RandomizedSelect(a,p,i,k);  
    }  
    else  {  
        //要找的a[p:r]中第k小元素是a[i+1，r]中第k-j小元素 
        return RandomizedSelect(a,i+1,r,k-j);  
    }  
}  

int main(int argc, char** argv) {
	int i,num[10000];
	srand((unsigned)time(NULL));	//用时间做种子，每次产生的随机数不同
	for(i=0;i<10000;i++){
		num[i]=rand();
	}
	cout<<" 在随机生成的10000个数中，第4999小的数为："<<RandomizedSelect(num,0,10000,4999);
	return 0;
}
