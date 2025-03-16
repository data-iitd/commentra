

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class s447509781{
  public static void main(String[] args) throws IOException {
    Input input = new Input(new BufferedReader(new InputStreamReader(System.in)));
    int n = input.nextInt();
    int[] s = input.nextIntArray();
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

class Input {
  private BufferedReader reader;
  private StringTokenizer tokenizer;

  public Input(BufferedReader reader) {
    this.reader = reader;
    tokenizer = new StringTokenizer("");
  }

  public String nextLine() throws IOException {
    return reader.readLine();
  }

  public int nextInt() throws IOException {
    return Integer.parseInt(nextLine());
  }

  public int[] nextIntArray() throws IOException {
    String[] s = nextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }
}

