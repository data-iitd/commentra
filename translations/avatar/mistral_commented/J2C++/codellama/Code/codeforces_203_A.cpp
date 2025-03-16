
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class Main {

    private:
        void solve() {
            int x = nextInt();
            int t = nextInt();
            int a = nextInt();
            int b = nextInt();
            int da = nextInt();
            int db = nextInt();

            int first = 0;
            int second = 0;
            bool ok = false;

            for (int i = 0; i < t; i++) {
                first = a - (da * i);
                for (int j = 0; j < t; j++) {
                    second = b - (db * j);

                    if (second + first == x || second == x || first == x || x == 0) {
                        ok = true;
                        break;
                    }
                }
            }

            if (ok) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }

    public:
        Main() {
            run();
        }

    private:
        int nextInt() {
            return stoi(next());
        }

        string next() {
            while (st == nullptr || !st->hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br->readLine());
                } catch (IOException e) {
                    return "END_OF_FILE";
                }
            }
            return st->nextToken();
        }

        void run() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
                solve();
                br->close();
                out->close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        BufferedReader* br;
        StringTokenizer* st;
        PrintWriter* out;
};

int main() {
    Main main;
    return 0;
}

