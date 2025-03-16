
// Importing necessary libraries
import java.util.*;

// Function to find the greatest common divisor (GCD) of two numbers
public static int gcd(int a, int b) {
    // Making 'a' greater than 'b'
    a = Math.max(a, b);
    b = Math.min(a, b);
    
    // Finding the GCD using Euclidean algorithm
    while (a % b > 0) {
        a = b;
        b = a % b;
    }
    
    // Returning the GCD
    return b;
}

// Function to solve the problem
public static void solve() {
    // Reading the input string from standard input
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    
    // Initializing an empty string 't' to store the output string
    String t = "";
    
    // Iterating through each character in the input string's'
    for (int i = 0; i < s.length(); i++) {
        // If the current character is 'A', append 'A' to 't' and move to the next character
        if (s.charAt(i) == 'A') {
            t += "A";
            i++;
        }
        // If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
        else if (s.charAt(i) == 'B') {
            if (i < s.length() - 1) {
                if (s.charAt(i + 1) == 'C') {
                    t += "D";
                    i += 2;
                }
                else {
                    t += "X";
                    i += 1;
            }
            else {
                t += "X";
                i += 1;
            }
        }
        // If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
        else {
            t += "X";
            i += 1;
        }
    }
    
    // Initializing variables 'total' and 'numA' to 0
    int total = 0, numA = 0;
    
    // Iterating through each character in the output string 't'
    for (int i = 0; i < t.length(); i++) {
        // If the current character is 'X', reset 'numA' to 0
        if (t.charAt(i) == 'X') {
            numA = 0;
        }
        // If the current character is 'A', increment 'numA' by 1
        else if (t.charAt(i) == 'A') {
            numA++;
        }
        // Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
        total += numA;
    }
    
    // Printing the final answer
    System.out.println(total);
}

// Starting the program if the script is run directly
public static void main(String[] args) {
    // Calling the'solve' function
    solve();
}

