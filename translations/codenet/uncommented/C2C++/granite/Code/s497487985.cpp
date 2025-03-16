
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
using namespace std;

typedef long long ll;

int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}
// 公約数
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}
// 最小公倍数 = a * b / 最大公约数
// 公倍数
ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}


// min
int main(void){
  ll n;
  ll k;
  ll q;
  ll a[100001];
  ll point[100001] = {0};

  cin >> n >> k >> q;


  /*
  // 初期化
  for(ll i = 0; i < n; i++){
    point[i] = k;
  }
  */
  /*
  if(q < k){
    for(ll i = 0; i < n; i++){
      cout << "Yes" << endl;
      return 0;
    }
    }*/
  //  一人ずつはしない。問題ずつそれぞれのポイントを考える
  for(ll i = 0; i < q; i++){
    cin >> a[i];
    point[a[i] - 1]++;
    /*
    for(ll j = 0; j < n; j++){
      if(a[i]!= (j + 1) && point[j] < k){
	point[j]++;
      }
      //      printf("i = %ld  point = %lld\n", i, point[j]);
    }
    */
  }

  // 求め方を変えた
  for(ll i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
}
