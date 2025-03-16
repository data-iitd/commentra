import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read a list of n integers from input
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }
        
        // Initialize an empty list to store the results after processing the input list
        List<Integer> l2 = new ArrayList<>();
        
        // Iterate through each element in the input list
        for (int i : l) {
            // If the current element is divisible by m, append the quotient to l2
            if (i % m == 0) {
                l2.add(i / m);
            } else {
                // If the current element is not divisible by m, append the quotient plus one to l2
                l2.add(i / m + 1);
            }
        }
        
        // Find the maximum value in the processed list l2
        int mx = l2.stream().max(Integer::compare).get();
        
        // Iterate through the range of n to find the index of the maximum value in l2
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (l2.get(i) == mx) {
                ind = i;  // Store the index of the maximum value
                break;
            }
        }
        
        // Print the index of the maximum value (1-based index)
        System.out.println(ind + 1);
    }
}
