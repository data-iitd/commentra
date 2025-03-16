import java.util.Scanner;

public class Main {
    // Calculate the number of factors of 2 in the factorial of n
    public static int twosInFactorial(int n) {
        return n - Integer.bitCount(n);
    }

    // Determine the parity (odd or even) of the binomial coefficient nCr
    public static boolean parityOfNCr(int n, int i) {
        int f = twosInFactorial(n);
        return f - twosInFactorial(n - i) - twosInFactorial(i) > 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer n
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read a list of integers from the input
        String[] input = scanner.nextLine().split(" ");
        int[] nums = new int[input.length];
        for (int j = 0; j < input.length; j++) {
            nums[j] = Integer.parseInt(input[j]) - 1;
        }
        
        // If the list does not contain the number 1, halve each number in the list and set no_one to true
        boolean noOne = false;
        boolean containsOne = false;
        for (int num : nums) {
            if (num == 1) {
                containsOne = true;
                break;
            }
        }
        
        if (!containsOne) {
            for (int j = 0; j < nums.length; j++) {
                nums[j] /= 2;
            }
            noOne = true;
        }
        
        // Initialize isOdd to false
        boolean isOdd = false;
        
        // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
        for (int i = 0; i < nums.length; i++) {
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) == 1) {
                isOdd ^= true;
            }
        }
        
        // If isOdd is false, print 0; otherwise, print 1 << noOne (which is equivalent to 2 ** noOne)
        if (!isOdd) {
            System.out.println(0);
        } else {
            System.out.println(1 << (noOne ? 1 : 0));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
