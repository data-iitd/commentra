import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Check if there is input available
        if (scanner.hasNext()) {
            // Read the size of the array
            int n = scanner.nextInt();
            // Initialize the array to hold n integers
            int arr[] = new int[n];
            
            // Populate the array with user input
            for (int i = 0; i < n; i++)
                arr[i] = scanner.nextInt();
            
            // Initialize max to the smallest possible integer value
            int max = Integer.MIN_VALUE;
            
            // Iterate through all possible subarrays
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    // Initialize a temporary variable to track the index for brr
                    int x = 0;
                    // Create a copy of the original array
                    int brr[] = new int[n];
                    for (int k : arr)
                        brr[x++] = k;
                    
                    // Flip the values in the subarray from index i to j
                    for (int k = i; k <= j; k++) {
                        if (brr[k] == 0)
                            brr[k] = 1; // Change 0 to 1
                        else
                            brr[k] = 0; // Change 1 to 0
                    }
                    
                    // Count the number of 1's in the modified array
                    int count = checKNo(brr);
                    
                    // Update max if the current count is greater
                    if (count > max)
                        max = count;
                }
            }
            
            // Handle the case when there is only one element in the array
            if (n == 1) {
                if (arr[0] == 1)
                    System.out.println(0); // Output 0 if the single element is 1
                else
                    System.out.println(1); // Output 1 if the single element is 0
            } else {
                // Output the maximum count of 1's found
                System.out.println(max);
            }
        }
    }

    // Method to count the number of 1's in the given array
    private static int checKNo(int[] brr) {
        int val = 0;
        // Count each occurrence of 1 in the array
        for (int i : brr)
            if (i == 1)
                ++val;
        return val; // Return the total count of 1's
    }
}
