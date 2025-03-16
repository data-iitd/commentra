import java.util.Scanner;

public class GCDExample {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Ask the user for an integer input and assign it to the variable x
        int x = scanner.nextInt();
        
        // Calculate the greatest common divisor (gcd) of 360 and the user input x
        int gcdValue = gcd(360, x);
        
        // Print the result of the division of 360 by the gcd
        System.out.println(360 / gcdValue);
        
        // Close the scanner
        scanner.close();
    }

    // Method to calculate gcd
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

// <END-OF-CODE>
