#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> a;
int ans = 0;

void dfs(int left, int i, int res, const unordered_map<char, int>& dic) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (auto it = dic.begin(); it != dic.end(); ++it) {
        if (it->second > 0) {
            unordered_map<char, int> new_dic = dic;
            new_dic[it->first]--;
            dfs(left - 1, i, res * it->second, new_dic);
        }
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<char, int> dic;
    cin.ignore(); // Ignore the newline character after n

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[c]++;
        }
    }

    for (auto& p : dic) {
        a.push_back(p.second);
    }

    dfs(3, 0, 1, dic);
    cout << ans << endl;

    return 0;
}
