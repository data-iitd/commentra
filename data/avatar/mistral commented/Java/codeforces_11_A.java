
import java.util.Scanner ;

// Create a Scanner object to read input from the console
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize a Scanner object

        // Read the number of elements in the array and the difference d from the input
        int n = in.nextInt();
        int d = in.nextInt();

        // Create an integer array of size n to store the numbers
        int[] nums = new int[n];

        // Read the numbers in the array from the input
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt(); // Read the next number and store it in the array
        }

        // Initialize variables for calculating the result and the difference between two consecutive numbers
        int result = 0;
        int a = 0;

        // Iterate through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Calculate the difference between the current and previous numbers
            a = nums[i - 1] - nums[i];

            // If the difference is positive, add the number of jumps to the result and update the current number in the array
            if (a >= 0) {
                result += a / d + 1;
                nums[i] += (a / d + 1) * d;
            }
        }

        // Print the result to the console
        System.out.println(result);
    }
}