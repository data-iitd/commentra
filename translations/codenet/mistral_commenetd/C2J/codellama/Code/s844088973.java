
import java.util.Scanner; // Import the Scanner class

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main function
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from the standard input
    int K = sc.nextInt(); // Read an integer from the standard input and store it in the variable K
    int X = sc.nextInt(); // Read an integer from the standard input and store it in the variable X

    for(int i=X-K+1;i<=X+K-1;i++){ // Start of the for loop
      System.out.print(i); // Print the current value of i to the standard output
      if(i<X+K-1) System.out.print(" "); // If the current value of i is less than X+K-1, print a space before the number
    }

    System.out.println(); // Print a newline character to move the cursor to the next line
  } // End of the main function
} // End of the Main class
