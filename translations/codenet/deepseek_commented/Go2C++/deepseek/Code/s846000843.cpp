#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Io {
public:
    Io() : buffer(new stringstream) {}
    ~Io() { delete buffer; }

    string nextLine() {
        string line;
        getline(*buffer, line);
        return line;
    }

    string next() {
        while (tokens.empty()) {
            string line = nextLine();
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        string token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    void printLn(const vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i] << (i == vec.size() - 1 ? '\n' : ' ');
        }
    }

    void printLn(int value) {
        cout << value << '\n';
    }

private:
    stringstream* buffer;
    vector<string> tokens;
};

vector<int> cumSum(const vector<int>& nums) {
    vector<int> sums = {0};
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int min(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

int main() {
    Io io;

    int n = io.nextInt();
    vector<int> aa(n);

    for (int i = 0; i < n; ++i) {
        aa[i] = io.nextInt();
    }

    vector<int> cumsum = cumSum(aa);

    int ans = 2020202020;
    for (int i = 1; i < cumsum.size() - 1; ++i) {
        ans = min(ans, abs(cumsum.back() - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    io.printLn(ans);

    return 0;
}
