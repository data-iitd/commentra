import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        // Read the number of elements and the list elements from input

        if (sum(a) % (n * (n + 1) / 2) != 0) {
            // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
            System.out.println("NO");
        } else {
            double k = (double) sum(a) / (n * (n + 1) / 2);
            // Calculate the quotient k by dividing the sum of the list by the triangular number
            int[] a2 = new int[n + 1];
            System.arraycopy(a, 0, a2, 0, n);
            a2[n] = a[0];
            // Append the first element to the end of the list to create a circular list

            if (sum(new int[]{((int) ((k - a2[i] + a2[i + 1]) % n))}) != 0 || sum(new int[]{((int) ((k - a2[i] + a2[i + 1]) / n))}) != n) {
                // Check if the condition is met for all elements in the circular list
                System.out.println("NO");
            } else {
                System.out.println("YES");
                // If the condition is met, print "YES"
            }
        }
    }

    private static int sum(int[] array) {
        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        return sum;
    }
}
