import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] h = new int[6]; // Initialize array h of size 6
        int[] w = new int[6]; // Initialize array w of size 6

        Scanner scanner = new Scanner(System.in);
        int x, ans = 0; // Initialize x and ans to zero

        // Read input value of x from the user
        x = scanner.nextInt();

        // Calculate the answer using the given formula
        ans = x + x * x + x * x * x;

        // Output the answer to the user
        System.out.println(ans);

        scanner.close();
    }
}

// <END-OF-CODE>
