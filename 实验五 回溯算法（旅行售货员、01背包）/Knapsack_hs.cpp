//回溯法求解0-1背包问题 
//子集树
//时间复杂度为O(n*2^n) 
#include <iostream>
#include <algorithm>
using namespace std;

 struct Goods{
 	double v;//物品价值
	double w;//物品重量
	int order;//物品编号
	double perp;//单位价值
	int put=0;//是否装入
 }goods[100]; 
 

int n;//物品数量
double c;//背包容量
double cw = 0;//当前背包重量
double cp = 0;//当前背包中物品总价值
double bestp = 0;//当前最优价值

 
bool comp(Goods a,Goods b){
	return a.perp>b.perp;
}
 
//按单位价值排序（注意是从goods[1]开始的） 
void knapsack(){
    sort(goods+1,goods+n+1,comp);
}
 
 
 double bound(int i);
 
//回溯函数
void backtrack(int i){ 

	//到达叶子节点 
    if(i>n){ 
        bestp=cp;
        return;
    }
    
    //将物品i放入背包,搜索左子树
    if(cw+goods[i].w<=c){	
        cw+=goods[i].w;//更新当前背包的重量
        cp+=goods[i].v;//更新当前背包的总价值
        goods[i].put=1;//放入背包 
        backtrack(i+1);//深度搜索进入下一层
        cw-=goods[i].w;//复原
        cp-=goods[i].v;//复原
    }
	
	//若当前背包的总价值cp＋剩余容量可容纳的最大价值>当前最优价值，则搜索右子树
    if(bound(i+1)>bestp)
        backtrack(i+1);
}
 
//上界函数，剪枝
//判断当前背包的总价值cp＋剩余容量可容纳的最大价值<=当前最优价值
double bound(int i){   
    //剩余背包容量
    double leftw = c-cw;
    double b = cp;//当前背包的总价值
    //以物品单位重量价值递减次序装入物品
    while(i<=n && goods[i].w<=leftw){
        leftw-=goods[i].w;
        b+=goods[i].v;
        i++;
    }
    //装满背包
    if(i<=n)
        b+=goods[i].perp*leftw;
    return b;//返回计算出的上界
 
}
 
 
 
int main(){
    int i;
    cout<<"请分别输入物品的数量和背包的容量：";
    cin>>n>>c;
    cout<<"请依次输入物品的重量:\n";
    for(i=1;i<=n;i++){
        cin>>goods[i].w;
        goods[i].order=i;
    }
 	cout<<"请依次输入物品的价值:\n";
    for(i=1;i<=n;i++){
    	cin>>goods[i].v;
		goods[i].perp=goods[i].v/goods[i].w;
	}
    	
	//先按单位价值排序，再进行回溯 
    knapsack();
    backtrack(1);
 
    cout<<"0-1背包问题的最优解为："<<bestp<<endl;
    cout<<"装入背包的物品有：";
    for(i=1;i<=n;i++){
        if(goods[i].put==1)
            cout<<"物品"<<goods[i].order<<" ";
    }
    cout<<endl; 
    return 0;
}
