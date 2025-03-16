import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Read the number of elements in the array
        int N = scan.nextInt();
        
        // Initialize an array to hold the input values
        int[] a = new int[N];
        
        // Populate the array with input values
        for (int i = 0; i < N; ++i) {
            a[i] = scan.nextInt();
        }
        
        // Arrays to hold the counts of elements to the left and right of each element
        int[] leftl = new int[N];
        int[] rightl = new int[N];
        
        // Deque to help with calculating the left and right counts
        ArrayDeque<Integer> que = new ArrayDeque<>();
        
        // Calculate the right counts for each element
        int index = 0;
        while (index < N) {
            // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
            while (!que.isEmpty() && a[que.peek()] > a[index]) {
                // Pop the index from the deque and calculate the right count
                int ind = que.poll();
                rightl[ind] = index - ind - 1;
            }
            // Push the current index onto the deque
            que.push(index++);
        }
        
        // For any remaining indices in the deque, calculate the right counts
        while (!que.isEmpty()) {
            int ind = que.poll();
            rightl[ind] = N - ind - 1;
        }
        
        // Reset index to calculate left counts
        index = N - 1;
        
        // Calculate the left counts for each element
        while (index >= 0) {
            // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
            while (!que.isEmpty() && a[que.peek()] > a[index]) {
                // Pop the index from the deque and calculate the left count
                int ind = que.poll();
                leftl[ind] = ind - index - 1;
            }
            // Push the current index onto the deque
            que.push(index--);
        }
        
        // For any remaining indices in the deque, calculate the left counts
        while (!que.isEmpty()) {
            int ind = que.poll();
            leftl[ind] = ind - index - 1;
        }
        
        // Calculate the final answer based on the left and right counts
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            // For each element, multiply its value by the number of valid subarrays it can form
            ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
        }
        
        // Output the final result
        System.out.println(ans);
    }
}
