import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the user
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        
        // Create an array to store the elements
        int[] h = new int[n];
        
        // Read the elements into the array
        for (int i = 0 ; i < n ; i++) {
            h[i] = sc.nextInt();
        }
        
        // Initialize the maximum length of non-increasing subsequence to 0
        int max = 0;
        
        // Loop through the array to find the longest non-increasing subsequence
        for (int l = 0 ; l < n - 1 ; l++) {
            // Initialize a counter for the current non-increasing subsequence
            int count = 0;
            
            // While the current element is greater than or equal to the next element,
            // increment the counter and move to the next element
            while (l < n - 1 && h[l] >= h[l + 1]) {
                l++;
                count++;
            }
            
            // Update the maximum length if the current subsequence is longer
            max = Math.max(max, count);
        }
        
        // Print the length of the longest non-increasing subsequence
        System.out.println(max);
    }
}
