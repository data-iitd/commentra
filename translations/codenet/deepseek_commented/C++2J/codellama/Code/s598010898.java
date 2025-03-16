import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of elements

        // Read n integers into array a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Read n integers into array b
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) { // Check if a[i] is greater than b[i]
                sum += a[i] - b[i]; // Add the difference to sum
            }
        }

        // Output the sum
        System.out.println(sum);
    }
}

