
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object
        Scanner input = new Scanner(System.in);

        // Read two integers from the user and store them in variables a and b
        int a = input.nextInt();
        int b = input.nextInt();

        // Multiply the two integers and store the result in variable c
        int c = a * b;

        // Multiply each integer with 2 and add them to get the value of d
        int d = 2 * a + 2 * b;

        // Print the values of c and d on the console
        System.out.println(c + " " + d);

        // Close the scanner object
        input.close();
    }
}

