#include <iostream>
#include<algorithm>
using namespace std;
#define maxint 1000
#define inf 100000
/* 	Kruskal最小生成树问题（不断包含最小边）:
	要设置一个数组connected给不同的连通分量标号，以此判断两个顶点是否连通 
*/



//定义一个边的结构体 
typedef struct{
    int u;	//边的起始顶点
    int v;	//边的n终点
    int w;	//边的权值
}Edge;


bool comp(Edge A,Edge B){
    return A.w<B.w;
}


void Kruskal(int n,int c[][8]){
    int i,j,uu,vv,connected_num1,connected_num2,k=0;
    int connected[maxint];	//数组connected用于判断两顶点之间是否连通
    Edge E[maxint];	//E为一个边的数组 
    
    //初始化 
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		if(i<j && c[i][j]!=0){
            	E[k].u=i;
            	E[k].v=j;
            	E[k].w=c[i][j];
            	k++;
        	}
		}
	}
	
	//对每条边按权值进行sort排序
    sort(E,E+k,comp);	
    
    //给每个顶点置不同连通分量编号，即初始时有n个连通分量
    for(i=0;i<n;i++)
        connected[i]=i;	
        
    k=1;	//k表示当前构造生成树的第n条边，初始值为1
    j=0;	//j为数组E中元素的下标，初值为0
    
    //循环产生最小生成树的n-1条边
	while(k<n){	
        uu=E[j].u;
		vv=E[j].v;	//边的头尾顶点
        connected_num1=connected[uu];
        connected_num2=connected[vv];	//顶点所属的连通分量编号
        
        //若两个顶点不在同一个连通分量上，把该边加入集合中 
		if(connected_num1!=connected_num2){	 
			//NOTE:顶点是从1开始的,数组中是从下标0开始的
            cout<<" Edge: ("<<uu+1<<","<<vv+1<<"), Wight: "<<E[j].w<<endl;
            
            k++;	//生成的边数增1
            
            /*更新这两个顶点所属的连通分量的编号，
			即所有连通分量的编号为sn2的边改其连通分量编号为sn1*/ 
			for(i=0;i<n;i++){
				if(connected[i]==connected_num2)
                    connected[i]=connected_num1;
            } 
        }
        
        j++;	//扫描下一条权值最小的边
    }    
}


int main(){
	int c[][8]={{0,2,8,1,0,0,0,0},{2,0,6,0,1,0,0,0},
	{8,6,0,7,5,1,2,0},{1,0,7,0,0,0,9,0},
	{0,1,5,0,0,3,0,8},{0,0,1,0,3,0,4,6},
	{0,0,2,9,0,4,0,3},{0,0,0,0,8,6,3,0}};
	cout<<" 邻阶矩阵为："<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	} 
	cout<<" 用Kruskal算法生成最小生成树的操作过程如下："<<endl;
	Kruskal(8,c);
	return 0;	
}
