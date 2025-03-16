import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read the number of elements (n) and the maximum value (m)
        int n = in.nextInt();
        int m = in.nextInt();
        
        // Initialize an array to store the input values
        int arr[] = new int[n];
        
        // Initialize a frequency array to count occurrences of each number from 1 to 10
        int gen[] = new int[11]; // gen[0] will remain unused
        
        // Read n integers from input and populate the arr and gen arrays
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt(); // Store the input value in arr
            gen[arr[i]]++; // Increment the count of the corresponding number in gen
        }
        
        // Initialize a variable to hold the final answer
        long ans = 0;
        
        // Calculate the number of valid pairs (i, k) where i != k
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= m; k++) {
                if (i != k) {
                    // Add the product of the counts of i and k to the answer
                    ans += (long) gen[i] * gen[k];
                }
            }
        }
        
        // Since each pair (i, k) is counted twice, divide the result by 2
        System.out.println(ans / 2);
    }
}
