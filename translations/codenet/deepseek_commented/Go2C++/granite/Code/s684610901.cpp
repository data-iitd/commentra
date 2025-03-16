

#include <bits/stdc++.h>
using namespace std;

// Package main defines the entry point for the program.

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
// pair struct holds two values and an index for sorting.
struct pair {
    int64_t index;
    int64_t p1, p2;
};

// pairs is a slice of pair structs for sorting.
typedef vector<pair> pairs;

// Len returns the length of the pairs slice.
int Len(pairs slice) {
    return slice.size();
}

// Less compares two pairs based on their index.
bool Less(pairs slice, int i, int j) {
    return slice[i].index < slice[j].index;
}

// Swap exchanges two pairs in the slice.
void Swap(pairs slice, int i, int j) {
    pair temp = slice[i];
    slice[i] = slice[j];
    slice[j] = temp;
}

// Int64Slice is a type alias for sorting slices of int64.
typedef vector<int64_t> Int64Slice;

// Len returns the length of the Int64Slice.
int Len(Int64Slice slice) {
    return slice.size();
}

// Less compares two int64 values.
bool Less(Int64Slice slice, int i, int j) {
    return slice[i] < slice[j];
}

// Swap exchanges two int64 values in the slice.
void Swap(Int64Slice slice, int i, int j) {
    int64_t temp = slice[i];
    slice[i] = slice[j];
    slice[j] = temp;
}

// Int64s sorts a slice of int64.
void Int64s(Int64Slice a) {
    sort(a.begin(), a.end());
}

// Int64sSliceAreSorted checks if a slice of int64 is sorted.
bool Int64sSliceAreSorted(Int64Slice a) {
    return is_sorted(a.begin(), a.end());
}

/*==========================================
 *             Constants and Variables
 *==========================================*/
// initialBufSize and maxBufSize define the buffer sizes for scanning input.
const int initialBufSize = 1e4;
const int maxBufSize = 1e8;
const int64_t INF = 1e8;

// scanner and writer are initialized for reading from standard input and writing to standard output.
ifstream scanner(ios_base::in);
ofstream writer(ios_base::out);
vector<int64_t> di = {-1, 0, 1, 0};
vector<int64_t> dj = {0, -1, 0, 1};

/*==========================================
 *             Main Function
 *==========================================*/
// main function reads three integers and checks if the third integer lies between the first and second.
int main() {
    string buf;
    scanner.rdbuf()->pubsetbuf(new char[initialBufSize], initialBufSize);
    scanner.exceptions(ios::badbit);
    while (getline(scanner, buf)) {
        stringstream ss(buf);
        int64_t A, B, C;
        ss >> A >> B >> C;
        if (C >= A && C <= B) {
            writer << "Yes" << endl;
        } else {
            writer << "No" << endl;
        }
    }
    return 0;
}

/*==========================================
 *             Library
 *==========================================*/
// NextPermutation finds the next permutation of a slice.
bool NextPermutation(vector<int64_t>& x) {
    int n = x.size() - 1;
    if (n < 1) {
        return false;
    }
    int j = n - 1;
    for (; x[j] > x[j + 1]; j--) {
        if (j == 0) {
            return false;
        }
    }
    int l = n;
    for (; x[j] > x[l]; l--) {
        ;
    }
    swap(x[j], x[l]);
    for (int k = j + 1, l = n; k < l; ) {
        swap(x[k], x[l]);
        k++;
        l--;
    }
    return true;
}

// doubleAry creates a 2D slice initialized with a given value.
vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    vector<vector<int64_t>> res(h);
    for (int i = 0; i < h; i++) {
        res[i] = vector<int64_t>(w, init);
    }
    return res;
}

// aryEq checks if two slices are equal.
bool aryEq(vector<int64_t>& a, vector<int64_t>& b) {
    return a == b;
}

// clone creates a copy of a slice.
vector<int64_t> clone(vector<int64_t>& n) {
    vector<int64_t> r(n.size());
    for (int i = 0; i < n.size(); i++) {
        r[i] = n[i];
    }
    return r;
}

// write writes a string to the writer.
void write(string s) {
    writer << s;
}

// print flushes the writer.
void print() {
    writer.flush();
}

// readLine reads a line of text from the scanner.
string readLine() {
    string s;
    getline(scanner, s);
    return s;
}

// readInt reads an integer from the scanner.
int64_t readInt() {
    int64_t read;
    scanner >> read;
    return read;
}

// readFloat reads a float from the scanner.
double readFloat() {
    double read;
    scanner >> read;
    return read;
}

// readRunes reads a slice of runes from the scanner.
vector<rune> readRunes() {
    string s;
    getline(scanner, s);
    vector<rune> r;
    for (char c : s) {
        r.push_back(c);
    }
    return r;
}

// readString reads a string from the scanner.
string readString() {
    string s;
    getline(scanner, s);
    return s;
}

// readStrings reads multiple strings from the scanner.
vector<string> readStrings() {
    string s;
    getline(scanner, s);
    vector<string> r;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        r.push_back(word);
    }
    return r;
}

// s2i converts a string to an integer.
int64_t s2i(string s) {
    int64_t intVal;
    stringstream ss(s);
    ss >> intVal;
    return intVal;
}

// i2s converts an integer to a string.
string i2s(int64_t i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

// s2f converts a string to a float.
double s2f(string s) {
    double floatVal;
    stringstream ss(s);
    ss >> floatVal;
    return floatVal;
}

// abs returns the absolute value of an integer.
int64_t abs(int64_t i) {
    return abs(i);
}

// max returns the maximum value in a list of integers.
int64_t max(vector<int64_t>& a) {
    int64_t ans = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (ans < a[i]) {
            ans = a[i];
        }
    }
    return ans;
}

// min returns the minimum value in a list of integers.
int64_t min(vector<int64_t>& a) {
    int64_t ans = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (ans > a[i]) {
            ans = a[i];
        }
    }
    return ans;
}

// sum returns the sum of a slice of integers.
int64_t sum(vector<int64_t>& i) {
    int64_t sum = 0;
    for (int i = 0; i < i.size(); i++) {
        sum += i[i];
    }
    return sum;
}

// split splits a string into a slice of strings.
vector<string> split(string s) {
    vector<string> res;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        res.push_back(word);
    }
    return res;
}

// strAry2intAry converts a slice of strings to a slice of integers.
vector<int64_t> strAry2intAry(vector<string>& strs) {
    vector<int64_t> res;
    for (string str : strs) {
        int64_t intVal;
        stringstream ss(str);
        ss >> intVal;
        res.push_back(intVal);
    }
    return res;
}

// intAry2strAry converts a slice of integers to a slice of strings.
vector<string> intAry2strAry(vector<int64_t>& nums) {
    vector<string> res;
    for (int i = 0; i < nums.size(); i++) {
        res.push_back(to_string(nums[i]));
    }
    return res;
}

// ary2str joins a slice of strings into a single string.
string ary2str(vector<string>& strs) {
    return strings.Join(strs, " ");
}

// reverse reverses a slice of integers.
vector<int64_t> reverse(vector<int64_t>& nums) {
    for i, j := 0, len(nums)-1; i < j {
        nums[i], nums[j] = nums[j], nums[i]
        res[i], res[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i] = nums[j], nums[i]
        nums[i], nums[j] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nums[i] = nums[j], nu