import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input number as a string
        Scanner sc = new Scanner(System.in);
        String N = sc.next();

        // Initialize a variable to hold the sum of the digits
        int S = 0;

        // Calculate the sum of the digits in the input string
        for (int i = 0; i < N.length(); i++) {
            S += N.charAt(i) - '0'; // Convert character to integer and add to sum
        }

        // Check if the original number is divisible by the sum of its digits
        if (Integer.parseInt(N) % S == 0) 
            System.out.println("Yes"); // Output "Yes" if divisible
        else 
            System.out.println("No"); // Output "No" if not divisible
    }
}
