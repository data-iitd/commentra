
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

    // Function to calculate the multiplication part of the expression
    public static int mul(String str, int idx) {
        int res = str.charAt(idx) - '0'; // Extract the first digit and store it in'res'
        while(idx+1 < str.length() && str.charAt(idx+1) == '*') { // Check if there is a '*' symbol
            idx += 2; // Move the index to the next symbol
            res *= str.charAt(idx) - '0'; // Multiply'res' with the next digit
        }
        return res; // Return the final result
    }

    // Function to calculate the addition part of the expression
    public static int add(String str, int idx) {
        int res = mul(str, idx); // Call the'mul' function to calculate the multiplication part
        while(idx+1 < str.length() && str.charAt(idx+1) == '+') { // Check if there is a '+' symbol
            idx += 2; // Move the index to the next symbol
            res += mul(str, idx); // Add the result of the next multiplication part
        }
        return res; // Return the final result
    }

    // Function to calculate the whole expression
    public static int bob(String str, int idx) {
        int res = str.charAt(idx) - '0'; // Extract the first digit and store it in'res'
        while(idx+1 < str.length()) { // Loop through the rest of the expression
            if(str.charAt(idx+1) == '+') res += str.charAt(idx+2) - '0'; // If there is a '+' symbol, add the next digit
            else                        res *= str.charAt(idx+2) - '0'; // If there is a '*' symbol, multiply the next digit
            idx += 2; // Move the index to the next symbol
        }
        return res; // Return the final result
    }
}

