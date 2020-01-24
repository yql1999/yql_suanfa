#include <iostream>
#include<cstring>
using namespace std;
/* ����Ӷκͣ������ģ� */

//��ٷ�
int maxInterval_all(int len,int*a){
	int i,j,k,ans=0,sum=0;
	int start=0,end=0;
	//����ѭ��������ֶκ� 
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			sum=0;
			for(k=i;k<=j;k++){
				sum+=a[k];
				if(sum>ans){
					start=i;
					end=j;
					ans=sum;
				}
			}
		}
	}
	return ans;
}

//����
int maxInterval_div(int*a,int left,int right){
	if(left==right)
		return a[left]>0?a[left]:0;
	int mid=(left+right)/2;
	int leftMaxInterval=maxInterval_div(a,left,mid);	//������������Ӷκ� 
	int rightMaxInterval=maxInterval_div(a,mid+1,right);	//�ұ����������Ӷκ�
	int i,j;
	int sum=0,left_max=0,right_max=0;
	//��mid��ʼ��������ӣ�����ߵ�����Ӷκͣ��������ģ� 
	for(i=mid;i>=left;i--){
		sum+=a[i];
		if(sum>left_max)
			left_max=sum;
	} 
	//��mid��ʼ��������ӣ����ұߵ�����Ӷκ� 
	sum=0;
	for(i=mid+1;i<right;i++){
		sum+=a[i];
		if(sum>right_max)
			right_max=sum;
	} 
	//���������ߵ�����Ӷκ���ӣ��ֱ������ҵ�����ӶκͱȽ�
	int ans=left_max+right_max;	 
	if(ans<leftMaxInterval)
		ans=leftMaxInterval;
	if(ans<rightMaxInterval)
		ans=rightMaxInterval;
	return ans;
} 

//��̬�滮��������iΪ�յ㣨���������a[i]�� 
int maxInterval(int len,int*a){
	int i,b=0,sum=0;
	for(i=0;i<len;i++){
		if(b>0)	//����i-1Ϊ�յ������b>0
		//��iΪ�յ������ = ��i-1Ϊ�յ������b + a[i]
			b+=a[i];	
		else	//����i-1Ϊ�յ������b<=0 
		//��ΪҪ���ǰ����i-1Ϊ�յ������b�Ǹ�����
		//��Ȼ����ʹ�������������iΪ�յ������ b = a[i] 
			b=a[i];
		//��b>sum������sum 
		if(b>sum)
			sum=b;
	}
	return sum;
}

int main(int argc, char** argv) {
	int a[]={-2,11,-4,13,-5,-2}; 
	cout<<" ����aΪ��";
	int i,len;
	len=6;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<" ��ٷ���������У�"<<maxInterval_all(len,a)<<endl;
	cout<<" ���η���������У�"<<maxInterval_div(a,0,len)<<endl;
	cout<<" ��̬�滮��������У�"<<maxInterval(len,a)<<endl;
	return 0;
}
