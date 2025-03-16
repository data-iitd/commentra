
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
        int n = sc.nextInt(); // Read an integer n from the user
        long ans = 0; // Initialize the variable ans to 0

        // Loop from 1 to n (inclusive)
        for (int i = 1; i < n + 1; i++) {
            // Calculate a value based on the current value of i and the variable n
            long term = (long) n / (long) i;
            long sum = term * (term + 1) / 2;
            ans += (long) i * sum;
        }

        // Print the value of ans
        System.out.println(ans);
    }
}

