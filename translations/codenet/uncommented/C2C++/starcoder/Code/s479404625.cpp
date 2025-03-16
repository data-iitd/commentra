#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char A[20], B[20], C[20];

	cin >> A >> B >> C;

	int la = strlen(A), lb = strlen(B);

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

