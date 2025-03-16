

// by syu
#include <bits/stdc++.h>
using namespace std;

// Define a custom Scanner class to read input efficiently
class Scanner {
public:
    Scanner(std::istream& in, int max = 1048576) : buf(max), s(in, &buf) {
        s.buf(&buf);
        s.imbue(std::locale::classic());
    }

    template <typename T>
    T next() {
        T val;
        s >> val;
        return val;
    }

private:
    std::string buf;
    std::istream_iterator<char> s;
};

int main() {
    // Initialize a global Scanner instance to read from standard input
    Scanner in(std::cin);

    // Read two integers, n and k, from standard input
    int n = in.next<int>();
    int k = in.next<int>();

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        cout << 0 << endl;
    } else {
        // If n is not divisible by k, print 1
        cout << 1 << endl;
    }

    return 0;
}

