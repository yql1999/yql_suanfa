// װ������
#include<iostream>
using namespace std;

template<class Type>
class Loading {
	friend Type MaxLoading(Type[], Type, int, int[]);
private:
	void Backtrack(int i);
	int n,	//��װ����
		*x,	//��ǰ��
		*bestx;	//��ǰ���Ž�
	Type *w,	//��װ����������
		c,	//��һ���ִ���������
		cw,	//��ǰ������
		bestw,	//��ǰ����������
		r;	//ʣ�༯װ������
};

template<class Type>
void Loading<Type>::Backtrack(int i) {
	if (i > n) {	//����Ҷ�ӽڵ�
		if (cw > bestw) {
			for (j = 1; j <= n; j++)
				bestx[j] = x[j];
			bestw = cw;
		}
		return;
	}
	r -= w[i];
	if (cw + w[i] <= c) {	//������
		x[i] = 1;
		cw += w[i];
		Backtrack(i + 1);
		cw -= w[i];
	}
	if (cw + r > bestw) {	//������
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
		int n = 0;  //��װ��������
		int c = 0;  //��һ�Ҵ�����������
		int bestx[4];  //���Ž�
		int *w = new int[n + 1];  //��װ����������
		int m = 0;  //����������
		cout << "�����뼯װ������: ";
		cin >> n;
		cout << endl;
		cout << "�������һ�Ҵ�����������: ";
		cin >> c;
		cout << endl;
		cout << "�����뼯װ����������� ��";
		for (int i = 0; i <= n; i++)
			cin >> w[i];

		m = MaxLoading(w, c, n, bestx);  //�������

		cout << "������Ž����£�" << endl;
		for (int i = 1; i < n; i++)
			cout << bestx[i] << " ";
		cout << "����������������� " << endl;
		cout << m;
}

