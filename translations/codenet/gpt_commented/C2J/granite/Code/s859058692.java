
import java.util.Scanner;

public class s859058692{
    public static void main(String[] args) {
        // Initialize variables to store the sum, current number, count of numbers, and min/max values
        long sum = 0; // To hold the sum of all numbers
        int m, n, i, min, max; // m: current number, n: total count of numbers, i: loop index, min: minimum value, max: maximum value

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the total number of integers to be processed
        n = scanner.nextInt();

        // Loop through each number to read and process
        for(i = 0; i < n; i++) {
            // Read the current number
            m = scanner.nextInt();
            
            // Add the current number to the sum
            sum += m;

            // Initialize min and max with the first number read
            if(i == 0) {
                min = m; // Set min to the first number
                max = m; // Set max to the first number
            }
             
            // Update min if the current number is less than the current min
            if(min > m) {
                min = m; // Update min
            }

            // Update max if the current number is greater than the current max
            if(max < m) {
                max = m; // Update max
            }
        }

        // Print the minimum, maximum, and sum of the numbers
        System.out.printf("%d %d %ld\n", min, max, sum);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
