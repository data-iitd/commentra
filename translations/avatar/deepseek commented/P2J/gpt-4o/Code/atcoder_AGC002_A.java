import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers a and b
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check conditions and print results
        if (a > 0) {
            System.out.println("Positive");
        } else if (a <= 0 && b >= 0) {
            System.out.println("Zero");
        } else {
            if ((a + b) % 2 == 0) {
                System.out.println("Negative");
            } else {
                System.out.println("Positive");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
