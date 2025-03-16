import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read a list of integers
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Initialize an empty list to store the results
        List<Integer> l2 = new ArrayList<>();
        
        // Iterate over each element in the list l
        for (int i : l) {
            if (i % m == 0) {  // Check if the element is divisible by m
                l2.add(i / m);  // Append the quotient to l2
            } else {
                l2.add(i / m + 1);  // Append the quotient plus one to l2
            }
        }
        
        // Find the maximum value in l2
        int mx = Collections.max(l2);
        
        // Iterate over l2 to find the index of the maximum value
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (l2.get(i) == mx) {
                ind = i;  // Store the index of the maximum value
                break; // Exit the loop once we find the first occurrence
            }
        }
        
        // Print the index of the maximum value plus one
        System.out.println(ind + 1);
        
        scanner.close();
    }
}
// <END-OF-CODE>
