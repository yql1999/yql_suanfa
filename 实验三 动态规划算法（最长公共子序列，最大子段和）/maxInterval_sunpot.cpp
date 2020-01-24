#include <iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#include<stdlib.h>
using namespace std;
/* ����Ӷκͣ������ģ�-----��ʷ�Ϻ�ʱ̫������ӭ������󱬷����ļ������� */

#define MAXN 1000

//��ٷ�(������ֶεĿ�ʼ�ͽ���λ��)
int maxInterval_all(int len,int*a,int& start,int& end){
	int i,j,k,ans=0,sum=0;
	start=0,end=0;
	//����ѭ��������ֶκ� 
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			sum=0;
			for(k=i;k<=j;k++){
				sum+=a[k];
				if(sum>ans){
					start=i;
					end=j;
					ans=sum;
				}
			}
		}
	}
	return ans;
}

//����
int maxInterval_div(int*a,int left,int right){
	if(left==right)
		return a[left]>0?a[left]:0;
	int mid=(left+right)/2;
	int leftMaxInterval=maxInterval_div(a,left,mid);	//������������Ӷκ� 
	int rightMaxInterval=maxInterval_div(a,mid+1,right);	//�ұ����������Ӷκ�
	int i,j;
	int sum=0,left_max=0,right_max=0;
	for(i=mid;i>=left;i--){
		sum+=a[i];
		if(sum>left_max)
			left_max=sum;
	} 
	sum=0;
	for(i=mid+1;i<right;i++){
		sum+=a[i];
		if(sum>right_max)
			right_max=sum;
	} 
	//���������ߵ�����Ӷκ���ӣ��ֱ������ҵ�����ӶκͱȽ�
	int ans=left_max+right_max;	 
	if(ans<leftMaxInterval)
		ans=leftMaxInterval;
	if(ans<rightMaxInterval)
		ans=rightMaxInterval;
	return ans;
} 

//��̬�滮��������iΪ�յ㣨���������a[i]�� 
int maxInterval(int len,int*a){
	int i,b=0,sum=0;
	for(i=0;i<len;i++){
		if(b>0)	//����i-1Ϊ�յ������b>0
		//��iΪ�յ������ = ��i-1Ϊ�յ������b + a[i]
			b+=a[i];	
		else	//����i-1Ϊ�յ������b<=0 
		//��ΪҪ���ǰ����i-1Ϊ�յ������b�Ǹ�����
		//��Ȼ����ʹ�������������iΪ�յ������ b = a[i] 
			b=a[i];
		//��b>sum������sum 
		if(b>sum)
			sum=b;
	}
	return sum;
}

/*�ļ������� 
ofstream: д��������������ļ��� (��ostream�������) 
ifstream: �����������룩���ļ���(��istream�������) 
fstream: ��ͬʱ��д�������ļ��� (��iostream�������)*/ 
int main(int argc, char** argv) {
	ifstream file("E:\\ʵ��\\�㷨��������ʵ��\\ʵ���� �����㷨������������У�����Ӷκͣ�\\̫�����Ӵ��������.txt");
	if(!file.is_open()){
		cerr<<"�ļ���ʧ�ܣ�"<<endl;
		return 0;
	} 
	vector<string>v;
	string s;
	int a[MAXN];	//����a���̫�������� 
	int len=0; 
	while(getline(file,s)){	//���ļ��ж�ȡÿһ�� ��ÿһ�����������ݣ�year  sunspot	variation�� 
		v.push_back(s);	//���������� 
	}
	vector<string>::iterator it;
	for(it=v.begin();it!=v.end();it++){
		//istringstream���Դ���һ�����󣬰�һ���ַ�����Ȼ���Կո�Ϊ�ָ����Ѹ��зָ�
		istringstream is(*it);
		string str;
		int temp=0;
		while(is>>str){
			if(temp==2){
				double x=atof(str.c_str());	//���ַ���������תΪ�����͵���ֵ
				//double x = stod(str);
				a[len++]=x;
			}
			temp++;
		}
	}
	len--;	//����a���� 
	int start,end;
	clock_t cstart,cend;
	cstart=clock();
	int sum1=maxInterval_all(len,a,start,end);
	cend=clock();
	int t1=cend-cstart;
	cstart=clock();
	int sum2=maxInterval_div(a,0,len);
	cend=clock();
	int t2=cend-cstart;
	cstart=clock();
	int sum3=maxInterval(len,a);
	cend=clock();
	int t3=cend-cstart;
	cout<<" ̫��������󱬷�������ǣ�"<<v.at(end)<<endl;
	cout<<" ����ѭ����ʱ��"<<t1<<" ms"<<endl; 
	cout<<" ���η���ʱ��"<<t2<<" ms"<<endl; 
	cout<<" ��̬�滮��ʱ��"<<t3<<" ms"<<endl; 
	return 0;
}
