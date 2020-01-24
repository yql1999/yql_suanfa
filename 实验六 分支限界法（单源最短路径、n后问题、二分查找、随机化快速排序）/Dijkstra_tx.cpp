#include<iostream>
#include<cstring>
#define MAXN 1000
using namespace std;
/*单源最短路径问题 贪心求解（Dijstra）*/

/*n是顶点数，v是源，
dist[i]表示当前从源到顶点i的最短特殊路径长度,
prev[i]=j：最短路径中顶点i的前一个顶点是j
*/ 
void dijkstra(int n,int v, int a[][MAXN], int dist[], int prev[]) {
        if(v<0 || v>n)
            return;
        bool s[n+1];	//判断是否已存入该点到集合中 
        
		// 初始化
        for(int i=1;i<n;i++) {
            dist[i]=a[v][i];	//从顶点0到顶点i的路径长度 
            s[i]=false;
            if(dist[i]==MAXN){ 
                prev[i]=-1;
            } 
            else
                prev[i]=v;
        }
        dist[v]=0;
        s[v]=true;	//把顶点0加入集合中 

		// 循环n-1次，找出当前未加入集合的顶点j的dist[j]最小
        for(int i=1;i<n;i++){ 
            int temp=MAXN;
            int u=v;
            for(int j=1;j<n;j++) {// 寻找不在集合内且距离集合最近的节点j
                if((!s[j]) && (dist[j]<temp)){
                    u=j;
                    temp=dist[j];// 记录最短特殊路径长度
                }
            }
            s[u] = true;// 将节点u放入集合
			//更新dist[]和prev[]的值(只要更新和新加入的顶点u相邻的顶点即可)
            for (int j=1;j<=n;j++) {
                if ((!s[j]) && (a[u][j]<MAXN)){	//寻找不在集合内，且可达的节点
                    int newdist=dist[u]+a[u][j];
                    if(newdist<dist[j]) { // 与旧值进行比较，保留小的值
                        dist[j]=newdist;
                        prev[j]=u;
                    }
                }
            }
        }
}

int main() {
	//边权 
    int c[][MAXN]={{MAXN,MAXN,20,5,MAXN},
            {MAXN,MAXN,30,20,MAXN},{MAXN,MAXN,MAXN,30,MAXN},
            {MAXN,MAXN,MAXN,MAXN,10},{MAXN,MAXN,MAXN,MAXN,MAXN}};
    int n=5;	//顶点数 
    int dist[n+1]={0};	//dist[i]表示当前从源到顶点i的最短特殊路径长度 
    int prev[n+1]={0};	//前一个节点 
    dijkstra(n,0, c, dist, prev);
    for(int i=0;i<n;i++){
    	if(dist[i]==0 || dist[i]==MAXN){
    		cout<<"顶点0无法到达顶点"<<i<<endl;
		}
    	else
			cout<<"顶点0到顶点"<<i<<"的最短路径长度为"<<dist[i]<<endl;
	}
}
