import java.util.Scanner;

public class Main {
    
    // Define a helper function 'twosInFactorial' to count the number of twos in the factorial of a given number
    public static int twosInFactorial(int n) {
        // Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
        return n - Integer.bitCount(n);
    }

    // Define a helper function 'parityOfNCr' to check if the index 'i' has odd parity in the combination 'nCr'
    public static boolean parityOfNCr(int n, int i) {
        // Use the 'twosInFactorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
        int f = twosInFactorial(n);
        return f - twosInFactorial(n - i) - twosInFactorial(i) > 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input values
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int j = 0; j < n; j++) {
            nums[j] = scanner.nextInt() - 1;
        }
        
        // Initialize a flag to indicate if there is no '1' in the list of numbers
        boolean noOne = false;
        
        // If there is no '1' in the list of numbers, then replace each number by half of it
        boolean foundOne = false;
        for (int num : nums) {
            if (num == 1) {
                foundOne = true;
                break;
            }
        }
        
        if (!foundOne) {
            for (int j = 0; j < nums.length; j++) {
                nums[j] /= 2;
            }
            noOne = true;
        }
        
        // Initialize a flag to indicate if the result is odd
        boolean isOdd = false;
        
        // Iterate through each number in the list and check if it satisfies the given condition
        for (int i = 0; i < nums.length; i++) {
            // Skip the number if it doesn't satisfy the parity condition
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) == 1) {
                // Toggle the 'isOdd' flag
                isOdd = !isOdd;
            }
        }
        
        // Print the result based on the value of the 'isOdd' flag
        if (!isOdd) {
            System.out.println(0);
        } else {
            // If there is no '1' in the list of numbers, then print the result with the 'noOne' flag shifted to the left
            System.out.println(1 << (noOne ? 1 : 0));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
