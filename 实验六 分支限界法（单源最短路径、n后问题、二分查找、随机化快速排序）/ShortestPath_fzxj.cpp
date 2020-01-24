#include<iostream>
#include"MinHeap.h"
#define MAXN 1000
using namespace std;
 //单源最短路径问题 分支限界法求解
 
template<class Type>
class Graph{
	friend int main();
    public:
		void ShortesPaths(int);
	private:
        int		n,		   //图G的顶点数
				*prev;     //前驱顶点数组
 	    Type	**c,       //图G的领接矩阵
				*dist;     //最短距离数组
}; 
 
//节点属性 
template<class Type>
class MinHeapNode{
   friend Graph<Type>;
   public:
	   operator int ()const{return length;}
   private:
       int i;		  //顶点编号
       Type length;	  //当前路长（优先级） 
}; 
 
template<class Type>
void Graph<Type>::ShortesPaths(int v){	//单源最短路径问题的优先队列式分支限界法
	//定义最小堆容量为1000 
	MinHeap<MinHeapNode<Type> > H(1000);
	//定义源为初始扩展节点 
	MinHeapNode<Type> E;
	E.i=v;
	E.length=0;
	dist[v]=0;
 
	while (true){//搜索问题的解空间
		for (int j = 1; j <= n; j++)
			//若顶点i到顶点j可达，且满足控制约束
			if((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) {				 
				 dist[j]=E.length+c[E.i][j];
				 prev[j]=E.i;
				 // 加入活结点优先队列
				 MinHeapNode<Type> N;
				 N.i=j;
				 N.length=dist[j];
				 H.Insert(N);
			}
		try {
			H.DeleteMin(E); // 取下一扩展结点
		}        
		catch (int) {
			break;
		}  
		if (H.currentSize==0){// 优先队列空
			break;
		}
	}
}
 
int main(){  
	int n=5;
	int prev[n+1] = {0};  
	int dist[n+1]={MAXN,MAXN,MAXN,MAXN,MAXN};
 	//边权 
    int a[][MAXN]={{MAXN,MAXN,20,5,MAXN},
            {MAXN,MAXN,30,20,MAXN},{MAXN,MAXN,MAXN,30,MAXN},
            {MAXN,MAXN,MAXN,MAXN,10},{MAXN,MAXN,MAXN,MAXN,MAXN}};
   	int **c = new int*[n+1];
 	cout<<"单源图的邻接矩阵如下："<<endl;
	for(int i=0;i<n;i++){
		c[i]=new int[n+1];
		for(int j=0; j<n; j++)
		{
			c[i][j]=a[i][j];
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	//从顶点0开始 
	int v=0;
    Graph<int> G;
    G.n=n;
    G.c=c;
    G.dist=dist;
    G.prev=prev;
    G.ShortesPaths(v);
 
    cout<<"从顶点0到顶点4的最短路长是："<<dist[4]<<endl;
    for (int i=1;i<=4;i++)
		cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;
 
    for(int i=0;i<n;i++){
    	if(dist[i]==0 || dist[i]==MAXN){
    		cout<<"顶点0无法到达顶点"<<i<<endl;
		}
    	else
			cout<<"顶点0到顶点"<<i<<"的最短路径长度为"<<dist[i]<<endl;
	}
 
	for(int i=1;i<=n;i++)
		delete []c[i];
	delete []c;
	c=0;	
	return 0;
}
