#include <bits/stdc++.h>
using namespace std;

class FastReader {
    public:
    vector<string> split_string(string input_string) {
        string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x =='';
        });

        input_string.erase(new_end, input_string.end());

        while (input_string[input_string.length() - 1] =='') {
            input_string.pop_back();
        }

        vector<string> splits;
        char delimiter ='';

        size_t i = 0;
        size_t pos = input_string.find(delimiter);

        while (pos!= string::npos) {
            splits.push_back(input_string.substr(i, pos - i));

            i = pos + 1;
            pos = input_string.find(delimiter, i);
        }

        splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

        return splits;
    }

    string string;
    vector<string> stringVector;
    int arrayPointer = 0;
    FastReader() {
        string = "";
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string next() {
        while (arrayPointer >= stringVector.size()) {
            string = "";
            getline(cin, string);
            stringVector = split_string(string);
            arrayPointer = 0;
        }
        return stringVector[arrayPointer++];
    }
    int nextInt() {
        string integer = next();
        return stoi(integer);
    }
    long long nextLong() {
        string integer = next();
        return stoll(integer);
    }
    double nextDouble() {
        string integer = next();
        return stod(integer);
    }
    string nextLine() {
        string str = "";
        getline(cin, str);
        return str;
    }
};

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

class pair {
public:
    int first, second;
    pair(int first, int second) {
        this->first = first;
        this->second = second;
    }
};

int main() {
    FastReader in;
    long a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = in.nextLong();
    }
    cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))) << endl;
    return 0;
}

