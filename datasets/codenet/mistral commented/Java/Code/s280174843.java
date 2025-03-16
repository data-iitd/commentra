
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
  // Declare a BufferedReader object to read input from the console
  private static BufferedReader buf;

  public static void main(String[] args) throws IOException {
    // Initialize an integer array 'abc' of size 3
    int[] abc = new int[3];

    // Declare a String variable 'str' to store a line of input
    String str;

    // Declare a String array 'inp' to store the split parts of the input string
    String[] inp;

    // Initialize the BufferedReader object with System.in as the input source
    buf = new BufferedReader(new InputStreamReader(System.in));

    // Read a line of input from the console and store it in the 'str' variable
    str = buf.readLine();

    // Split the input string using a space as the delimiter and store the parts in the 'inp' array
    inp = str.split(" ", -1);

    // Iterate through the 'inp' array and assign each element to the corresponding index in the 'abc' array
    for (int i = 0; i < inp.length; i++) {
      abc[i] = Integer.parseInt(inp[i]);
    }

    // Check if the first element of the 'abc' array is less than the second element
    if (abc[0] < abc[1]) {
      // Check if the second element of the 'abc' array is less than the third element
      if (abc[1] < abc[2]) {
        // If both conditions are true, print "Yes" to the console
        System.out.println("Yes");
      }
    } else {
      // If the first condition is false, print "No" to the console
      System.out.println("No");
    }
  }
}