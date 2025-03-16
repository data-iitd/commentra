
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct bufReader {
    bufReader() {
        r = new bufio::Reader(cin);
        buf = new vector<char>();
        i = 0;
    }
    void readLine() {
        if (i < buf->size()) {
            return;
        }
        buf->clear();
        i = 0;
        for (;;) {
            string line;
            bool isPrefix;
            tie(line, isPrefix) = r->ReadLine();
            buf->insert(buf->end(), line.begin(), line.end());
            if (!isPrefix) {
                break;
            }
        }
    }
    string next() {
        readLine();
        int from = i;
        for (; i < buf->size(); i++) {
            if ((*buf)[i] == ' ') {
                break;
            }
        }
        string s(buf->begin() + from, buf->begin() + i);
        i++;
        return s;
    }
    string nextLine() {
        readLine();
        string s(buf->begin() + i, buf->end());
        i = buf->size();
        return s;
    }
    bufio::Reader *r;
    vector<char> *buf;
    int i;
};

bufReader reader;

int64 nextInt() {
    return stoll(reader.next());
}

int64 max(int64 x, int64 y) {
    if (x > y) {
        return x;
    }
    return y;
}

int64 min(int64 x, int64 y) {
    if (x < y) {
        return x;
    }
    return y;
}

string joinInts(vector<int64> a, string sep) {
    vector<string> b;
    for (int64 v : a) {
        b.push_back(to_string(v));
    }
    return join(b, sep);
}

int64 divUp(int64 x, int64 y) {
    return (x + y - 1) / y;
}

void solve() {
    int64 N = nextInt();
    vector<int64> T, A;
    for (int64 i = 0; i < N; i++) {
        T.push_back(nextInt());
        A.push_back(nextInt());
    }
    int64 t, a;
    tie(t, a) = make_tuple(T[0], A[0]);
    for (int64 i = 1; i < N; i++) {
        int64 r = max(divUp(t, T[i]), divUp(a, A[i]));
        tie(t, a) = make_tuple(T[i] * r, A[i] * r);
    }
    cout << t + a << endl;
}

int main() {
    solve();
    return 0;
}

