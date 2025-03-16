import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the main class
    public static void main(String[] args) { // Defining the main method
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input
        
        // Reading the number of test cases
        int n = sc.nextInt(); // Reading the first integer from the user input

        int maxv = Integer.MIN_VALUE; // Initializing max value to the minimum possible integer value
        int minv = sc.nextInt(); // Reading the second integer from the user input and assigning it to min value

        // Iterating through the test cases
        for (int i = 1; i < n; i++) { // Iterating from 1 to n-1
            int ri = sc.nextInt(); // Reading the next integer from the user input and assigning it to ri

            // Updating max and min values
            maxv = Math.max(maxv, ri - minv); // Finding the maximum difference between ri and minv
            minv = Math.min(minv, ri); // Finding the minimum value among all ri
        }

        // Printing the result
        System.out.println(maxv); // Printing the maximum difference found

        sc.close(); // Closing the Scanner object
    }
}
