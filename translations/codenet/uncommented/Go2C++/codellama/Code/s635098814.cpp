
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define rrep(i, n, a) for (int i = (n) - 1; i >= (a); i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

int main() {
    int ALPHABET_NUM = 26;
    int memo[ALPHABET_NUM];
    string str;

    while (cin >> str) {
        if (str.size() == 0) break;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            if ('a' <= c && c <= 'z') {
                // toUpper
                // c-('a'-'A')
                memo[c-'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // toLower
                // c+('a'-'A')
                memo[c-'A']++;
            } else {
                // stay
                // c
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << char(i+'a') << " : " << memo[i] << endl;
    }
}

