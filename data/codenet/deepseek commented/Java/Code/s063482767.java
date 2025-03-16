import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input
        Scanner sc = new Scanner(System.in);
        // Read the number of elements
        int n = sc.nextInt();
        // Initialize a priority queue to store the elements
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        // Read n elements from the user and add them to the priority queue
        for(int i = 0; i < n; i++) {
            queue.add(sc.nextInt());
        }
        // Initialize sum to store the sum of the smallest n-1 elements
        int sum = 0;
        // Calculate the sum of the smallest n-1 elements
        for(int i = 0; i < n - 1; i++) {
            sum += queue.poll();
        }
        // Compare the remaining element with the sum and print the result
        System.out.println(queue.poll() < sum ? "Yes" : "No");
    }
}
