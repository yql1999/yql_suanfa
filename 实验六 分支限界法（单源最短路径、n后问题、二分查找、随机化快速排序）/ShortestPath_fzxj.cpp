#include<iostream>
#include"MinHeap.h"
#define MAXN 1000
using namespace std;
 //��Դ���·������ ��֧�޽編���
 
template<class Type>
class Graph{
	friend int main();
    public:
		void ShortesPaths(int);
	private:
        int		n,		   //ͼG�Ķ�����
				*prev;     //ǰ����������
 	    Type	**c,       //ͼG����Ӿ���
				*dist;     //��̾�������
}; 
 
//�ڵ����� 
template<class Type>
class MinHeapNode{
   friend Graph<Type>;
   public:
	   operator int ()const{return length;}
   private:
       int i;		  //������
       Type length;	  //��ǰ·�������ȼ��� 
}; 
 
template<class Type>
void Graph<Type>::ShortesPaths(int v){	//��Դ���·����������ȶ���ʽ��֧�޽編
	//������С������Ϊ1000 
	MinHeap<MinHeapNode<Type> > H(1000);
	//����ԴΪ��ʼ��չ�ڵ� 
	MinHeapNode<Type> E;
	E.i=v;
	E.length=0;
	dist[v]=0;
 
	while (true){//��������Ľ�ռ�
		for (int j = 1; j <= n; j++)
			//������i������j�ɴ���������Լ��
			if((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) {				 
				 dist[j]=E.length+c[E.i][j];
				 prev[j]=E.i;
				 // ����������ȶ���
				 MinHeapNode<Type> N;
				 N.i=j;
				 N.length=dist[j];
				 H.Insert(N);
			}
		try {
			H.DeleteMin(E); // ȡ��һ��չ���
		}        
		catch (int) {
			break;
		}  
		if (H.currentSize==0){// ���ȶ��п�
			break;
		}
	}
}
 
int main(){  
	int n=5;
	int prev[n+1] = {0};  
	int dist[n+1]={MAXN,MAXN,MAXN,MAXN,MAXN};
 	//��Ȩ 
    int a[][MAXN]={{MAXN,MAXN,20,5,MAXN},
            {MAXN,MAXN,30,20,MAXN},{MAXN,MAXN,MAXN,30,MAXN},
            {MAXN,MAXN,MAXN,MAXN,10},{MAXN,MAXN,MAXN,MAXN,MAXN}};
   	int **c = new int*[n+1];
 	cout<<"��Դͼ���ڽӾ������£�"<<endl;
	for(int i=0;i<n;i++){
		c[i]=new int[n+1];
		for(int j=0; j<n; j++)
		{
			c[i][j]=a[i][j];
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	//�Ӷ���0��ʼ 
	int v=0;
    Graph<int> G;
    G.n=n;
    G.c=c;
    G.dist=dist;
    G.prev=prev;
    G.ShortesPaths(v);
 
    cout<<"�Ӷ���0������4�����·���ǣ�"<<dist[4]<<endl;
    for (int i=1;i<=4;i++)
		cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;
 
    for(int i=0;i<n;i++){
    	if(dist[i]==0 || dist[i]==MAXN){
    		cout<<"����0�޷����ﶥ��"<<i<<endl;
		}
    	else
			cout<<"����0������"<<i<<"�����·������Ϊ"<<dist[i]<<endl;
	}
 
	for(int i=1;i<=n;i++)
		delete []c[i];
	delete []c;
	c=0;	
	return 0;
}
