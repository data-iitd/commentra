
import java.util.Scanner;

public class s141561537{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int x = scanner.nextInt();
        int sum = 0;

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
    }
}

