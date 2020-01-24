//��֧�޽編���0-1�������� 
//���ȶ���
//BFS ����������� 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 

int n;//��Ʒ����
double c;//��������
int maxSize=0;

struct Goods{
 	double v;//��Ʒ��ֵ
	double w;//��Ʒ����
	int order;//��Ʒ���
	double perp;//��λ��ֵ
	int put;//�Ƿ�ѡ�� 
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
 	double v;//��������ǰ�ڵ���ܼ�ֵ
	double w;//��������ǰ�ڵ�������� 
	double bound;//�Ըýڵ�Ϊ���������ļ�ֵ�Ͻ� 
	int level;//�ýڵ����ڲ��� 
	Node*parent; //���ڵ�ָ�� 
 };  
 
 struct comp{
 	bool operator()(Node*a,Node*b){
 		return a->bound<b->bound;
	 }
 };
 
 
double maxBound(Node*node,Goods goods[],int c);

int branchAndBound(Goods goods[],int c){
	int i,maxValue;//��ǰ����������ֵ
	Node *maxNode = new Node();//���浱ǰ����ֵ�ڵ㣨Ҷ�ڵ㣩
	
	priority_queue<Node *, vector<Node *>, comp> maxQueue; //����ֵ���ȶ���
	
	Node *firstNode, *curNode;
	//�ѵ�һ���ڵ�������ȶ��� 
	firstNode = new Node();
	firstNode->bound = maxBound(firstNode,goods,c);
	firstNode->parent = NULL;
	maxQueue.push(firstNode);
	maxValue = 0;
	maxNode = firstNode;
	//�����ȶ��в�Ϊ�� 
	while (!maxQueue.empty()){
		curNode=maxQueue.top();
		maxQueue.pop();
		//��չ��ڵ�
		//ֻ��������������޽磬�����Կ��ǣ��������ȶ��� 
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
			//����maxValue��maxNode 
			if (maxValue < leftNode->v) {
				maxValue = leftNode->v;
				maxNode = leftNode;
			}
		}
		//��չ�ҽڵ� 
		//ֻ�е��ҽڵ���Ͻ�ֵ�ȵ�ǰ���Ž�Ҫ��ʱ�����Կ��ǣ��������ȶ��� 
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
			//����maxValue��maxNode 
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

//�Ͻ纯�����Ըýڵ�Ϊ�����������ܴﵽ�ļ�ֵ�Ͻ磩������ݷ����Ͻ纯�����ƣ� 
double maxBound(Node*node,Goods goods[],int c) {
	double maxValue=node->v;//��ǰ�������ܼ�ֵ
	//ʣ�౳������
    double leftw=c-node->w;
    int i=node->level;	//ȷ����ǰ�ڵ����Ӽ����ĵڼ��� 
    //����Ʒ��λ������ֵ�ݼ�����װ����Ʒ
    while(i<=n && goods[i].w<=leftw){
        leftw-=goods[i].w;
        maxValue+=goods[i].v;
        i++;
    }
    //װ��������if��������ݷ���ͬi<=n�� 
    if(leftw!=0)
        maxValue+=goods[i].perp*leftw;
    return maxValue;//���ؼ�������Ͻ�
}

int main() {
	int i;
    cout<<"��ֱ�������Ʒ�������ͱ�����������";
    cin>>n>>c;
    cout<<"������������Ʒ������:\n";
    for(i=1;i<=n;i++){
        cin>>goods[i].w;
        goods[i].order=i;
    }
 	cout<<"������������Ʒ�ļ�ֵ:\n";
    for(i=1;i<=n;i++){
    	cin>>goods[i].v;
		goods[i].perp=goods[i].v/goods[i].w;
	}
    	
	//�Ȱ���λ��ֵ����
    sort(goods+1,goods+1+n,comp_goods);
    int maxVlue=branchAndBound(goods,c);
 
    cout<<"��֧�޽編���0-1������������Ž�Ϊ��"<<maxVlue<<endl;
    cout<<"װ�뱳������Ʒ�У�";
    for(i=1;i<=n;i++){
        if(goods[i].put==1)
            cout<<"��Ʒ"<<goods[i].order<<" ";
    }
    cout<<endl; 
    return 0;
}
