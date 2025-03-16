import java.util.*;

public class Main {
    
    public static void main(String args[]){
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array
        int N = sc.nextInt();
        // Initialize an array to hold the integers
        int[] A = new int[N];
        // Initialize variables to track the minimum absolute value, count of negative numbers, and the sum of absolute values
        int min = Integer.MAX_VALUE;
        int count = 0;
        long sum = 0;

        // Loop through the input values to populate the array and calculate necessary statistics
        for(int i = 0; i < N; i++){
            // Read the next integer and store it in the array
            A[i] = sc.nextInt();
            // Check if the number is negative and increment the count if it is
            if(A[i] < 0)
                count++;
            // Update the minimum absolute value found so far
            min = Math.min(min, Math.abs(A[i]));
            // Accumulate the sum of absolute values
            sum += Math.abs(A[i]);
        }
        // Close the scanner to prevent resource leaks
        sc.close();

        // If the count of negative numbers is even, print the total sum of absolute values
        if(count % 2 == 0)
            System.out.println(sum);
        else {
            // If the count is odd, print the sum minus twice the minimum absolute value
            System.out.println(sum - min * 2);
        }
    }
}
