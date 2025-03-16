
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
    string n() {
        while (tokenizer == nullptr || !tokenizer->hasMoreTokens()) {
            try {
                tokenizer = new stringtokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer->nextToken();
    }
    int ni() {
        return stoi(n());
    }
private:
    istream& reader;
    stringtokenizer* tokenizer;
};

class Solution {
public:
    void solve(InputReader& in, PrintWriter& out) {
        int n = in.ni();
        int k = in.ni();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = in.ni();
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }
        out.println(ans);
    }
};

int main() {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Solution sol = new Solution();
    sol.solve(in, out);
    out.close();
}

