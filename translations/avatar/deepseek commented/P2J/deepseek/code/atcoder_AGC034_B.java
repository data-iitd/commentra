import java.util.*;

public class Main {
    // Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
    public static int gcd(int a, int b) {
        a = Math.max(a, b);
        b = Math.min(a, b);
        while (a % b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return b;
    }

    // Main function to solve the problem
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Read input string
        StringBuilder t = new StringBuilder();  // Initialize a StringBuilder to store processed characters
        int i = 0;  // Initialize index
        
        // Process the input string character by character
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                t.append("A");
                i++;
            } else if (s.charAt(i) == 'B') {
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        t.append("D");
                        i += 2;
                    } else {
                        t.append("X");
                        i++;
                    }
                } else {
                    t.append("X");
                    i++;
                }
            } else {
                t.append("X");
                i++;
            }
        }
        
        int total = 0;  // Initialize total count
        int numA = 0;  // Initialize count of 'A' characters
        
        // Count the number of 'A' characters before each 'X' in the processed string
        for (int j = 0; j < t.length(); j++) {
            if (t.charAt(j) == 'X') {
                numA = 0;
            } else {
                if (t.charAt(j) == 'A') {
                    numA++;
                } else {
                    total += numA;
                }
            }
        }
        
        System.out.println(total);  // Print the total count
        
        // Define constants for infinity and modulo
        final long INF = (long) Math.pow(10, 25);
        final int mod = 7 + (int) Math.pow(10, 9);
        
        // No return statement needed for the main method
    }
}
