
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    FastScanner input;
    int n = input.nextInt();
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        map[val] = map.getOrDefault(val, 0) + 1;
    }
    int max = INT_MIN;
    for (map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
        int value = it->second;
        max = max(max, value);
    }
    cout << max << " " << map.size() << endl;
    return 0;
}

class FastScanner {
public:
    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer("");
    }

    String next() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }

private:
    BufferedReader br;
    StringTokenizer st;
}

