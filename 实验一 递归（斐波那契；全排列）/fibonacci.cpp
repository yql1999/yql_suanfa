#include <iostream>
#include<string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//�ݹ鷨��쳲����� 
long long int function1(int n){
	if(n==1 || n==0)	return 1;
	else{
		return function1(n-1)+function1(n-2);
	}
}

//�ǵݹ���쳲�������STL�� 
long long int function2(int n){
	if(n==1 || n==0)	return 1;
	else{
		long long int i,num1=1,num2=1,cmp=0;
			for(i=2;i<=n;i++){
				cmp=num1+num2;
				num1=num2;
				num2=cmp;
			}
		return cmp;
	}
}

int main(int argc, char** argv) {
	cout<<" Please input the number to calculate: ";
	int n;
	while(cin>>n){
		cout<<" case1: ʹ�÷ǵݹ鷽�� fibonacci( "<<n<<" ) = "<<function2(n)<<endl;
		cout<<" case2: ʹ�õݹ�ķ��� fibonacci( "<<n<<" ) = "<<function1(n)<<endl;
		cout<<" Please input the number to calculate: ";
	}
	return 0;
}
