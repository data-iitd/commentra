import java.util.PriorityQueue;
import java.util.Scanner;

public class MedianCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();  // Read the number of queries
        PriorityQueue<Integer> p1 = new PriorityQueue<>();  // Initialize the first priority queue
        PriorityQueue<Integer> p2 = new PriorityQueue<>((a, b) -> b - a);  // Initialize the second priority queue
        int sum_b = 0;  // Initialize the sum of differences
        int sum_p1 = 0;  // Initialize the sum of the first priority queue
        int sum_p2 = 0;  // Initialize the sum of the second priority queue

        // Loop through each query
        for (int i = 0; i < q; i++) {
            int[] ql = new int[3];
            ql[0] = scanner.nextInt();  // Read the query type
            if (ql[0] == 2) {  // Check if the query type is 2
                if (p1.size() == p2.size()) {  // If the sizes of the two heaps are equal
                    System.out.println(-p2.peek() + " " + (sum_p1 - p1.size() * p2.peek() + p2.size() * p2.peek() - sum_p2 + sum_b));  // Print the median and the sum of differences
                } else {  // If the sizes of the two heaps are not equal
                    System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));  // Print the median and the sum of differences
                }
            } else {  // If the query type is not 2
                ql[1] = scanner.nextInt();  // Read the first value
                ql[2] = scanner.nextInt();  // Read the second value
                sum_b += ql[2];  // Add the given value to the sum of differences
                if (p1.isEmpty()) {  // If the first priority queue is empty
                    p1.add(ql[1]);  // Add the value to the first priority queue
                    sum_p1 += ql[1];  // Update the sum of the first priority queue
                } else if (p1.peek() <= ql[1]) {  // If the smallest element in the first priority queue is less than or equal to the given value
                    p1.add(ql[1]);  // Add the value to the first priority queue
                    sum_p1 += ql[1];  // Update the sum of the first priority queue
                } else {  // If the given value is less than the smallest element in the first priority queue
                    p2.add(ql[1]);  // Add the negative value to the second priority queue
                    sum_p2 += ql[1];  // Update the sum of the second priority queue
                }
                if (p1.size() < p2.size()) {  // If the first priority queue has fewer elements than the second priority queue
                    p1.add(p2.poll());  // Move the smallest element from the second priority queue to the first priority queue
                    sum_p2 -= p1.peek();  // Update the sum of the second priority queue
                    sum_p1 += p1.peek();  // Update the sum of the first priority queue
                }
                if (p1.size() - 1 > p2.size()) {  // If the first priority queue has one more element than the second priority queue
                    p2.add(p1.poll());  // Move the smallest element from the first priority queue to the second priority queue
                    sum_p1 -= p2.peek();  // Update the sum of the first priority queue
                    sum_p2 += p2.peek();  // Update the sum of the second priority queue
                }
            }
        }
    }
}
