
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// Create a new Scanner to read input from standard input
	string line;
	getline(cin, line);
	stringstream ss(line);
	
	// Set the split function to scan words
	ss.imbue(locale(ss.getloc(), new word_separator()));
	
	// Initialize a 3x3 integer array and a 3-element integer array
	int c[3][3];
	int a[3], b[3];
	
	// Read values into the 3x3 array `c`
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ss >> c[i][j];
		}
	}

	// Calculate the values of `b` based on the initial assumption that `a[0]` is zero
	b[0] = c[0][0] - a[0];
	b[1] = c[0][1] - a[0];
	b[2] = c[0][2] - a[0];
	
	// Calculate the values of `a` based on the values in `c`
	a[1] = c[1][0] - c[0][0];
	a[2] = c[2][0] - c[0][0];
	
	// Check if the calculated values of `a` and `c` are consistent with the given relationships
	if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
		a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}

class word_separator : public std::ctype<char> {
public:
	word_separator() : std::ctype<char>(get_table()) {}

	static std::ctype_base::mask const* get_table() {
		static std::vector<std::ctype_base::mask>
			r(table_size, std::ctype_base::mask());
		std::fill(&r[0], &r[0] + table_size, std::ctype_base::mask());
		r[' '] = std::ctype_base::space;
		r['\t'] = std::ctype_base::space;
		r['\n'] = std::ctype_base::space;
		return &r[0];
	}
};

