#include <iostream>
#include<cmath>
using namespace std;
/* ���ݷ���� n������ */

#define MAXN 1000
int n;	//�ʺ����
int sum=0;	//���н����
int x[MAXN];	//��ǰ�� 

bool Place(int k){
	//��ǰ��źõĻʺ���бȽϣ�����ͬһб�ߡ�ͬһ���ϣ� 
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k])) || (x[j]==x[k]))
			return false;
	}
	return true;
}

void Backtrack(int t){
	if(t>n)
		sum++;	//�������Ҷ�ӽڵ㣬��ĸ������� 
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;	//��ʾ t �лʺ��λ�÷��� i �� 
			//������λ���ܷţ��������һ��ı��� 
			if(Place(t))
				Backtrack(t+1);
		}
	}
}

int main() {
	sum=0;
	while(1){
		cout<<"n������\n������ʺ������"<<endl; 
		cin>>n;
		//��ʼ�� 
		for(int i=0;i<=n;i++)
			x[i]=0;
		Backtrack(1);
		cout<<"���ݷ����"<<n<<"������Ľ�ĸ���Ϊ��"<<sum<<endl;
		sum=0;
		cout<<endl;
	}
	return 0;
}
