import java.util.*;

public class Main {
    // Setting recursion limit for the program
    static {
        System.setProperty("java.security.egd", "file:/dev/./urandom");
        System.setSecurityManager(new SecurityManager());
    }

    // Defining constants
    static final long inf = 10L * 18;
    static final double eps = 1.0 / 10e9;
    static final int mod = 1000000007;

    // Defining direction vectors
    static final int[] dd = { -1, 0, 1, 0 };
    static final int[] ddn = { -1, -1, 0, 1, 1, 1, 0, -1 };

    // Function to read a list of integers from standard input
    static int[] LI() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }
        return result;
    }

    // Function to read a list of integers from standard input, subtracting 1 from each element
    static int[] LI_() {
        int[] result = LI();
        for (int i = 0; i < result.length; i++) {
            result[i]--;
        }
        return result;
    }

    // Function to read a list of floats from standard input
    static double[] LF() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        double[] result = new double[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Double.parseDouble(tokens[i]);
        }
        return result;
    }

    // Function to read a single line from standard input as a list of strings
    static String[] LS() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine().split(" ");
    }

    // Function to read a single integer from standard input
    static int I() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single float from standard input
    static double F() {
        Scanner scanner = new Scanner(System.in);
        return Double.parseDouble(scanner.nextLine());
    }

    // Function to read a single string from standard input
    static String S() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to print a string with a newline character at the end
    static void pf(String s) {
        System.out.println(s);
    }

    // Main function
    public static void main(String[] args) {
        // Reading input string and number of occurrences of '1' required
        String s = S();
        int k = I();

        // Finding the length of the substring consisting only of '1's
        int l = 0;
        for (char c : s.toCharArray()) {
            if (c != '1') {
                // If the length of the substring is greater than or equal to the required number of occurrences, return 1
                if (l >= k) {
                    System.out.println(1);
                } else {
                    System.out.println(c);
                }
                break;
            }
            l++;
        }
    }
}
