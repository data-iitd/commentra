#include <iostream>

using namespace std;

int main(void)
{
	double a;
	double ave = 0;
	int i;
	
	for (i = 0; i < 5; i++){
		cin >> a;
		if (a <= 40){
			ave += 40;
		}
		else {
			ave += a;
		}
	}
	//cout << ave << endl;
	
	ave /= 5.0;
	
	cout << ave << endl;
	
	return (0);
}

