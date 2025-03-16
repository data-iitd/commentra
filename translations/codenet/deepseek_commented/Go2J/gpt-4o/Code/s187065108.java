import java.util.Scanner;

public class Main {
    // Scanner to read input
    private static Scanner scanner = new Scanner(System.in);

    // Main function to execute the program
    public static void main(String[] args) {
        // Read initial values for r, D, and x
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Loop to calculate and print the values of x for 10 iterations
        for (int i = 1; i <= 10; i++) {
            x = r * x - D;
            System.out.println(x);
        }
    }
}

// <END-OF-CODE>
