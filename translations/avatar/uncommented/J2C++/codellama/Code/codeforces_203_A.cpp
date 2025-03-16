
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cassert>
using namespace std;

class Main {
public:
    void solve() {
        int x = nextInt();
        int t = nextInt();
        int a = nextInt();
        int b = nextInt();
        int da = nextInt();
        int db = nextInt();
        int first;
        int second;
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
            out.print("YES");
        } else {
            out.print("NO");
        }
    }
    Main() {
        run();
    }
    ~Main() {
    }
    void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            br.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    int nextInt() {
        return Integer.parseInt(next());
    }
    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
                return "END_OF_FILE";
            }
        }
        return st.nextToken();
    }
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
};

int main() {
    Main main = new Main();
    return 0;
}

