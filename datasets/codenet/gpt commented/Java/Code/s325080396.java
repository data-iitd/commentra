import java.util.Scanner;

class Main {
    // Define a constant for the maximum size of the array
    static final int MAX = 200000;

    public static void main(String[] args) {
        // Create an array to store the input values
        int[] R = new int[MAX];
        
        // Initialize a Scanner object for reading input
        Scanner in = new Scanner(System.in);
        
        // Read the number of elements to be processed
        int n = in.nextInt();
        
        // Read the input values into the array R
        for(int i = 0; i < n; i++) {
            R[i] = in.nextInt();		
        }
        
        // Initialize maxv to the difference between the first two elements
        int maxv = R[1] - R[0];
        // Initialize minv to the first element of the array
        int minv = R[0];
        
        // Iterate through the array starting from the second element
        for(int i = 1; i < n; i++) {
            // Update maxv with the maximum difference found so far
            maxv = Math.max(maxv, R[i] - minv);	
            // Update minv with the minimum value encountered so far
            minv = Math.min(minv, R[i]);
        }
        
        // Output the maximum difference found
        System.out.println(maxv);
    }
}
