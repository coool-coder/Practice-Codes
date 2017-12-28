//--------------------Contact Appplication-----------------------//
// Input
/*4
add hack
add hackerrank
find hac
find hak*/

// Output
//2
//0
//---------------------------------------------------------------//

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;

struct trieNode{
	struct trieNode* children[26];
	bool isLeaf;
	int noOfWordsPossible;
};

struct trieNode *getNode(){
	struct trieNode *temp = new trieNode;
	temp->isLeaf = false;
	temp->noOfWordsPossible = 0;
	for(int i = 0; i < 26; i++){
		temp->children[i] = NULL;
	}
	return temp;
}

void insert(struct trieNode* root, string str){
	struct trieNode *troot = root;
	for(int i = 0; i < str.length(); i++){
		int ind = str[i] - 'a';
		if(!troot->children[ind]){
			troot->children[ind] = getNode();
		}
		troot = troot->children[ind];
		troot->noOfWordsPossible += 1; 
	}
	troot->isLeaf = true;
}

int getNonNullPoints(struct trieNode* root){
	int count = 0;
	for(int j = 0; j < 26; j++){
		if(root->children[j])
			count++;
	}
	return count;
}

// int wordCount(struct trieNode *root)
// {
//     int result = 0; 
//     if (root -> isLeaf)
//         result++;
     
//     for (int i = 0; i < 26; i++)    
//       if (root -> children[i])
//          result += wordCount(root -> children[i]);
    
//     return result;   
// }

int findCount(struct trieNode* root, string str){
	struct trieNode* troot = root;
	int ind = str[0]-'a';
	int count = 0;
	int i = 0;
	while(i <= str.length()-1) {
		if(!troot->children[ind]){	
			break;
		}
		troot = troot->children[ind];
		ind = str[++i]-'a';
		
	}

	if(i != str.length()){
		// no string is in current contact list with prefix "str"
		return 0;
	}
	else{
		// counting non null points in current node
		return troot->noOfWordsPossible;
		// return wordCount(troot);
	}
}

int main(){
	int n;
	cin >> n;
	getchar();
	string str;
	struct trieNode *root = getNode();
	for(int i = 0; i < n; i++){
		getline(cin, str);
		
		stringstream ss(str);
		string token;
		vector<string> vStrings;
		while(getline(ss, token, ' ')) {
			vStrings.push_back(token);
		}

		if(vStrings[0].compare("add") == 0){
			insert(root, vStrings[1]);
		}
		else{
			 cout << findCount(root, vStrings[1]) << endl; 
		}
	}	
	return 0;
}
