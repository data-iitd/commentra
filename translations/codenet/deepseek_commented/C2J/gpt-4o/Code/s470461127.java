import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x, y;
        x = 0; 
        y = 0;   

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the standard input and store them in x and y
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        // Calculate the product of x and y
        // Also, calculate the perimeter of a rectangle with sides x and y
        System.out.println(x * y + " " + ((2 * x) + (2 * y)));  

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
