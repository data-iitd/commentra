
// by syu
#include <bits/stdc++.h>
using namespace std;

// Initialize a new Scanner to read from standard input
class Scanner {
public:
    Scanner(std::istream& in, int max = 1048576) : buf(max), s(in, &buf) {}
    string next() {
        s.read(buf.data(), buf.size());
        s.ignore(numeric_limits<streamsize>::max(), '\n');
        return s.str();
    }
    int nextInt() {
        int x;
        s >> x;
        return x;
    }
private:
    string buf;
    istringstream s;
};

int main() {
    Scanner in(cin);
    int n = in.nextInt();
    int k = in.nextInt();
    cout << (n % k == 0? 0 : 1) << endl;
}

// 