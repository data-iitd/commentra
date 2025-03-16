#include <stdio.h>

public class Main {
  public static void main(String[] args) {
    int K, X;
    Scanner sc = new Scanner(System.in);
    K = sc.nextInt();
    X = sc.nextInt();
    for (int i = X - K + 1; i <= X + K - 1; i++) {
      System.out.print(i);
      if (i < X + K - 1) System.out.print(" ");
    }
    System.out.println();
  }
}

