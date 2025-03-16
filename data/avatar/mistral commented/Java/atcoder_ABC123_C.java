
import java.util.ArrayDeque; // Importing the ArrayDeque class from the java.util package
import java.util.Queue; // Importing the Queue interface and its implementation classes from the java.util package
import java.util.Random; // Importing the Random class from the java.util package
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main {

 // Creating a Scanner object to read input from the standard input stream
  private static Scanner sc = new Scanner(System.in);

  // Main method where the execution of the program starts
  public static void main(String[] args) {

    // Reading the first long integer input N
    long N = sc.nextLong();

    // Initializing the minimum long integer variable with the first input value
    long min = 0;
    for (int i = 0; i < 5; i++) {
      if (i == 0) { // If it's the first iteration of the loop
        min = sc.nextLong(); // Set the minimum value to the current input value
      } else { // Otherwise
        min = Math.min(min, sc.nextLong()); // Update the minimum value with the current input value if it's smaller
      }
    }

    // Printing the answer using the p method
    p((long)Math.ceil((double)N/min)+4);
  }

  // Utility method to print a string as output
  static void p(String ans) {
    System.out.println(ans);
  }

  // Utility method to print an integer as output
  static void p(int ans) {
    System.out.println(ans);
  }

  // Utility method to print nothing as output
  static void p() {
    System.out.println();
  }

  // Utility method to print a long integer as output
  static void p(long ans) {
    System.out.println(ans);
  }

  // Utility method to print a double as output
  static void p(double ans) {
    System.out.println(ans);
  }
}

