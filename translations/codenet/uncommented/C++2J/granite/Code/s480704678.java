
import java.io.*;
import java.util.*;

class s480704678 {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }

  static class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      long[] a = new long[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextLong();
      }
      long[] acc = new long[n + 1];
      for (int i = 0; i < n; i++) {
        acc[i + 1] = acc[i] + a[i];
        acc[i + 1] %= 1000000007;
      }
      long ans = 0;
      for (int i = 0; i < n; i++) {
        ans += a[i] % 1000000007 * (1000000007 + acc[n] - acc[i + 1]) % 1000000007;
        ans %= 1000000007;
      }
      out.println(ans);
    }
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
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
  }
}

