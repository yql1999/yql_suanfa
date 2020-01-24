#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
/*��֧�޽編�����У���� n������*/
 
 
class Node{
public:
	//��ʼ�� 
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
	
	int t;	//��ǰ�Ѿ����õĻʺ���� 
	int n;	//�ʺ����� 
	int *x; //��Żʺ�λ�ã���ʾ��i�еĻʺ���� x[i] �� 
};
 
//�����ڵ�k�еĻʺ��Ƿ���ǰ���ѷŵĻʺ��г�ͻ 
bool Node::check(int k){
	//���Ѿ����ûʺ���н��бȽ� 
	for(int i=1;i<=t;i++){
		//����ͬһ�л�ͬһ�Խ��� 
		if(x[i]==k || abs(k-x[i])==abs(t-i+1))
			return false;
	}
	return true;
}
 

int QueenArrange(int n){
	int sum=0;
	queue<Node> q;	//�����ʺ�ڵ�Ķ��� q
	Node firstnode(n);
	q.push(firstnode);
	while (!q.empty()){	//�����зǿ� 
		Node node = q.front();
		q.pop();
		if (node.t == n)
			sum++;	//���������һ 
		//BFS�������������Ĳ������
		for (int i=1;i<=n;i++){
				//��֦��ֻ�з���check()�����Ļʺ�ڵ�ſ��ǣ�������� q 
				if (node.check(i)){
					Node newnode(node);	//����node�ڵ��newnode 
					newnode.t++; 
					newnode.x[newnode.t] = i; //��¼λ��
					q.push(newnode);
				}
		}
	}
	return sum;
}
 
int main(){
	int n;
	while(1){
		cout<<"n������\n������ʺ������"<<endl; 
		cin>>n;
		cout<<"��֧�޽編���"<<n<<"������Ľ�ĸ���Ϊ��"<<QueenArrange(n)<<endl;
		cout<<endl; 
	}
	return 0;
}
