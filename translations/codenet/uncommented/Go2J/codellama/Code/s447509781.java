
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Input {
  private BufferedReader reader;
  private StringTokenizer tokenizer;

  public Input() {
    reader = new BufferedReader(new InputStreamReader(System.in));
    tokenizer = new StringTokenizer("");
  }

  public String nextLine() throws IOException {
    tokenizer = new StringTokenizer(reader.readLine());
    return tokenizer.nextToken();
  }

  public int nextInt() throws IOException {
    return Integer.parseInt(nextLine());
  }

  public long[] nextIntArray() throws IOException {
    String[] s = nextLine().split(" ");
    long[] a = new long[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Long.parseLong(s[i]);
    }
    return a;
  }
}

public class Main {
  public static void main(String[] args) throws IOException {
    Input input = new Input();
    int n = input.nextInt();
    long[] s = input.nextIntArray();
    boolean[] u = new boolean[n];
    long m = 0, f = 0;
    for (int c = 1; c < n - 1; c++) {
      f = 0;
      for (int k = 0; c < n - 1 - k * c; k++) {
        u[k * c] = true;
        if (u[n - 1 - k * c]) {
          break;
        }
        f += s[n - 1 - k * c] + s[k * c];
        if (m < f) {
          m = f;
        }
      }
      for (int k = 0; k * c < n - 1; k++) {
        u[k * c] = false;
      }
    }
    System.out.println(m);
  }
}

