import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Declare variables to store the number of successful and failed runs
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculate the total time in milliseconds for the successful and failed runs
        int x = m * 1900 + (n - m) * 100;
        
        // Print the result of the expression (total time * 2^m)
        System.out.println(x * (int)Math.pow(2, m));
    }
}
