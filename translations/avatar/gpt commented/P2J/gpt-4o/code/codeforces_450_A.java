import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read a list of n integers from input
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Initialize an array to store the results after processing the input list
        int[] l2 = new int[n];
        
        // Iterate through each element in the input list
        for (int i = 0; i < n; i++) {
            // If the current element is divisible by m, store the quotient in l2
            if (l[i] % m == 0) {
                l2[i] = l[i] / m;
            } else {
                l2[i] = l[i] / m + 1; // Append the quotient plus one to l2
            }
        }
        
        // Find the maximum value in the processed list l2
        int mx = l2[0];
        for (int i = 1; i < n; i++) {
            if (l2[i] > mx) {
                mx = l2[i];
            }
        }
        
        // Iterate through the range of n to find the index of the maximum value in l2
        int ind = 0; // Initialize index
        for (int i = 0; i < n; i++) {
            if (l2[i] == mx) {
                ind = i; // Store the index of the maximum value
                break; // Break after finding the first occurrence
            }
        }
        
        // Print the index of the maximum value (1-based index)
        System.out.println(ind + 1);
        
        scanner.close();
    }
}
// <END-OF-CODE>
