
import java.util.*;

public class s874174693{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        int m = n;

        // Calculate the sum of the digits of n (up to 9 digits)
        for (int i = 0; i < 9; i++) {
            sum += n % 10; // Add the last digit to sum
            n /= 10; // Remove the last digit
        }

        // Check if m is divisible by the sum of its digits
        if (m % sum == 0) {
            System.out.println("Yes"); // Print "Yes" if divisible
        } else {
            System.out.println("No"); // Print "No" if not divisible
        }
    }
}
