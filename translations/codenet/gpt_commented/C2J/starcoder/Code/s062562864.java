import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare integer variables to hold input values and results
        int a, b, c, d, i, j;

        // Read four integers from user input
        Scanner input = new Scanner(System.in);
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();
        d = input.nextInt();

        // Calculate the product of the first two integers
        i = a * b;

        // Calculate the product of the last two integers
        j = c * d;

        // Compare the two products and print the larger one
        if (i > j) {
            // If the first product is greater, print it
            System.out.println(i);
        } else {
            // Otherwise, print the second product
            System.out.println(j);
        }
    }
}
