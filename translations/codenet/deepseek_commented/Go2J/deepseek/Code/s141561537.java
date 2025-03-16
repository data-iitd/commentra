public class Main {
    public static void main(String[] args) {
        int a, b, c, x, sum = 0; // Declare variables to store input and result
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read input values for a, b, c, and x
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();

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

        // Output the number of combinations that meet the condition
        System.out.println(sum);
    }
}
