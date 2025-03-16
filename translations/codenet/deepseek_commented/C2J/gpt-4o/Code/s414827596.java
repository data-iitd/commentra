import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the input values
        // The code uses a while loop to read six integers from the standard input until the end of the input is reached.
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            int e = scanner.nextInt();
            int f = scanner.nextInt();
            
            // Calculating the values of x and y
            // The code calculates the values of x and y using the formula derived from the given equations.
            double y = (double)(c * d - f * a) / (b * d - e * a);
            double x = (double)(c * e - f * b) / (a * e - d * b);
            
            // Adjusting the values of x and y if they are very close to zero
            // The code checks if the values of x and y are very close to zero and adjusts them to exactly zero if they are.
            if (y <= 0 && y > -0.0005) y = 0;
            if (x <= 0 && x > -0.0005) x = 0;
            
            // Printing the results
            // The code prints the calculated values of x and y with three decimal places.
            System.out.printf("%.3f %.3f%n", x, y);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
