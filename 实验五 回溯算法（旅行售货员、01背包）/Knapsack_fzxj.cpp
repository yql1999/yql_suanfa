//分支限界法求解0-1背包问题 
//优先队列
//BFS 广度优先搜索 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 

int n;//物品数量
double c;//背包容量
int maxSize=0;

struct Goods{
 	double v;//物品价值
	double w;//物品重量
	int order;//物品编号
	double perp;//单位价值
	int put;//是否选中 
 }goods[100];
 
 bool comp_goods(Goods a,Goods b){
 	return a.perp>b.perp;
 }
 
struct Node{
	Node(){
		v=0;
		w=0;
		level=0;
		parent=0;
		bound=0;
	}
 	double v;//搜索到当前节点的总价值
	double w;//搜索到当前节点的总重量 
	double bound;//以该节点为根的子树的价值上界 
	int level;//该节点所在层数 
	Node*parent; //父节点指针 
 };  
 
 struct comp{
 	bool operator()(Node*a,Node*b){
 		return a->bound<b->bound;
	 }
 };
 
 
double maxBound(Node*node,Goods goods[],int c);

int branchAndBound(Goods goods[],int c){
	int i,maxValue;//当前背包的最大价值
	Node *maxNode = new Node();//保存当前最大价值节点（叶节点）
	
	priority_queue<Node *, vector<Node *>, comp> maxQueue; //最大价值优先队列
	
	Node *firstNode, *curNode;
	//把第一个节点加入优先队列 
	firstNode = new Node();
	firstNode->bound = maxBound(firstNode,goods,c);
	firstNode->parent = NULL;
	maxQueue.push(firstNode);
	maxValue = 0;
	maxNode = firstNode;
	//若优先队列不为空 
	while (!maxQueue.empty()){
		curNode=maxQueue.top();
		maxQueue.pop();
		//扩展左节点
		//只有满足最大重量限界，才予以考虑，加入优先队列 
		if (curNode->w + goods[curNode->level].w <= c) {
			Node *leftNode = new Node();
			leftNode->v = curNode->v + goods[curNode->level].v;
			leftNode->w = curNode->w + goods[curNode->level].w;
			leftNode->level = curNode->level + 1;
			leftNode->parent = curNode;
			leftNode->bound = curNode->bound;
			if (leftNode->level<n) {
				maxQueue.push(leftNode);
			}
			//更新maxValue、maxNode 
			if (maxValue < leftNode->v) {
				maxValue = leftNode->v;
				maxNode = leftNode;
			}
		}
		//扩展右节点 
		//只有当右节点的上界值比当前最优解要大时才予以考虑，加入优先队列 
		if (maxBound(curNode, goods, c)>maxValue) {
			Node *rightNode = new Node();
			rightNode->v = curNode->v;
			rightNode->w = curNode->w;
			rightNode->level = curNode->level + 1;
			rightNode->parent = curNode;
			rightNode->bound = maxBound(rightNode,goods,c);
			if (rightNode->level < n) {
				maxQueue.push(rightNode);
			}
			//更新maxValue、maxNode 
			if (maxValue < rightNode->v) {
				maxValue = rightNode->v;
				maxNode = rightNode;
			}
		}
	}
	curNode = maxNode;
	while (curNode) {
		int tempv = curNode->v;
		curNode = curNode->parent;
		if (curNode && curNode->v != tempv)
			goods[curNode->level].put = 1;
	}
	return maxValue;
}

//上界函数（以该节点为根的子树所能达到的价值上界）（与回溯法的上界函数相似） 
double maxBound(Node*node,Goods goods[],int c) {
	double maxValue=node->v;//当前背包的总价值
	//剩余背包容量
    double leftw=c-node->w;
    int i=node->level;	//确定当前节点在子集树的第几行 
    //以物品单位重量价值递减次序装入物品
    while(i<=n && goods[i].w<=leftw){
        leftw-=goods[i].w;
        maxValue+=goods[i].v;
        i++;
    }
    //装满背包（if条件与回溯法不同i<=n） 
    if(leftw!=0)
        maxValue+=goods[i].perp*leftw;
    return maxValue;//返回计算出的上界
}

int main() {
	int i;
    cout<<"请分别输入物品的数量和背包的容量：";
    cin>>n>>c;
    cout<<"请依次输入物品的重量:\n";
    for(i=1;i<=n;i++){
        cin>>goods[i].w;
        goods[i].order=i;
    }
 	cout<<"请依次输入物品的价值:\n";
    for(i=1;i<=n;i++){
    	cin>>goods[i].v;
		goods[i].perp=goods[i].v/goods[i].w;
	}
    	
	//先按单位价值排序
    sort(goods+1,goods+1+n,comp_goods);
    int maxVlue=branchAndBound(goods,c);
 
    cout<<"分支限界法求得0-1背包问题的最优解为："<<maxVlue<<endl;
    cout<<"装入背包的物品有：";
    for(i=1;i<=n;i++){
        if(goods[i].put==1)
            cout<<"物品"<<goods[i].order<<" ";
    }
    cout<<endl; 
    return 0;
}
