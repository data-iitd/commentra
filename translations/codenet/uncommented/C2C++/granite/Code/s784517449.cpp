
#include <iostream>

int A[1000000], n;

/* 二分探索 */
int binarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == A[mid]) return 1; /* keyを発見 */
    if(key > A[mid]) left = mid + 1; /* 後半を探索 */
    else if(key < A[mid]) right = mid; /* 前 halfを探索 */
  }
  return 0;
}

int main(void) {
  int i, q, k, sum = 0;
  std::cin >> n;
  for(i=0; i<n; i++) {
    std::cin >> A[i];
  }
  std::cin >> q;
  for(i=0;i<q;i++) {
    std::cin >> k;
    if(binarySearch(k))
      sum++;
  }
  std::cout << sum << std::endl;
  return 0;
}
