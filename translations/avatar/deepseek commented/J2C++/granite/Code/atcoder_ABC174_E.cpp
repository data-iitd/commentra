
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            logsLength[i] = in.nextInt();
        }
        int min = 1, max = (int) 1e9 + 1000;
        while (min < max) {
            int mid = (min + max) / 2;
            if (nei(mid, logsLength, k)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        out.println(min);
    }

    bool nei(int mid, vector<int>& logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1;
            if (k < 0) {
                return false;
            }
        }
        return true;
    }
};

class InputReader {
private:
    BufferedReader reader;
    StringTokenizer tokenizer;

public:
    InputReader(InputStream stream) {
        reader = BufferedReader(InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    string next() {
        while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    vector<int> readArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        return a;
    }
};

int main() {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in(inputStream);
    PrintWriter out(outputStream);
    Solution sol;
    sol.solve(in, out);
    out.close();
    return 0;
}

