
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Declare and initialize two integer variables n and m using cin
	int n, m;
	cin >> n >> m;

	// Calculate the value of x using the given formula
	int x = m*1900 + (n-m)*100;

	// Print the result using cout
	cout << x * pow(2, m) << endl;

	return 0;
}

