#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
using namespace std;

int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}
// 公約数
long int gcd(long int a, long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}
// 最小公倍数 = a * b / 最大公約数
// 公倍数
long int lcm(long int a, long int b){
  return a * b / gcd(a, b);
}


// min
int main(void){
  long int n;
  long long int k;
  long int q;
  long int a[100001];
  long long int point[100001] = {0};

  cin >> n >> k >> q;


  /*
  // 初期化
  for(long int i = 0; i < n; i++){
    point[i] = k;
  }
  */
  /*
  if(q < k){
    for(long int i = 0; i < n; i++){
      cout << "Yes" << endl;
      return 0;
    }
    }*/
  //  一人ずつはしない。問題ずつそれぞれのポイントを考える
  for(long int i = 0; i < q; i++){
    cin >> a[i];
    point[a[i] - 1]++;
    /*
    for(long int j = 0; j < n; j++){
      if(a[i] != (j + 1) && point[j] < k){
	point[j]++;
      }
      //      printf("i = %ld  point = %lld\n", i, point[j]);
    }
    */
  }

  // 求め方を変えた
  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
}

