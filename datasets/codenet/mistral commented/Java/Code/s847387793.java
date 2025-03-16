import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

class Main {

  static class Solver {
    // Declare the inner class Solver with its constructor, instance variables, and methods

    final FastScanner sc;
    final PrintWriter writer;

    Solver(final FastScanner sc, final PrintWriter writer) {
      this.sc = sc;
      this.writer = writer;
    }

    int n, m, q;
    int max = 0;
    int[] a, b, c, d;

    void run() {
      // Initialize the instance variables and read input
      n = sc.nextInt();
      m = sc.nextInt();
      q = sc.nextInt();
      a = new int[q];
      b = new int[q];
      c = new int[q];
      d = new int[q];

      // Read q queries and store them in arrays a, b, c, and d
      for (int i = 0; i < q; i++) {
        a[i] = sc.nextInt();
        b[i] = sc.nextInt();
        c[i] = sc.nextInt();
        d[i] = sc.nextInt();
      }

      // Call the recursive method dfs with an initial empty array
      dfs(new int[] {});

      // Print the maximum score
      writer.println(max);
    }

    private void dfs(int[] array) {
      // Base case: if the length of the array is greater than n, calculate the score and return
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

      // Recursive case: append an item to the existing array and perform a depth-first search
      int[] newArray = new int[array.length + 1];
      System.arraycopy(array, 0, newArray, 0, array.length);
      System.arraycopy(new int[] { array[array.length - 1] }, 0, newArray, array.length, 1);

      // Continue the depth-first search with the new array until it exceeds m
      while (newArray[newArray.length - 1] <= m) {
        dfs(newArray);
        newArray[newArray.length - 1] += 1;
      }
    }
  }

  public static void main(final String[] args) {
    // Initialize the FastScanner and PrintWriter objects and call the Solver constructor with them
    final FastScanner sc = new FastScanner();
    try (final PrintWriter w = new PrintWriter(System.out)) {
      new Solver(sc, w).run();
      w.flush();
    }
  }

  // FastScanner class with its methods and instance variables
  static class FastScanner {
    // Declare the inner class FastScanner with its constructor, instance variables, and methods

    private final InputStream in;
    private final byte[] buffer;
    private int ptr;
    private int buflen;

    public FastScanner() {
      this.in = System.in;
      this.buffer = new byte[1024];
    }

    private boolean hasNextByte() {
      // Check if there is a byte left in the buffer or if more data needs to be read
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

    private int readByte() {
      // Read a byte from the buffer if available or return -1 if not
      if (hasNextByte())
        return buffer[ptr++];
      else
        return -1;
    }

    private boolean isPrintableChar(final int c) {
      // Check if a character is printable (ASCII range 33-126)
      return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
      // Read bytes until a printable character is found or the end of the input is reached
      while (hasNextByte() && !isPrintableChar(buffer[ptr]))
        ptr++;
      return hasNextByte();
    }

    public String next() {
      // Read and store a sequence of printable characters as a String
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

    public long nextLong() {
      // Read and parse a long integer from the input
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

    public int nextInt() {
      // Read and parse an integer from the input
      final long nl = nextLong();
      if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
        throw new NumberFormatException();
      return (int) nl;
    }

    public double nextDouble() {
      // Read and parse a double from the input
      return Double.parseDouble(next());
    }

    public int[] nextIntArray(final int n) {
      // Read and store n integers as an array
      final int[] a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = nextInt();
      return a;
    }

    public long[] nextLongArray(final int n) {
      // Read and store n long integers as an array
      final long[] a = new long[n];
      for (int i = 0; i < n; i++)
        a[i] = nextLong();
      return a;
    }
  }
}
