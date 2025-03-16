#include <bits/stdc++.h>
using namespace std;

// FastReader class to read input efficiently
class FastReader {
	std::istream *stream;
	std::string buf, cur;
	int pos;
	char ch;

	public FastReader() {
		stream = &std::cin;
	}

	public FastReader(std::istream &stream) {
		this->stream = &stream;
	}

	public void set_stream(std::istream &stream) {
		this->stream = &stream;
	}

	void refill() {
		pos = 0;
		buf.clear();
		std::getline(*stream, buf);
		cur = buf;
	}

	public char get_char() {
		if (pos == cur.length()) refill();
		ch = cur[pos++];
		return ch;
	}

	public char peek_char() {
		if (pos == cur.length()) refill();
		return cur[pos];
	}

	public int get_int() {
		int num = 0;
		char c;
		bool neg = false;
		while ((c = get_char()) =='') ;
		if (c == '-') {
			neg = true;
			c = get_char();
		}
		while (c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
			c = get_char();
		}
		if (neg) return -num;
		return num;
	}

	public long get_long() {
		long num = 0;
		char c;
		bool neg = false;
		while ((c = get_char()) =='') ;
		if (c == '-') {
			neg = true;
			c = get_char();
		}
		while (c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
			c = get_char();
		}
		if (neg) return -num;
		return num;
	}

	public double get_double() {
		double num = 0, div = 1;
		char c;
		bool neg = false;
		while ((c = get_char()) =='') ;
		if (c == '-') {
			neg = true;
			c = get_char();
		}
		while (c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
			c = get_char();
		}
		if (c == '.') {
			while ((c = get_char()) >= '0' && c <= '9') {
				num = num * 10 + c - '0';
				div *= 10;
				c = get_char();
			}
		}
		if (neg) return -num / div;
		return num / div;
	}

	public std::string get_string() {
		std::string str = "";
		char c;
		while ((c = get_char())!='') str += c;
		return str;
	}
};

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower(int x, int y, int mod) {
	int res = 1;
	x %= mod;
	if (x == 0) return 0;
	while (y > 0) {
		if (y % 2 == 1) {
			res = (res * x) % mod;
		}
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}

// Generic pair class to hold two elements of type T1 and T2
template <typename T1, typename T2>
class pair {
	T1 first;
	T2 second;

	public pair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}
};

// Main function to read input, calculate the maximum product, and print the result
int main() {
	FastReader in;
	long a[4];
	for (int i = 0; i < 4; i++)
		a[i] = in.get_long();
	cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))) << endl;
	return 0;
}

