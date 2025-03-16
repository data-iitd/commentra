import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

class Main {

  // Solver class to handle the main logic of the problem
  static class Solver {
    final FastScanner sc; // Scanner for input
    final PrintWriter writer; // Writer for output

    // Constructor to initialize the scanner and writer
    Solver(final FastScanner sc, final PrintWriter writer) {
      this.sc = sc;
      this.writer = writer;
    }

    // Variables to store input sizes and results
    int n, m, q;
    int max = 0; // Variable to track the maximum score
    int[] a, b, c, d; // Arrays to store input values

    // Main method to run the solver logic
    void run() {
      // Read the sizes of n, m, and q
      n = sc.nextInt();
      m = sc.nextInt();
      q = sc.nextInt();
      // Initialize arrays to hold the input values
      a = new int[q];
      b = new int[q];
      c = new int[q];
      d = new int[q];
      // Read the input values into the arrays
      for (int i = 0; i < q; i++) {
        a[i] = sc.nextInt();
        b[i] = sc.nextInt();
        c[i] = sc.nextInt();
        d[i] = sc.nextInt();
      }
      // Start the depth-first search with an initial array
      dfs(new int[] { 1 });
      // Output the maximum score found
      writer.println(max);
    }

    // Depth-first search method to explore possible combinations
    private void dfs(int[] array) {
      // Base case: if the array length exceeds n
      if (array.length > n) {
        int score = 0; // Variable to calculate the score
        // Calculate the score based on the conditions provided
        for (int i = 0; i < q; i++) {
          if (array[b[i]] - array[a[i]] == c[i]) {
            score += d[i]; // Add to score if condition is met
          }
        }
        // Update the maximum score found
        max = Math.max(max, score);
        return; // Exit the method
      }

      // Create a new array to append the next item
      int[] newArray = new int[array.length + 1];
      System.arraycopy(array, 0, newArray, 0, array.length);
      System.arraycopy(new int[] { array[array.length - 1] }, 0, newArray, array.length, 1);

      // Incrementally explore values for the last element of the new array
      while (newArray[newArray.length - 1] <= m) {
        dfs(newArray); // Recursive call to explore further
        newArray[newArray.length - 1] += 1; // Increment the last element
      }
    }
  }

  // Main method to execute the program
  public static void main(final String[] args) {
    final FastScanner sc = new FastScanner(); // Initialize the scanner
    try (final PrintWriter w = new PrintWriter(System.out)) { // Initialize the writer
      new Solver(sc, w).run(); // Run the solver
      w.flush(); // Flush the output
    }
  }

  // FastScanner class for efficient input reading
  static class FastScanner {
    private final InputStream in = System.in; // Input stream
    private final byte[] buffer = new byte[1024]; // Buffer for reading input
    private int ptr = 0; // Pointer for current position in buffer
    private int buflen = 0; // Length of the buffer

    // Constructor for FastScanner
    public FastScanner() {
    }

    // Check if there is a next byte available in the input
    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true; // Return true if there are bytes left
      } else {
        ptr = 0; // Reset pointer
        try {
          buflen = in.read(buffer); // Read new bytes into buffer
        } catch (final IOException e) {
          e.printStackTrace(); // Handle IO exceptions
        }
        if (buflen <= 0) {
          return false; // Return false if no bytes read
        }
      }
      return true; // Return true if bytes are available
    }

    // Read the next byte from the input
    private int readByte() {
      if (hasNextByte())
        return buffer[ptr++]; // Return the next byte
      else
        return -1; // Return -1 if no bytes are available
    }

    // Check if the character is printable
    private boolean isPrintableChar(final int c) {
      return 33 <= c && c <= 126; // ASCII range for printable characters
    }

    // Check if there is a next printable character
    public boolean hasNext() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr]))
        ptr++; // Skip non-printable characters
      return hasNextByte(); // Return if there is a next printable character
    }

    // Read the next string from the input
    public String next() {
      if (!hasNext())
        throw new NoSuchElementException(); // Throw exception if no next element
      final StringBuilder sb = new StringBuilder(); // StringBuilder for constructing the string
      int b = readByte(); // Read the first byte
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b); // Append printable characters to the StringBuilder
        b = readByte(); // Read the next byte
      }
      return sb.toString(); // Return the constructed string
    }

    // Read the next long integer from the input
    public long nextLong() {
      if (!hasNext())
        throw new NoSuchElementException(); // Throw exception if no next element
      long n = 0; // Variable to store the long value
      boolean minus = false; // Flag for negative numbers
      int b = readByte(); // Read the first byte
      if (b == '-') {
        minus = true; // Set flag if negative
        b = readByte(); // Read the next byte
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException(); // Throw exception if not a valid number
      }
      // Construct the long value from the bytes
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10; // Shift left
          n += b - '0'; // Add the digit
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n; // Return the value with sign
        } else {
          throw new NumberFormatException(); // Throw exception for invalid number
        }
        b = readByte(); // Read the next byte
      }
    }

    // Read the next integer from the input
    public int nextInt() {
      final long nl = nextLong(); // Read long and cast to int
      if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
        throw new NumberFormatException(); // Check for integer overflow
      return (int) nl; // Return the integer value
    }

    // Read the next double from the input
    public double nextDouble() {
      return Double.parseDouble(next()); // Parse and return the double value
    }

    // Read an array of integers from the input
    public int[] nextIntArray(final int n) {
      final int[] a = new int[n]; // Create an array of size n
      for (int i = 0; i < n; i++)
        a[i] = nextInt(); // Fill the array with integers
      return a; // Return the array
    }

    // Read an array of long integers from the input
    public long[] nextLongArray(final int n) {
      final long[] a = new long[n]; // Create an array of size n
      for (int i = 0; i < n; i++)
        a[i] = nextLong(); // Fill the array with long integers
      return a; // Return the array
    }
  }
}
