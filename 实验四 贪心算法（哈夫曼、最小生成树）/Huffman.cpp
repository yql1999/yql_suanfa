#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
/*����������*/
 
 
//����һ���ڵ�ṹ�� 
struct Node{
    double weight;	//Ȩֵ 
    string ch;		//�ַ� 
    string code;	//���� 
    int lchild;
	int rchild;
	int parent;		//���ҡ����׽ڵ� 
};


//��Ȩֵ��С�������ڵ�a��b���ϲ��ɽڵ�n 
void Select(Node huffTree[], int *a, int *b, int n){  
    int i;
    double weight = 0; 
	//��Ҷ�ӽڵ�����С��
    for(i=0;i<n;i++){
        if(huffTree[i].parent!=-1)
            continue;
        //�ڵ㻹û�б�ѡ��
        else{
            if(weight==0){
                weight=huffTree[i].weight;
                *a=i;
            }
			else{
                if(huffTree[i].weight<weight){
                    weight=huffTree[i].weight;
                    *a=i;
                }
            }
        }
    }
    //�ҵڶ�С�Ľڵ� 
    weight=0;
    for(i=0;i<n;i++){
        if(huffTree[i].parent!=-1 || (i==*a))	//�ų���ѡ������
            continue;
        else{
            if(weight==0){
                weight=huffTree[i].weight;
                *b=i;
            }
			else{
                if(huffTree[i].weight<weight){
                    weight=huffTree[i].weight;
                    *b=i;
                }
            }
        }
    }
	//С���������
    int temp;
    if(huffTree[*a].lchild<huffTree[*b].lchild){  
        temp=*a;
        *a=*b;
        *b=temp;
    }
}

//����Huffman�� 
void Huff_Tree(Node huffTree[], int w[], char ch[], int n){
	int i,k; 
	//��ʼ�� 
    for(i=0;i<2*n-1;i++){
        huffTree[i].parent=-1;    
        huffTree[i].lchild=-1;    
        huffTree[i].rchild=-1;  
        huffTree[i].code="";
    }
    //Ҷ�ӽڵ��ʼ�� 
    for(i=0;i<n;i++){
        huffTree[i].weight=w[i];  
        huffTree[i].ch=ch[i];     
    }
    for(k=n;k<2*n-1;k++){
        int i1=0;
        int i2=0;
        //��i1��i2�ڵ�ϳɽڵ�k��ͬʱ���ºϳɵĽڵ�k���뵽δȡ��Ҷ�ӽڵ��н��бȽ� 
        Select(huffTree, &i1, &i2, k);
        huffTree[i1].parent=k;   
        huffTree[i2].parent=k;
        huffTree[k].weight=huffTree[i1].weight+huffTree[i2].weight;
        huffTree[k].lchild=i1;
        huffTree[k].rchild=i2; 
    }
}
 
 
//���� 
void Huff_Code(Node huffTree[], int n){
    int i,j;
    string s = "";
    //ͨ���������丸�׽ڵ㣬���˶�n��Ҷ�ӽڵ���б��� 
    for(i=0;i<n;i++){
    	s="";
    	j=i;
    	while(huffTree[j].parent!=-1){
    		int k=huffTree[j].parent;
    		//��Ϊ���� 
    		if(j==huffTree[k].lchild)
    			s+="0";
    		else
    			s+="1";
    		j=huffTree[j].parent; 
		}
		cout<<"�ַ� "<<huffTree[i].ch<<" �ı��룺";
		//��Ϊ�Ǵ�Ҷ�ӵ����ڵ�����룬����Ҫ���󵽵ı��뵹ת 
		reverse(s.begin(),s.end());
        huffTree[i].code=s;
        cout<<s<<endl;
	}
}


//���� 
string Huff_Decode(Node huffTree[], int n,string s){
    cout<< "�����Ϊ��";
    int i,j,len=s.size(); 
    string temp="",str="";
    //�������Ҫ������ַ�����ÿһ���������ƥ�� 
    for(i=0;i<len;i++){
    	temp+=s[i];
    	for(j=0;j<n;j++){
    		//��ƥ�䵽�˱��� 
    		if(temp==huffTree[j].code){
    			str+=huffTree[j].ch;
    			temp="";	//����
				break; 
			}
			//��ȫ��������û�� 
			else if(i==(len-1) && j==(n-1) && temp!=""){
				str="�������";
			}
    		
		}
	}
    return str;
}


int main(int argc, char** argv) {
	int n=0,i,j;
	cout<<" ������Ҫ���б�����ַ�����"<<endl;
	char ch,c[256];
	int w[256],num[256]={0};
	//����ÿ���ַ���Ƶ�� 
	while((ch=getchar())!='\n')
  		num[ch]++;
 	for(i=0;i<256;i++){
 		if(num[i]){ 
		 	c[n]=i;
   			w[n]=num[i];
   			n++;
  		}
	}
	for(i=0;i<n;i++)
		cout<<c[i]<<":"<<w[i]<<endl;
	//����
	Node huffTree[2*n];	//Ҷ�ӽڵ���n��ʱ����ȫ�������Ľڵ㹲��2*n-1�� 
	Huff_Tree(huffTree,w,c,n);
	Huff_Code(huffTree,n);
	//����
	string s;
	cout<<" ��������룺";
	cin>>s;
	cout<<Huff_Decode(huffTree,n,s)<<endl; 
	return 0;
}
