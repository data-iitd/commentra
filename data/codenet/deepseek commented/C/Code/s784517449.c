#include <stdio.h>

int A[1000000], n;

/* 
 * binarySearch function performs a binary search on the array A to find a given key.
 * It returns 1 if the key is found, otherwise it returns 0.
 */
int binarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == A[mid]) return 1; /* keyを発見 */
    if(key > A[mid]) left = mid + 1; /* 後半を探索 */
    else if(key < A[mid]) right = mid; /* 前半を探索 */
  }
  return 0;
}

/* 
 * main function is the entry point of the program.
 * It reads the size of the array and the elements of the array from the user.
 * It then reads the number of queries and performs binary search for each query.
 * Finally, it prints the number of elements found.
 */
int main(void) {
  int i, q, k, sum = 0;
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&k);
    if(binarySearch(k))
      sum++;
  }
  printf("%d\n",sum);
  return 0;
}