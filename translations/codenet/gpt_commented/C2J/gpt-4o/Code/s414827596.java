import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Continuously read input until EOF (End of File) is reached
        while (scanner.hasNextInt()) {
            // Declare integer variables for input coefficients
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            int e = scanner.nextInt();
            int f = scanner.nextInt();
            
            // Declare double variables for the results of the equations
            double x, y;

            // Calculate the value of y using the given formula
            y = (double)(c * d - f * a) / (b * d - e * a);
            // Calculate the value of x using the given formula
            x = (double)(c * e - f * b) / (a * e - d * b);
            
            // Adjust y to 0 if it is a small negative number close to zero
            if (y <= 0 && y > -0.0005) y = 0;
            // Adjust x to 0 if it is a small negative number close to zero
            if (x <= 0 && x > -0.0005) x = 0;

            // Print the results x and y formatted to three decimal places
            System.out.printf("%.3f %.3f\n", x, y);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
