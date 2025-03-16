#######
# Code
#######

// Import necessary libraries
import java.util.*;

// Main function
public class Main {
    public static void main(String[] args) {
        // Read input values
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        // Calculate the maximum product of pairs of numbers
        int result = Math.max(a*c, b*d, a*d, b*c);

        // Print the result
        System.out.println(result);
    }
}

// 