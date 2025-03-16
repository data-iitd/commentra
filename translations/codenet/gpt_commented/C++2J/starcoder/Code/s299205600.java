import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input values
        int a;
        int b;

        // Read two integer values from the user
        Scanner input = new Scanner(System.in);
        a = input.nextInt();
        b = input.nextInt();

        // Declare a variable to store the result
        int result;

        // Determine the result based on the comparison of a and b
        if (a > b) {
            // If a is greater than b, calculate result as 2 * a - 1
            result = 2 * a - 1;
        } else if (a == b) {
            // If a is equal to b, calculate result as 2 * a
            result = 2 * a;
        } else {
            // If a is less than b, calculate result as 2 * b - 1
            result = 2 * b - 1;
        }

        // Output the result to the console
        System.out.println(result);
    }
}
