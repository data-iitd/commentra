import java.util.Scanner;

public class Main {
    // Define a helper function 'twosInFactorial' to count the number of twos in the factorial of a given number
    public static int twosInFactorial(int n) {
        // Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
        return n - Integer.bitCount(n);
    }

    // Define a helper function 'parityOfNCR' to check if the index 'i' has odd parity in the combination 'nCr'
    public static boolean parityOfNCR(int n, int i) {
        // Use the 'twosInFactorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
        int f = twosInFactorial(n) - twosInFactorial(n - i) - twosInFactorial(i);
        // Return true if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
        return f > 0;
    }

    // Check if the input is valid and process the given problem
    public static void main(String[] args) {
        // Read the input values from the standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt() - 1;
        }
        scanner.close();

        // Initialize a flag to indicate if there is no '1' in the list of numbers
        boolean noOne = false;

        // If there is no '1' in the list of numbers, then replace each number by half of it
        boolean allOnes = true;
        for (int num : nums) {
            if (num != 0) {
                allOnes = false;
                break;
            }
        }
        if (allOnes) {
            noOne = true;
            nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = scanner.nextInt() / 2;
            }
        }

        // Initialize a flag to indicate if the result is odd
        boolean isOdd = false;

        // Iterate through each number in the list and check if it satisfies the given condition
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            // Skip the number if it doesn't satisfy the parity condition
            if (!parityOfNCR(n - 1, i) && num % 2 != 0) {
                // Toggle the 'isOdd' flag
                isOdd ^= true;
            }
        }

        // Print the result based on the value of the 'isOdd' flag
        if (!isOdd) {
            System.out.println(0);
        } else {
            // If there is no '1' in the list of numbers, then print the result with the 'noOne' flag shifted to the left
            System.out.println(1 << (noOne ? 1 : 0));
        }
    }
}
