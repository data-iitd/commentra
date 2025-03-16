import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take three integers as input from the user
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Iterate through the range of numbers from 2 to 11 (12 is excluded)
        for (int i = 2; i < 12; i++) {
            // Calculate the expression and print the integer result
            int result = (int) Math.round(Math.pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r));
            System.out.println(result);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)
