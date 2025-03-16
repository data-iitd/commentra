
import java.util.*;
import java.io.*;

class s950360470 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    long mod = 1000000007L;
    long ans = mod_nCk(n, k, mod);
    System.out.println(ans);
  }

  //a^n
  static long pow(long a, long n) {
    long res = 1;
    while (n > 0) {
      if (n % 2 == 1) res *= a;
      a *= a;
      n /= 2;
    }
    return res;
  }

  //a^n % mod
  static long mod_pow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
      if (n % 2 == 1) res = res * a % mod;
      a = a * a % mod;
      n /= 2;
    }
    return res;
  }

  //a^(-1) % mod (only if : a % p!= 0)
  static long mod_inv(long a, long mod) {
    return mod_pow(a, mod - 2, mod);
  }

  //nCk % mod
  static long mod_nCk(int n, int k, long mod) {
    if (n == 0 || k == 0) return 1;
    long p = 1, q = 1;
    for (int i = n - k + 1; i <= n; i++)
      p = (p * i) % mod;
    for (int i = 2; i <= k; i++)
      q = (q * i) % mod;
    q = mod_inv(q, mod);
    return (p * q) % mod;
  }
}
