
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

    string string_trim_space(string input_string) {
        string::iterator it = input_string.begin();

        while (it!= input_string.end() && (*it =='' || *it == '\n' || *it == '\r' || *it == '\t')) {
            it = input_string.erase(it);
        }

        it = input_string.end();

        while (it!= input_string.begin() && (*it =='' || *it == '\n' || *it == '\r' || *it == '\t')) {
            it = input_string.erase(it - 1);
        }

        return input_string;
    }

    void read_input() {
        getline(cin, input_string);

        vector<string> splits = split_string(input_string);

        for (int i = 0; i < splits.size(); i++) {
            input_integer_vector.push_back(stoi(splits[i]));
        }
    }

    FastReader() {
        read_input();
    }

    string input_string;
    vector<int> input_integer_vector;
};

int main() {
    FastReader fs;

    int n = fs.input_integer_vector[0];
    int m = fs.input_integer_vector[1];

    int t = reverse(m);

    cout << t + n << endl;
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

