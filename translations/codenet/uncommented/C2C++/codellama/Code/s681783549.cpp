#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char S[6];
	cin >> S;
	for(int i = 0; S[i] != '\0'; i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}

