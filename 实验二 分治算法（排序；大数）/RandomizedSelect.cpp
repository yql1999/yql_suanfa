#include <iostream>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
/* �������10000������Ҫ���ҳ����е�4999С���� */
  
//Ѱ�һ�׼�����л��� 
template <class Type>  
int Partition(Type a[],int p,int r)  {  
    int i = p,j = r + 1;  
    Type x = a[p];  
    while(true)  
    {  
    	//����whileѭ����Ϊfalseʱ���� 
        while(a[++i]<x && i<r);  
        while(a[--j]>x);  
        if(i>=j)  
            break;  
        swap(a[i],a[j]);  
    }  
    a[p] = a[j];  
    a[j] = x;  
    return j;	//���ػ�׼Ԫ�ص�λ�� 
}  
  
//���ѡ���׼λ�� 
template<class Type>  
int RandomizedPartition(Type a[],int p,int r)  {  
    int i = p+rand()%(r-p);  
    swap(a[i],a[p]);	//�û�׼λ�ڵ�һ�� 
    return Partition(a,p,r);  
}  

//���ҵ�kС��Ԫ�� 
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
        //Ҫ�ҵ�a[p:r]�е�kСԪ����a[i+1��r]�е�k-jСԪ�� 
        return RandomizedSelect(a,i+1,r,k-j);  
    }  
}  

int main(int argc, char** argv) {
	int i,num[10000];
	srand((unsigned)time(NULL));	//��ʱ�������ӣ�ÿ�β������������ͬ
	for(i=0;i<10000;i++){
		num[i]=rand();
	}
	cout<<" ��������ɵ�10000�����У���4999С����Ϊ��"<<RandomizedSelect(num,0,10000,4999);
	return 0;
}
