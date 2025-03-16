import java.util.Scanner;

public class Main {
    // Constants for infinity, epsilon, and a modulus value
    static final long inf = (long) 1e20;
    static final double eps = 1.0 / 1e10;
    static final int mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading a string from input
        String s = scanner.nextLine();
        // Reading an integer k from input
        int k = scanner.nextInt();
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

        scanner.close();
    }
}

// <END-OF-CODE>
