
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            String s = sc.next();
            int d = sc.nextInt();
            int idx = 0;
            int a = add(s, idx);
            idx = 0;
            int b = bob(s, idx);
            if(a == d) {
                System.out.println(b == d? "U" : "M");
            } else {
                System.out.println(b == d? "L" : "I");
            }
        }
    }

    // Function to perform multiplication based on the custom operator '*' in the string
    public static int mul(String str, int idx) {
        // Initialize result with the first digit
        int res = str.charAt(idx) - '0';
        // Loop through the string to find '*' operators and perform multiplication
        while(idx+1 < str.length() && str.charAt(idx+1) == '*') {
            idx += 2; // Move index to the next number after '*'
            res *= str.charAt(idx) - '0'; // Multiply the result with the next number
        }
        return res; // Return the final multiplication result
    }

    // Function to perform addition based on the custom operator '+' in the string
    public static int add(String str, int idx) {
        // Start with the first multiplication result
        int res = mul(str, idx);
        // Loop through the string to find '+' operators and perform addition
        while(idx+1 < str.length() && str.charAt(idx+1) == '+') {
            idx += 2; // Move index to the next number after '+'
            res += mul(str, idx); // Add the next multiplication result to the total
        }
        return res; // Return the final addition result
    }

    // Function to calculate the result based on Bob's interpretation of the expression
    public static int bob(String str, int idx) {
        // Initialize result with the first digit
        int res = str.charAt(idx) - '0';
        // Loop through the string to evaluate the expression according to Bob's rules
        while(idx+1 < str.length()) {
            // Check if the next operator is '+' or '*' and perform the corresponding operation
            if(str.charAt(idx+1) == '+') 
                res += str.charAt(idx+2) - '0'; // Add the next number
            else                  
                res *= str.charAt(idx+2) - '0'; // Multiply by the next number
            idx += 2; // Move index to the next operator
        }
        return res; // Return the final result according to Bob's interpretation
    }
}

