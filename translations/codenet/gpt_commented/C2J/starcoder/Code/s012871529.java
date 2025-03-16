import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Read two integers from the user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
        System.out.println(a * b + " " + 2 * (a + b));

        // Return 0 to indicate successful execution of the program
        return 0;
    }
}
