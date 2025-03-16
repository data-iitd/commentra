public class LinearEquationSolver {
    public static void main(String[] args) {
        // Declare integer variables for input coefficients
        int a, b, c, d, e, f;
        // Declare double variables for the results of the equations
        double x, y;

        // Continuously read input until EOF (End of File) is reached
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            d = scanner.nextInt();
            e = scanner.nextInt();
            f = scanner.nextInt();

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
        
        // Return 0 to indicate successful completion of the program
        scanner.close();
    }
}
