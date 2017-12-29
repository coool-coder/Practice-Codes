#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;
struct node
{
	char letter;
	string bin;
	int freq;
	struct node* left;
	struct node* right;
};
class huffmann
{
	node ** n;
	int a[256];
	string EncodedString;
	int No_of_leaves;
	public:
		int scann();
		node* HuffmanTree(int k);
		void Encoding(node *root , string s);
		void CreateBinStr(int k);
		void Compress();
		huffmann();
		string Decoding(node * root , int i,int count, node *chandu);
};
huffmann:: huffmann()
{
	No_of_leaves=0;
}
struct Mycomp
{
	bool operator()(node * x, node * y)
	{
		return y->freq < x->freq;
	}
};
int strtoi(string s)
{
	int n = s.length();
	int sum = 0;
	for(int i=0;i<n;i++)
		sum = sum + (s[i]-48)*pow(10,n-i-1);
	return sum;
}
 
int BinToDec(string s)
{
	int sum=0,n=s.length();
	for(int i=0;i<n;i++)
		sum = sum + s[i]*pow(2,n-i-1);
	return sum;
}


int huffmann :: scann()
{
	int i=0;
	for(int j=0;j<256;j++)
		a[j]=0;
	n=new node*[10000];
	char ch;
	char str;
	ifstream infile;
	infile.open("input.txt");
	while(infile.get(ch)){
		n[i] = new node;
		int k = (int)ch;
		a[k]=a[k]+1;
	}
	a[10]=a[10]-1;
	cout<<endl;
	int k=0;
	for(int i=0; i<256;i++){
		if(a[i]!=0){
			n[k]=new node;
			n[k]->freq = a[i];
			No_of_leaves+= a[i];
			str = (char)i;
			n[k]->letter = str;
			k++;
		}
	}
	return k;

}

node * huffmann :: HuffmanTree(int k)
{
	priority_queue< node * , vector<node *> , Mycomp>  q;
	for(int i=0;i<k;i++)
	{
		q.push(n[i]);
	}
	while(q.size()>1)
	{
		node *temp1=new node;
		node * temp2=new node;
		node * temp3=new node;
		temp1=q.top();
		q.pop();
		temp2=q.top();
		q.pop();
		temp3->freq = temp1->freq + temp2->freq;
		temp3->left = temp1;
		temp3->right = temp2;
		q.push(temp3);
	}
	node * root=q.top();

	return root;
}
void huffmann :: Encoding(node *root, string s)
{

	if(root->left==NULL && root->right==NULL){
		root->bin=s;
		return;
	}
	if(root->left!=NULL){
		s=s+'0';
		Encoding(root->left,s);
		s.erase(s.length()-1,1);
	}
	if(root->right!=NULL){
		s=s+'1';
		Encoding(root->right,s);
		s.erase(s.length()-1,1);
	}
}

void huffmann :: CreateBinStr(int k)
{

	ifstream in;
	in.open("input.txt");
	string str = "";
	char ch;
	while(in.get(ch)){
		for(int i=0;i<k;i++){
			if(ch==n[i]->letter)
				str = str + n[i]->bin;
		}	
	}
	cout<<endl;
	int n = str.length()%8;
	if(n==0)
		EncodedString = str;
	else{
		for(int i=0; i < 8-n;i++)
			str+='0';
		EncodedString = str;
	}
	in.close();	
		
}
void huffmann :: Compress()
{
	int temp,k=0,i;
	string s,str;
	ofstream out;
	out.open("compress.txt");
	while(k<EncodedString.length()){
			s="";
			for(i=0;i < 8;i++){
				s = s + EncodedString[k];
				k++;
			}
			temp = BinToDec(s);
			str = (char)temp;
			out << str;
	}	
}


string str="";
string huffmann :: Decoding(node * root , int i,int count, node *temp)
{
	int n = EncodedString.length();
	
	if(i < n and count < No_of_leaves){
		if(root->left==NULL && root->right==NULL){
			count++;
			str+=root->letter;
			cout<<str<<endl;
			root=temp;
		}
		if(EncodedString[i]=='0'){
			Decoding(root->left,i+1,count,temp);
		}
		if(EncodedString[i]=='1'){
			Decoding(root->right,i+1,count,temp);
		}	
	}
	return str;
}	

int main()
{
        int i,k;
	huffmann H;
        k=H.scann();
	ofstream out;
	out.open("output.txt",ios::out);
        struct node * root = H.HuffmanTree(k);
        string s="";
	H.Encoding(root , s);
	H.CreateBinStr(k);
	H.Compress();
	string str=H.Decoding(root , 0 , 0,root);
	out<<str;
	out.close();
        return 0;
}
