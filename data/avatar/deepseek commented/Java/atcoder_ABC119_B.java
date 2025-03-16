import java.util.Scanner; // Import Scanner for input operations
import java.util.stream.IntStream; // Import IntStream for stream operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
        int N = sc.nextInt(); // Read the number of elements N from the user
        double[] x = new double[N]; // Initialize the array to store the values
        String[] u = new String[N]; // Initialize the array to store the currencies

        // Read the values into the arrays x and u
        for (int i = 0; i < N; ++i) {
            x[i] = sc.nextDouble();
            u[i] = sc.next();
        }

        // Call the solve method and print the result
        System.out.println(solve(x, u));
        sc.close(); // Close the Scanner object to free up resources
    }

    // Define the solve method to calculate the total value based on the currency
    static double solve(double[] x, String[] u) {
        return IntStream.range(0, x.length).mapToDouble(i -> x[i] * (u[i].equals("JPY") ? 1 : 380000)).sum();
    }
}
