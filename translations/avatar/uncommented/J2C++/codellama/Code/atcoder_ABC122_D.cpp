
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Main {
public:
    int N;
    long MOD = 1000000007L;
    string TOKENS[4] = {"A", "C", "G", "T"};
    map<string, long> *memo;
    Main() {
        cin >> N;
        cin.close();
        this->memo = new map<string, long>[N + 1];
        for (int i = 0; i < this->memo->size(); ++i) {
            this->memo[i] = new map<string, long>();
        }
    }
    long calc() {
        return dfs(0, "TTT");
    }
    bool isOK(string last4) {
        if (last4.find("AGC") != string::npos) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            char vals[4];
            last4.copy(vals, 4);
            vals[i] = last4[i + 1];
            vals[i + 1] = last4[i];
            string s = vals;
            if (s.find("AGC") != string::npos) {
                return false;
            }
        }
        return true;
    }
    long dfs(int current, string last3) {
        if (this->memo[current].find(last3) != this->memo[current].end()) {
            return (long)(this->memo[current][last3]);
        }
        if (current == N) {
            return 1;
        }
        long result = 0;
        for (string c : TOKENS) {
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1, last3.length()) + c)) % MOD;
            }
        }
        this->memo[current][last3] = result;
        return result;
    }
    public:
    void main() {
        Main ins = new Main();
        cout << ins.calc() << endl;
    }
};

int main() {
    Main ins = new Main();
    cout << ins.calc() << endl;
    return 0;
}

