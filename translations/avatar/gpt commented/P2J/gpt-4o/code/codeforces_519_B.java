import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read an integer input which represents the number of elements in the lists
        int n = scanner.nextInt();

        // Read three lists of integers from input
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }

        // Initialize variables to hold the sum of each list
        int x = 0;
        int y = 0;
        int z = 0;

        // Calculate the sum of elements in list 'a'
        for (int i : a) {
            x += i;
        }

        // Calculate the sum of elements in list 'b'
        for (int i : b) {
            y += i;
        }

        // Calculate the sum of elements in list 'c'
        for (int i : c) {
            z += i;
        }

        // Print the absolute difference between the sums of list 'a' and list 'b'
        System.out.println(Math.abs(x - y));

        // Print the absolute difference between the sums of list 'b' and list 'c'
        System.out.println(Math.abs(y - z));

        scanner.close();
    }
}
// <END-OF-CODE>
