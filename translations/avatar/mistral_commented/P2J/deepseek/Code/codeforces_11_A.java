import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements 'n' and the difference 'd'
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Initialize an empty list 'x' to store the input elements
        int[] x = new int[n];
        
        // Read the 'n' elements from the input and store them in the list 'x'
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize variables 'm' and 'q' to 0
        int m = 0;
        int q = 0;
        
        // Iterate through the list 'x' to find the elements that are not in increasing order
        for (int i = 0; i < n - 1; i++) {
            // Check if the current element is greater than or equal to the next element
            if (x[i] >= x[i + 1]) {
                // Calculate the number of elements that need to be added to the next element
                q = (x[i] - x[i + 1]) / d + 1;
                // Add the calculated number of elements to the current and next elements
                m += q;
                x[i + 1] += q * d;
            }
        }
        
        // Print the final result 'm'
        System.out.println(m);
    }
}
