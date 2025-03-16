#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (1 ? 1e9 + 7 : 998244353);



int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	ll a, b, c, d, e, f, g, T;
	String z;
	cin >> z;
	a = z.length();
	for (int i = 0; i < a - 1; i++)
	{
		if (z.charAt(i) == z.charAt(i + 1))
		{
			System.out.println("Bad");
			return 0;
		}
	}
	System.out.println("Good");
}

