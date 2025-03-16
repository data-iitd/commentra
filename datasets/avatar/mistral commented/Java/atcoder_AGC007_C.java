
import java.math.BigDecimal; // Importing BigDecimal class for arithmetic operations with large numbers
import java.text.DecimalFormat; // Importing DecimalFormat class for formatting the output
import java.util.Scanner; // Importing Scanner class for reading user input

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a Scanner object to read user input

        // Reading input values from the user
        double N = scan.nextDouble();
        double d = scan.nextDouble();
        double x = scan.nextDouble();

        BigDecimal ans = new BigDecimal("0.0"); // Initializing an answer variable of BigDecimal type with zero value

        // Calculating the answer using the given formula
        while (N > 0.5) {
            BigDecimal adnum = BigDecimal.valueOf(d + x * (N - 0.5)); // Calculating the next term of the sum
            ans = ans.add(adnum); // Adding the next term to the answer

            // Updating the values of d and x for the next iteration
            d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
            x = (1.0 + (2.0 / N)) * x;

            --N; // Decreasing the value of N by 1 for the next iteration
        }

        // Formatting the output with 20 decimal places
        DecimalFormat format = new DecimalFormat("#.#");
        format.setMinimumFractionDigits(20);

        // Printing the final answer with 20 decimal places
        System.out.println(format.format(ans));
    }
}

These comments should provide a clear understanding of the code's functionality and logic.