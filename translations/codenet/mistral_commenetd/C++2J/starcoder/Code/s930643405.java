import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Check each digit in the input number 'k' times
        for (int i = 0; i < k; ++i) {
            int a = sc.nextInt(); // Read the digit from the input
            boolean[] d = new boolean[10]; // A boolean array to keep track of digits that have been seen
            d[a] = true; // Mark the digit as seen
        }

        // Keep generating numbers until a valid one is found
        while (1) {
            int x = n; // Initialize a variable 'x' to store the current number being checked

            // Initialize a flag 'hantei' to indicate if the current number is valid
            boolean hantei = true;

            // Check each digit in the number 'x'
            while (x) {
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

