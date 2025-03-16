#include <iostream>
using namespace std;

int main()
{
	int a, b, c, i, count;
	cin >> a >> b >> c;
	count = 0;
	for (i = a; i <= b; i++ ){
		if (c % i == 0)
			count++;
	}
	cout << count << endl;
	
	return 0;
}

