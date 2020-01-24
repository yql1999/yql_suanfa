#include <iostream>
#include<cstring>
using namespace std;
/* 求最长公共子序列（没有保存数组b） */


#define MAXN 1000
char c[MAXN][MAXN];

//求最大长度 
int LCS(int lenx,int leny,char* x,char* y){
	int i,j;
	//边界条件 
	for(i=0;i<=lenx;i++)
		c[i][0]=0;
	for(i=0;i<=leny;i++)
		c[0][i]=0;
	//递归求最优解 
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

//递归打印公共子序列
void PrintLCS(int i,int j,char* x,char* y) {
	if(i==0 || j==0)
		return;
	if(x[i-1]==y[j-1]){	
		PrintLCS(i-1,j-1,x,y);
		cout<<x[i-1];	//若两个数相等，则打印该数 
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
	cout<<" 请输入第一个字符串序列x：";
	while(gets(x)){
		cout<<" 请输入第二个字符串序列y：";
		gets(y);
		lenx=strlen(x),leny=strlen(y);
		cout<<x<<" 和 "<<y<<" 的长公共子序列长度为："<<LCS(lenx,leny,x,y)<<endl;
		cout<<x<<" 和 "<<y<<" 的最长公共子序列是： ";
		PrintLCS(lenx,leny,x,y);
		cout<<endl;
		cout<<" 请输入第一个字符串序列x：";
	}
	return 0;
}
