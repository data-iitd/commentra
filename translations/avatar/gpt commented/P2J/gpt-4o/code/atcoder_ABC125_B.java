import java.util.Scanner;

public class ProfitCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read the values into an array and convert them to integers
        String[] valueStrings = scanner.nextLine().split(" ");
        int[] V = new int[N];
        for (int i = 0; i < N; i++) {
            V[i] = Integer.parseInt(valueStrings[i]);
        }

        // Read the costs into an array and convert them to integers
        String[] costStrings = scanner.nextLine().split(" ");
        int[] C = new int[N];
        for (int i = 0; i < N; i++) {
            C[i] = Integer.parseInt(costStrings[i]);
        }

        // Initialize a variable to hold the total profit
        int ans = 0;

        // Iterate through each item
        for (int i = 0; i < N; i++) {
            // Check if the value is greater than the cost
            if (V[i] - C[i] > 0) {
                // Calculate the profit and add it to the total profit
                ans += (V[i] - C[i]);
            }
        }

        // Print the total profit
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
