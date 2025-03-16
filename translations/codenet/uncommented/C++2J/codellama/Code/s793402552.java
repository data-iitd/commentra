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


int main()
{
	int a, b; cin >> a >> b;
	String bstr = Integer.toString(b);
	int num = a * (int)Math.pow(10, bstr.length()) + b;

	int i;
	for (i = 1; i <= 100100; i++)
	{
		if (i * i == num) break;
	}

	if (i > 100100) System.out.println("No");
	else System.out.println("Yes");
}

