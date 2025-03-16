import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

// Importing necessary classes for input and output operations
class Main {
  private static BufferedReader buf;

  // Declaring a static BufferedReader object to read input
  public static void main(String[] args) throws IOException {
    int[] abc = new int[3];
    String str;
    String[] inp;

    // Declaring an array to hold three integers and variables to hold input and split input
    buf = new BufferedReader(new InputStreamReader(System.in));

    // Initializing the BufferedReader to read from the standard input stream
    str = buf.readLine();

    // Reading a line of input from the user and storing it in str
    inp = str.split(" ", -1);

    // Splitting the input string by space and storing the parts in inp
    for (int i = 0; i < inp.length; i++) abc[i] = Integer.parseInt(inp[i]);

    // Converting each string in the split input to an integer and storing them in the abc array
    if (abc[0] < abc[1] && abc[1] < abc[2]) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

    // Checking if the first element is less than the second and the second is less than the third
    // Printing "Yes" if the condition is true, otherwise printing "No"
  }
}
