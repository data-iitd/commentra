import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 3: Declare variables
        int a, b;

        // Step 4: Read input values
        // Use Scanner to read input values from the user.
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Step 5: Perform calculations
        // Calculate the result based on the input values.
        int result = 6 - a - b;

        // Step 6: Output the result
        // Use System.out.println to display the result.
        System.out.println(result);
    }
}

