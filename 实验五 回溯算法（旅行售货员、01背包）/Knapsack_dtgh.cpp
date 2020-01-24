//0/1�������⣨��̬�滮��
//ʱ�临�Ӷ�ΪO(nc)���ռ临�Ӷ�ΪO(n^2) 

#include <iostream>
using namespace std;

#define MAXN 1000
int m[MAXN][MAXN];

/*v--��Ʒ��ֵ;*w--��Ʒ����;
  c--��������;n--��Ʒ������;
  ����m--����������Ž�*/
void Knapsack(int*v,int*w,int c,int n,int m[][MAXN]){
	int i,j;
	//��ʼ������һ�У� 
	int jMax=min(w[n]-1,c);
	for(j=0;j<=jMax;j++)
		m[n][j]=0;
	for(j=w[n];j<=c;j++)
		m[n][j]=v[n]; 
	//��2~n��
	for(i=n-1;i>1;i--){	//��������Ʒ����n,������c 
		jMax=min(w[i]-1,c);	//����ѡ��Ʒiʱ�����Ž�
		//װ����ʱ
		for(j=0;j<=jMax;j++)
			m[i][j]=m[i+1][j];
		//װ����ʱȡ���ֵ 
		for(j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	} 
	//���һ�У�������Ʒ1��ֻҪ����m[1][c]�ı߽������ 
	m[1][c]=m[2][c];
	if(c>=w[1])
		m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

//��������m��ֵ�жϸ���Ʒ�Ƿ���뱳�� 
void Traceback(int m[][MAXN],int*w,int c,int n,int*x){
	for(int i=1;i<n;i++){
		if(m[i][c]==m[i+1][c])	//������ 
			x[i]=0;
		else{	//���� 
			x[i]=1;
			c-=w[i];
		}
	}
	//���һ����Ʒ 
	x[n]=(m[n][c]) ? 1:0;
}

void output(int n,int*x){
	cout<<"װ�뱳������Ʒ�У�"<<endl;; 
	for(int i=1;i<=n;i++){
		if(x[i]==1)
			cout<<"��Ʒ"<<i<<" ";
	}
	
}

int main(int argc, char** argv) {
	int n=5,c=10;
	int*v=new int[n+1]{0,6,3,5,4,6};
	int*w=new int[n+1]{0,2,2,6,5,4};
	int*x=new int[n+1];
	cout<<"������������Ʒ����Ϊ5���������� c = 10��"<<endl;
	cout<<"��Ʒ��ֵ�ֱ�Ϊ��6��3��5��4��6����Ʒ�����ֱ�Ϊ��2��2��6��5��4"<<endl; 
	cout<<" ��̬�滮���0-1��������Ľ⣺"<<endl;
	Knapsack(v,w,c,n,m);
	Traceback(m,w,c,n,x);
	output(n,x);
	return 0;
}
