import java.util.Scanner;

public class Main {
    
    // Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
    public static int gcd(int a, int b) {
        a = Math.max(a, b);
        b = Math.min(a, b);
        while (a % b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return b;
    }

    // Main function to solve the problem
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Read input string
        StringBuilder t = new StringBuilder();  // Initialize an empty string to store processed characters
        int i = 0;  // Initialize index
        
        // Process the input string character by character
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                t.append('A');
                i++;
            } else if (s.charAt(i) == 'B') {
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        t.append('D');
                        i += 2;
                    } else {
                        t.append('X');
                        i++;
                    }
                } else {
                    t.append('X');
                    i++;
                }
            } else {
                t.append('X');
                i++;
            }
        }

        int total = 0;  // Initialize total count
        int numA = 0;  // Initialize count of 'A' characters
        
        // Count the number of 'A' characters before each 'X' in the processed string
        for (i = 0; i < t.length(); i++) {
            if (t.charAt(i) == 'X') {
                numA = 0;
            } else {
                if (t.charAt(i) == 'A') {
                    numA++;
                } else {
                    total += numA;
                }
            }
        }

        System.out.println(total);  // Print the total count
        
        // Define constants for infinity and modulo
        long INF = (long) Math.pow(10, 25);
        long mod = 7 + (long) Math.pow(10, 9);
        
        scanner.close();
    }

    // Check if the script is being run as the main module
    public static void main(String[] args) {
        solve();
    }
}

// <END-OF-CODE>
