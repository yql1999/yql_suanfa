#include<iostream>
using namespace std;   
/*��5Ϊ��������ȡ�ֵ�����ѡ��*/

const int maxm=100;	//��5���� 
int mid[maxm];	//���ڴ����λ�� 

//��ÿ���5��Ԫ�ؽ��в�������
void InsertSort(int *a,int left,int right){
	int i,j; 
	for(i=left+1;i<=right;i++){	//�ӵڶ�������ʼ����������Ϊ��һ�������ź��� 
		for(j=left;j<i;j++){  //�ڶ���ѭ�������ź�������н���ɨ�裬��Ҫ����������бȽϣ��������뵽���� 
			if(a[j]>a[i])
				swap(a[i],a[j]);
		}
	}
}

//������λ������λ��
int FindMedian(int *a,int left,int right){
	if(left==right)
		return a[left];
	int i,j;
	//��ÿ��5��һ���Ԫ�ؽ��в��������ҳ���λ�� 
	if(right-left+1>=5){
		for(i=left;i<=right-4;i+=5){
			InsertSort(a,left+i,left+i+5);
			int num=i-left;
			
			mid[num/5]=a[i+2];	//���浽��λ�������� 
		}
	}
	//����ʣ�µĲ���5����Ԫ��
	int remain=right-i+1;	//ʣ�µ�Ԫ�ظ��� 
	if(remain>0){
		InsertSort(a,left+i,right);
		int num=i-left;
		mid[num/5]=a[i+(remain>>1)];	//���浽��λ�������� 
	} 
	int cnt=(right-left+1)/5;	//�м���5��һ�����      
    if((right-left+1)%5==0) {        
        cnt--;	//�±��Ǵ�0��ʼ��������Ҫ-1    
    }
    if(cnt==0)      
        return mid[0];      
    else       
        return FindMedian(mid,0,cnt);	//�ݹ������λ������λ�� 
}

//���Կ��ٲ��ҵ�kС���� 
int QSelect(int a[],int left,int right,int k){
	int x=FindMedian(a,left,right);	//������λ������λ�� 
	int i=left-1,j=right+1;
	while(true){
		while(a[++i]<x && i<right);
		while(a[--j]>x);	//������Ϊfalse����ѭ��
		if(i>=j)	break;
		swap(a[i],a[j]); 
	}
	int remain=i-left+1;	//ʣ�µ��� 
	if(k==remain)
		return a[i];
	else if(k<remain)
		return QSelect(a,left,i-1,k);
	else	
		return QSelect(a,i+1,right,k-remain);
}

int main() {
	int a[]={4,59,7,23,61,55,46};
    cout<<" ����a��Ԫ�طֱ�Ϊ��4,59,7,23,61,55,46"<<endl; 
    cout<<" ������a������Ԫ��Ϊ��"<<QSelect(a,0,6,7)<<endl;
    cout<<" ������a�еڶ����Ԫ��Ϊ��"<<QSelect(a,0,6,6)<<endl;
    cout<<" ������a�е��Ĵ��Ԫ��Ϊ��"<<QSelect(a,0,6,4)<<endl;
	return 0;
}
