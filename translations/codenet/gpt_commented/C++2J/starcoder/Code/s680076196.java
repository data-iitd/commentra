import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin

        int a = sc.nextInt(); // Read the first integer from stdin
        int b = sc.nextInt(); // Read the second integer from stdin
        int c = sc.nextInt(); // Read the third integer from stdin
        int d = sc.nextInt(); // Read the fourth integer from stdin

        // Calculate the product of the differences between the first two and the last two integers
        // This represents the area of a rectangle defined by the points (a, b) and (c, d)
        System.out.println((a - c) * (b - d));
    }
}

