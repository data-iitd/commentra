import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Define the scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements 'n' and the modulus 'm'
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize an array 'l' to store the elements
        int[] l = new int[n];
        
        // Read the elements into the array 'l'
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Initialize a list 'l2' to store the quotient of each element in 'l' divided by 'm'
        List<Integer> l2 = new ArrayList<>();
        
        // Iterate through each element 'i' in the array 'l'
        for (int i = 0; i < n; i++) {
            // Check if the element 'i' is divisible by 'm'
            if (l[i] % m == 0) {
                l2.add(l[i] / m);
            } else {
                l2.add(l[i] / m + 1);
            }
        }
        
        // Find the maximum quotient in 'l2'
        int mx = Collections.max(l2);
        
        // Initialize the index variable 'ind'
        int ind = -1;
        
        // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
        for (int i = 0; i < n; i++) {
            // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'
            if (l2.get(i) == mx) {
                ind = i;
                break; // We can break since we only need the first occurrence
            }
        }
        
        // Print the index 'ind' plus one (since the indices in Java start from 0)
        System.out.println(ind + 1);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
