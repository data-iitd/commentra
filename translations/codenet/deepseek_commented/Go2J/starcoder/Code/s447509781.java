
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Input in = new Input(System.in);
    int n = in.nextInt();
    int[] s = in.nextIntArray();
    long m = 0;
    for (int c=1;c<n-1;c++) {
      long f = 0;
      for (int k=0;c<n-1-k*c;k++) {
        if (k*c==n-1-k*c) {
          f += s[n-1-k*c]+s[k*c];
          if (m < f) { m = f; }
          break;
        }
        f += s[n-1-k*c]+s[k*c];
        if (m < f) { m = f; }
      }
    }
    System.out.println(m);
  }
}

class Input {
  BufferedReader reader;
  StringTokenizer tokenizer;
  public Input(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream),1000000);
    tokenizer = new StringTokenizer("");
  }
  public String next() {
    while (!tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }
  public int nextInt() {
    return Integer.parseInt(next());
  }
  public long nextLong() {
    return Long.parseLong(next());
  }
  public double nextDouble() {
    return Double.parseDouble(next());
  }
  public String nextLine() {
    try {
      return reader.readLine();
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }
  public int[] nextIntArray() {
    return nextIntArr(nextInt());
  }
  public int[] nextIntArr(int n) {
    int[] a = new int[n];
    for (int i=0;i<n;i++) { a[i] = nextInt(); }
    return a;
  }
  public long[] nextLongArray() {
    return nextLongArr(nextLong());
  }
  public long[] nextLongArr(long n) {
    long[] a = new long[(int)n];
    for (int i=0;i<n;i++) { a[i] = nextLong(); }
    return a;
  }
  public double[] nextDoubleArray() {
    return nextDoubleArr(nextDouble());
  }
  public double[] nextDoubleArr(double n) {
    double[] a = new double[(int)n];
    for (int i=0;i<n;i++) { a[i] = nextDouble(); }
    return a;
  }
}

