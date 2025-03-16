package main;

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Input in = new Input(System.in);
    int n = in.nextInt();
    int[] s = in.nextIntArray();
    boolean[] u = new boolean[n];
    long m = 0,f = 0;
    for (int c=1;c<n-1;c++) {
      f = 0;
      for (int k=0;c<n-1-k*c;k++) {
        u[k*c] = true;
        if (u[n-1-k*c]) break;
        f += s[n-1-k*c]+s[k*c];
        if (m < f) m = f;
      }
      for (int k=0;k*c<n-1;k++) u[k*c] = false;
    }
    System.out.println(m);
  }
}

class Input {
  BufferedReader reader;
  StringTokenizer tokenizer;
  public Input(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream),1000000);
    tokenizer = null;
  }
  public String next() {
    while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
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
  public String[] nextStringArray() {
    return next().split(" ");
  }
  public int[] nextIntArray() {
    String[] strings = nextStringArray();
    int[] ans = new int[strings.length];
    for (int i=0;i<ans.length;i++) {
      ans[i] = Integer.parseInt(strings[i]);
    }
    return ans;
  }
  public long[] nextLongArray() {
    String[] strings = nextStringArray();
    long[] ans = new long[strings.length];
    for (int i=0;i<ans.length;i++) {
      ans[i] = Long.parseLong(strings[i]);
    }
    return ans;
  }
  public double[] nextDoubleArray() {
    String[] strings = nextStringArray();
    double[] ans = new double[strings.length];
    for (int i=0;i<ans.length;i++) {
      ans[i] = Double.parseDouble(strings[i]);
    }
    return ans;
  }
}

