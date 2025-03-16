package main;

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Input in = new Input(System.in);
    int n = in.nextInt();
    int[] s = in.nextIntArray();
    long m = 0;
    for (int c = 1; c < n-1; c++) {
      long f = 0;
      boolean[] u = new boolean[n];
      for (int k = 0; c < n-1-k*c; k++) {
        u[k*c] = true;
        if (u[n-1-k*c]) { break; }
        f += s[n-1-k*c] + s[k*c];
        if (m < f) { m = f; }
      }
      for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
    }
    System.out.println(m);
  }
}

// Input class to handle reading from standard input
class Input {
  BufferedReader reader;
  StringTokenizer tokenizer;

  public Input(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 1000000);
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
    int[] ints = new int[strings.length];
    for (int i = 0; i < strings.length; i++) {
      ints[i] = Integer.parseInt(strings[i]);
    }
    return ints;
  }

  public long[] nextLongArray() {
    String[] strings = nextStringArray();
    long[] longs = new long[strings.length];
    for (int i = 0; i < strings.length; i++) {
      longs[i] = Long.parseLong(strings[i]);
    }
    return longs;
  }

  public double[] nextDoubleArray() {
    String[] strings = nextStringArray();
    double[] doubles = new double[strings.length];
    for (int i = 0; i < strings.length; i++) {
      doubles[i] = Double.parseDouble(strings[i]);
    }
    return doubles;
  }
}

