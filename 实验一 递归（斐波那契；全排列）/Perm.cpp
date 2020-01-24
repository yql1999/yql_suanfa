#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//�ݹ����ȫ���� 
void Perm(char* a, int k, int m) {
	int i,j;
    if (k == m) {	//ֻʣ��һ��Ԫ�� 
        for (i = 0; i <= m; i++)
            cout<<a[i];
        cout<<endl;
    } 
	else {	//���ж��Ԫ�ش����򣬵ݹ�������� 
        for (j = k; j <= m; j++) {
			swap(a[j], a[k]);	//�ӹ̶��������һ�����ν���
            Perm(a, k + 1, m);
            swap(a[j],a[k]);
        }
    }
        
}

//�ǵݹ����ȫ���У�STL�� 
void permutation(char* str,int length)
{
	sort(str,str+length);	//�ȶ��ַ����������� 
	while(next_permutation(str,str+length)){	//����STL���� 
		for(int i=0;i<length;i++)
			cout<<str[i];
		cout<<endl;
	}
}
 
int main() {
	char *s=new char[100];
	cout<<" ������Ҫ�������е��ַ�����";
	cin>>s;
	int n=strlen(s);	//�ַ������� 
	cout<<" �ݹ��㷨��ȫ���н��Ϊ��"<<endl;
	Perm(s,0,n-1);
	cout<<" �ǵݹ��㷨��ȫ���н��Ϊ��"<<endl;
	permutation(s,n);
	return 0;
}
