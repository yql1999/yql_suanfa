#include<iostream>
#include<algorithm>
using namespace std;
/*贪心算法-磁盘文件最优存储问题*/

bool cmp(int a,int b){
    return a>b;
}

void Sort(int n,int a[]){
	int i,k,mid,b[n];
    sort(a,a+n,cmp);	//递减 
    mid=n/2;
    b[mid]=a[0];	//中间的最大 
    for(i=1,k=1;i<n;i++,k++){   //a的值从中间往两边依次减少
        b[mid-k]=a[i];
        i++;
        if(i!=n)	
			b[mid+k] = a[i];
    }
    for(i=0;i<n;i++)	//b->a
        a[i]=b[i];
}

//第k个文件的检索概率为 pi = ak / ∑ai 
void  minStore(int n,int a[]){
    int i,j,sum = 0;
    for(i=0;i<n;i++)
        sum+=a[i];
    double ans=0;
    for(i=0;i<(n-1);i++){	//磁道间的检索时间 ∑(pi*pj*d(j-i)),0<=i<j<n
        for(j=i+1;j<n;j++){
            ans+=(a[i]*1.0/sum)*(a[j]*1.0/sum)*(j-i);
        }
    }
    cout<<"最小期望检索时间:"<<ans<<endl;
}

int main(){
    int n,k,mid,i;
    cout<<"输入文件个数"<<endl;
    cin>>n;
    int a[n];
    cout<<"输入文件的检索概率:"<<endl;
    for(i = 0;i<n;i++){
        cin>>a[i];
    }
    Sort(n,a);
    minStore(n,a);
    return 0;
}
