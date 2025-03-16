
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B, C;

	cin >> A >> B >> C;

	int la = A.length(), lb = B.length();

	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}

