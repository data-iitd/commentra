#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// Define a large constant for infinity
const int inf = 1e14;

// ---------------------------------------------------------
int main() {
	// Initialize a new scanner for input
	auto next = newScanner();

	// Read the number of elements and the value of x
	int n = next->Int();
	int x = next->Int();

	// Create a vector to hold the input integers
	vector<int> a(n);

	// Read n integers into the vector a
	for (int i = 0; i < n; i++) {
		a[i] = next->Int();
	}

	// Create a copy of the vector a for manipulation
	vector<int> v(n);
	copy(v.begin(), v.end(), a.begin());

	// Initialize the answer to infinity
	int ans = inf;

	// Iterate over each possible k value
	for (int k = 0; k < n; k++) {
		int kans = 0; // Initialize the current answer for this k

		// Calculate the minimum values for the current k
		for (int i = 0; i < n; i++) {
			if (i - k < 0) {
				// If i-k is out of bounds, use the wrapped index
				v[i] = min(v[i], a[n + i - k]);
			} else {
				// Otherwise, use the normal index
				v[i] = min(v[i], a[i - k]);
			}
			// Accumulate the current answer
			kans += v[i];
		}

		// Update the overall answer with the minimum found so far
		ans = min(ans, kans + k * x);
	}

	// Print the final answer
	printf("%d\n", ans);
}

// ---------------------------------------------------------

// Pair represents a pair of integers
struct Pair {
	int a, b;
};

// Pairs is a vector of Pair structs that can be sorted
typedef vector<Pair> Pairs;

// Implement the sort.Interface for Pairs
int Len(const Pairs &p) {
	return p.size();
}
void Swap(Pairs &p, int i, int j) {
	Pair t = p[i];
	p[i] = p[j];
	p[j] = t;
}
bool Less(const Pairs &p, int i, int j) {
	// Define sorting criteria based on the first and second elements of the pairs
	if (p[i].a < p[j].a) {
		return true;
	} else if (p[i].a == p[j].a) {
		return p[i].b < p[j].b;
	}
	return false;
}

// -------------------------------

// in checks if c is within the range [a, z)
bool in(int c, int a, int z) {
	return c >= a && c < z;
}

// btoi converts a boolean to an integer (1 for true, 0 for false)
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}

// itob converts an integer to a boolean (false for 0, true for non-zero)
bool itob(int a) {
	if (a == 0) {
		return false;
	}
	return true;
}

// max returns the maximum value from a list of integers
int max(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// min returns the minimum value from a list of integers
int min(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// minmax returns the minimum and maximum of two integers
pair<int, int> minmax(int a, int b) {
	if (a > b) {
		return make_pair(b, a);
	}
	return make_pair(a, b);
}

// abs returns the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// sum returns the sum of a list of integers
int sum(int a, int b) {
	return a + b;
}

// ---------- buffered scanner -----------------------------------------

// scanner is a custom buffered scanner for reading input
struct scanner {
	FILE *r; // Buffered reader
	char *buf;
	int p;
	int n;
};

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	scanner *s = new scanner;
	s->r = fopen(NULL, "r");
	s->p = 0;
	s->n = 0;
	s->buf = NULL;
	return s;
}

// next reads the next token from the input
char *next(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	char *start = s->buf + s->p;
	while (s->p < s->n && s->buf[s->p]!='') {
		s->p++;
	}
	int len = s->p - s->n;
	char *result = new char[len + 1];
	memcpy(result, start, len);
	result[len] = 0;
	s->p++; // Move past the space
	return result;
}

// Line reads the remainder of the current line
char *Line(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	char *start = s->buf + s->p;
	s->p = s->n; // Move to the end of the buffer
	return start;
}

// Int reads the next integer from the input
int Int(scanner *s) {
	return atoi(next(s));
}

// Int64 reads the next int64 from the input
int64_t Int64(scanner *s) {
	return atoll(next(s));
}

// pre fills the buffer if the current position is at the end
void pre(scanner *s) {
	if (s->p >= s->n) {
		s->readLine(); // Read a new line into the buffer
		s->p = 0;     // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input into the buffer
void readLine(scanner *s) {
	if (s->buf) {
		delete[] s->buf;
	}
	s->n = 0;
	s->p = 0;
	int c;
	while ((c = fgetc(s->r))!= EOF) {
		if (s->n == s->p) {
			s->p = 0;
			s->n = s->n * 2 + 1000;
			char *t = new char[s->n];
			memcpy(t, s->buf, s->n);
			delete[] s->buf;
			s->buf = t;
		}
		s->buf[s->n] = c;
		s->n++;
		if (c == '\n') {
			break;
		}
	}
	s->buf[s->n] = 0;
}

