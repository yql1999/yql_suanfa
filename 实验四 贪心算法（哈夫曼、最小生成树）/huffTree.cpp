#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


//定义节点的结构体 
typedef struct treeNode {
    treeNode *lchild, *rchild;
    string ch;
    int weight;
    string huffCode;
    //带构造函数
    treeNode():lchild(NULL),rchild(NULL),ch(""),weight(0),huffCode(""){}
}treeNode,*tree;


//遍历哈夫曼树，打印哈夫曼编码
void createHuffCode(treeNode * root) {
	//若还存在左节点，则左节点的编码在该节点的基础上加"0"，再对左节点进行递归，直到叶子节点 
        if (root->lchild) {
            root->lchild->huffCode =root->huffCode+ "0";
            createHuffCode(root->lchild);
        }
        //如果是叶子结点，打印
        if (!(root->lchild) && !(root->rchild)) {
            cout << root->ch << " ";
			cout << root->huffCode<<endl; 
        }
        if (root->rchild) {
            root->rchild->huffCode = root->huffCode + "1";
            createHuffCode(root->rchild);
        }
}


//自定义比较体
struct cmp {
    bool operator() (treeNode *a, treeNode * b) {
        return a->weight > b->weight;
    }
};


//最小堆
priority_queue < treeNode*, vector<treeNode*>, cmp > pque;

void createHuffTree() {
	int n=0,i,j;
	cout<<" 请输入要进行编码的字符串："<<endl;
	char ch,c[256];
	int w[256],num[256]={0};
	//计算每个字符的频率 
	while((ch=getchar())!='\n')
  		num[ch]++;
 	for(i=0;i<256;i++){
 		if(num[i]){ 
		 	c[n]=i;
   			w[n]=num[i];
   			n++;
  		}
	}
    vector<int> v_weight;     
    vector<char> v_ch;
    for(i=0;i<n;i++){
        v_ch.push_back(c[i]);
        v_weight.push_back(w[i]);
    }
	for(i=0;i<v_ch.size();i++) {
        treeNode * t = new treeNode;
        t->ch = v_ch[i];
        t->weight = v_weight[i];
		pque.push(t);	//加入优先队列
    }

    //依次找出权值最小的两个结点
    while(pque.size()!=1){
        treeNode *a,*b;
        a=pque.top();
        pque.pop();
        b=pque.top();
        pque.pop();
        //把a、b两个节点合并成temp节点，并加入优先队列中 
        treeNode *temp = new treeNode;
        temp->weight = a->weight + b->weight;
        temp->rchild = b;
        pque.push(temp);
    }
    
    createHuffCode(q.top());
}


int main() {
    createHuffTree();
    return 0;
}
