#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <numeric>
#include <functional>
#include <iterator>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define setrecursionlimit(x) (void(0))
#define dbg(args...) (void(0))
#define LMIIS vector<int> input_list() { string s; getline(cin, s); return list_to_vector(s); }
#define II int input() { int x; cin >> x; return x; }
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define P pair<int,int>
#define V vector
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

const int P = 1000000007;
const int INF = 1000000010;

int input() {
    string s;
    getline(cin, s);
    return stoi(s);
}

vector<int> input_list() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> lst;
    int num;
    while (ss >> num) {
        lst.push_back(num);
    }
    return lst;
}

void main_() {
    string sa, sb;
    cin >> sa >> sb;

    int a = stoi(sa);
    int b = round(stof(sb) * 100);

    cout << (a * b) / 100 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_();
    return 0;
}
