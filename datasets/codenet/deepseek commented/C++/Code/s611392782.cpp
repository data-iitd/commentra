// ACM-ICPCアジア地区予選2014 B. Miscalculation

#include <iostream>
#include <string>

using namespace std;

// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
int mul(const string& str, int& idx){
	int res = str[idx]-'0';
	while(idx+1 < str.size() && str[idx+1]=='*'){
		idx += 2;
		res *= str[idx]-'0';
	}
	return res;
}

// This function adds the results of multiple calls to mul by handling '+' operations.
int add(const string& str, int& idx){
	int res = mul(str, idx);
	while(idx+1 < str.size() && str[idx+1] == '+'){
		idx += 2;
		res += mul(str, idx);
	}
	return res;
}

// This function performs the same operations as add but uses a different approach.
int bob(const string& str, int& idx){
	int res = str[idx]-'0';
	while(idx+1 < str.size()){
		if(str[idx+1] == '+') res += str[idx+2]-'0';
		else                  res *= str[idx+2]-'0';
		idx += 2;
	}
	return res;
}

int main(){
	string s; int d;
	while(cin >> s >> d){
		int idx = 0;
		int a = add(s, idx);  // Calculate the result using the add function
		idx = 0;
		int b = bob(s, idx);  // Calculate the result using the bob function
		if(a == d){
			cout << (b == d ? "U" : "M") << endl;  // Output based on both results
		} else {
			cout << (b == d ? "L" : "I") << endl;  // Output based on both results
		}
	}
}
