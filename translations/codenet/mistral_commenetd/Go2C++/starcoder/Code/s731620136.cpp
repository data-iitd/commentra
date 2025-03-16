
#include <bits/stdc++.h>

using namespace std;

// I/O
struct Scanner {
	std::istream& in;
	Scanner(std::istream& in) : in(in) {}
	template<typename T> T next() {
		T x; in >> x; return x;
	}
	template<typename T> vector<T> next_vector(size_t size) {
		vector<T> ret;
		for (size_t i = 0; i < size; i++) {
			ret.push_back(next<T>());
		}
		return ret;
	}
	template<typename T> void next_pair(T& a, T& b) {
		a = next<T>(); b = next<T>();
	}
	template<typename T> void next_triple(T& a, T& b, T& c) {
		a = next<T>(); b = next<T>(); c = next<T>();
	}
	template<typename T> void next_array(T* a, size_t size) {
		for (size_t i = 0; i < size; i++) {
			a[i] = next<T>();
		}
	}
	void next_line() {
		std::string s;
		std::getline(in, s);
	}
	std::istream& operator>>(std::istream& in) {
		return in;
	}
	template<typename T> T next_int() {
		return next<T>();
	}
	template<typename T> vector<T> next_int_vector(size_t size) {
		return next_vector<T>(size);
	}
	template<typename T> void next_int_pair(T& a, T& b) {
		next_pair(a, b);
	}
	template<typename T> void next_int_triple(T& a, T& b, T& c) {
		next_triple(a, b, c);
	}
	template<typename T> void next_int_array(T* a, size_t size) {
		next_array(a, size);
	}
};

//... (rest of the Scanner methods)

int run(std::istream& input, std::ostream& output) {
	Scanner sc(input); // Initialize a new Scanner

	int N = sc.next_int<int>(); // Read the first integer from input

	//... (empty block for N == 0 case)

	if (N < 4) { // Check if N is less than 4
		cout << 0 << endl; // Print 0 if N is less than 4
		return 0; // Return 0
	}

	//... (variable initialization block)

	int nr = 0; // Declare and initialize variables for red, blue, and green balls
	int nb = 0;
	int ng = 0;

	for (char c : S) { // Iterate through each character in the string S
		if (c == 'R') { // If the character is 'R'
			nr++; // Increment the nr counter
		}

		if (c == 'B') { // If the character is 'B'
			nb++; // Increment the nb counter
		}

		if (c == 'G') { // If the character is 'G'
			ng++; // Increment the ng counter
		}
	}

	int same = 0; // Initialize a counter for the number of same-colored groups of three balls

	//... (outer loop block)

	for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
		int i = 0; // Initialize index i to 0
		int j = 1 * a; // Initialize index j to a multiplied by 1
		int k = 2 * a; // Initialize index k to a multiplied by 2

		//... (inner loop block)

		for (k = 2 * a; k < N; k++) { // Iterate through each index k from a*2 to N-1
			//... (check condition block)

			if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) { // Check if the balls at indices i, j, and k have different colors
				same++; // If so, increment the same counter
			}

			//... (update indices block)

			i++; // Increment index i
			j++; // Increment index j
			k++; // Increment index k
		}
	}

	int tot = nr * nb * ng; // Calculate the total number of balls

	//... (comment out or remove the following lines as they are not used in the final solution)

	// int tot = 0; // Initialize a variable for the total number of balls
	// int sum = 0; // Initialize a variable for the number of distinct triples
	// int sum2 = 0; // Initialize a variable for the number of distinct triples with the same middle index

	//... (calculate the final result)

	cout << tot - same << endl; // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

	return 0; // Return 0 to indicate successful execution
}

int main() {
	run(cin, cout); // Run the main function with standard input and output
}

