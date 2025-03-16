#include <stdio.h>  // Include standard input-output library
#include <stdbool.h>  // Include library for boolean types
#include <string.h>  // Include library for string manipulation

public class Main {
  public static void main(String[] args) {
    int n, m;
    scanf("%d%d", &n, &m);  // Read two integers n and m from standard input
    boolean r0[] = new boolean[n];
    for (int i = 0; i < n; i++) {
      r0[i] = false;
    }  // Initialize array r0 with false values
    int r1[] = new int[n];
    int nr1 = 0;  // Initialize array r1 and set nr1 to 0
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);  // Read pairs of integers a and b
      if (a > b) {
        int t = a;
        a = b;
        b = t;
      }  // Ensure a is less than or equal to b
      if (a == 1) r0[b - 1] = true;  // If a is 1, set r0[b-1] to true
      if (b == n) r1[nr1++] = a - 1;  // If b is n, add a-1 to r1
    }
    boolean res = false;
    for (int i = 0; i < nr1; i++) {
      if (r0[r1[i]]) res = true;  // Check if any element in r1 has a true in r0
    }
    puts(res ? "POSSIBLE" : "IMPOSSIBLE");  // Print "POSSIBLE" if res is true, otherwise print "IMPOSSIBLE"
  }
}

