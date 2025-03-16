import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        
        String s = scanner.next(); // Get the input day as a string.
        int index = -1;
        
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i; // Set the index of the day found in the week array.
                break;
            }
        }

        System.out.println(7 - index); // Print the number of days until Sunday.
    }

    // Function to return the absolute value of an integer.
    public static int abs(int a) {
        return Math.abs(a);
    }

    // Function to return the result of raising the first argument to the power of the second argument.
    public static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Function to return the smallest integer from a list of integers.
    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Function to return the largest integer from a list of integers.
    public static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Function to check if a string is present in a list of strings.
    public static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    // Function to print an array of integers in a specific format.
    public static void printIntArray(int[] array) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        System.out.println(sb.toString());
    }

    // Function to return the modulo of an integer with respect to MOD.
    public static int calcMod(int x) {
        return x % MOD;
    }
}

// <END-OF-CODE>
