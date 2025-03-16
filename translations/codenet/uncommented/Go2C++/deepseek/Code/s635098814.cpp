#include <bits/stdc++.h>
using namespace std;

/*********** I/O ***********/

string readString() {
    string str;
    cin >> str;
    return str;
}

int readInt() {
    return stoi(readString());
}

vector<int> readInts(int n) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = readInt();
    }
    return b;
}

float readFloat() {
    return stof(readString());
}

vector<float> readFloats(int n) {
    vector<float> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = readFloat();
    }
    return b;
}

vector<string> readStrings(int n) {
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = readString();
    }
    return b;
}

vector<char> readRunes() {
    string str = readString();
    return vector<char>(str.begin(), str.end());
}

/*********** Debugging ***********/

template <class T>
void print(T v) {
    cout << v << endl;
}

template <class T>
void printSlice(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

template <class T, class U>
void printMap(const map<T, U>& m) {
    for (const auto& [key, value] : m) {
        cout << key << " : " << value << endl;
    }
}

/*********** Arithmetic ***********/

int max(const vector<int>& v) {
    return *max_element(v.begin(), v.end());
}

int min(const vector<int>& v) {
    return *min_element(v.begin(), v.end());
}

int sum(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

/*********** DP sub-functions ***********/

/*********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadInts(n)
//S := ReadRunes()
//a := ReadFloat()
//A := ReadFloats(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = numeric_limits<int64_t>::max();

int memo[ALPHABET_NUM];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        getline(cin, str);
        if (str.empty()) {
            break;
        }
        for (char c : str) {
            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << char(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}
