import java.util.Scanner; // Import the Scanner class for input and output operations
import java.util.Arrays; // Import the Arrays class for sorting functions

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input
        int n = sc.nextInt(); // Read the value of n from the standard input
        int a = sc.nextInt(); // Read the value of a from the standard input
        int sum = 0; // Initialize a variable to store the sum of the last 'a' elements
        int[] s = new int[n]; // Declare an array to store the elements
        for (int i = 0; i < n; i++) { // Loop to read 'n' elements into the array 's'
            s[i] = sc.nextInt(); // Read the elements from the standard input
        }
        Arrays.sort(s); // Sort the array 's' in ascending order
        for (int i = n - 1; i > n - a - 1; i--) { // Loop to calculate the sum of the last 'a' elements
            sum += s[i]; // Add the value of the current element to the sum
        }
        System.out.println(sum); // Print the calculated sum to the standard output
        sc.close(); // Close the Scanner object
    }
}
