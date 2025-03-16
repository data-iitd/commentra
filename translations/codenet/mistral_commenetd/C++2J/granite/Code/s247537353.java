
import java.util.*;
import java.io.*;

class s247537353 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int K = sc.nextInt();

    if (A + B >= K) {
      System.out.println(Math.min(A, K));
    } else {
      System.out.println(A - (K - (A + B)));
    }
  }
}

// 