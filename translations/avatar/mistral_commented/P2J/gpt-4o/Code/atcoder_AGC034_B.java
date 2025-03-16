import java.util.Scanner;

public class Main {
    
    // Function to find the greatest common divisor (GCD) of two numbers
    public static int gcd(int a, int b) {
        // Making 'a' greater than 'b'
        a = Math.max(a, b);
        b = Math.min(a, b);
        
        // Finding the GCD using Euclidean algorithm
        while (a % b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        // Returning the GCD
        return b;
    }

    // Function to solve the problem
    public static void solve() {
        // Reading the input string from standard input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initializing an empty string 't' to store the output string
        StringBuilder t = new StringBuilder();
        
        // Iterating through each character in the input string 's'
        int i = 0;
        while (i < s.length()) {
            // If the current character is 'A', append 'A' to 't' and move to the next character
            if (s.charAt(i) == 'A') {
                t.append('A');
                i++;
            }
            // If the current character is 'B', check if the next character is 'C'
            else if (s.charAt(i) == 'B') {
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
            }
            // If the current character is not 'A' or 'B', append 'X' to 't'
            else {
                t.append('X');
                i++;
            }
        }
        
        // Initializing variables 'total' and 'numA' to 0
        int total = 0;
        int numA = 0;
        
        // Iterating through each character in the output string 't'
        for (i = 0; i < t.length(); i++) {
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
        // Calling the 'solve' function
        solve();
    }
}

// <END-OF-CODE>
