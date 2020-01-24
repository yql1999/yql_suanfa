// 装载问题
#include<iostream>
using namespace std;

template<class Type>
class Loading {
	friend Type MaxLoading(Type[], Type, int, int[]);
private:
	void Backtrack(int i);
	int n,	//集装箱数
		*x,	//当前解
		*bestx;	//当前最优解
	Type *w,	//集装箱重量数组
		c,	//第一艘轮船的载重量
		cw,	//当前载重量
		bestw,	//当前最优载重量
		r;	//剩余集装箱重量
};

template<class Type>
void Loading<Type>::Backtrack(int i) {
	if (i > n) {	//到达叶子节点
		if (cw > bestw) {
			for (j = 1; j <= n; j++)
				bestx[j] = x[j];
			bestw = cw;
		}
		return;
	}
	r -= w[i];
	if (cw + w[i] <= c) {	//右子树
		x[i] = 1;
		cw += w[i];
		Backtrack(i + 1);
		cw -= w[i];
	}
	if (cw + r > bestw) {	//左子树
		x[i] = 0;
		Backtrack(i + 1);
	}
	r += w[i];
}

template<class Type>
Type MaxLoading(Type w[],Type c,int n,int bestx[]) {
	Loading<Type>X;
	X.x = new int[n + 1];
	X.w = w;
	X.c = c;
	X.n = n;
	X.bestx = bestx;
	X.bestw = 0;
	X.r = 0;
	for (int i = 1; i <= n; i++) {
		X.r += w[i];
	}
	X.Backtrack(1);
	delete[]X.x;
	return X.bestw;
}

int main(){
		int n = 0;  //集装箱数量；
		int c = 0;  //第一艘船的载重重量
		int bestx[4];  //最优解
		int *w = new int[n + 1];  //集装箱重量数组
		int m = 0;  //最优载重量
		cout << "请输入集装箱数量: ";
		cin >> n;
		cout << endl;
		cout << "请输入第一艘船的载重重量: ";
		cin >> c;
		cout << endl;
		cout << "请输入集装箱的重量数组 ：";
		for (int i = 0; i <= n; i++)
			cin >> w[i];

		m = MaxLoading(w, c, n, bestx);  //求解问题

		cout << "输出最优解如下：" << endl;
		for (int i = 1; i < n; i++)
			cout << bestx[i] << " ";
		cout << "请输出最优载重量： " << endl;
		cout << m;
}

