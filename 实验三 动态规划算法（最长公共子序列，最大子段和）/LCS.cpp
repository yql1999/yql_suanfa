#include <iostream>
#include<cstring>
using namespace std;
/* ������������У�û�б�������b�� */


#define MAXN 1000
char c[MAXN][MAXN];

//����󳤶� 
int LCS(int lenx,int leny,char* x,char* y){
	int i,j;
	//�߽����� 
	for(i=0;i<=lenx;i++)
		c[i][0]=0;
	for(i=0;i<=leny;i++)
		c[0][i]=0;
	//�ݹ������Ž� 
	for(i=1;i<=lenx;i++){
		for(j=1;j<=leny;j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
			}
			else if(c[i-1][j]>=c[i][j-1])
				c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i][j-1];
		}
	}
	return c[lenx][leny];
}

//�ݹ��ӡ����������
void PrintLCS(int i,int j,char* x,char* y) {
	if(i==0 || j==0)
		return;
	if(x[i-1]==y[j-1]){	
		PrintLCS(i-1,j-1,x,y);
		cout<<x[i-1];	//����������ȣ����ӡ���� 
	}
	else if(c[i-1][j]>=c[i][j-1])
		PrintLCS(i-1,j,x,y); 
	else
		PrintLCS(i,j-1,x,y);
}

int main(int argc, char** argv) {
	//char*x1="ABCBDAB",*y1="BDCABA",*x2="zhejiang university of technology",*y2="zhejiang university city college";
	char x[MAXN],y[MAXN];
	int lenx,leny;
	cout<<" �������һ���ַ�������x��";
	while(gets(x)){
		cout<<" ������ڶ����ַ�������y��";
		gets(y);
		lenx=strlen(x),leny=strlen(y);
		cout<<x<<" �� "<<y<<" �ĳ����������г���Ϊ��"<<LCS(lenx,leny,x,y)<<endl;
		cout<<x<<" �� "<<y<<" ��������������ǣ� ";
		PrintLCS(lenx,leny,x,y);
		cout<<endl;
		cout<<" �������һ���ַ�������x��";
	}
	return 0;
}
