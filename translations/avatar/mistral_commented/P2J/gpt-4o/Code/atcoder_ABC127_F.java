import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Define the input size and initialize an empty list for answers
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        long sumB = 0;
        long sumP1 = 0;
        long sumP2 = 0;

        // Initialize empty priority queues for piles p1 and p2
        PriorityQueue<Long> p1 = new PriorityQueue<>();
        PriorityQueue<Long> p2 = new PriorityQueue<>(Collections.reverseOrder());

        // Iterate through each query
        for (int i = 0; i < q; i++) {
            int queryType = scanner.nextInt();
            if (queryType == 2) {
                // Check if both piles have equal number of balls
                if (p1.size() == p2.size()) {
                    // Calculate the answer and print it
                    long answer = -p2.peek();
                    System.out.println(answer + (sumP1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sumP2 + sumB));
                } else {
                    // Calculate the answer and print it
                    long answer = p1.peek();
                    System.out.println(answer + (sumP1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sumP2 + sumB));
                }
            } else {
                long balls = scanner.nextLong();
                long pileValue = scanner.nextLong();
                // Add the number of balls to the total sum
                sumB += balls;

                // If pile p1 is empty, add the ball to it
                if (p1.isEmpty()) {
                    p1.add(pileValue);
                    sumP1 += pileValue;
                } else if (p1.peek() <= pileValue) {
                    p1.add(pileValue);
                    sumP1 += pileValue;
                } else {
                    p2.add(pileValue);
                    sumP2 += pileValue;
                    sumP1 -= pileValue;
                    sumP2 -= pileValue;
                }

                // Adjust the priority queues if necessary
                if (p1.size() < p2.size()) {
                    long k = p2.poll();
                    p1.add(k);
                    sumP2 -= k;
                    sumP1 += k;
                }

                if (p1.size() - 1 > p2.size()) {
                    long k = p1.poll();
                    p2.add(k);
                    sumP1 -= k;
                    sumP2 += k;
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
