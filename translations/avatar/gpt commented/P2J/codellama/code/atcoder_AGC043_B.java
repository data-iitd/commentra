public class Main {
    public static int twosInFactorial(int n) {
        // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
        return n - Integer.bitCount(n);
    }

    public static boolean parityOfnCr(int n, int i) {
        // Determine the parity (even or odd) of the binomial coefficient C(n, i)
        int f = twosInFactorial; // Reference to the function that calculates the number of factors of 2
        // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
        return f(n) - f(n - i) - f(i) > 0;
    }

    public static void main(String[] args) {
        // Read an integer n from input
        int n = Integer.parseInt(args[0]);
        // Read a list of integers, subtracting 1 from each input value
        int[] nums = Arrays.stream(args[1].split(" ")).mapToInt(Integer::parseInt).map(i -> i - 1).toArray();

        boolean noOne = false; // Flag to check if there are no '1's in the input list
        if (Arrays.stream(nums).noneMatch(i -> i == 1)) {
            // If there are no '1's, divide each number in nums by 2
            for (int i = 0; i < nums.length; i++) {
                nums[i] /= 2;
            }
            noOne = true; // Set the flag to True since there were no '1's
        }

        boolean isOdd = false; // Flag to track if the overall parity is odd
        for (int i = 0; i < nums.length; i++) {
            // Check the parity of C(n-1, i) and if num is odd
            if (!parityOfnCr(n - 1, i) && (nums[i] & 1) == 1) {
                isOdd ^= true; // Toggle the isOdd flag if the conditions are met
            }
        }

        // Print the result based on the parity
        if (!isOdd) {
            System.out.println(0); // If the overall parity is even, print 0
        } else {
            System.out.println(1 << noOne); // If odd, print 1 or 2 based on the noOne flag
        }
    }
}
