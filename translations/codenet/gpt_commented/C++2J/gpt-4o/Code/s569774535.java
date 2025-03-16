import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to store the elements
        int[] a = new int[n];

        // Input the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize the answer counter
        int ans = 0;

        // Loop until an odd number is found in the array
        while (true) {
            // Check each element in the array
            boolean foundOdd = false;
            for (int i = 0; i < n; i++) {
                // If the current element is odd, print the answer and exit
                if (a[i] % 2 == 1) {
                    System.out.println(ans);
                    return;
                }
                // If the current element is even, divide it by 2
                else {
                    a[i] /= 2;
                }
            }
            // Increment the answer counter for each complete iteration
            ans++;
        }
    }
}
// <END-OF-CODE>
