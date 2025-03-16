#include <iostream>

using namespace std;

int main() {
	int m, f, r;
	while (cin >> m >> f >> r && (m != -1 || f != -1 || r != -1)) { // 1. The program reads three integers: m, f, and r from the standard input.
		if (m == -1 || f == -1) cout << "F"; // 2. It then checks if any of these integers are -1, in which case it outputs "F".
		else if (m + f >= 80) cout << "A"; // 3. If not, it checks if the sum of m and f is 80 or more, in which case it outputs "A".
		else if (m + f >= 65) cout << "B"; // 4. If not, it checks if the sum of m and f is 65 or more, in which case it outputs "B".
		else if (m + f >= 50 || r >= 50) cout << "C"; // 5. If not, it checks if the sum of m and f is 50 or more, or if r is 50 or more, in which case it outputs "C".
		else if (m + f >= 30) cout << "D"; // 6. If not, it checks if the sum of m and f is 30 or more, in which case it outputs "D".
		else cout << "F"; // 7. If none of the above conditions are met, it outputs "F".
		cout << endl; // 8. The program continues to read and process new sets of m, f, and r values until all three are -1.
	}

	return 0;
}
