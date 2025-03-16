import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize a scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of integers to be processed
        int n = sc.nextInt();
        
        // Create a priority queue to store the integers
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        
        // Read n integers from the input and add them to the priority queue
        for(int i = 0; i < n; i++) {
            queue.add(sc.nextInt());
        }
        
        // Initialize a variable to hold the sum of the smallest n-1 integers
        int sum = 0;
        
        // Poll the smallest n-1 integers from the queue and accumulate their sum
        for(int i = 0; i < n - 1; i++) {
            sum += queue.poll();
        }

        // Compare the last remaining integer in the queue with the sum of the smallest n-1 integers
        // Output "Yes" if the last integer is less than the sum, otherwise output "No"
        System.out.println(queue.poll() < sum ? "Yes" : "No");
    }
}
