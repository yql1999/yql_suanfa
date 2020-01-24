#include <iostream>
using namespace std;
/* 	Prim最小生成树问题变量声明： 
	closest[j]=i---j在S中的邻接顶点i（j属于V-S,i属于S） 
   	c[i][j]--------边（i，j）的权
   	lowcost[j]=c[j][closest[j]],其中c[j][closest[j]]<=c[j][k]
*/

#define maxint 1000
#define inf 100000

//NOTE:顶点是从1开始的,数组中是从下标0开始的 
void Prim(int n,int c[][8]){
    int lowcost[maxint];
    int closest[maxint];
    bool s[maxint];
    int min=inf;
    int k,i,j;
    
    //若邻阶矩阵中两个顶点为0，则两者距离为inf无穷远 
	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){ 
    		if(c[i][j]==0)	
				c[i][j]=inf;
		} 
	}
	
    //初始化 
    s[0] = true;	//刚开始时S={1}
    for(i=1;i<n;i++){
        lowcost[i]=c[0][i];
        closest[i]=0;
        s[i]=false;
    }
    
	//n个顶点的最小生成树有(n-1)条边 
    for(i=0;i<(n-1);i++){
    	j=0;
    	min=inf;
    	//找顶点 
        for(k=1;k<n;k++){
        	if((lowcost[k]<min) && (!s[k])){
                min=lowcost[k];
                j=k;
            }
		}
            
		s[j]=true;	//把j顶点加入到集合中
        cout<<j+1<<" "<<closest[j]+1<<endl;
         
        /*更新 lowcost 和 closest,
		只要考虑相对于新加入顶点j有变化的V-S中的顶点（即还没有被取到的顶点）*/ 
        for(k=1;k<n;k++)
            if((c[j][k]<lowcost[k])&&(!s[k])){
                lowcost[k]=c[j][k];
                closest[k]=j;
            }
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
	cout<<" 用Prim算法生成最小生成树的操作过程如下："<<endl;
	Prim(8,c);
	return 0;	
}
