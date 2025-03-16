import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a, b, c, x, sum = 0; // Declare variables to store input and result
        a = scanner.nextInt(); // Read input values for a
        b = scanner.nextInt(); // Read input values for b
        c = scanner.nextInt(); // Read input values for c
        x = scanner.nextInt(); // Read input values for x

        // Nested loops to iterate through all combinations of coins
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    if (500 * i + 100 * j + 50 * k == x) { // Check if the total value equals the target value
                        sum++; // Increment the sum if the condition is met
                    }
                }
            }
        }

        System.out.println(sum); // Output the number of combinations that meet the condition
        scanner.close();
    }
}
// <END-OF-CODE>
