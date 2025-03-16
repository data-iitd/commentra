#include <bits/stdc++.h>
using namespace std;

class FastReader {
    public:
    vector<string> split_string(string);
    string str;
    public:
    FastReader() {
        //nothing
    }
    string next() {
        while (str.size() == 0) {
            try {
                str = split_string(cin.get_line());
            }
            catch (...) {
                //end of file
                return "";
            }
        }
        size_t pos = 0;
        string out = "";
        while (pos < str.size() && str[pos]!='') {
            out += str[pos++];
        }
        while (pos < str.size() && str[pos] =='') {
            pos++;
        }
        str = str.substr(pos, str.size() - pos);
        return out;
    }
    int nextInt() {
        return stoi(next());
    }
    long long nextLong() {
        return stoll(next());
    }
    double nextDouble() {
        return stod(next());
    }
    string nextLine() {
        string out = str;
        str = "";
        return out;
    }
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
};

int main() {
    FastReader sc;
    int n = sc.nextInt();
    int m = sc.nextInt();
    int t = reverse(m);
    cout << t + n << endl;
    return 0;
}

int reverse(int n) {
    if (n < 10) return n * 10;
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + t % 10;
        t = t / 10;
    }
    return r;
}

