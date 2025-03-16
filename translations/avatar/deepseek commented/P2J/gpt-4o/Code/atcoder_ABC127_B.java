import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers r, D, and x from input
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Loop from 2 to 11 (inclusive)
        for (int i = 2; i <= 11; i++) {
            // Calculate the value using the given formula and print the integer result
            int result = (int) (Math.pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r));
            System.out.println(result);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
