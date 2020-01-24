#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
 using namespace std;
 
string product(string a,string b){  //�˻�
    int len1 = a.length();
    int len2 = b.length();
    string ans;
    int num = 0;
    int carry = 0;
    if(len1 == 1){
        for(int i=len2-1;i>=0;--i){
            num = carry + (a[0]-'0')*(b[i]-'0');
            carry = num/10;
            num %= 10;
            ans += (char)(num+'0');
        }
        if(carry) ans += (char)(carry+'0');
    }
    else if(len2 == 1){
        for(int i=len1-1;i>=0;--i){
            num = carry + (b[0]-'0')*(a[i]-'0');
            carry = num/10;
            num %= 10;
            ans += (char)(num+'0');
        }
        if(carry) ans += (char)(carry+'0');        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
 
string add(string a,string b,string c,string d){ //���
    string ans;
    int len1 = a.length()-1;
    int len2 = b.length()-1;
    int len3 = c.length()-1;
    int len4 = d.length()-1;
    int num = 0;
    int carry = 0;
    while(len1 >= 0 || len2 >= 0 || len3 >= 0 || len4 >= 0){
        num = carry;
        if(len1 >= 0) num += a[len1]-'0';
        if(len2 >= 0) num += b[len2]-'0';
        if(len3 >= 0) num += c[len3]-'0';
        if(len4 >= 0) num += d[len4]-'0';
        carry = num/10;
        num %= 10;
        ans += (char)(num+'0');
        --len1;--len2;--len3;--len4;
    }
    while(carry){
        ans += (char)(carry%10 + '0');
        carry /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
 
 //���η�������˷� 
string LargeMultiply(string a,string b,int n1,int n2){
    if(n1 == 1 || n2 == 1){
        return product(a,b);
    }
    int len1 = n1/2;
    int len2 = n2/2;
    string A,B,C,D;	//��a��ΪA��B�����֣���b��ΪC��D������ 
    A.append(a,0,len1);
    B.append(a,len1,n1-len1);
    C.append(b,0,len2);
    D.append(b,len2,n2-len2);
    // cout << A << " " << B << " " << C << " " << D << endl;getchar();
    string num1 = LargeMultiply(A,C,len1,len2);
    string num2 = LargeMultiply(A,D,len1,n2-len2);
    string num3 = LargeMultiply(B,C,n1-len1,len2);
    string num4 = LargeMultiply(B,D,n1-len1,n2-len2);
    num1.append(n1-len1+n2-len2,'0');
    num2.append(n1-len1,'0');
    num3.append(n2-len2,'0');
    // cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;getchar();
    return add(num1,num2,num3,num4);
}
 
int main(){
    string a,b;
    cout<<" ����������������"; 
    while(cin >> a >> b){
        int n1 = a.length();
        int n2 = b.length();
        cout << a<<" * "<<b<<" = "<<LargeMultiply(a,b,n1,n2) << endl;
        // cout << product(a,b) << endl;
        // cout << add(a,b,a,b) << endl;
		cout<<" ����������������"; 
    }
    return 0;
}
