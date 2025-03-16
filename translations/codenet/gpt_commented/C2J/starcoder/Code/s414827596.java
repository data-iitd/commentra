import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner input = new Scanner(System.in);

        // Continuously read input until EOF (End of File) is reached
        while (input.hasNext()) {
            // Declare integer variables for input coefficients
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();
            int d = input.nextInt();
            int e = input.nextInt();
            int f = input.nextInt();

            // Calculate the value of y using the given formula
            double y = (double)(c * d - f * a) / (b * d - e * a);
            // Calculate the value of x using the given formula
            double x = (double)(c * e - f * b) / (a * e - d * b);

            // Adjust y to 0 if it is a small negative number close to zero
            if (y <= 0 && y > -0.0005) y = 0;
            // Adjust x to 0 if it is a small negative number close to zero
            if (x <= 0 && x > -0.0005) x = 0;

            // Print the results x and y formatted to three decimal places
            System.out.printf("%.3f %.3f\n", x, y);
        }
    }
}
