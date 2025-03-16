import java.util.Scanner; 
import java.util.Arrays; 

public class Main { 

    // Method to calculate the number of digits in a given number
    public static int power(Long a) { 
        int res = 0; 
        // Count the number of digits by dividing the number by 10 until it becomes 0
        while (a > 0) { 
            res++; 
            a = a / 10; 
        } 
        return res; 
    } 

    // Method to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
    public static long mult(Long a) { 
        int pow = power(a); // Get the number of digits in 'a'
        long max = 0; 
        // Create the largest number with the same number of digits as 'a' (all 9s)
        for (int j = 0; j < pow; ++j) { 
            max = max * 10 + 9; 
        } 
        // Return the product of 'a' and the difference between the largest number and 'a'
        return a * (max - a); 
    } 

    public static void main(String[] args) { 
        Scanner in = new Scanner(System.in); // Create a Scanner object for input
        long l = in.nextLong(); // Read the lower bound of the range
        long r = in.nextLong(); // Read the upper bound of the range
        long res = 0; // Variable to store the maximum result
        long[] maxxes = new long[10]; // Array to store maximum products for numbers with different digit lengths
        long temp = 0; 

        // Precompute maximum products for numbers with up to 10 digits
        for (int i = 0; i < 10; ++i) { 
            temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
            maxxes[i] = temp / 2 * (temp - temp / 2); // Calculate the maximum product for this digit length
        } 

        // Calculate the maximum product for the lower bound 'l'
        res = Math.max(mult(l), res); 
        // Calculate the maximum product for the upper bound 'r'
        res = Math.max(mult(r), res); 
        temp = 0; 

        // Check for numbers formed by all 9s and see if they lie within the range [l, r]
        for (int i = 0; i < 10; ++i) { 
            temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
            // If the half of this number is within the range, consider its maximum product
            if (l <= temp / 2 && temp / 2 <= r) 
                res = Math.max(maxxes[i], res); 
        } 

        // Output the maximum product found
        System.out.println(res); 
    } 
}
