

import java.util.Scanner; // For reading input
import java.util.logging.Logger; // For logging errors

public class s141943854{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sage = scanner.nextLine();

        switch (sage) {
            case "1":
                System.out.println("Hello World"); // Print "Hello World" if input is "1"
                break;
            case "2":
                int sum = 0; // Declare sum variable to store the sum of two integers
                for (int i = 0; i < 2; i++) {
                    String numStr = scanner.nextLine(); // Read input from standard input
                    int num = Integer.parseInt(numStr); // Convert string to integer
                    sum += num; // Add the integer to the sum
                }
                System.out.println(sum); // Print the sum of the two integers
                break;
        }
    }
}

