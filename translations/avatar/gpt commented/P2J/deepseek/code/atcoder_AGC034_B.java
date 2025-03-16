import java.util.*;

public class Main {

    // Function to compute the greatest common divisor (GCD) of two numbers
    public static int gcd(int a, int b) {
        // Ensure a is the larger and b is the smaller number
        a = Math.max(a, b);
        b = Math.min(a, b);
        // Use the Euclidean algorithm to find GCD
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
        String s = scanner.nextLine(); // Read input string
        StringBuilder t = new StringBuilder(); // Initialize a StringBuilder to build the result
        int i = 0; // Initialize index for traversing the input string

        // Process the input string character by character
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                // If the character is 'A', add it to the result
                t.append('A');
                i++; // Move to the next character
            } else if (s.charAt(i) == 'B') {
                // If the character is 'B', check the next character
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        // If the next character is 'C', add 'D' to the result
                        t.append('D');
                        i += 2; // Skip the next character as well
                    } else {
                        // If the next character is not 'C', add 'X' to the result
                        t.append('X');
                        i++; // Move to the next character
                    }
                } else {
                    // If 'B' is the last character, add 'X' to the result
                    t.append('X');
                    i++;
                }
            } else {
                // For any other character, add 'X' to the result
                t.append('X');
                i++;
            }
        }

        int total = 0; // Initialize total count
        int numA = 0; // Initialize count of 'A's encountered

        // Calculate the total based on the processed string
        for (int j = 0; j < t.length(); j++) {
            if (t.charAt(j) == 'X') {
                // Reset count of 'A's when 'X' is encountered
                numA = 0;
            } else {
                if (t.charAt(j) == 'A') {
                    // Increment count of 'A's
                    numA++;
                } else {
                    // If the character is not 'A', add the count of 'A's to total
                    total += numA;
                }
            }
        }

        // Print the final total
        System.out.println(total);
    }
}
