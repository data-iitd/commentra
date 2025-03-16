
import java.io.PrintWriter; // Import the PrintWriter class for writing to the console
import java.util.*; // Import the util package for collections
import java.util.stream.Collectors; // Import the Collectors class for collecting stream results

public class Main {

  // Main method is the entry point of the Java application
  public static void main(String[] args) {
    try { // Begin try block to handle exceptions
      Scanner in = new Scanner(System.in); // Create a Scanner object for reading input
      PrintWriter out = new PrintWriter(System.out); // Create a PrintWriter object for writing output

      // Read the number of elements in the list from the user input
      int n = in.nextInt();

      // Create an ArrayList to store the unique and sorted list elements
      List<Integer> a = new ArrayList<>();
      for (int i = 0; i < n; i++) { // Iterate through the input elements
        int value = in.nextInt(); // Read the next input value
        a.add(value); // Add the value to the ArrayList
      }

      // Filter and sort the ArrayList using Java Stream API
      a = a.stream() // Stream of ArrayList elements
          .distinct() // Distinct elements
          .sorted() // Sorted elements
          .collect(Collectors.toList()); // Collect the stream result into a List

      // Check if there exists a sequence of three consecutive elements with a difference of 1
      boolean found = false;
      for (int i = 0; i < a.size(); i++) { // Iterate through the ArrayList elements
        if (i + 1 < a.size() && i + 2 < a.size()) { // Check if the next and next-next elements exist
          if (a.get(i) + 1 == a.get(i + 1) && a.get(i + 1) + 1 == a.get(i + 2)) { // Check if the difference is 1
            found = true; // Set the found flag if a sequence is found
            break; // Exit the loop if a sequence is found
          }
        }
      }

      // Write the output to the console
      out.println(found ? "YES" : "NO");

    } finally { // End try block, execute the finally block to close the input and output streams
      in.close();
      out.close();
    }
  }
}