
#include <iostream>
#include <string>

int main(){
	std::string S;
	std::cin >> S;
	for(int i = 0; i < S.length(); i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			std::cout << "Yes\n";
			return 0;
		}
	}
	std::cout << "No\n";
	return 0;
}
