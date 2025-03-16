import java.util.*; // Importing utility classes for general utilities and input/output operations.
import java.io.*;   // Importing input/output classes for file handling.

public class Main {
    public static void main(String args[]) { // Main method, the entry point of the program.
      Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the console.

      for(int i = 0; i < 5; i++){ // Starting a for loop that runs 5 times.
          if(sc.nextInt() == 0){ // Reading an integer input and checking if it is 0.
              System.out.println(i+1); // Printing the current loop index (1-based) if the condition is true.
              break; // Exiting the loop once the condition is met.
          }
      }
    }
}
