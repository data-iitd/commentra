import java.util.Scanner;

public class Main {
    // min finds the smallest number among the given arguments
    public static int min(int... nums) {
        int min = nums[0]; // Initialize min with the first element
        for (int v : nums) {
            if (v < min) { // Compare each element with the current min
                min = v; // Update min if a smaller value is found
            }
        }
        return min; // Return the smallest value
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt(); // Read three integers from input

        System.out.println(min(n * a, b)); // Print the minimum of n*a and b
        scanner.close();
    }
}

// <END-OF-CODE>
