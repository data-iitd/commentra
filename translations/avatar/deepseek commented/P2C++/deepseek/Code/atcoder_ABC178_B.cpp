#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <bitset>
#include <limits>
#include <type_traits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define INF 1e20
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> result;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = line.find(' ', start)) != string::npos) {
        result.push_back(stoi(line.substr(start, end - start)));
        start = end + 1;
    }
    result.push_back(stoi(line.substr(start)));
    return result;
}

int I() {
    int x;
    cin >> x;
    return x;
}

double F() {
    double x;
    cin >> x;
    return x;
}

vector<string> LS() {
    string line;
    getline(cin, line);
    vector<string> result;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = line.find(' ', start)) != string::npos) {
        result.push_back(line.substr(start, end - start));
        start = end + 1;
    }
    result.push_back(line.substr(start));
    return result;
}

string S() {
    string line;
    getline(cin, line);
    return line;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> input = LI();
    int a = input[0], b = input[1], c = input[2], d = input[3];

    int result = max({a * c, b * d, a * d, b * c});
    cout << result << endl;

    return 0;
}
