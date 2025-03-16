import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first integer from input and convert it to an integer
        int a = Integer.parseInt(scanner.nextLine());
        // Read the second integer from input and convert it to an integer
        int b = Integer.parseInt(scanner.nextLine());

        // Check if the product of a and b is odd
        if (a * b % 2 != 0) {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        } else {
            // If the product is even, print "Even"
            System.out.println("Even");
        }
    }
}
