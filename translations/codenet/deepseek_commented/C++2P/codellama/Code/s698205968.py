#include <iostream>

using namespace std;

int main() {
	int m, f, r;
	while (cin >> m >> f >> r && (m != -1 || f != -1 || r != -1)): # 1. The program reads three integers: m, f, and r from the standard input.
		if (m == -1 || f == -1): # 2. It then checks if any of these integers are -1, in which case it outputs "F".
			print("F")
		elif (m + f >= 80): # 3. If not, it checks if the sum of m and f is 80 or more, in which case it outputs "A".
			print("A")
		elif (m + f >= 65): # 4. If not, it checks if the sum of m and f is 65 or more, in which case it outputs "B".
			print("B")
		elif (m + f >= 50 or r >= 50): # 5. If not, it checks if the sum of m and f is 50 or more, or if r is 50 or more, in which case it outputs "C".
			print("C")
		elif (m + f >= 30): # 6. If not, it checks if the sum of m and f is 30 or more, in which case it outputs "D".
			print("D")
		else: # 7. If none of the above conditions are met, it outputs "F".
			print("F")
		print() # 8. The program continues to read and process new sets of m, f, and r values until all three are -1.

	return 0
}

