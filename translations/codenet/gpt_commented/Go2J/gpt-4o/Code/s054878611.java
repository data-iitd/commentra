import java.util.Scanner;

public class Main {
    // solution method takes an integer n and an array of integers a.
    // It calculates the maximum frequency of any number or its two consecutive successors in the array.
    public static int solution(int n, int[] a) {
        // Create a memoization array to count occurrences of numbers and their successors.
        int[] memo = new int[100002];
        
        // Iterate through each number in the input array.
        for (int num : a) {
            // Increment the count for the current number and its two successors.
            memo[num]++;
            memo[num + 1]++;
            memo[num + 2]++;
        }
        
        // Initialize the output variable to track the maximum frequency found.
        int out = 0;
        
        // Iterate through the memoization array to find the maximum frequency.
        for (int count : memo) {
            // Update the output if the current count is greater than the current maximum.
            if (count > 0) {
                out = Math.max(out, count);
            }
        }
        
        // Return the maximum frequency found.
        return out;
    }

    // main method is the entry point of the program.
    public static void main(String[] args) {
        // Declare a variable to hold the number of elements.
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        // Create an array to hold the input integers.
        int[] a = new int[n];
        
        // Read each integer into the array.
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Call the solution method and print the result.
        System.out.println(solution(n, a));
        
        scanner.close();
    }
}

// <END-OF-CODE>
