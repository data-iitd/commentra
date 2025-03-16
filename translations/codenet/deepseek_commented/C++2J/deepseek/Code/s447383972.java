import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array.
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt(); // Read the elements of the array.
        }
        Arrays.sort(a, 1, n + 1); // Sort the array.
        int[] q = new int[n + 1];
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i + 1]) {
                q[++tot] = a[i];
                i++; // Skip the next element to avoid duplicates.
            }
        }
        System.out.println(q[tot] * q[tot - 1]); // Print the product of the two largest distinct elements.
    }
}
