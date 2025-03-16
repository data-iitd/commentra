import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of intervals
        if (n % 2 != 0) { // Check if n is even
            System.out.println("n must be an even number for Simpson's method. Exiting.");
            return; // Exit the program if n is odd
        }
        double a = scanner.nextDouble(); // Read the lower limit of the interval
        double b = scanner.nextDouble(); // Read the upper limit of the interval
        Main integration = new Main(); // Create an instance of the Main class
        double h = (b - a) / n; // Calculate the step size
        double integralEvaluation = integration.simpsonsMethod(n, h, a); // Call the Simpson's method
        System.out.println("The integral is equal to: " + integralEvaluation); // Print the result
    }

    // Simpson's method implementation
    public double simpsonsMethod(int n, double h, double a) {
        TreeMap<Integer, Double> data = new TreeMap<>(); // Initialize a TreeMap to store function values
        double temp;
        double xi = a; // Initialize xi with the lower limit a
        for (int i = 0; i <= n; i++) { // Loop to calculate function values at each point
            temp = f(xi); // Calculate the function value at xi
            data.put(i, temp); // Store the function value in the TreeMap
            xi += h; // Move to the next point
        }
        double integralEvaluation = 0; // Initialize the integral value
        for (int i = 0; i < data.size(); i++) { // Loop to calculate the integral using Simpson's rule
            if (i == 0 || i == data.size() - 1) { // For the first and last points
                integralEvaluation += data.get(i); // Add the function value
            } else if (i % 2 != 0) { // For odd indices
                integralEvaluation += 4 * data.get(i); // Multiply by 4 and add
            } else { // For even indices
                integralEvaluation += 2 * data.get(i); // Multiply by 2 and add
            }
        }
        integralEvaluation = h / 3 * integralEvaluation; // Apply the Simpson's rule formula
        return integralEvaluation; // Return the integral value
    }

    // Function to be integrated
    public double f(double x) {
        return Math.exp(-x) * (4 - Math.pow(x, 2)); // Define the function
    }
}
