
import java.util.Scanner; // Importing Scanner class for user input
import java.util.regex.Pattern; // Importing Pattern class for regular expression
import java.util.regex.Matcher; // Importing Matcher class for pattern matching

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in); // Creating a Scanner object for user input

    int[] num = new int[in.nextInt()]; // Creating an integer array of size user input

    // Initializing the array with numbers from 1 to its size
    for (int i = 0; i < num.length; i++) {
      num[i] = i + 1;
    }

    int count = in.nextInt(); // Reading the number of swap operations from user input

    Pattern pt = Pattern.compile("(\\d+),(\\d+)"); // Compiling a regular expression pattern for reading swap operations

    int line[] = new int[2]; // Creating an integer array of size 2 to store swap indices

    // Swapping elements in the array based on user input
    for (int i = 0; i < count; i++) {
      String next = in.nextLine(); // Reading a line of user input as a String
      String[] parts = next.split(","); // Splitting the line into two parts using comma as delimiter

      // Validating user input and storing swap indices in the array
      if (parts.length == 2 && isValidInput(parts)) {
        line[0] = Integer.parseInt(parts[0]) - 1;
        line[1] = Integer.parseInt(parts[1]) - 1;
      } else {
        System.out.println("Invalid input. Please enter numbers separated by a comma.");
        i--; // Decrementing the loop counter to handle the invalid input again
        continue;
      }

      int change = num[line[0]]; // Storing the number to be swapped out
      num[line[0]] = num[line[1]]; // Swapping the numbers at the given indices
      num[line[1]] = change; // Swapping the numbers back to their original positions for display
    }

    // Printing the swapped numbers in the array
    for (int i = 0; i < num.length; i++) {
      System.out.println(num[i]);
    }
  }

  // Helper method to validate user input
  private static boolean isValidInput(String[] parts) {
    for (String part : parts) {
      try {
        Integer.parseInt(part);
      } catch (NumberFormatException e) {
        return false;
      }
    }
    return true;
  }
}