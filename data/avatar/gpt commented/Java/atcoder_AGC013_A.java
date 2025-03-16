import java.util.*; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner stdIn = new Scanner(System.in);
        
        // Reading the number of elements N from user input
        int N = stdIn.nextInt();
        
        // Initializing an array A of size N to store the input integers
        int[] A = new int[N];
        
        // Loop to read N integers from user input and store them in array A
        for (int i = 0; i < N; i++) {
            A[i] = stdIn.nextInt();
        }
        
        // Initializing a counter to keep track of the number of segments
        int count = 0;
        
        // Loop through the array to identify segments of increasing or decreasing values
        for (int i = 0; i < N; i++) {
            // If we are at the last element, increment the count
            if (i == N - 1) {
                count++;
            } 
            // If the current element is equal to the next element, do nothing
            else if (A[i] == A[i + 1]) {
                // No action needed, just continue
            } 
            // If the current element is less than the next element, find the end of the increasing segment
            else if (A[i] < A[i + 1]) {
                while (A[i] <= A[i + 1]) {
                    i++; // Move to the next element
                    // Break if we reach the end of the array
                    if (i == N - 1) break;
                }
                // Increment the count for the found segment
                count++;
            } 
            // If the current element is greater than the next element, find the end of the decreasing segment
            else {
                while (A[i] >= A[i + 1]) {
                    i++; // Move to the next element
                    // Break if we reach the end of the array
                    if (i == N - 1) break;
                }
                // Increment the count for the found segment
                count++;
            }
        }
        
        // Output the total number of segments found
        System.out.println(count);
    }
}
