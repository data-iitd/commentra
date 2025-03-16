import java.util.Scanner;

public class TrapezoidArea {
    public static void main(String[] args) {
        // Declare variables to hold the lengths of the two bases (a and b) and the height (h)
        int a, b, h;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the values of the two bases and the height from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Calculate the area of the trapezoid using the formula: Area = ((base1 + base2) * height) / 2
        // and print the result
        System.out.println((a + b) * h / 2);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
