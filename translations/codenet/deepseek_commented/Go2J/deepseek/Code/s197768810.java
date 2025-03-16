import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers n and m from the input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize a sum variable to hold the sum of integers
        int sum = 0;

        // Read m integers and calculate their sum
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            sum += a;
        }

        // Check if the sum of integers exceeds n
        if (sum > n) {
            // Print -1 if the sum exceeds n
            System.out.println("-1");
        } else {
            // Print the difference between n and the sum if it's within bounds
            System.out.println(n - sum);
        }
    }
}
