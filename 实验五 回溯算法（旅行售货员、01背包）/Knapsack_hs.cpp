//���ݷ����0-1�������� 
//�Ӽ���
//ʱ�临�Ӷ�ΪO(n*2^n) 
#include <iostream>
#include <algorithm>
using namespace std;

 struct Goods{
 	double v;//��Ʒ��ֵ
	double w;//��Ʒ����
	int order;//��Ʒ���
	double perp;//��λ��ֵ
	int put=0;//�Ƿ�װ��
 }goods[100]; 
 

int n;//��Ʒ����
double c;//��������
double cw = 0;//��ǰ��������
double cp = 0;//��ǰ��������Ʒ�ܼ�ֵ
double bestp = 0;//��ǰ���ż�ֵ

 
bool comp(Goods a,Goods b){
	return a.perp>b.perp;
}
 
//����λ��ֵ����ע���Ǵ�goods[1]��ʼ�ģ� 
void knapsack(){
    sort(goods+1,goods+n+1,comp);
}
 
 
 double bound(int i);
 
//���ݺ���
void backtrack(int i){ 

	//����Ҷ�ӽڵ� 
    if(i>n){ 
        bestp=cp;
        return;
    }
    
    //����Ʒi���뱳��,����������
    if(cw+goods[i].w<=c){	
        cw+=goods[i].w;//���µ�ǰ����������
        cp+=goods[i].v;//���µ�ǰ�������ܼ�ֵ
        goods[i].put=1;//���뱳�� 
        backtrack(i+1);//�������������һ��
        cw-=goods[i].w;//��ԭ
        cp-=goods[i].v;//��ԭ
    }
	
	//����ǰ�������ܼ�ֵcp��ʣ�����������ɵ�����ֵ>��ǰ���ż�ֵ��������������
    if(bound(i+1)>bestp)
        backtrack(i+1);
}
 
//�Ͻ纯������֦
//�жϵ�ǰ�������ܼ�ֵcp��ʣ�����������ɵ�����ֵ<=��ǰ���ż�ֵ
double bound(int i){   
    //ʣ�౳������
    double leftw = c-cw;
    double b = cp;//��ǰ�������ܼ�ֵ
    //����Ʒ��λ������ֵ�ݼ�����װ����Ʒ
    while(i<=n && goods[i].w<=leftw){
        leftw-=goods[i].w;
        b+=goods[i].v;
        i++;
    }
    //װ������
    if(i<=n)
        b+=goods[i].perp*leftw;
    return b;//���ؼ�������Ͻ�
 
}
 
 
 
int main(){
    int i;
    cout<<"��ֱ�������Ʒ�������ͱ�����������";
    cin>>n>>c;
    cout<<"������������Ʒ������:\n";
    for(i=1;i<=n;i++){
        cin>>goods[i].w;
        goods[i].order=i;
    }
 	cout<<"������������Ʒ�ļ�ֵ:\n";
    for(i=1;i<=n;i++){
    	cin>>goods[i].v;
		goods[i].perp=goods[i].v/goods[i].w;
	}
    	
	//�Ȱ���λ��ֵ�����ٽ��л��� 
    knapsack();
    backtrack(1);
 
    cout<<"0-1������������Ž�Ϊ��"<<bestp<<endl;
    cout<<"װ�뱳������Ʒ�У�";
    for(i=1;i<=n;i++){
        if(goods[i].put==1)
            cout<<"��Ʒ"<<goods[i].order<<" ";
    }
    cout<<endl; 
    return 0;
}
