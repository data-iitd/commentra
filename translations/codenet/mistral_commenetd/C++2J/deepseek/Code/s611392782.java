import java.util.Scanner;

public class Miscalculation {

    // Function to calculate the multiplication part of the expression
    static int mul(String str, int idx) {
        int res = str.charAt(idx) - '0'; // Extract the first digit and store it in 'res'
        while (idx + 1 < str.length() && str.charAt(idx + 1) == '*') { // Check if there is a '*' symbol
            idx += 2; // Move the index to the next symbol
            res *= str.charAt(idx) - '0'; // Multiply 'res' with the next digit
        }
        return res; // Return the final result
    }

    // Function to calculate the addition part of the expression
    static int add(String str, int idx) {
        int res = mul(str, idx); // Call the 'mul' function to calculate the multiplication part
        while (idx + 1 < str.length() && str.charAt(idx + 1) == '+') { // Check if there is a '+' symbol
            idx += 2; // Move the index to the next symbol
            res += mul(str, idx); // Add the result of the next multiplication part
        }
        return res; // Return the final result
    }

    // Function to calculate the whole expression
    static int bob(String str, int idx) {
        int res = str.charAt(idx) - '0'; // Extract the first digit and store it in 'res'
        while (idx + 1 < str.length()) { // Loop through the rest of the expression
            if (str.charAt(idx + 1) == '+') res += str.charAt(idx + 2) - '0'; // If there is a '+' symbol, add the next digit
            else res *= str.charAt(idx + 2) - '0'; // If there is a '*' symbol, multiply the next digit
            idx += 2; // Move the index to the next symbol
        }
        return res; // Return the final result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String s = scanner.next();
            int d = scanner.nextInt();
            int idx = 0; // Initialize the index to 0
            int a = add(s, idx); // Call the 'add' function to calculate the addition part of the expression
            idx = 0; // Reset the index to 0
            int b = bob(s, idx); // Call the 'bob' function to calculate the whole expression
            if (a == d) { // Check if the addition part matches the desired result
                System.out.println((b == d) ? "U" : "M"); // If both parts match, print 'U', otherwise print 'M'
            } else { // If the addition part doesn't match, check if the whole expression matches
                System.out.println((b == d) ? "L" : "I"); // If the whole expression matches, print 'L', otherwise print 'I'
            }
        }
        scanner.close();
    }
}
