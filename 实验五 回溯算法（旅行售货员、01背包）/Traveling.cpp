//旅行售货员问题（还要回到最开始的节点） 
//排列树 
#include<iostream>
using namespace std;

/*
n是节点数;
cc是当前路径的费用;bestc是当前最优值;
*x是当前解;*bestx是当前最优解
*/
const int INF=100000;
int n,cc=0,bestc=INF;
int **a;
int *x,*bestx;


void Traveling(int i) {
	//到达叶子节点 
	if(i==n){
		/*判断x[i]是否与上一层x[i-1]存在通路，x[i]是否能回到x[1]，且满足 
		从1到i-1所走的路程cc加上x[i]与x[i-1]的距离小于当前最优解*/
		if(a[x[i-1]][x[i]]!=0 && a[x[i]][1]!=0 &&
		(cc+a[x[i-1]][x[i]]+a[x[i]][1]<bestc || bestc==0)){
			//更新每个走过的节点 
			for(int j=1;j<=n;j++){
				bestx[j]=x[j];
			}
			bestc=cc+a[x[i-1]][x[i]]+a[x[i]][1];
			return;
		}
	}
	//非叶子节点时 
 	else{
 		/*判断x[i]是否与上一层x[i-1]存在通路，且满足
		从1到i-1所走的路程cc加上x[i]与x[i-1]的距离小于当前最优解*/
 		for(int j=i;j<=n;j++) {
			if (a[x[i-1]][x[j]]!=0 && (cc+a[x[i-1]][x[j]])<bestc
				|| bestc==0) {
					
					swap(x[j], x[i]);
					cc+=a[x[i-1]][x[i]];
					Traveling(i+1);	//回溯 
					cc-=a[x[i-1]][x[i]];
					swap(x[j], x[i]);	//注意排列数问题回溯完成后还要交换回来的 
					
			}
		}
	}
}
 
//输出 
void output() {
	cout<<bestc<<endl;
	cout<<"最优路径为："<<bestx[1];
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
	//赋值 
	a[1][1]=a[2][2]=a[3][3]=a[4][4]=0;
	a[2][1]=a[1][2]=1;
	a[1][3]=a[3][1]=2;
	a[1][4]=a[4][1]=3;
	a[2][3]=a[3][2]=9;
	a[2][4]=a[4][2]=4;
	a[3][4]=a[4][3]=6;
	cout<<"当节点数为"<<n<<",且权重为" <<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<" "; 
		cout<<endl;
	}
	cout<<"时,用回溯法求解得最优值（开销）为："; 
	
	Traveling(2);
	output();
	
	return 0;
}

