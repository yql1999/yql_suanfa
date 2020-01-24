//0/1背包问题（动态规划）
//时间复杂度为O(nc)，空间复杂度为O(n^2) 

#include <iostream>
using namespace std;

#define MAXN 1000
int m[MAXN][MAXN];

/*v--物品价值;*w--物品重量;
  c--背包容量;n--物品种类数;
  数组m--子问题的最优解*/
void Knapsack(int*v,int*w,int c,int n,int m[][MAXN]){
	int i,j;
	//初始化（第一行） 
	int jMax=min(w[n]-1,c);
	for(j=0;j<=jMax;j++)
		m[n][j]=0;
	for(j=w[n];j<=c;j++)
		m[n][j]=v[n]; 
	//第2~n行
	for(i=n-1;i>1;i--){	//逐步增加物品数至n,容量至c 
		jMax=min(w[i]-1,c);	//仅可选物品i时的最优解
		//装不下时
		for(j=0;j<=jMax;j++)
			m[i][j]=m[i+1][j];
		//装得下时取最大值 
		for(j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	} 
	//最后一行（处理物品1，只要处理m[1][c]的边界情况） 
	m[1][c]=m[2][c];
	if(c>=w[1])
		m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

//根据数组m的值判断该物品是否放入背包 
void Traceback(int m[][MAXN],int*w,int c,int n,int*x){
	for(int i=1;i<n;i++){
		if(m[i][c]==m[i+1][c])	//不放入 
			x[i]=0;
		else{	//放入 
			x[i]=1;
			c-=w[i];
		}
	}
	//最后一件物品 
	x[n]=(m[n][c]) ? 1:0;
}

void output(int n,int*x){
	cout<<"装入背包的物品有："<<endl;; 
	for(int i=1;i<=n;i++){
		if(x[i]==1)
			cout<<"物品"<<i<<" ";
	}
	
}

int main(int argc, char** argv) {
	int n=5,c=10;
	int*v=new int[n+1]{0,6,3,5,4,6};
	int*w=new int[n+1]{0,2,2,6,5,4};
	int*x=new int[n+1];
	cout<<"问题描述：物品总数为5，背包容量 c = 10，"<<endl;
	cout<<"物品价值分别为：6，3，5，4，6，物品重量分别为：2，2，6，5，4"<<endl; 
	cout<<" 动态规划求解0-1背包问题的解："<<endl;
	Knapsack(v,w,c,n,m);
	Traceback(m,w,c,n,x);
	output(n,x);
	return 0;
}
