
import java.util.*;

public class s930643405{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the initial number 'n'
        int k = sc.nextInt(); // Read the count of forbidden digits 'k'
        boolean[] d = new boolean[10]; // Array to track forbidden digits
        Arrays.fill(d, false); // Initialize all digits as not forbidden

        // Read the forbidden digits and mark them in the array
        for (int i = 0; i < k; ++i) {
            int a = sc.nextInt(); // Input each forbidden digit
            d[a] = true; // Mark the digit as forbidden
        }

        // Infinite loop to find the next valid number
        while (true) {
            int x = n; // Start checking from the current number 'n'
            boolean hantei = true; // Reset the validity flag for the new number

            // Check each digit of the number 'x'
            while (x > 0) {
                // If the current digit is forbidden
                if (d[x % 10]) {
                    hantei = false; // Mark the number as invalid
                    break; // Exit the digit checking loop
                }
                x /= 10; // Remove the last digit
            }

            // If the number is valid (no forbidden digits found)
            if (hantei) {
                System.out.println(n); // Output the valid number
                break; // Exit the infinite loop
            }
            n++; // Increment the number and check the next one
        }
    }
}

