import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include the necessary imports for input operations
        Scanner scanner = new Scanner(System.in);
        
        // Declare integer variables to store input values
        int h, w, hh, ww;
        
        // Read values from the standard input and store them in the variables
        h = scanner.nextInt();
        w = scanner.nextInt();
        hh = scanner.nextInt();
        ww = scanner.nextInt();
        
        // Perform arithmetic operation to calculate the area of a rectangle
        System.out.println((h - hh) * (w - ww));
        
        // Close the scanner
        scanner.close();
    }
}

// Indicate that the program ended successfully
// <END-OF-CODE>
