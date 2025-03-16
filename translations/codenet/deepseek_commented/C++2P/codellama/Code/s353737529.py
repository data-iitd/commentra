#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------ここから-----------

/*
1. The code includes several standard libraries such as <iostream>, <vector>, <string>, <queue>, <algorithm>, <utility>, <set>, <map>, <cmath>, <tuple>, and <iomanip>. These libraries provide various functionalities for input/output operations, data structures, mathematical operations, and more.
*/

int main(void){
	int n;

	cin >> n;

	string s = "";

/*
2. If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
*/
	if(n == 0){
		cout << '0' << endl;
		return 0;
	}
	

	int i = 1;
	while(n != 0){
		if(n % 2 == 0){
			s += '0';
		} else {
			s += '1';
		}

		n -= abs(n % 2);

		n /= -2;
	}

	reverse(s.begin(), s.end());

	cout << s << endl;

/*
3. Inside the `main` function, a string `s` is initialized as an empty string. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the string `s`; if `n` is odd, it appends '1' to the string `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.
*/

/*
4. After the loop, the string `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
*/

}

