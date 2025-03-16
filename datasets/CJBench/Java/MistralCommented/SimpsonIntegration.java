
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the number of intervals n from the user
        int n = scanner.nextInt();

        // Check if n is an even number. If not, print an error message and exit the program
        if (n % 2 != 0) {
            System.out.println("n must be an even number for Simpson's method. Exiting.");
            return;
        }

        // Read the first limit a and the second limit b from the user
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();

        // Create an instance of the Main class to call the simpsonsMethod()
        Main integration = new Main();

        // Calculate the step size h and store the number of intervals n, step size h, and the first limit a
        double h = (b - a) / n;

        // Call the simpsonsMethod() with the number of intervals n, step size h, and the first limit a as arguments
        double integralEvaluation = integration.simpsonsMethod(n, h, a);

        // Print the result of the integral evaluation
        System.out.println("The integral is equal to: " + integralEvaluation);
    }

    // Simpson's Method implementation
    public double simpsonsMethod(int n, double h, double a) {
        // Initialize an empty TreeMap to store the function values at each interval
        TreeMap<Integer, Double> data = new TreeMap<>();

        // Initialize a temporary variable to store the function value at each interval
        double temp;

        // Initialize the current x value at the first limit a
        double xi = a;

        // Iterate through each interval from 0 to n+1
        for (int i = 0; i <= n; i++) {
            // Calculate the function value at the current x value xi using the f() method
            temp = f(xi);

            // Store the function value and its corresponding index in the TreeMap
            data.put(i, temp);

            // Increment the current x value by the step size h
            xi += h;
        }

        // Initialize the integral evaluation to zero
        double integralEvaluation = 0;

        // Iterate through each key-value pair in the TreeMap
        for (int i = 0; i < data.size(); i++) {
            // Calculate the contribution of the current function value to the integral evaluation based on its index i
            if (i == 0) {
                integralEvaluation += data.get(i); // First term: w(0) * f(xi)
            } else if (i == data.size() - 1) {
                integralEvaluation += data.get(i); // Last term: w(n) * f(xi)
            } else if (i % 2 != 0) {
                integralEvaluation += 4 * data.get(i); // Odd terms: w(i) * f(xi)
            } else {
                integralEvaluation += 2 * data.get(i); // Even terms: w(i) * f(xi)
            }
        }

        // Calculate the final integral evaluation by multiplying the sum of the contributions by the step size h and dividing by 3
        integralEvaluation = h / 3 * integralEvaluation;

        // Return the final integral evaluation
        return integralEvaluation;
    }

    // Function to calculate f(x) = e^(-x) * (4 - x^2)
    public double f(double x) {
        return Math.exp(-x) * (4 - Math.pow(x, 2));
    }
}