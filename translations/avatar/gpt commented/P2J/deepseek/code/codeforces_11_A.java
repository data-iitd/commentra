import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and d from input
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Initialize an empty list to store the elements
        List<Integer> x = new ArrayList<>();
        
        // Read the elements of the list from input and split them into individual strings
        for (int i = 0; i < n; i++) {
            x.add(scanner.nextInt());
        }
        
        // Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
        int m = 0;
        
        // Iterate through the list to compare adjacent elements
        for (int a = 0; a < n - 1; a++) {
            // Check if the current element is greater than or equal to the next element
            if (x.get(a) >= x.get(a + 1)) {
                // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
                int q = (x.get(a) - x.get(a + 1)) / d + 1;
                // Update the total adjustments made
                m = m + q;
                // Adjust the next element by adding the necessary increments of d
                x.set(a + 1, x.get(a + 1) + q * d);
            }
        }
        
        // Print the total number of adjustments made
        System.out.println(m);
    }
}
