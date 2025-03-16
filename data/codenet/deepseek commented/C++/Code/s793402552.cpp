
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

/*
This section of the code reads two integers, a and b, from the standard input.
*/
int main()
{
	int a, b; cin >> a >> b;

	/*
	This section converts the integer b to a string to determine its length.
	*/
	string bstr = to_string(b);

	/*
	This section calculates a new number, num, by multiplying a with 10 raised to the power of the length of b (in string form), and then adding b to it.
	*/
	int num = a * pow(10, bstr.length()) + b;

	int i;
	for (i = 1; i <= 100100; i++)
	{
		if (i * i == num) break;
	}

	/*
	This section checks if the loop has finished due to finding a perfect square root of num. If not, it prints "No". Otherwise, it prints "Yes".
	*/
	if (i > 100100) cout << "No" << endl;
	else cout << "Yes" << endl;
}