#include <iostream>
#include <string>

int main(){
	int i;
	std::string S;
	std::cin >> S;
	for(i = 0; i < S.length(); i++){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}

