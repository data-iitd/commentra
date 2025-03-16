import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long n = in.nextLong();
    long[] a = new long[n];
    long[] count = new long[n];

    for (long i = 1; i < n; i++)
      a[i] = in.nextLong();

    for (long i = 0; i < n; i++)
      count[i] = 0;

    for (long i = 1; i < n; i++)
      count[a[i]-1]++;

    for (long i = 0; i < n; i++)
      System.out.println(count[i]);
  }
}
