#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


//����ڵ�Ľṹ�� 
typedef struct treeNode {
    treeNode *lchild, *rchild;
    string ch;
    int weight;
    string huffCode;
    //�����캯��
    treeNode():lchild(NULL),rchild(NULL),ch(""),weight(0),huffCode(""){}
}treeNode,*tree;


//����������������ӡ����������
void createHuffCode(treeNode * root) {
	//����������ڵ㣬����ڵ�ı����ڸýڵ�Ļ����ϼ�"0"���ٶ���ڵ���еݹ飬ֱ��Ҷ�ӽڵ� 
        if (root->lchild) {
            root->lchild->huffCode =root->huffCode+ "0";
            createHuffCode(root->lchild);
        }
        //�����Ҷ�ӽ�㣬��ӡ
        if (!(root->lchild) && !(root->rchild)) {
            cout << root->ch << " ";
			cout << root->huffCode<<endl; 
        }
        if (root->rchild) {
            root->rchild->huffCode = root->huffCode + "1";
            createHuffCode(root->rchild);
        }
}


//�Զ���Ƚ���
struct cmp {
    bool operator() (treeNode *a, treeNode * b) {
        return a->weight > b->weight;
    }
};


//��С��
priority_queue < treeNode*, vector<treeNode*>, cmp > pque;

void createHuffTree() {
	int n=0,i,j;
	cout<<" ������Ҫ���б�����ַ�����"<<endl;
	char ch,c[256];
	int w[256],num[256]={0};
	//����ÿ���ַ���Ƶ�� 
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
		pque.push(t);	//�������ȶ���
    }

    //�����ҳ�Ȩֵ��С���������
    while(pque.size()!=1){
        treeNode *a,*b;
        a=pque.top();
        pque.pop();
        b=pque.top();
        pque.pop();
        //��a��b�����ڵ�ϲ���temp�ڵ㣬���������ȶ����� 
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
