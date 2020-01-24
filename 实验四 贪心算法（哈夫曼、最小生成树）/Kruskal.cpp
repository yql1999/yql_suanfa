#include <iostream>
#include<algorithm>
using namespace std;
#define maxint 1000
#define inf 100000
/* 	Kruskal��С���������⣨���ϰ�����С�ߣ�:
	Ҫ����һ������connected����ͬ����ͨ������ţ��Դ��ж����������Ƿ���ͨ 
*/



//����һ���ߵĽṹ�� 
typedef struct{
    int u;	//�ߵ���ʼ����
    int v;	//�ߵ�n�յ�
    int w;	//�ߵ�Ȩֵ
}Edge;


bool comp(Edge A,Edge B){
    return A.w<B.w;
}


void Kruskal(int n,int c[][8]){
    int i,j,uu,vv,connected_num1,connected_num2,k=0;
    int connected[maxint];	//����connected�����ж�������֮���Ƿ���ͨ
    Edge E[maxint];	//EΪһ���ߵ����� 
    
    //��ʼ�� 
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
	
	//��ÿ���߰�Ȩֵ����sort����
    sort(E,E+k,comp);	
    
    //��ÿ�������ò�ͬ��ͨ������ţ�����ʼʱ��n����ͨ����
    for(i=0;i<n;i++)
        connected[i]=i;	
        
    k=1;	//k��ʾ��ǰ�����������ĵ�n���ߣ���ʼֵΪ1
    j=0;	//jΪ����E��Ԫ�ص��±꣬��ֵΪ0
    
    //ѭ��������С��������n-1����
	while(k<n){	
        uu=E[j].u;
		vv=E[j].v;	//�ߵ�ͷβ����
        connected_num1=connected[uu];
        connected_num2=connected[vv];	//������������ͨ�������
        
        //���������㲻��ͬһ����ͨ�����ϣ��Ѹñ߼��뼯���� 
		if(connected_num1!=connected_num2){	 
			//NOTE:�����Ǵ�1��ʼ��,�������Ǵ��±�0��ʼ��
            cout<<" Edge: ("<<uu+1<<","<<vv+1<<"), Wight: "<<E[j].w<<endl;
            
            k++;	//���ɵı�����1
            
            /*����������������������ͨ�����ı�ţ�
			��������ͨ�����ı��Ϊsn2�ı߸�����ͨ�������Ϊsn1*/ 
			for(i=0;i<n;i++){
				if(connected[i]==connected_num2)
                    connected[i]=connected_num1;
            } 
        }
        
        j++;	//ɨ����һ��Ȩֵ��С�ı�
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
	cout<<" ��Kruskal�㷨������С�������Ĳ����������£�"<<endl;
	Kruskal(8,c);
	return 0;	
}
