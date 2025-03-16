import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static int twosInFactorial(int n) {
        // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
        return n - Integer.bitCount(n);
    }

    public static boolean parityOfNCR(int n, int i) {
        // Reference to the function that calculates the number of factors of 2
        int f = twosInFactorial(n) - twosInFactorial(n - i) - twosInFactorial(i);
        // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
        return f > 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read an integer n from input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        // Read a list of integers, subtracting 1 from each input value
        String[] input = scanner.nextLine().split(" ");
        List<Integer> nums = new ArrayList<>();
        for (String s : input) {
            nums.add(Integer.parseInt(s) - 1);
        }

        boolean noOne = nums.stream().noneMatch(x -> x == 1);
        if (noOne) {
            // If there are no '1's, divide each number in nums by 2
            nums.replaceAll(num -> num / 2);
        }

        boolean isOdd = false;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums.get(i);
            // Check the parity of C(n-1, i) and if num is odd
            if (!parityOfNCR(n - 1, i) && (num & 1) == 1) {
                isOdd ^= true; // Toggle the is_odd flag if the conditions are met
            }
        }

        // Print the result based on the parity
        if (!isOdd) {
            System.out.println(0); // If the overall parity is even, print 0
        } else {
            System.out.println(1 << (noOne ? 1 : 0)); // If odd, print 1 or 2 based on the no_one flag
        }
    }
}
