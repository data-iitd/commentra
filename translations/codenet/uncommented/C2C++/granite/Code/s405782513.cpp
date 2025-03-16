
#include <iostream>

using namespace std;

int main(void)
{
	int c[3];
	
	while (cin >> c[0] >> c[1] >> c[2]){
		char card[10] = {0};
		int i;
		int count = 0;
		int sum = c[0] + c[1];
		
		for (i = 0; i < 3; i++){
			card[c[i] - 1] = 1;
		}
		for (i = 0; i < 10; i++){
			if (card[i] == 0 && sum + i + 1 <= 20){
				count++;
			}
		}
		if (count >= 4){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}

