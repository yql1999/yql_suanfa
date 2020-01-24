#include<iostream>
#include<algorithm>
using namespace std;
/*̰���㷨-�����ļ����Ŵ洢����*/

bool cmp(int a,int b){
    return a>b;
}

void Sort(int n,int a[]){
	int i,k,mid,b[n];
    sort(a,a+n,cmp);	//�ݼ� 
    mid=n/2;
    b[mid]=a[0];	//�м����� 
    for(i=1,k=1;i<n;i++,k++){   //a��ֵ���м����������μ���
        b[mid-k]=a[i];
        i++;
        if(i!=n)	
			b[mid+k] = a[i];
    }
    for(i=0;i<n;i++)	//b->a
        a[i]=b[i];
}

//��k���ļ��ļ�������Ϊ pi = ak / ��ai 
void  minStore(int n,int a[]){
    int i,j,sum = 0;
    for(i=0;i<n;i++)
        sum+=a[i];
    double ans=0;
    for(i=0;i<(n-1);i++){	//�ŵ���ļ���ʱ�� ��(pi*pj*d(j-i)),0<=i<j<n
        for(j=i+1;j<n;j++){
            ans+=(a[i]*1.0/sum)*(a[j]*1.0/sum)*(j-i);
        }
    }
    cout<<"��С��������ʱ��:"<<ans<<endl;
}

int main(){
    int n,k,mid,i;
    cout<<"�����ļ�����"<<endl;
    cin>>n;
    int a[n];
    cout<<"�����ļ��ļ�������:"<<endl;
    for(i = 0;i<n;i++){
        cin>>a[i];
    }
    Sort(n,a);
    minStore(n,a);
    return 0;
}
