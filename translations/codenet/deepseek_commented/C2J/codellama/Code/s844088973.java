#include <stdio.h>

public class Main {
  public static void main(String[] args) {
    int K, X;
    // Read two integers, K and X, from the standard input
    scanf("%d %d", &K, &X);
    
    // Loop from X-K+1 to X+K-1
    for(int i = X - K + 1; i <= X + K - 1; i++){
      printf("%d", i);
      // Print a space after each number except the last one
      if(i < X + K - 1) printf(" ");
    }
    // Print a newline character to move to the next line
    printf("\n");
  }
}
