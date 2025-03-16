#include <iostream>
using namespace std;

int main() {
	int N, D; /* N, Dは1以上20以下の整数 */
	int ans, rem;

	// Read two integers from standard input
	cin >> N >> D;

	// Calculate the number of groups that can be formed
	ans = N / (D*2+1);
	rem = N % (D*2+1);

	// If there are remaining items, increment the number of groups
	if(rem!= 0){
		ans = ans + 1;
	}

	// Print the result to standard output
	cout << ans << endl;

	return 0;
}
