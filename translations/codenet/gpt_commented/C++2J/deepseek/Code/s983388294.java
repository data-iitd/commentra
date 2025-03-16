public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to store the input elements
        int[] a = new int[n];

        // Read n integers into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize a counter for the current expected number
        int curr = 0;

        // Iterate through the array to find the longest prefix of consecutive integers starting from 1
        for (int i = 0; i < n; i++) {
            if (a[i] == curr + 1) {
                curr++; // Increment curr if the current element matches the expected value
            }
        }

        // Check if any consecutive integers were found
        if (curr > 0) {
            // Print the number of elements not in the consecutive sequence
            System.out.println(n - curr);
        } else {
            // If no consecutive integers were found, print -1
            System.out.println("-1");
        }
    }
}
