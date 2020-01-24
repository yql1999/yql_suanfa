#include <iostream>
using namespace std;
/* 	Prim��С������������������� 
	closest[j]=i---j��S�е��ڽӶ���i��j����V-S,i����S�� 
   	c[i][j]--------�ߣ�i��j����Ȩ
   	lowcost[j]=c[j][closest[j]],����c[j][closest[j]]<=c[j][k]
*/

#define maxint 1000
#define inf 100000

//NOTE:�����Ǵ�1��ʼ��,�������Ǵ��±�0��ʼ�� 
void Prim(int n,int c[][8]){
    int lowcost[maxint];
    int closest[maxint];
    bool s[maxint];
    int min=inf;
    int k,i,j;
    
    //���ڽ׾�������������Ϊ0�������߾���Ϊinf����Զ 
	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){ 
    		if(c[i][j]==0)	
				c[i][j]=inf;
		} 
	}
	
    //��ʼ�� 
    s[0] = true;	//�տ�ʼʱS={1}
    for(i=1;i<n;i++){
        lowcost[i]=c[0][i];
        closest[i]=0;
        s[i]=false;
    }
    
	//n���������С��������(n-1)���� 
    for(i=0;i<(n-1);i++){
    	j=0;
    	min=inf;
    	//�Ҷ��� 
        for(k=1;k<n;k++){
        	if((lowcost[k]<min) && (!s[k])){
                min=lowcost[k];
                j=k;
            }
		}
            
		s[j]=true;	//��j������뵽������
        cout<<j+1<<" "<<closest[j]+1<<endl;
         
        /*���� lowcost �� closest,
		ֻҪ����������¼��붥��j�б仯��V-S�еĶ��㣨����û�б�ȡ���Ķ��㣩*/ 
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
	cout<<" �ڽ׾���Ϊ��"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	} 
	cout<<" ��Prim�㷨������С�������Ĳ����������£�"<<endl;
	Prim(8,c);
	return 0;	
}
