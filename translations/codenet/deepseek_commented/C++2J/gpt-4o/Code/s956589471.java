import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 3: Declare variables to store input values
        int a, b, c, d, e, k;

        // Step 4: Read input values from the user
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
        System.out.println((e - a <= k) ? "Yay!" : ":(");

        // Close the scanner
        scanner.close();
        
        // Step 7: Return 0 to indicate successful execution
    }
}

// <END-OF-CODE>
