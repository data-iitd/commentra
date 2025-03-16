import java.util.Scanner; // Import the Scanner class for input and output operations

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object for input
        int N = sc.nextInt(); // Read an integer value from the standard input and store it in N
        int[] A = new int[N]; // Declare an array A of size N
        for (int i = 0; i < N; i++) A[i] = sc.nextInt(); // Read N integers from the standard input and store them in the array A

        int m = A[0]; // Initialize the variable m to the first element of the array A
        int M = A[0]; // Initialize the variable M to the first element of the array A
        for (int i = 0; i < N; i++) { // Start a loop that iterates through the array A
            if (A[i] < m) m = A[i]; // If the current element is less than m, update m to the current element
            if (A[i] > M) M = A[i]; // If the current element is greater than M, update M to the current element
        }

        System.out.println(M - m); // Print the difference between the maximum and minimum values in the array A
    }
}

