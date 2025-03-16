#include <bits/stdc++.h>
using namespace std;

class FastReader {
    public:
    vector <string> split_string(string);
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    string next() {
        while (isspace(stream.peek())) stream.ignore();
        string str = "";
        while (!isspace(stream.peek())) {
            str += stream.get();
        }
        return str;
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
        string str = "";
        while (stream.peek()!= '\n' && stream.peek()!= EOF)
            str += stream.get();
        while (isspace(stream.peek())) stream.ignore();
        return str;
    }
    private:
    istream stream;
};

vector <string> FastReader::split_string(string input_string) {
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

int main() {
    FastReader in;
    int n = in.nextInt();
    int m = in.nextInt();
    set <int> bannedRows, bannedCols;
    for (int i = 0; i < m; i++) {
        int r = in.nextInt();
        if (r > 1 && r < n) bannedRows.insert(r);
        int c = in.nextInt();
        if (c > 1 && c < n) bannedCols.insert(c);
    }
    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();
    if (n % 2!= 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) {
            answer--;
        }
    }
    cout << answer << endl;
    return 0;
}

