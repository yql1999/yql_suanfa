#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
/*哈夫曼编码*/
 
 
//设置一个节点结构体 
struct Node{
    double weight;	//权值 
    string ch;		//字符 
    string code;	//编码 
    int lchild;
	int rchild;
	int parent;		//左、右、父亲节点 
};


//找权值最小的两个节点a、b，合并成节点n 
void Select(Node huffTree[], int *a, int *b, int n){  
    int i;
    double weight = 0; 
	//找叶子节点中最小的
    for(i=0;i<n;i++){
        if(huffTree[i].parent!=-1)
            continue;
        //节点还没有被选过
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
    //找第二小的节点 
    weight=0;
    for(i=0;i<n;i++){
        if(huffTree[i].parent!=-1 || (i==*a))	//排除已选过的数
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
	//小的数放左边
    int temp;
    if(huffTree[*a].lchild<huffTree[*b].lchild){  
        temp=*a;
        *a=*b;
        *b=temp;
    }
}

//构造Huffman树 
void Huff_Tree(Node huffTree[], int w[], char ch[], int n){
	int i,k; 
	//初始化 
    for(i=0;i<2*n-1;i++){
        huffTree[i].parent=-1;    
        huffTree[i].lchild=-1;    
        huffTree[i].rchild=-1;  
        huffTree[i].code="";
    }
    //叶子节点初始化 
    for(i=0;i<n;i++){
        huffTree[i].weight=w[i];  
        huffTree[i].ch=ch[i];     
    }
    for(k=n;k<2*n-1;k++){
        int i1=0;
        int i2=0;
        //将i1，i2节点合成节点k，同时把新合成的节点k加入到未取的叶子节点中进行比较 
        Select(huffTree, &i1, &i2, k);
        huffTree[i1].parent=k;   
        huffTree[i2].parent=k;
        huffTree[k].weight=huffTree[i1].weight+huffTree[i2].weight;
        huffTree[k].lchild=i1;
        huffTree[k].rchild=i2; 
    }
}
 
 
//编码 
void Huff_Code(Node huffTree[], int n){
    int i,j;
    string s = "";
    //通过不断找其父亲节点，依此对n个叶子节点进行编码 
    for(i=0;i<n;i++){
    	s="";
    	j=i;
    	while(huffTree[j].parent!=-1){
    		int k=huffTree[j].parent;
    		//若为左孩子 
    		if(j==huffTree[k].lchild)
    			s+="0";
    		else
    			s+="1";
    		j=huffTree[j].parent; 
		}
		cout<<"字符 "<<huffTree[i].ch<<" 的编码：";
		//因为是从叶子到根节点求编码，所以要将求到的编码倒转 
		reverse(s.begin(),s.end());
        huffTree[i].code=s;
        cout<<s<<endl;
	}
}


//解码 
string Huff_Decode(Node huffTree[], int n,string s){
    cout<< "解码后为：";
    int i,j,len=s.size(); 
    string temp="",str="";
    //逐个增加要解码的字符，与每一个编码进行匹配 
    for(i=0;i<len;i++){
    	temp+=s[i];
    	for(j=0;j<n;j++){
    		//若匹配到了编码 
    		if(temp==huffTree[j].code){
    			str+=huffTree[j].ch;
    			temp="";	//重置
				break; 
			}
			//若全部遍历后都没有 
			else if(i==(len-1) && j==(n-1) && temp!=""){
				str="解码错误！";
			}
    		
		}
	}
    return str;
}


int main(int argc, char** argv) {
	int n=0,i,j;
	cout<<" 请输入要进行编码的字符串："<<endl;
	char ch,c[256];
	int w[256],num[256]={0};
	//计算每个字符的频率 
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
	//编码
	Node huffTree[2*n];	//叶子节点有n个时，完全二叉树的节点共有2*n-1个 
	Huff_Tree(huffTree,w,c,n);
	Huff_Code(huffTree,n);
	//解码
	string s;
	cout<<" 请输入编码：";
	cin>>s;
	cout<<Huff_Decode(huffTree,n,s)<<endl; 
	return 0;
}
