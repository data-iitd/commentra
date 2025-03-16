
/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

#include <bits/stdc++.h>
using namespace std;

/********** FAU standard libraries **********/

//cout << bitset<32>(9) << endl; 	// binary expression

/********** I/O usage **********/

//string str = ReadString();
//int i = ReadInt();
//vector<int> X = ReadIntVec(n);
//vector<string> S = ReadStringVec();
//double d = ReadDouble();
//vector<double> A = ReadDoubleVec(n);

//string str = ZeroPaddingStr(num, 32);
//PrintIntLine(X...);

/*******************************************************************/

const int MOD = 1000000000 + 7;
//const int MOD = 998244353;
const int ALPHABET_NUM = 26;
const long long INF_LL = 1e18;
const int INF_INT = 1e9;
const long long NIL = -1;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void init() {
  // bufio.ScanWords <---> bufio.ScanLines
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  init();

  int n, q;
  cin >> n >> q;
  vector<int> C(n);
  for (int i = 0; i < n; i++) {
    cin >> C[i];
    C[i]--;
  }

  vector<int> P(n, NIL);
  vector<int> Answers(q);

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    for (int j = l; j <= r; j++) {
      if (P[C[j]]!= NIL) {
        // FenwickTree
      }
      P[C[j]] = j;
    }

    // FenwickTree
  }

  for (int i = 0; i < q; i++) {
    cout << Answers[i] << endl;
  }

  return 0;
}