#include <iostream>
#include<cmath>
using namespace std;
/* 回溯法求解 n后问题 */

#define MAXN 1000
int n;	//皇后个数
int sum=0;	//可行解个数
int x[MAXN];	//当前解 

bool Place(int k){
	//与前面放好的皇后进行比较（不在同一斜线、同一列上） 
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k])) || (x[j]==x[k]))
			return false;
	}
	return true;
}

void Backtrack(int t){
	if(t>n)
		sum++;	//如果到达叶子节点，解的个数增加 
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;	//表示 t 行皇后的位置放在 i 处 
			//如果这个位置能放，则进行下一层的遍历 
			if(Place(t))
				Backtrack(t+1);
		}
	}
}

int main() {
	sum=0;
	while(1){
		cout<<"n后问题\n请输入皇后个数："<<endl; 
		cin>>n;
		//初始化 
		for(int i=0;i<=n;i++)
			x[i]=0;
		Backtrack(1);
		cout<<"回溯法求得"<<n<<"后问题的解的个数为："<<sum<<endl;
		sum=0;
		cout<<endl;
	}
	return 0;
}
