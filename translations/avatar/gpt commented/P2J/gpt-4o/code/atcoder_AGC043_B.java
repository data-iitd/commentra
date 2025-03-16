import java.util.Scanner;

public class Main {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    public static int twosInFactorial(int n) {
        return n - Integer.bitCount(n);
    }

    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    public static boolean parityOfNCr(int n, int i) {
        int f = twosInFactorial(n); // Number of factors of 2 in n!
        int f1 = twosInFactorial(n - i); // Number of factors of 2 in (n-i)!
        int f2 = twosInFactorial(i); // Number of factors of 2 in i!
        return f - f1 - f2 > 0; // C(n, i) is odd if the number of factors of 2 in n! is greater
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer n from input
        int n = scanner.nextInt();
        // Read a list of integers, subtracting 1 from each input value
        int[] nums = new int[n];
        for (int j = 0; j < n; j++) {
            nums[j] = scanner.nextInt() - 1;
        }

        boolean noOne = false; // Flag to check if there are no '1's in the input list
        for (int num : nums) {
            if (num == 0) {
                noOne = true; // Set the flag to true if there is a '1' (which is 0 after subtraction)
                break;
            }
        }

        if (!noOne) {
            // If there are no '1's, divide each number in nums by 2
            for (int j = 0; j < nums.length; j++) {
                nums[j] /= 2;
            }
        }

        boolean isOdd = false; // Flag to track if the overall parity is odd
        for (int i = 0; i < nums.length; i++) {
            // Check the parity of C(n-1, i) and if num is odd
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) == 1) {
                isOdd ^= true; // Toggle the isOdd flag if the conditions are met
            }
        }

        // Print the result based on the parity
        if (!isOdd) {
            System.out.println(0); // If the overall parity is even, print 0
        } else {
            System.out.println(1 << (noOne ? 1 : 0)); // If odd, print 1 or 2 based on the noOne flag
        }

        scanner.close();
    }
}
// <END-OF-CODE>
