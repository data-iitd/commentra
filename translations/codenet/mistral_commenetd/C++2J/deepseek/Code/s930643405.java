import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize a boolean array to keep track of digits that have been seen
        boolean[] d = new boolean[10];

        // Check each digit in the input number 'k' times
        for (int i = 0; i < k; ++i) {
            int a = scanner.nextInt();
            d[a] = true; // Mark the digit as seen
        }

        // Keep generating numbers until a valid one is found
        while (true) {
            int x = n; // Initialize a variable 'x' to store the current number being checked

            // Initialize a flag 'hantei' to indicate if the current number is valid
            boolean hantei = true;

            // Check each digit in the number 'x'
            while (x > 0) {
                // If the current digit has already been seen, then the number is not valid
                if (d[x % 10]) {
                    hantei = false;
                    break;
                }
                x /= 10; // Move to the next digit
            }

            // If the current number is valid, print it and exit the loop
            if (hantei) {
                System.out.println(n);
                break;
            }

            // If the current number is not valid, increment 'n' and continue checking
            n++;
        }
    }
}
