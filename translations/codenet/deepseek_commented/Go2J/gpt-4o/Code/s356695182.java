import java.util.Scanner;

public class Main {
    
    // Reads a single integer from standard input.
    private static int nextInt(Scanner sc) {
        return sc.nextInt();
    }

    // Reads a slice of integers from standard input.
    private static int[] scanNums(Scanner sc, int len) {
        int[] nums = new int[len];
        for (int i = 0; i < len; i++) {
            nums[i] = nextInt(sc);
        }
        return nums;
    }

    // Computes a value using the first two and last two elements of the input array.
    private static int pattern1(int[] l) {
        return (l[0] * l[3]) + (l[1] * l[4]);
    }

    // Computes another value using the third element and the maximum of the last two elements.
    private static int pattern2(int[] l) {
        return 2 * l[2] * max(l[3], l[4]);
    }

    // Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
    private static int pattern3(int[] l) {
        return 2 * l[2] * min(l[3], l[4]) + doch(l);
    }

    // Returns the minimum value among the given integers.
    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Returns the maximum value among the given integers.
    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Calculates a specific value based on the input array.
    private static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            return l[1] * (l[4] - l[3]);
        }
    }

    // Main function to read input, compute the minimum value, and print it.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = 5;
        int[] l = scanNums(sc, len);
        System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
        sc.close();
    }
}

// <END-OF-CODE>
