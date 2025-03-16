import java.util.ArrayList; // Import ArrayList for dynamic array
import java.util.Scanner; // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // Initialize Scanner object
        int n = input.nextInt(); // Read the number of elements n
        int m = input.nextInt(); // Read the number of elements m
        
        ArrayList<Integer> req = new ArrayList<>(); // Initialize ArrayList req
        ArrayList<Integer> pre = new ArrayList<>(); // Initialize ArrayList pre
        
        // Read elements into req
        for (int i = 0; i < n; i++) {
            req.add(input.nextInt());
        }
        
        // Read elements into pre
        for (int i = 0; i < m; i++) {
            pre.add(input.nextInt());
        }
        
        int i = n - 1, j = m - 1; // Initialize indices i and j
        int ans = 0; // Initialize ans to store the result
        
        // Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
        while (i >= 0 && j >= 0) {
            if (req.get(i) > pre.get(j)) { // If the element in req is greater than the element in pre
                ans++; // Increment ans
            } else {
                j--; // Decrement j to check the next element in pre
            }
            i--; // Decrement i in each iteration
        }
        
        // Print the result which is the sum of ans and the remaining elements in req
        System.out.print(ans + i + 1);
    }
}
