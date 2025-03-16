#include <bits/stdc++.h>

using namespace std;

// getScanner Function
// Purpose: Initializes a scanner for the given file pointer.
// Details: Creates a new scanner and sets it to scan words.
inline istream& getScanner(istream& fp, istream::pos_type& pos) {
	fp.clear();
	fp.seekg(pos);
	pos = 0;
	return fp;
}

// getNextString Function
// Purpose: Retrieves the next word from the scanner.
// Details: Scans the next word and returns it.
inline string getNextString(istream& fp, istream::pos_type& pos) {
	string s;
	fp >> s;
	pos = fp.tellg();
	return s;
}

// getNextInt Function
// Purpose: Retrieves the next word and converts it to an integer.
// Details: Uses `getNextString` and `stoi`.
inline int getNextInt(istream& fp, istream::pos_type& pos) {
	int i;
	fp >> i;
	pos = fp.tellg();
	return i;
}

// getNextInt64 Function
// Purpose: Retrieves the next word and converts it to an int64.
// Details: Uses `getNextString` and `stoll`.
inline int64_t getNextInt64(istream& fp, istream::pos_type& pos) {
	int64_t i;
	fp >> i;
	pos = fp.tellg();
	return i;
}

// getNextUint64 Function
// Purpose: Retrieves the next word and converts it to a uint64.
// Details: Uses `getNextString` and `stoull`.
inline uint64_t getNextUint64(istream& fp, istream::pos_type& pos) {
	uint64_t i;
	fp >> i;
	pos = fp.tellg();
	return i;
}

// getNextFloat64 Function
// Purpose: Retrieves the next word and converts it to a float64.
// Details: Uses `getNextString` and `stod`.
inline double getNextFloat64(istream& fp, istream::pos_type& pos) {
	double i;
	fp >> i;
	pos = fp.tellg();
	return i;
}

// main Function
// Purpose: Main entry point of the program.
// Details: Sets up input/output streams, reads strings, initializes pattern matching, and performs the main logic.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	istream& fp = cin;
	istream::pos_type pos = 0;

	if (getenv("MASPY") == "ますピ") {
		fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		freopen(getenv("NGTKANA_IS_GENIUS10"), "w", stdout);
	}

	istream& scanner = getScanner(fp, pos);
	ostream& writer = cout;

	string s = getNextString(scanner, pos);
	string t = getNextString(scanner, pos);

	int ns = s.size();
	int nt = t.size();
	string* ss = new string[nt/ns+1];

	for (int i = 0; i < nt/ns+1; i++) {
		ss[i] = s;
	}

	string sss = ss[0] + ss[0];

	bool* ok = new bool[ns];

	int* uni = new int[ns];
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}
	int m = 0;
	bool o;
	for (int i = 0; i < ns; i++) {
		o = true;
		for (m = 0; m < nt; m++) {
			if (t[m]!= sss[i+m]) {
				o = false;
				break;
			}
		}
		ok[i] = o;
		if (o) {
			i += nt - m;
			m = m;
		}
		for (m = 0; m >= 0 && t[m]!= sss[i+m]; m = m) {
			i += m - m;
			m = m;
		}
		i--;
		m++;
	}

	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue;
		}
		if (!ok[(i+nt)%ns]) {
			continue;
		}
		r = root(i, uni);
		rr = root((i+nt)%ns, uni);
		if (rr == r) {
			cout << -1 << endl;
			return 0;
		}
		uni[rr] = r;
	}

	int* counter = new int[ns];
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (!ok[r]) {
			continue;
		}
		counter[r]++;
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	cout << ans << endl;

	delete[] ss;
	delete[] ok;
	delete[] uni;
	delete[] counter;

	return 0;
}

// root Function
// Purpose: Implements the union-find structure to find the root of a node.
// Details: Uses path compression to optimize the union-find structure.
int root(int i, int* uni) {
	if (i == uni[i]) {
		return i;
	}

	uni[i] = root(uni[i], uni);
	return uni[i];
}

