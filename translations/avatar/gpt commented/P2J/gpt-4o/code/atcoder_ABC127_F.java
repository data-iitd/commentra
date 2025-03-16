import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of queries
        int q = scanner.nextInt();
        
        // Initialize answers and sums
        long sumB = 0;
        long sumP1 = 0;
        long sumP2 = 0;

        // Initialize two priority queues for managing two groups of numbers
        PriorityQueue<Long> p1 = new PriorityQueue<>(); // Min-heap for p1
        PriorityQueue<Long> p2 = new PriorityQueue<>(Collections.reverseOrder()); // Max-heap for p2

        // Process each query
        for (int i = 0; i < q; i++) {
            int queryType = scanner.nextInt();
            if (queryType == 2) {
                // If both heaps are of equal length, calculate and print the result based on p2
                if (p1.size() == p2.size()) {
                    System.out.println(-p2.peek() + sumP1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sumP2 + sumB);
                } else {
                    // If p1 is longer, calculate and print the result based on p1
                    System.out.println(p1.peek() + sumP1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sumP2 + sumB);
                }
            } else {
                long value = scanner.nextLong();
                sumB += value; // Add the third element of the query to the sumB
                
                // If p1 is empty, push the new value into p1
                if (p1.isEmpty()) {
                    p1.offer(value);
                    sumP1 += value;
                } 
                // If the new value is greater than or equal to the smallest in p1, push it to p1
                else if (p1.peek() <= value) {
                    p1.offer(value);
                    sumP1 += value;
                } 
                // Otherwise, push the new value into p2 (to maintain max-heap behavior)
                else {
                    p2.offer(value);
                    sumP2 += value;
                }

                // Balance the heaps if p1 has fewer elements than p2
                if (p1.size() < p2.size()) {
                    long k = p2.poll(); // Pop the largest from p2
                    p1.offer(k); // Push it to p1
                    sumP2 -= k; // Update sumP2
                    sumP1 += k; // Update sumP1
                }

                // Balance the heaps if p1 has more than one extra element compared to p2
                if (p1.size() - 1 > p2.size()) {
                    long k = p1.poll(); // Pop the smallest from p1
                    p2.offer(k); // Push it to p2
                    sumP1 -= k; // Update sumP1
                    sumP2 += k; // Update sumP2
                }
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
