import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read input for n
        int k = scanner.nextInt();  // Read input for k
        int x = 0;  // Initialize x to 0

        // Check if k is within the feasible range for placing 'L' characters
        if (k <= Math.max(n * n / 2, n * n - (n * n / 2))) {
            System.out.println("YES");  // Print 'YES' if k is feasible
            for (int i = 0; i < n; i++) {  // Loop through each row
                for (int j = 0; j < n; j++) {  // Loop through each column
                    if (i % 2 == j % 2 && x < k) {  // Check if the cell should be 'L'
                        System.out.print("L");  // Print 'L'
                        x++;  // Increment x
                    } else {
                        System.out.print("S");  // Print 'S' otherwise
                    }
                }
                System.out.println();  // Move to the next line after each row
            }
        } else {
            System.out.println("NO");  // Print 'NO' if k is not feasible
        }
        scanner.close();
    }
}
// <END-OF-CODE>
