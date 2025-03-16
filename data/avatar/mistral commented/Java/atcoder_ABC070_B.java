
import java.io.BufferedReader; // For reading input from standard input
import java.io.IOException;
import java.io.InputStream; // For getting input stream
import java.io.InputStreamReader; // For reading input from input stream
import java.io.OutputStream; // For writing output to standard output
import java.io.PrintWriter; // For writing output
import java.util.ArrayList; // For creating dynamic arrays (Lists) of integers
import java.util.Arrays; // For using predefined functions like Arrays.sort()
import java.util.Collections; // For using predefined functions like Collections.sort()
import java.util.HashSet; // For creating a HashSet
import java.util.List; // For creating dynamic arrays (Lists) of any type
import java.util.Set; // For creating a Set
import java.util.StringTokenizer; // For parsing input strings into tokens

public class Main {

 // Main method is the entry point of the Java application
  public static void main(String[] args) {

    // Initialize input and output streams
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;

    // Create InputReader and PrintWriter objects
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);

    // Read input integers a, b, c, and d
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    int d = in.nextInt();

    // Check if c is greater than b
    if (c > b) {
      // If yes, print 0 and exit
      out.println(0);
      return;
    }

    // Check if a is greater than d
    else if (a > d) {
      // If yes, print 0 and exit
      out.println(0);
      return;
    }

    // Check if a is less than c
    else if (a < c) {
      // If yes, calculate the difference between the smaller and larger of b and d
      int difference = Math.min(b, d) - c;
      // Print the difference
      out.println(difference);
      return;
    }

    // If none of the above conditions are true, then a, b, c, and d are in sorted order
    else {
      // Create a List of integers a, b, c, and d
      List<Integer> l = new ArrayList<>();
      l.add(a);
      l.add(b);
      l.add(c);
      l.add(d);

      // Sort the List in ascending order
      Collections.sort(l);

      // Calculate the difference between the second and third elements of the List
      int difference = l.get(2) - l.get(1);

      // Print the difference
      out.println(difference);
    }
  }

  // InputReader class for reading input from standard input
  static class InputReader {

    BufferedReader reader; // For reading input from standard input
    StringTokenizer tokenizer; // For parsing input strings into tokens

    // Constructor for InputReader
    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    // Method for reading a string
    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    // Method for reading an integer
    public int nextInt() {
      return Integer.parseInt(next());
    }

    // Method for reading a long integer
    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}

