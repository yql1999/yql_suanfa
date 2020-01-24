#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
/*分支限界法（队列）求解 n后问题*/
 
 
class Node{
public:
	//初始化 
	Node(int n) : t(0), n(n){
		x = new int[n + 1];
		for (int i = 0; i <= n; ++i)
			x[i] = 0;
	}
	Node(const Node& node){
		t = node.t;
		n = node.n;
		x = new int[node.n + 1];
		for (int i = 0; i <= n; ++i)
			x[i] = node.x[i];
	}
	~Node(){
		if (x != NULL){
			delete[] x;
			x = NULL;
		}
	}
	bool check(int k);
	
	int t;	//当前已经放置的皇后个数 
	int n;	//皇后数量 
	int *x; //存放皇后位置，表示第i行的皇后放在 x[i] 处 
};
 
//检查放在第k列的皇后是否与前面已放的皇后有冲突 
bool Node::check(int k){
	//与已经放置皇后的行进行比较 
	for(int i=1;i<=t;i++){
		//不在同一列或同一对角线 
		if(x[i]==k || abs(k-x[i])==abs(t-i+1))
			return false;
	}
	return true;
}
 

int QueenArrange(int n){
	int sum=0;
	queue<Node> q;	//建立皇后节点的队列 q
	Node firstnode(n);
	q.push(firstnode);
	while (!q.empty()){	//若队列非空 
		Node node = q.front();
		q.pop();
		if (node.t == n)
			sum++;	//解的总数加一 
		//BFS，将符合条件的插入队列
		for (int i=1;i<=n;i++){
				//剪枝，只有符合check()函数的皇后节点才考虑，加入队列 q 
				if (node.check(i)){
					Node newnode(node);	//拷贝node节点给newnode 
					newnode.t++; 
					newnode.x[newnode.t] = i; //记录位置
					q.push(newnode);
				}
		}
	}
	return sum;
}
 
int main(){
	int n;
	while(1){
		cout<<"n后问题\n请输入皇后个数："<<endl; 
		cin>>n;
		cout<<"分支限界法求得"<<n<<"后问题的解的个数为："<<QueenArrange(n)<<endl;
		cout<<endl; 
	}
	return 0;
}
