//�����ۻ�Ա���⣨��Ҫ�ص��ʼ�Ľڵ㣩 
//������ 
#include<iostream>
using namespace std;

/*
n�ǽڵ���;
cc�ǵ�ǰ·���ķ���;bestc�ǵ�ǰ����ֵ;
*x�ǵ�ǰ��;*bestx�ǵ�ǰ���Ž�
*/
const int INF=100000;
int n,cc=0,bestc=INF;
int **a;
int *x,*bestx;


void Traveling(int i) {
	//����Ҷ�ӽڵ� 
	if(i==n){
		/*�ж�x[i]�Ƿ�����һ��x[i-1]����ͨ·��x[i]�Ƿ��ܻص�x[1]�������� 
		��1��i-1���ߵ�·��cc����x[i]��x[i-1]�ľ���С�ڵ�ǰ���Ž�*/
		if(a[x[i-1]][x[i]]!=0 && a[x[i]][1]!=0 &&
		(cc+a[x[i-1]][x[i]]+a[x[i]][1]<bestc || bestc==0)){
			//����ÿ���߹��Ľڵ� 
			for(int j=1;j<=n;j++){
				bestx[j]=x[j];
			}
			bestc=cc+a[x[i-1]][x[i]]+a[x[i]][1];
			return;
		}
	}
	//��Ҷ�ӽڵ�ʱ 
 	else{
 		/*�ж�x[i]�Ƿ�����һ��x[i-1]����ͨ·��������
		��1��i-1���ߵ�·��cc����x[i]��x[i-1]�ľ���С�ڵ�ǰ���Ž�*/
 		for(int j=i;j<=n;j++) {
			if (a[x[i-1]][x[j]]!=0 && (cc+a[x[i-1]][x[j]])<bestc
				|| bestc==0) {
					
					swap(x[j], x[i]);
					cc+=a[x[i-1]][x[i]];
					Traveling(i+1);	//���� 
					cc-=a[x[i-1]][x[i]];
					swap(x[j], x[i]);	//ע�����������������ɺ�Ҫ���������� 
					
			}
		}
	}
}
 
//��� 
void output() {
	cout<<bestc<<endl;
	cout<<"����·��Ϊ��"<<bestx[1];
	for(int i=2;i<=n;i++)
		cout<<" "<<bestx[i];
	cout<<" "<<bestx[1]<<endl;
}


int main()
{
	n=4;
	a=new int*[n+1];
	x=new int[n+1];
	bestx=new int[n+1];
	int i,j;
	for(i=0;i<(n+1);i++){
		a[i]=new int[n+1];
		x[i]=i;
		for(j=0;j<(n+1);j++){
			a[i][j]=INF;
		}	
	}
	//��ֵ 
	a[1][1]=a[2][2]=a[3][3]=a[4][4]=0;
	a[2][1]=a[1][2]=1;
	a[1][3]=a[3][1]=2;
	a[1][4]=a[4][1]=3;
	a[2][3]=a[3][2]=9;
	a[2][4]=a[4][2]=4;
	a[3][4]=a[4][3]=6;
	cout<<"���ڵ���Ϊ"<<n<<",��Ȩ��Ϊ" <<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<" "; 
		cout<<endl;
	}
	cout<<"ʱ,�û��ݷ���������ֵ��������Ϊ��"; 
	
	Traveling(2);
	output();
	
	return 0;
}

