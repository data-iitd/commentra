#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int i;
	char S[6];
	cin >> S;
	for(i = 0; S[i]!= '\0'; i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}

