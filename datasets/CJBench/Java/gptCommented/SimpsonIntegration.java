import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of intervals (n) from user input
        int n = scanner.nextInt();
        
        // Check if n is even; if not, print an error message and exit
        if (n % 2 != 0) {
            System.out.println("n must be an even number for Simpson's method. Exiting.");
            return;
        }
        
        // Read the lower limit (a) and upper limit (b) for integration from user input
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        
        // Create an instance of the Main class to access the integration method
        Main integration = new Main();
        
        // Calculate the width of each interval (h)
        double h = (b - a) / n;
        
        // Perform Simpson's method to evaluate the integral
        double integralEvaluation = integration.simpsonsMethod(n, h, a);
        
        // Output the result of the integral evaluation
        System.out.println("The integral is equal to: " + integralEvaluation);
    }
    
    // Method to perform Simpson's method for numerical integration
    public double simpsonsMethod(int n, double h, double a) {
        // Create a TreeMap to store the function values at each interval
        TreeMap<Integer, Double> data = new TreeMap<>(); 
        double temp;
        double xi = a; 
        
        // Calculate the function values at each interval and store them in the TreeMap
        for (int i = 0; i <= n; i++) {
            temp = f(xi); 
            data.put(i, temp);
            xi += h; 
        }
        
        // Initialize the variable to hold the result of the integral evaluation
        double integralEvaluation = 0;
        
        // Apply Simpson's rule to compute the integral
        for (int i = 0; i < data.size(); i++) {
            // Add the first and last terms
            if (i == 0 || i == data.size() - 1) {
                integralEvaluation += data.get(i);
            } 
            // Add the odd-indexed terms multiplied by 4
            else if (i % 2 != 0) {
                integralEvaluation += 4 * data.get(i);
            } 
            // Add the even-indexed terms multiplied by 2
            else {
                integralEvaluation += 2 * data.get(i);
            }
        }
        
        // Multiply the accumulated sum by h/3 to get the final integral value
        integralEvaluation = h / 3 * integralEvaluation;
        return integralEvaluation;
    }
    
    // Function to evaluate the mathematical function f(x) = e^(-x) * (4 - x^2)
    public double f(double x) {
        return Math.exp(-x) * (4 - Math.pow(x, 2));
    }
}
