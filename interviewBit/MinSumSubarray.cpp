// given an array of n +ve integers and a positive integer s(say). 
//Find the min length of a contiguous subarray for which sum>=s else return 0;

#include <iostream>
#include <cstdio>

using namespace std;

struct node{
	int st;
	int end;
	float s; //sum
};
	
//void checkSum()

int main(){
	int s, n;
	cin >> n;
	float a[n];
	node** arr;
	arr=new node*[10000]; 
	
	int ptr1=0, ptr2=1;

	for(int i=0; i<n; i++){
		cin>>a[i];
	} 

	cin>>s;
	float sum=a[ptr1];
	int len=1, minLen=0, itr=0, flag, temp;
	while(ptr1<n && ptr2<n){
		flag=0;
		while(sum>=s){
			if (flag==0){
				arr[itr]=new node;
			}
			arr[itr]->st = ptr1;
			arr[itr]->end = ptr2;
			arr[itr]->s = sum;
			ptr1+=1;
			//itr+=1;
			flag=1;
			sum=sum-a[ptr1-1];
		}
		if (flag==1){
			itr+=1;
		}

		//cout << "a[ptr2] = " << a[ptr2] << "sum = "<< sum <<endl ;
 		sum = sum + a[ptr2];
		ptr2+=1;
	}

	int min_len=(arr[0]->end - arr[0]->st);
	int ind;

	for (int i=0; i<itr; i++){
		if ((arr[i]->end-arr[i]->st) < min_len){
			min_len = (arr[i]->end-arr[i]->st);
			ind = i;
		}
		else if ((arr[i]->end-arr[i]->st)== min_len){
			if (arr[i]->s > arr[ind]->s){
				min_len = (arr[ind]->end-arr[ind]->st);
			}
			else{
				min_len = (arr[i]->end-arr[i]->st);
				ind = i;
			}
		}
	}
	if (itr>0)
		cout << min_len << endl;
	else
		cout <<  0 << endl;
	return 0;
}