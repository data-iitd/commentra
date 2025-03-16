
import java.util.Scanner ;

// Create a new Scanner object to read input from the console
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Initialize the Scanner object

        // Read the number of test cases from the input
        int t = scan.nextInt();

        // Iterate through each test case
        for (int i = 0; i < t; i++) {
            int n = scan.nextInt(); // Read the number of elements in the array

            // Print the maximum left sum
            System.out.println(maxLeft(n));
        }

        // Close the Scanner object to free up system resources
        scan.close();
    }

    // Function to calculate the maximum sum of elements to the left of a given index
    public static int maxLeft(int n) {
        // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
        return n > 2 ? n - 2 : 0;
    }
}