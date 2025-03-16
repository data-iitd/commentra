import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();  // Read the number of queries
        long[] ans = {0, 0};  // Initialize the answer array with two zeros
        PriorityQueue<Integer> p1 = new PriorityQueue<>();  // Initialize the first priority queue (min-heap)
        PriorityQueue<Integer> p2 = new PriorityQueue<>(Collections.reverseOrder());  // Initialize the second priority queue (max-heap)
        long sum_b = 0;  // Initialize the sum of differences
        long sum_p1 = 0;  // Initialize the sum of the first priority queue
        long sum_p2 = 0;  // Initialize the sum of the second priority queue

        // Loop through each query
        for (int i = 0; i < q; i++) {
            int type = scanner.nextInt();  // Read the query type
            if (type == 2) {  // Check if the query type is 2
                if (p1.size() == p2.size()) {  // If the sizes of the two heaps are equal
                    System.out.println(-p2.peek() + " " + (sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b));
                } else {  // If the sizes of the two heaps are not equal
                    System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));
                }
            } else {  // If the query type is not 2
                int value = scanner.nextInt();  // Read the value
                sum_b += value;  // Add the given value to the sum of differences
                if (p1.isEmpty()) {  // If the first priority queue is empty
                    p1.offer(value);  // Push the value to the first priority queue
                    sum_p1 += value;  // Update the sum of the first priority queue
                } else if (p1.peek() <= value) {  // If the smallest element in the first priority queue is less than or equal to the given value
                    p1.offer(value);  // Push the value to the first priority queue
                    sum_p1 += value;  // Update the sum of the first priority queue
                } else {  // If the given value is less than the smallest element in the first priority queue
                    p2.offer(value);  // Push the value to the second priority queue
                    sum_p2 += value;  // Update the sum of the second priority queue
                }
                if (p1.size() < p2.size()) {  // If the first priority queue has fewer elements than the second priority queue
                    int k = p2.poll();  // Pop the smallest element from the second priority queue
                    p1.offer(k);  // Push the value to the first priority queue
                    sum_p2 -= k;  // Update the sum of the second priority queue
                    sum_p1 += k;  // Update the sum of the first priority queue
                }
                if (p1.size() - 1 > p2.size()) {  // If the first priority queue has one more element than the second priority queue
                    int k = p1.poll();  // Pop the smallest element from the first priority queue
                    p2.offer(k);  // Push the value to the second priority queue
                    sum_p1 -= k;  // Update the sum of the first priority queue
                    sum_p2 += k;  // Update the sum of the second priority queue
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
