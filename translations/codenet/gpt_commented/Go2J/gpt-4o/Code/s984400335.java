import java.util.Scanner;

public class Main {
    // min function takes a variable number of integer arguments and returns the minimum value among them.
    public static int min(int... nums) {
        // Initialize min with the first element of nums
        int min = nums[0];
        // Iterate over each value in nums to find the minimum
        for (int v : nums) {
            // Update min if the current value is less than the current min
            if (v < min) {
                min = v;
            }
        }
        // Return the minimum value found
        return min;
    }

    public static void main(String[] args) {
        // Declare variables to hold input values
        Scanner scanner = new Scanner(System.in);
        int n, a, b;
        // Read three integers from standard input
        n = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the minimum of n*a and b, and print the result
        System.out.println(min(n * a, b));
        scanner.close();
    }
}

// <END-OF-CODE>
