import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to store the number of successful and failed runs
        int n, m;
        
        // Read the number of successful and failed runs from the standard input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        
        // Calculate the total time in milliseconds for the successful and failed runs
        int x = m * 1900 + (n - m) * 100;
        
        // Print the result of the expression (total time * 2^m)
        System.out.println(x * Math.pow(2, m));
        
        scanner.close();
    }
}

// <END-OF-CODE>
