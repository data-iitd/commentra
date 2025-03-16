
import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    long[] acc = new long[n + 1];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
      acc[i + 1] = acc[i] + a[i];
      acc[i + 1] %= MOD;
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD;
      ans %= MOD;
    }
    System.out.println(ans);
  }
}

