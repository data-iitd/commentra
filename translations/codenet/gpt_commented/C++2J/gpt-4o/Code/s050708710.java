import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of red, green, blue items and the total number of items
        Scanner scanner = new Scanner(System.in);
        int r = scanner.nextInt();
        int g = scanner.nextInt();
        int b = scanner.nextInt();
        int n = scanner.nextInt();
        
        // Initialize the answer counter to zero
        int ans = 0;

        // Iterate over the possible counts of red items (i)
        for (int i = 0; i <= n / r; ++i) {
            // Iterate over the possible counts of green items (j)
            for (int j = 0; j <= n / g; ++j) {
                // Calculate the remaining items after selecting i red and j green items
                int num = n - r * i - g * j;

                // Check if the remaining items can be exactly filled with blue items
                if (num >= 0 && num % b == 0) {
                    // If valid, increment the answer counter
                    ++ans;
                }
            }
        }

        // Output the total number of valid combinations found
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
