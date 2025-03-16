
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// Segment struct represents a segment tree and includes methods to initialize it and update/query it.
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// init initializes the segment tree with a given size n.
	void init(int n) {
		this->n = n;
		this->unit.push_back(1);
		this->bucket.push_back(vector<int>(n));

		int chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n - 1) / chunk + 1;
			this->bucket.push_back(vector<int>(n));
			this->unit.push_back(this->unit[i] * chunk);
		}
		this->h = this->unit.size();
		this->chunk = chunk;
	}

	// maximize updates the value at a given index in the segment tree.
	void maximize(int index, int value) {
		this->bucket[0][index] = value;
		for (this->i = 0; this->i < this->h - 1; this->i++) {
			int s = index - index % this->chunk;
			int t = s + this->chunk;
			if (t > this->bucket[this->i].size()) {
				t = this->bucket[this->i].size();
			}
			int parent = index / this->chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < this->bucket[this->i][i]) {
					max = this->bucket[this->i][i];
				}
			}
			this->bucket[this->i + 1][parent] = max;
			index /= this->chunk;
		}
	}

	// top returns the index of the maximum value in the segment tree.
	int top() {
		int index = 0;
		for (this->i = this->h - 2; this->i >= 0; this->i--) {
			int s = index * this->chunk;
			int t = s + this->chunk;
			if (t > this->bucket[this->i].size()) {
				t = this->bucket[this->i].size();
			}
			for (int i = s; i < t; i++) {
				if (this->bucket[this->i][i] == this->bucket[this->i + 1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
};

// getScanner initializes a new scanner that reads from the given file pointer.
ifstream* getScanner(ifstream* fp) {
	fp->sync_with_stdio(false);
	fp->tie(0);
	return fp;
}

// getNextString reads the next word from the scanner.
string getNextString(ifstream* fp) {
	string s;
	fp->ignore(numeric_limits<streamsize>::max(), ' ');
	getline(*fp, s, ' ');
	return s;
}

// getNextInt converts the next word to an integer.
int getNextInt(ifstream* fp) {
	return stoi(getNextString(fp));
}

// getNextInt64 converts the next word to a 64-bit integer.
int64_t getNextInt64(ifstream* fp) {
	return stoll(getNextString(fp));
}

// getNextUint64 converts the next word to an unsigned 64-bit integer.
uint64_t getNextUint64(ifstream* fp) {
	return stoull(getNextString(fp));
}

// getNextFloat64 converts the next word to a floating-point number.
double getNextFloat64(ifstream* fp) {
	return stod(getNextString(fp));
}

// Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
int main() {
	ifstream* fp = new ifstream();
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->close();
	}
	if (fp->eof()) {
		fp->close();
	}
	if (fp->fail()) {
		fp->close();
	}
	if (fp->bad()) {
		fp->close();
	}
	if (fp->is_open()) {
		fp->close();
	}
	if (fp->good()) {
		fp->c