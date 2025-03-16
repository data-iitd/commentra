
import java.util.*;

public class Main {
  // The split method calculates the sum of the remainders when n is divided by k repeatedly.
  // This is used to determine the sum of digits in base k.
  private static long split(long n, long k) {
    long sum = 0;
    while (n > 0) {
      sum += n % k;
      n /= k;
    }
    return sum;
  }

  // The solve method finds the smallest base k such that the sum of the digits of n in base k equals s.
  private static long solve(long n, long s) {
    long k;
    // Check for bases from 2 up to the square root of n or up to 100, whichever is smaller.
    for (k = 2; k*k <= n || k < 100; k++) {
      if (split(n, k) == s) {
        return k;
      }
    }
    // If no base is found within the range, use a different approach to find the smallest base k.
    while (k <= n) {
      long a = n / k;
      long b = n % k;
      if ((a + b - s) % a == 0) {
        long dk = (a + b - s) / a;
        if (dk >= 0 && b - dk*a >= 0) {
          return k + dk;
        }
      }
      k = n / a + 1;
    }
    // If n equals s, then the smallest base k is n+1.
    if (n == s) {
      return n+1;
    }
    // If no base k is found, return -1.
    return -1;
  }

  // The main method reads input values for n and s, and prints the result of the solve method.
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    long nl = s.nextLong();
    long sl = s.nextLong();
    System.out.println(solve(nl, sl));
  }
}

