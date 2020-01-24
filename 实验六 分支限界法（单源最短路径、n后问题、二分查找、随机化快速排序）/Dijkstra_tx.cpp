#include<iostream>
#include<cstring>
#define MAXN 1000
using namespace std;
/*��Դ���·������ ̰����⣨Dijstra��*/

/*n�Ƕ�������v��Դ��
dist[i]��ʾ��ǰ��Դ������i���������·������,
prev[i]=j�����·���ж���i��ǰһ��������j
*/ 
void dijkstra(int n,int v, int a[][MAXN], int dist[], int prev[]) {
        if(v<0 || v>n)
            return;
        bool s[n+1];	//�ж��Ƿ��Ѵ���õ㵽������ 
        
		// ��ʼ��
        for(int i=1;i<n;i++) {
            dist[i]=a[v][i];	//�Ӷ���0������i��·������ 
            s[i]=false;
            if(dist[i]==MAXN){ 
                prev[i]=-1;
            } 
            else
                prev[i]=v;
        }
        dist[v]=0;
        s[v]=true;	//�Ѷ���0���뼯���� 

		// ѭ��n-1�Σ��ҳ���ǰδ���뼯�ϵĶ���j��dist[j]��С
        for(int i=1;i<n;i++){ 
            int temp=MAXN;
            int u=v;
            for(int j=1;j<n;j++) {// Ѱ�Ҳ��ڼ������Ҿ��뼯������Ľڵ�j
                if((!s[j]) && (dist[j]<temp)){
                    u=j;
                    temp=dist[j];// ��¼�������·������
                }
            }
            s[u] = true;// ���ڵ�u���뼯��
			//����dist[]��prev[]��ֵ(ֻҪ���º��¼���Ķ���u���ڵĶ��㼴��)
            for (int j=1;j<=n;j++) {
                if ((!s[j]) && (a[u][j]<MAXN)){	//Ѱ�Ҳ��ڼ����ڣ��ҿɴ�Ľڵ�
                    int newdist=dist[u]+a[u][j];
                    if(newdist<dist[j]) { // ���ֵ���бȽϣ�����С��ֵ
                        dist[j]=newdist;
                        prev[j]=u;
                    }
                }
            }
        }
}

int main() {
	//��Ȩ 
    int c[][MAXN]={{MAXN,MAXN,20,5,MAXN},
            {MAXN,MAXN,30,20,MAXN},{MAXN,MAXN,MAXN,30,MAXN},
            {MAXN,MAXN,MAXN,MAXN,10},{MAXN,MAXN,MAXN,MAXN,MAXN}};
    int n=5;	//������ 
    int dist[n+1]={0};	//dist[i]��ʾ��ǰ��Դ������i���������·������ 
    int prev[n+1]={0};	//ǰһ���ڵ� 
    dijkstra(n,0, c, dist, prev);
    for(int i=0;i<n;i++){
    	if(dist[i]==0 || dist[i]==MAXN){
    		cout<<"����0�޷����ﶥ��"<<i<<endl;
		}
    	else
			cout<<"����0������"<<i<<"�����·������Ϊ"<<dist[i]<<endl;
	}
}
