#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    ll H = sc.nextLong();
    ll W = sc.nextLong();

    ll ans;
    if (H == 1 || W == 1) {
      ans = 1;
    } else {
      ll m = H*W;
      if (m % 2 == 0) ans = m/2;
      else ans = m/2+1;
    }
    System.out.println(ans);
  }
}
