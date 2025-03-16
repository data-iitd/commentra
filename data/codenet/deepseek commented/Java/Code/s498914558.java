import java.util.*; // Importing Scanner for Input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner for user input
        int n = sc.nextInt(); // Read the number of elements
        int m = sc.nextInt(); // Read the initial value of m

        int[] po = new int[n]; // Initialize array to store elements
        for (int i = 0; i < n; i++) {
            po[i] = sc.nextInt(); // Populate the array with n integers
            m -= po[i]; // Subtract each element from m
        }

        Arrays.sort(po); // Sort the array
        System.out.println(n + m / po[0]); // Calculate and print the result
    }
}
