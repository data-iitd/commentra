
// Import the Scanner class from the java.util package
import java.util.Scanner;

// Create a new Scanner object to read input from the command line
Scanner scanner = new Scanner(System.in);

// Read three integers from the user
int r = scanner.nextInt();
int D = scanner.nextInt();
int x = scanner.nextInt();

// Iterate through the range of numbers from 2 to 11 (12 is excluded)
for (int i = 2; i < 12; i++) {
    // Calculate the expression and print the integer result
    System.out.println((int) Math.round(Math.pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r)));
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)

