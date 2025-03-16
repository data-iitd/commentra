
import java.util.Scanner; // Importing Scanner class for user input
import java.util.stream.IntStream; // Importing IntStream class for parallel processing

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input
        int N; // Declaring an integer variable 'N' to store the number of elements

        // Reading the number of elements from the user input
        N = sc.nextInt();

        double[] x = new double[N]; // Declaring and initializing an array 'x' of size 'N' to store the double values
        String[] u = new String[N]; // Declaring and initializing an array 'u' of size 'N' to store the currency strings

        // Reading the double values and currency strings from the user input and storing them in respective arrays
        for (int i = 0; i < N; ++i) {
            x[i] = sc.nextDouble();
            u[i] = sc.next();
        }

        // Calling the 'solve' method to find the sum of products of double values and their respective currency conversion factors
        System.out.println(solve(x, u));

        sc.close(); // Closing the Scanner object to free up system resources
    }

    static double solve(double[] x, String[] u) {
        return IntStream.range(0, x.length) // Creating an IntStream to process the indices of the 'x' array in parallel
                .mapToDouble(i -> x[i] * (u[i].equals("JPY") ? 1 : 380000)) // Multiplying the double value at index 'i' with the conversion factor based on the currency string
                .sum(); // Summing up all the products obtained from the previous step
    }
}

