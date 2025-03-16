
// +build ignore
#include <bits/stdc++.h>

using namespace std;

// I/O
struct Scanner {
    istream& in;
    Scanner(istream& in) : in(in) {}
    string next() {
        string str;
        in >> str;
        return str;
    }
    template <class T>
    T nextInt() {
        T val;
        in >> val;
        return val;
    }
};

void run(Scanner& sc, ostream& out) {
    int N = sc.nextInt();

    if (N < 4) {
        out << 0 << endl;
        return;
    }

    string S = sc.next();

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') nr++;
        if (c == 'B') nb++;
        if (c == 'G') ng++;
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        while (k < N) {
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;
    out << tot - same << endl;
}

int main() {
    Scanner sc(cin);
    run(sc, cout);
    return 0;
}



