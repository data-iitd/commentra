public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[105]; // Step 2: Initialize array to keep track of positions

        for(int i = 0; i < m; ++i) {
            int temp = scanner.nextInt(); // Read the positions to be marked
            a[temp] = 1; // Step 3: Mark the positions in array a
        }

        int ansl = 0, ansr = 0; // Initialize variables to store distances
        for(int i = x; i <= n; ++i) { // Step 4: Calculate the number of marked positions to the right of x
            ansr += a[i];
        }
        for(int i = x; i >= 0; --i) { // Calculate the number of marked positions to the left of x
            ansl += a[i];
        }

        System.out.println(Math.min(ansl, ansr)); // Step 5: Print the minimum of the left and right distances
    }
}
