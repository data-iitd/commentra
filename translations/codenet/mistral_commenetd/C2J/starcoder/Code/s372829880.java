
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize two integer variables, x and a
        int x, a;

        // Read data from the standard input stream and store it into x and a
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        a = scanner.nextInt();

        // Check if x is greater than or equal to a
        int result = (x >= a);

        // Multiply the result by 10
        result *= 10;

        // Print the result to the standard output stream
        System.out.println(result);
    }
}

