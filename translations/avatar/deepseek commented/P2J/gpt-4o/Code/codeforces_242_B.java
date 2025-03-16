import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Initialize variables to track the best candidate interval
        int id = 0;
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        // Process each interval
        for (int i = 1; i < n; i++) {
            int li = scanner.nextInt();
            int ri = scanner.nextInt();
            // Check if the current interval completely covers the best candidate interval
            if (li <= l && r <= ri) {
                id = i;
            }
            // Check if the current interval overlaps with the best candidate interval
            else if (li < l || r < ri) {
                id = n;
            }
            // Update the boundaries of the best candidate interval
            l = Math.min(l, li);
            r = Math.max(r, ri);
        }

        // Output the result
        System.out.println(id == n ? -1 : id + 1);
        
        scanner.close();
    }
}

// <END-OF-CODE>
