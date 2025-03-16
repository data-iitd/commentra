
import java.io.*;
import java.util.*;

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
public static int gcd(int a, int b) {
    a = Math.max(a, b);
    b = Math.min(a, b);
    while (a % b > 0) {
        a = b;
        b = a % b;
    }
    return b;
}

// Main function to solve the problem
public static void solve() {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();  // Read input string
    String t = "";  // Initialize an empty string to store processed characters
    int i = 0;  // Initialize index
    
    // Process the input string character by character
    while (i < s.length()) {
        if (s.charAt(i) == 'A') {
            t += "A";
            i++;
        } else if (s.charAt(i) == 'B') {
            if (i < s.length() - 1) {
                if (s.charAt(i + 1) == 'C') {
                    t += "D";
                    i += 2;
                } else {
                    t += "X";
                    i++;
                }
            } else {
                t += "X";
                i++;
            }
        } else {
            t += "X";
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
    int INF = 10 ** 25;
    int mod = 7 + 10 ** 9;
    
    return;
}

// Check if the script is being run as the main module
if (true) {
    solve();
}

