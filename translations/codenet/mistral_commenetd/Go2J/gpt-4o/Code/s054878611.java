import java.util.Scanner;

public class Main {
    // Function to find the maximum number of occurrences of a number in the array
    public static int solution(int n, int[] a) {
        // Initialize a memo table to store the number of occurrences of each number
        int[] memo = new int[100002];

        // Iterate through the array and update the memo table
        for (int num : a) {
            // Increment the memo table for the current number and the next two numbers
            memo[num]++;
            memo[num + 1]++;
            memo[num + 2]++;
        }

        // Initialize output variable to store the maximum number of occurrences found
        int out = 0;

        // Iterate through the memo table and update the output variable if a larger number is found
        for (int num : memo) {
            if (num > 0) {
                // Update the output variable with the maximum number found so far
                out = Math.max(out, num);
            }
        }

        // Return the maximum number of occurrences found
        return out;
    }

    // Main function to read input and call the solution function
    public static void main(String[] args) {
        // Read the size of the array from the standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Allocate memory for the array and read its elements from the standard input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Call the solution function and print the result
        System.out.println(solution(n, a));
        scanner.close();
    }
}

// <END-OF-CODE>
