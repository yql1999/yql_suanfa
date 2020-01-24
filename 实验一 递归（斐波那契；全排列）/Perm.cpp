#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//递归计算全排列 
void Perm(char* a, int k, int m) {
	int i,j;
    if (k == m) {	//只剩下一个元素 
        for (i = 0; i <= m; i++)
            cout<<a[i];
        cout<<endl;
    } 
	else {	//还有多个元素待排序，递归产生排序 
        for (j = k; j <= m; j++) {
			swap(a[j], a[k]);	//从固定的数与第一个依次交换
            Perm(a, k + 1, m);
            swap(a[j],a[k]);
        }
    }
        
}

//非递归计算全排列（STL） 
void permutation(char* str,int length)
{
	sort(str,str+length);	//先对字符串进行排序 
	while(next_permutation(str,str+length)){	//运用STL函数 
		for(int i=0;i<length;i++)
			cout<<str[i];
		cout<<endl;
	}
}
 
int main() {
	char *s=new char[100];
	cout<<" 请输入要进行排列的字符串：";
	cin>>s;
	int n=strlen(s);	//字符串长度 
	cout<<" 递归算法的全排列结果为："<<endl;
	Perm(s,0,n-1);
	cout<<" 非递归算法的全排列结果为："<<endl;
	permutation(s,n);
	return 0;
}
