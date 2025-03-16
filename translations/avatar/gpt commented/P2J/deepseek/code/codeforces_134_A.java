import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = Integer.parseInt(scanner.nextLine());
        
        // Read the list of integers
        String[] input = scanner.nextLine().split(" ");
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(input[i]);
        }
        
        // Calculate the sum of the list
        int x = 0;
        for (int num : w) {
            x += num;
        }
        
        // Initialize an empty list to store indices
        List<Integer> d = new ArrayList<>();
        
        // Iterate through each element in the list
        for (int i = 0; i < n; i++) {
            // Check if removing the current element results in an average equal to the current element
            if ((x - w[i]) * 1.0 / (n - 1) == w[i]) {
                // If the condition is met, add the 1-based index to the list
                d.add(i + 1);
            }
        }
        
        // Print the number of valid indices found
        System.out.println(d.size());
        
        // Print the valid indices as a space-separated string
        for (int i = 0; i < d.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(d.get(i));
        }
        System.out.println();
    }
}
