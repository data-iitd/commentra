import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int a, b, h; // Declaring three integer variables a, b, and h
        
        a = scanner.nextInt(); // Reading the first integer
        b = scanner.nextInt(); // Reading the second integer
        h = scanner.nextInt(); // Reading the third integer
        
        System.out.println((a + b) * h / 2); // Calculating and printing the area of a trapezoid
        
        scanner.close(); // Closing the scanner
    }
}

// <END-OF-CODE>
