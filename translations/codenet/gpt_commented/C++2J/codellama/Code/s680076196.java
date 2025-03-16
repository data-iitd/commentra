import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from standard input
        int a = sc.nextInt(); // Read the first integer value from standard input
        int b = sc.nextInt(); // Read the second integer value from standard input
        int c = sc.nextInt(); // Read the third integer value from standard input
        int d = sc.nextInt(); // Read the fourth integer value from standard input
        sc.close(); // Close the Scanner object

        // Calculate the product of the differences between the first two and the last two integers
        // This represents the area of a rectangle defined by the points (a, b) and (c, d)
        int area = (a - c) * (b - d);

        // Print the result to standard output
        System.out.println(area);
    }
}

