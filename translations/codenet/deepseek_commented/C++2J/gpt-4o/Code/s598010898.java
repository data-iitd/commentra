import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int[] a = new int[100];
        int[] b = new int[100];
        int sum = 0;

        // Read n integers into array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Read n integers into array b
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
            if (a[i] - b[i] > 0) { // Check if a[i] is greater than b[i]
                sum += a[i] - b[i]; // Add the difference to sum
            }
        }

        // Output the sum
        System.out.println(sum);
        scanner.close();
    }
}

// <END-OF-CODE>
