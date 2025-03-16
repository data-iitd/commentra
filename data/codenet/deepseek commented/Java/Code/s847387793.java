import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

class Main {

  // Solver class to handle the logic of the program
  static class Solver {
    // FastScanner to read input efficiently
    final FastScanner sc;
    // PrintWriter to write output
    final PrintWriter writer;

    // Constructor for Solver class
    Solver(final FastScanner sc, final PrintWriter writer) {
      this.sc = sc;
      this.writer = writer;
    }

    // Variables to store input values
    int n, m, q;
    // Variable to store the maximum score
    int max = 0;
    // Arrays to store input values a, b, c, d
    int[] a, b, c, d;

    // Main method to run the solver
    void run() {
      // Read values of n, m, q
      n = sc.nextInt();
      m = sc.nextInt();
      q = sc.nextInt();
      // Initialize arrays a, b, c, d with the size of q
      a = new int[q];
      b = new int[q];
      c = new int[q];
      d = new int[q];
      // Read values for arrays a, b, c, d
      for (int i = 0; i < q; i++) {
        a[i] = sc.nextInt();
        b[i] = sc.nextInt();
        c[i] = sc.nextInt();
        d[i] = sc.nextInt();
      }
      // Start the DFS with an initial array containing 1
      dfs(new int[] { 1 });
      // Print the maximum score
      writer.println(max);
    }

    // Depth-first search method to generate sequences and calculate scores
    private void dfs(int[] array) {
      // If the length of the array exceeds n, calculate the score and return
      if (array.length > n) {
        int score = 0;
        for (int i = 0; i < q; i++) {
          if (array[b[i]] - array[a[i]] == c[i]) {
            score += d[i];
          }
        }
        max = Math.max(max, score);
        return;
      }

      // Append an item to the existing array
      int[] newArray = new int[array.length + 1];
      System.arraycopy(array, 0, newArray, 0, array.length);
      System.arraycopy(new int[] { array[array.length - 1] }, 0, newArray, array.length, 1);

      while (newArray[newArray.length - 1] <= m) {
        dfs(newArray);
        newArray[newArray.length - 1] += 1;
      }
    }
  }

  // Main method to start the program
  public static void main(final String[] args) {
    // Initialize FastScanner and PrintWriter
    final FastScanner sc = new FastScanner();
    try (final PrintWriter w = new PrintWriter(System.out)) {
      // Create an instance of Solver and run it
      new Solver(sc, w).run();
      // Flush the PrintWriter to ensure all output is written
      w.flush();
    }
  }

  // FastScanner class to read input efficiently
  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    // Constructor for FastScanner
    public FastScanner() {
    }

    // Method to check if there is a next byte available
    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (final IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    // Method to read the next byte
    private int readByte() {
      if (hasNextByte())
        return buffer[ptr++];
      else
        return -1;
    }

    // Method to check if a character is printable
    private boolean isPrintableChar(final int c) {
      return 33 <= c && c <= 126;
    }

    // Method to check if there is a next element
    public boolean hasNext() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr]))
        ptr++;
      return hasNextByte();
    }

    // Method to read the next string
    public String next() {
      if (!hasNext())
        throw new NoSuchElementException();
      final StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    // Method to read the next long
    public long nextLong() {
      if (!hasNext())
        throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    // Method to read the next int
    public int nextInt() {
      final long nl = nextLong();
      if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
        throw new NumberFormatException();
      return (int) nl;
    }

    // Method to read the next double
    public double nextDouble() {
      return Double.parseDouble(next());
    }

    // Method to read the next int array
    public int[] nextIntArray(final int n) {
      final int[] a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = nextInt();
      return a;
    }

    // Method to read the next long array
    public long[] nextLongArray(final int n) {
      final long[] a = new long[n];
      for (int i = 0; i < n; i++)
        a[i] = nextLong();
      return a;
    }
  }
}
