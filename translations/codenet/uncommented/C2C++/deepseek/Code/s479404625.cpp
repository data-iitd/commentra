#include <iostream>
#include <string>

int main()
{
	std::string A, B, C;

	std::cin >> A >> B >> C;

	int la = A.length(), lb = B.length();

	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		std::cout << "YES\n";
	}
	else
	{
		std::cout << "NO\n";
	}

	return 0;
}
