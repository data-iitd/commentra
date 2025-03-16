import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include necessary libraries for input/output operations.
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Read the values of n and d from the standard input.
        double a = d * 2 + 1;
        // Calculate the value of 'a' which is used in the subsequent calculations.
        System.out.println(Math.ceil(n / a));
        // Output the ceiling of the division of n by 'a' to the standard output.

        scanner.close();
    }
}

// <END-OF-CODE>
