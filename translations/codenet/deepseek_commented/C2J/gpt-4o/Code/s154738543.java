import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 3: Declare variables
        int x, y;

        // Step 4: Read input from the user
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();

        // Step 5: Perform the computation
        y = x * x * x;

        // Step 6: Output the result
        System.out.println(y);

        // Step 7: Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
