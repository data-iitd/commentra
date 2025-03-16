#include <stdio.h>

int main():
  int K, X;
  # Read two integers, K and X, from the standard input
  scanf("%d %d", &K, &X);
  
  # Loop from X-K+1 to X+K-1
  for i in range(X - K + 1, X + K):
    print(i, end=" ");
  # Print a newline character to move to the next line
  print();
  return 0;

