
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class InputReader {
public:
    InputReader(istream& stream) : reader(stream) {
        tokenizer = nullptr;
    }
    string next() {
        while (tokenizer == nullptr || !tokenizer->hasMoreTokens()) {
            try {
                tokenizer = new stringtokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer->nextToken();
    }
    int nextInt() {
        return stoi(next());
    }
    long nextLong() {
        return stol(next());
    }
private:
    istream& reader;
    stringtokenizer* tokenizer;
};

int main() {
    InputReader in(cin);
    PrintWriter out(cout);
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    int d = in.nextInt();
    if (c > b) {
        out.println(0);
    } else if (a > d) {
        out.println(0);
    } else if (a < c) {
        out.println(min(b, d) - c);
    } else {
        vector<int> l;
        l.push_back(a);
        l.push_back(b);
        l.push_back(c);
        l.push_back(d);
        sort(l.begin(), l.end());
        out.println(l[2] - l[1]);
    }
}

