#include <iostream>
#include<cstring>
using namespace std;
/* 求最长子段和（连续的） */

//穷举法
int maxInterval_all(int len,int*a){
	int i,j,k,ans=0,sum=0;
	int start=0,end=0;
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
	//从mid开始往左逐个加，求左边的最大子段和（是连续的） 
	for(i=mid;i>=left;i--){
		sum+=a[i];
		if(sum>left_max)
			left_max=sum;
	} 
	//从mid开始往右逐个加，求右边的最大子段和 
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

int main(int argc, char** argv) {
	int a[]={-2,11,-4,13,-5,-2}; 
	cout<<" 数组a为：";
	int i,len;
	len=6;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<" 穷举法求最长子序列："<<maxInterval_all(len,a)<<endl;
	cout<<" 分治法求最长子序列："<<maxInterval_div(a,0,len)<<endl;
	cout<<" 动态规划求最长子序列："<<maxInterval(len,a)<<endl;
	return 0;
}
