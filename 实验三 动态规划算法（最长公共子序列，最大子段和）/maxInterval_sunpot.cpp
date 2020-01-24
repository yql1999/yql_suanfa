#include <iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#include<stdlib.h>
using namespace std;
/* 求最长子段和（连续的）-----历史上何时太阳黑子迎来了最大爆发（文件操作） */

#define MAXN 1000

//穷举法(更新最长字段的开始和结束位置)
int maxInterval_all(int len,int*a,int& start,int& end){
	int i,j,k,ans=0,sum=0;
	start=0,end=0;
	//三重循环查找最长字段和 
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

//分治
int maxInterval_div(int*a,int left,int right){
	if(left==right)
		return a[left]>0?a[left]:0;
	int mid=(left+right)/2;
	int leftMaxInterval=maxInterval_div(a,left,mid);	//左边区域的最大子段和 
	int rightMaxInterval=maxInterval_div(a,mid+1,right);	//右边区域的最大子段和
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
	//将左右两边的最大子段和相加，分别与左、右的最大子段和比较
	int ans=left_max+right_max;	 
	if(ans<leftMaxInterval)
		ans=leftMaxInterval;
	if(ans<rightMaxInterval)
		ans=rightMaxInterval;
	return ans;
} 

//动态规划：考虑以i为终点（即必须包含a[i]） 
int maxInterval(int len,int*a){
	int i,b=0,sum=0;
	for(i=0;i<len;i++){
		if(b>0)	//若以i-1为终点的最大和b>0
		//以i为终点的最大和 = 以i-1为终点的最大和b + a[i]
			b+=a[i];	
		else	//若以i-1为终点的最大和b<=0 
		//因为要最大，前面以i-1为终点的最大和b是负数，
		//必然不能使其更大，所以令以i为终点的最大和 b = a[i] 
			b=a[i];
		//若b>sum，更新sum 
		if(b>sum)
			sum=b;
	}
	return sum;
}

/*文件操作： 
ofstream: 写操作（输出）的文件类 (由ostream引申而来) 
ifstream: 读操作（输入）的文件类(由istream引申而来) 
fstream: 可同时读写操作的文件类 (由iostream引申而来)*/ 
int main(int argc, char** argv) {
	ifstream file("E:\\实验\\算法设计与分析实验\\实验三 分治算法（最长公共子序列，最大子段和）\\太阳黑子处理后数据.txt");
	if(!file.is_open()){
		cerr<<"文件打开失败！"<<endl;
		return 0;
	} 
	vector<string>v;
	string s;
	int a[MAXN];	//数组a存放太阳黑子数 
	int len=0; 
	while(getline(file,s)){	//从文件中读取每一行 （每一行有三组数据：year  sunspot	variation） 
		v.push_back(s);	//存入向量中 
	}
	vector<string>::iterator it;
	for(it=v.begin();it!=v.end();it++){
		//istringstream可以创建一个对象，绑定一行字符串，然后以空格为分隔符把该行分隔
		istringstream is(*it);
		string str;
		int temp=0;
		while(is>>str){
			if(temp==2){
				double x=atof(str.c_str());	//把字符串的数字转为数字型的数值
				//double x = stod(str);
				a[len++]=x;
			}
			temp++;
		}
	}
	len--;	//数组a长度 
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
	cout<<" 太阳黑子最大爆发的年份是："<<v.at(end)<<endl;
	cout<<" 三重循环用时："<<t1<<" ms"<<endl; 
	cout<<" 分治法用时："<<t2<<" ms"<<endl; 
	cout<<" 动态规划用时："<<t3<<" ms"<<endl; 
	return 0;
}
