// Define the input size and initialize an empty list for answers
int q = Integer.parseInt(scanner.nextLine());
int[] ans = new int[2];

// Import PriorityQueue class for priority queue implementation
import java.util.PriorityQueue;

// Initialize empty priority queues for piles p1 and p2
PriorityQueue<Integer> p1 = new PriorityQueue<>();
PriorityQueue<Integer> p2 = new PriorityQueue<>();

// Initialize variables for sums of balls and priority queues
int sum_b = 0;
int sum_p1 = 0;
int sum_p2 = 0;

// Iterate through each query
for (int i = 0; i < q; i++) {
    // Check if the current query is to find the answer
    if (scanner.nextInt() == 2) {
        // Check if both piles have equal number of balls
        if (p1.size() == p2.size()) {
            // Calculate the answer and print it
            System.out.println(-p2.peek() + " " + (sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b));
        } else {
            // Calculate the answer and print it
            System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));
        }
    }

    // Else, the current query is to add balls to a pile
    else {
        // Add the number of balls to the total sum
        sum_b += scanner.nextInt();

        // If pile p1 is empty, add the ball to it
        if (p1.isEmpty()) {
            p1.add(scanner.nextInt());
            sum_p1 += p1.peek();
        }

        // Else, check if the ball can be added to pile p1
        else if (p1.peek() <= scanner.nextInt()) {
            p1.add(scanner.nextInt());
            sum_p1 += p1.peek();
        }

        // Else, add the ball to pile p2 and adjust the sums accordingly
        else {
            p2.add(scanner.nextInt());
            sum_p2 += p2.peek();
            sum_p1 -= p2.peek();
            sum_p2 -= p2.peek();
        }

        // Adjust the priority queues if necessary
        if (p1.size() < p2.size()) {
            int k = p2.poll();
            p1.add(-k);
            sum_p2 += k;
            sum_p1 -= k;
        }

        if (p1.size() - 1 > p2.size()) {
            int k = p1.poll();
            p2.add(-k);
            sum_p1 -= k;
            sum_p2 += k;
        }
    }
}

// Print the answer
System.out.println(ans[0] + " " + ans[1]);

