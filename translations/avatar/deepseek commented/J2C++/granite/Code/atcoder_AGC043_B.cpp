

#include <bits/stdc++.h>

using namespace std;

class Main {
public:
    // This method calculates a result based on a given string and character.
    int cal(string s, char c) {
        int n = s.length();
        int m = n - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c && (m & i) == i) {
                ans ^= 1;
            }
        }
        return ans;
    }

    // This method is responsible for solving the problem by processing the input and outputting the result.
    void solve() {
        int n = sc.nextInt();
        string s = sc.next();
        stringstream ss;
        for (int i = 1; i < n; i++) {
            ss << abs(s[i] - s[i - 1]);
        }
        if (n == 2) {
            cout << ss.str()[0] << endl;
            return;
        }
        s = ss.str();
        if (s.find('1')!= string::npos) {
            cout << cal(s, '1') << endl;
        } else {
            cout << cal(s, '2') * 2 << endl;
        }
    }

private:
    // This nested class handles input operations.
    static PrintWriter out;
    static MyScanner sc;

    class MyScanner {
        BufferedReader br;
        stringstream st;

        MyScanner() {
            br = new BufferedReader(new InputStreamReader(cin));
        }

        // Reads the next token from the input.
        string next() {
            while (st.str().empty()) {
                getline(br, st.str());
                st.clear();
            }
            return st.str();
        }

        // Reads the next integer from the input.
        int nextInt() {
            return stoi(next());
        }

        // Reads the next long from the input.
        long nextLong() {
            return stol(next());
        }

        // Reads the next double from the input.
        double nextDouble() {
            return stod(next());
        }
    };
};

int main() {
    out = new PrintWriter(new BufferedOutputStream(cout));
    sc = new Main::MyScanner();
    Main().solve();
    out->close();
    return 0;
}

