import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of text from the standard input stream and convert it into two integers
        int vamshi = scanner.nextInt();
        int z = scanner.nextInt();
        
        // Calculate the number of complete divisions of z into vamshi
        // Add 1 to account for the remainder
        // Multiply the result by z
        System.out.println((vamshi / z + 1) * z);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
