import java.util.*;

public class Main {
    // Setting the recursion limit to a high value to allow deep recursion
    static {
        System.setProperty("java.lang.Integer.MAX_VALUE", "1000000000");
    }

    // Defining constants for infinity, epsilon, and a modulus value
    static final long inf = (long) 1e20;
    static final double eps = 1.0 / 10e10;
    static final long mod = (long) 1e9 + 7;

    // Defining direction vectors for 4-way and 8-way movement
    static final int[][] dd = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static final int[][] ddn = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    // Function to read a line of integers from input
    static int[] LI() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }
        return result;
    }

    // Function to read a line of integers from input and convert them to zero-based index
    static int[] LI_() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]) - 1;
        }
        return result;
    }

    // Function to read a line of floats from input
    static double[] LF() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        double[] result = new double[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Double.parseDouble(tokens[i]);
        }
        return result;
    }

    // Function to read a line of strings from input
    static String[] LS() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine().split(" ");
    }

    // Function to read a single integer from input
    static int I() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single float from input
    static double F() {
        Scanner scanner = new Scanner(System.in);
        return Double.parseDouble(scanner.nextLine());
    }

    // Function to read a single string from input
    static String S() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to print a string and flush the output buffer
    static void pf(String s) {
        System.out.println(s);
        System.out.flush();
    }

    // Main function to process the input and return the result
    public static void main(String[] args) {
        // Reading a string from input
        String s = S();
        // Reading an integer k from input
        int k = I();
        int l = 0;  // Initialize a counter for leading '1's

        // Count the number of leading '1's in the string
        for (char c : s.toCharArray()) {
            if (c != '1') {
                break;
            }
            l++;
        }

        // If the count of leading '1's is greater than or equal to k, return 1
        if (l >= k) {
            System.out.println(1);
        } else {
            // Otherwise, return the character at position l in the string
            System.out.println(s.charAt(l));
        }
    }
}
