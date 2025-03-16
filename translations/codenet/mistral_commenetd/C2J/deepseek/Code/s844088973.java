import java.util.Scanner; // Import the Scanner class to read input from the standard input stream

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main method
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the standard input stream
    int K = scanner.nextInt(); // Read an integer from the standard input and store it in variable K
    int X = scanner.nextInt(); // Read an integer from the standard input and store it in variable X

    for(int i = X - K + 1; i <= X + K - 1; i++) { // Start of the for loop
      System.out.print(i); // Print the current value of i to the standard output
      if(i < X + K - 1) System.out.print(" "); // If the current value of i is less than X+K-1, print a space before the number
    }

    System.out.println(); // Print a newline character to move the cursor to the next line
  } // End of the main method
} // End of the Main class <END-OF-CODE>