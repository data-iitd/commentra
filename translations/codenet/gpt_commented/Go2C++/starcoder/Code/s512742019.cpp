#include <bits/stdc++.h>

using namespace std;

// I/O
// Template for Reader class
class Reader {
public:
	Reader() : buf(NULL), bufEnd(NULL), ptr(NULL) {}
	Reader(const char* _buf, const char* _bufEnd) : buf(_buf), bufEnd(_bufEnd), ptr(_buf) {}
	Reader(const string& str) : buf(str.c_str()), bufEnd(str.c_str() + str.length()), ptr(str.c_str()) {}
	Reader(const Reader& R) : buf(R.buf), bufEnd(R.bufEnd), ptr(R.ptr) {}
	Reader& operator>>(int& x) {
		x = 0;
		bool neg = false;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (*ptr == '-') {
			neg = true;
			ptr++;
		}
		else if (*ptr == '+') {
			ptr++;
		}
		while (ptr < bufEnd && *ptr >= '0' && *ptr <= '9') {
			x = x*10 + *ptr - '0';
			ptr++;
		}
		if (neg) x = -x;
		return *this;
	}
	Reader& operator>>(long long& x) {
		x = 0;
		bool neg = false;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (*ptr == '-') {
			neg = true;
			ptr++;
		}
		else if (*ptr == '+') {
			ptr++;
		}
		while (ptr < bufEnd && *ptr >= '0' && *ptr <= '9') {
			x = x*10 + *ptr - '0';
			ptr++;
		}
		if (neg) x = -x;
		return *this;
	}
	Reader& operator>>(double& x) {
		x = 0;
		bool neg = false;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (*ptr == '-') {
			neg = true;
			ptr++;
		}
		else if (*ptr == '+') {
			ptr++;
		}
		while (ptr < bufEnd && *ptr >= '0' && *ptr <= '9') {
			x = x*10 + *ptr - '0';
			ptr++;
		}
		if (ptr < bufEnd && *ptr == '.') {
			ptr++;
			double pow10 = 10;
			while (ptr < bufEnd && *ptr >= '0' && *ptr <= '9') {
				x += (*ptr - '0') / pow10;
				pow10 *= 10;
				ptr++;
			}
		}
		if (neg) x = -x;
		return *this;
	}
	Reader& operator>>(string& str) {
		str.clear();
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			str += *ptr;
			ptr++;
		}
		return *this;
	}
	Reader& operator>>(char& c) {
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		c = *ptr;
		ptr++;
		return *this;
	}
	Reader& operator>>(vector<int>& vec) {
		vec.clear();
		int x;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			vec.push_back(x);
			*this >> x;
		}
		return *this;
	}
	Reader& operator>>(vector<long long>& vec) {
		vec.clear();
		long long x;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			vec.push_back(x);
			*this >> x;
		}
		return *this;
	}
	Reader& operator>>(vector<double>& vec) {
		vec.clear();
		double x;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			vec.push_back(x);
			*this >> x;
		}
		return *this;
	}
	Reader& operator>>(vector<string>& vec) {
		vec.clear();
		string str;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			vec.push_back(str);
			*this >> str;
		}
		return *this;
	}
	Reader& operator>>(vector<char>& vec) {
		vec.clear();
		char c;
		while (ptr < bufEnd && *ptr =='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (ptr < bufEnd && *ptr!='') {
			vec.push_back(c);
			*this >> c;
		}
		return *this;
	}
	const char* buf;
	const char* bufEnd;
	const char* ptr;
};

// Template for Writer class
class Writer {
public:
	Writer() : buf(NULL), bufEnd(NULL), ptr(NULL) {}
	Writer(char* _buf, char* _bufEnd) : buf(_buf), bufEnd(_bufEnd), ptr(_buf) {}
	Writer(string& str) : buf(const_cast<char*>(str.c_str())), bufEnd(const_cast<char*>(str.c_str() + str.length())), ptr(const_cast<char*>(str.c_str())) {}
	Writer(const Writer& W) : buf(W.buf), bufEnd(W.bufEnd), ptr(W.ptr) {}
	Writer& operator<<(int x) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (x < 0) {
			*ptr++ = '-';
			x = -x;
		}
		int numDigits = 0;
		while (x) {
			numDigits++;
			x /= 10;
		}
		while (numDigits--) {
			*ptr++ = '0' + x % 10;
			x /= 10;
		}
		return *this;
	}
	Writer& operator<<(long long x) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (x < 0) {
			*ptr++ = '-';
			x = -x;
		}
		long long numDigits = 0;
		while (x) {
			numDigits++;
			x /= 10;
		}
		while (numDigits--) {
			*ptr++ = '0' + x % 10;
			x /= 10;
		}
		return *this;
	}
	Writer& operator<<(double x) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		if (x < 0) {
			*ptr++ = '-';
			x = -x;
		}
		int numDigits = 0;
		while (x) {
			numDigits++;
			x /= 10;
		}
		while (numDigits--) {
			*ptr++ = '0' + x % 10;
			x /= 10;
		}
		if (ptr < bufEnd) *ptr++ = '.';
		while (x) {
			numDigits++;
			x *= 10;
		}
		while (numDigits--) {
			*ptr++ = '0' + x % 10;
			x /= 10;
		}
		return *this;
	}
	Writer& operator<<(const char* str) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		while (*str) {
			*ptr++ = *str++;
		}
		return *this;
	}
	Writer& operator<<(const string& str) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < str.length(); i++) {
			*ptr++ = str[i];
		}
		return *this;
	}
	Writer& operator<<(char c) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		*ptr++ = c;
		return *this;
	}
	Writer& operator<<(const vector<int>& vec) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < (int)vec.size(); i++) {
			*this << vec[i];
			if (i < (int)vec.size() - 1) *ptr++ ='';
		}
		return *this;
	}
	Writer& operator<<(const vector<long long>& vec) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < (int)vec.size(); i++) {
			*this << vec[i];
			if (i < (int)vec.size() - 1) *ptr++ ='';
		}
		return *this;
	}
	Writer& operator<<(const vector<double>& vec) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < (int)vec.size(); i++) {
			*this << vec[i];
			if (i < (int)vec.size() - 1) *ptr++ ='';
		}
		return *this;
	}
	Writer& operator<<(const vector<string>& vec) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < (int)vec.size(); i++) {
			*this << vec[i];
			if (i < (int)vec.size() - 1) *ptr++ ='';
		}
		return *this;
	}
	Writer& operator<<(const vector<char>& vec) {
		while (ptr < bufEnd && *ptr!='') ptr++;
		if (ptr >= bufEnd) return *this;
		for (int i = 0; i < (int)vec.size(); i++) {
			*this << vec[i];
			if (i < (int)vec.size() - 1) *ptr++ ='';
		}
		return *this;
	}
	char* buf;
	char* bufEnd;
	char* ptr;
};

// Constants
const int MOD = int(1e+9) + 7; // Define a constant for modulo operation
const int INF = 1 << 60;       // Define a constant for infinity

// Mon represents a monster with position x and health h
struct Mon {
	int x, h;
	Mon(int _x, int _h) : x(_x), h(_h) {}
};

// Mons is a slice of Mon for sorting
struct Mons : vector<Mon> {
	bool operator()(const Mon& a, const Mon& b) {
		return a.x < b.x;
	}
};

// Node represents a position and damage
struct Node {
	int x, h;
	Node(int _x, int _h) : x(_x), h(_h) {}
};

// Queue is a simple queue implementation for Nodes
struct Queue : vector<Node> {
	void push(Node v) {
		push_back(v);
	}
	Node first() {
		return front();
	}
	Node pop() {
		Node res = front();
		pop_front();
		return res;
	}
	bool isEmpty() {
		return empty();
	}
};

// max returns the maximum value from a list of integers
int max(int nums...) {
	int m = nums[0];
	for (int i = 1; i < (int)nums.size(); i++) {
		if (m < nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

// min returns the minimum value from a list of integers
int min(int nums...) {
	int m = nums[0];
	for (int i = 1; i < (int)nums.size(); i++) {
		if (m > nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

// pow calculates x raised to the power of y
int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// ceil calculates the ceiling of a/b
int ceil(int a, int b) {
	if (a%b == 0) {
		return a / b;
	} else {
		return a/b + 1;
	}
}

// Main
int main() {
	Reader sc; // Initialize the scanner for input
	Writer wtr; // Create a writer for output
	int N, D, A; // Read N, D, A
	sc >> N >> D >> A;
	vector<Mon> M(N); // Create a vector to hold monsters
	for (int i = 0; i < N; i++) {
		sc >> M[i].x >> M[i].h; // Read each monster's position and health
	}
	sort(M.begin(), M.end(), Mons()); // Sort monsters by their position

	Queue q; // Initialize a queue to manage damage
	int ans = 0; // Variable to count the total number of attacks
	int total = 0; // Variable to track total damage dealt

	// Iterate through each monster
	for (int i = 0; i < N; i++) {
		Mon m = M[i]; // Get the current monster
		// Remove monsters from the queue that are out of range
		while (!q.isEmpty() && q.front().x < m.x) {
			total -= q.pop().h; // Decrease total damage by the damage of the popped monster
		}
		// If the total damage is less than the monster's health
		if (total < m.h) {
			m.h -= total; // Reduce the monster's health by total damage
			int count = ceil(m.h, A); // Calculate how many attacks are needed
			ans += count; // Increment the total attack count
			int damage = count * A; // Calculate the total damage dealt to this monster
			q.push(Node(m.x + 2*D, damage)); // Add the monster's damage to the queue
			total += damage; // Update the total damage
		}
	}

	wtr << ans << endl; // Output the total number of attacks
	return 0;
}

