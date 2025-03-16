import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
  // Declare a BufferedReader to read input from the console
  private static BufferedReader buf;

  public static void main(String[] args) throws IOException {
    // Initialize an array to hold three integers
    int[] abc = new int[3];
    String str; // Variable to hold the input string
    String[] inp; // Array to hold the split input strings

    // Create a BufferedReader to read input from the standard input stream
    buf = new BufferedReader(new InputStreamReader(System.in));
    
    // Read a line of input from the user
    str = buf.readLine();
    
    // Split the input string by spaces and store the result in the inp array
    inp = str.split(" ", -1);
    
    // Convert the split string inputs into integers and store them in the abc array
    for (int i = 0; i < inp.length; i++) {
      abc[i] = Integer.parseInt(inp[i]);
    }
    
    // Check if the three integers are in strictly increasing order
    if (abc[0] < abc[1] && abc[1] < abc[2]) {
      // If they are in increasing order, print "Yes"
      System.out.println("Yes");
    } else {
      // If they are not in increasing order, print "No"
      System.out.println("No");
    }
  }
}
