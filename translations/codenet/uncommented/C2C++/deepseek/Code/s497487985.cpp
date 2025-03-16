#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

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

int main() {
  long int n;
  long long int k;
  long int q;
  std::vector<long int> a(100001);
  std::vector<long long int> point(100001, 0);

  std::cin >> n >> k >> q;

  for(long int i = 0; i < q; i++){
    std::cin >> a[i];
    point[a[i] - 1]++;
  }

  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      std::cout << "Yes" << std::endl;
    }else{
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}

