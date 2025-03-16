
#include <bits/stdc++.h>
using namespace std;

class FastReader {
    public:
    FastReader() {
        sbuf = new streambuf();
    }

    string next() {
        int c;
        while ((c = sbuf->sbumpc()) =='' || c == '\n' || c == '\r' || c == '\t')
            ;
        if (c == EOF)
            return "";
        string str = "";
        do {
            str += (char)c;
        } while ((c = sbuf->sbumpc())!= EOF && c!='' && c!= '\n' && c!= '\r' && c!= '\t');
        return str;
    }

    int nextInt() {
        return atoi(next().c_str());
    }

    long long nextLong() {
        return atoll(next().c_str());
    }

    double nextDouble() {
        return atof(next().c_str());
    }

    string nextLine() {
        string str = "";
        getline(cin, str);
        return str;
    }

    private:
    streambuf *sbuf;
};

int main() {
    FastReader scan;
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}

void solve() {
    int t = scan.nextInt();
    int arr[t];
    for (int i = 0; i < t; i++) {
        arr[i] = scan.nextInt();
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
            if ((i - 1) % 2 == 0) {
                cout << (prevWinner == 0? 2 : 1) << endl;
                prevWinner = (prevWinner == 0? 2 : 1);
            }
        }
    }
}

int prevWinner = 0;

