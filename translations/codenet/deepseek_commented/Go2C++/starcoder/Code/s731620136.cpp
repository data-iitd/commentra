
#include <bits/stdc++.h>

using namespace std;

// I/O
// The Scanner struct is defined to read input efficiently.
struct Scanner {
	std::istream& in;
	std::string buf;
	int curChar;
	Scanner(std::istream& in) : in(in), curChar(-1) {}
	void getChar() {
		if (curChar == -1) {
			curChar = in.get();
		}
	}
	bool hasNext() {
		while (curChar >= 0) {
			if (curChar == '\n') {
				return true;
			}
			curChar = in.get();
		}
		return false;
	}
	void readChar() {
		getChar();
		while (curChar >= 0 && curChar <= 32) {
			curChar = in.get();
		}
	}
	std::string next() {
		std::string str;
		readChar();
		while (curChar >= 0 && curChar!= '\n') {
			str.push_back(curChar);
			curChar = in.get();
		}
		return str;
	}
	int nextInt() {
		int x;
		std::istringstream iss(next());
		iss >> x;
		return x;
	}
	float nextFloat() {
		float x;
		std::istringstream iss(next());
		iss >> x;
		return x;
	}
	std::string nextLine() {
		std::string str;
		std::getline(in, str);
		return str;
	}
};

// The run function reads the input, processes it, and prints the result.
int run(std::istream& in, std::ostream& out) {
	Scanner sc(in);
	// Reads the number of elements N and the string S.
	int N = sc.nextInt();
	std::string S = sc.next();

	if (N == 0) {
	}

	if (N < 4) {
		out << 0 << endl;
		return 0;
	}

	// Counts the number of 'R', 'B', and 'G' characters in S.
	int nr = 0, nb = 0, ng = 0;
	for (char c : S) {
		if (c == 'R') {
			nr++;
		}

		if (c == 'B') {
			nb++;
		}

		if (c == 'G') {
			ng++;
		}
	}

	// Calculates the number of triplets where the characters are all different.
	int same = 0;
	for (int a = 1; a < N; a++) {
		int i = 0;
		int j = 1 * a;
		int k = 2 * a;
		if (k >= N) {
			break;
		}
		for (; k < N; i++, j++, k++) {
			if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
				same++;
			}
		}
	}

	// Calculates the total number of possible triplets.
	int tot = nr * nb * ng;

	// Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
	out << tot - same << endl;

	return 0;
}

// The main function calls the run function with standard input and output, and exits with the return value of run.
int main() {
	return run(std::cin, std::cout);
}

