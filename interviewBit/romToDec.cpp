#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	//creating map to store the corresponding values of Roman charachter
	map<char, int> m;
	m['M'] = 1000;
	m['D'] = 500;
	m['C'] = 100;
	m['L'] = 50;
	m['X'] = 10;
	m['V'] = 5;
	m['I'] = 1;

	string str;
	cin >> str;
	int len = str.length();
	
	//initialising high priority roman charachter to the last character of the string
	char highPriority = str[len-1];
	int dec = m[highPriority];
	 
	for(int i = len - 2; i >= 0; i--){
		if(m[str[i]] >= m[highPriority]){
			dec += m[str[i]];
			highPriority = str[i];
		}else{
			dec -= m[str[i]];
		}
	}
	cout << dec << endl;

	return 0;
}