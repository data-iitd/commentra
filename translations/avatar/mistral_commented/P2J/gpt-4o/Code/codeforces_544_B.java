import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input: two integers n and k
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize variable x to 0
        int x = 0;

        // Check if k is valid based on the condition
        if (k <= Math.max(n * n / 2, n * n - (n * n / 2))) {
            // If k is valid, print 'YES'
            System.out.println("YES");

            // Iterate through rows and columns of the grid
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Check if current position (i, j) is valid based on the condition
                    if (i % 2 == j % 2 && x < k) {
                        // If valid, print 'L' and increment x
                        System.out.print("L");
                        x++;
                    } else {
                        // If not valid, print 'S'
                        System.out.print("S");
                    }
                }
                // Move to the next line after completing a row
                System.out.println();
            }
        } else {
            // If k is not valid, print 'NO'
            System.out.println("NO");
        }

        scanner.close();
    }
}

// <END-OF-CODE>
