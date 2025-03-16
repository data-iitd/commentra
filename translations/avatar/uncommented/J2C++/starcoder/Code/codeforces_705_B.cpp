#include <bits/stdc++.h>
using namespace std;

class FastReader {
    std::istream *stream;
    std::string buf, token;
    int pos;
    int len;
public:
    FastReader() {
        stream = new std::istream(NULL);
    }
    FastReader(std::istream &stream) {
        this->stream = &stream;
        len = 0;
        pos = 0;
        buf = "";
        token = "";
    }
    void ignore() {
        char c;
        while (stream->get(c) && (c == '\n' || c =='' || c == '\t' || c == '\r'));
    }
    void ignore(int n) {
        char c;
        while (n-- > 0 && stream->get(c) && (c == '\n' || c =='' || c == '\t' || c == '\r'));
    }
    std::string next() {
        while (pos >= len) {
            pos = 0;
            len = stream->rdbuf()->in_avail();
            buf = stream->rdbuf()->str();
        }
        token = "";
        while (pos < len &&!isspace(buf[pos])) {
            token += buf[pos++];
        }
        ignore();
        return token;
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
    std::string nextLine() {
        std::string s = "";
        while (pos < len && buf[pos]!= '\n') {
            s += buf[pos++];
        }
        pos++;
        ignore();
        return s;
    }
};

int main() {
    FastReader scan;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

