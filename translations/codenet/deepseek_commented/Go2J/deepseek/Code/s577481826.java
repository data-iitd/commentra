import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first integer from input
        int a = Integer.parseInt(scanner.next());
        // Read the second integer from input
        int b = Integer.parseInt(scanner.next());

        // Perform addition of the two integers
        int ret = a + b;

        // Check if the result is less than the difference between the two integers
        if (ret < (a - b)) {
            ret = a - b;
        }
        // Check if the updated result is less than the product of the two integers
        if (ret < (a * b)) {
            ret = a * b;
        }

        // Print the final result
        System.out.println(ret);
    }
}

