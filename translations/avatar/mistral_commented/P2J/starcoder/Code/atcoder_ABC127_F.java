// Define the input size and initialize an empty list for answers
int q = Integer.parseInt(input());
List<Integer> ans = new ArrayList<Integer>();

// Import heapq module for priority queue implementation
import java.util.PriorityQueue;

// Initialize empty priority queues for piles p1 and p2
PriorityQueue<Integer> p1 = new PriorityQueue<Integer>();
PriorityQueue<Integer> p2 = new PriorityQueue<Integer>();

// Initialize variables for sums of balls and priority queues
int sum_b = 0;
int sum_p1 = 0;
int sum_p2 = 0;

// Iterate through each query
for (int i = 0; i < q; i++) {
    String[] ql = input().split(" ");

    // Check if the current query is to find the answer
    if (Integer.parseInt(ql[0]) == 2) {
        // Check if both piles have equal number of balls
        if (p1.size() == p2.size()) {
            // Calculate the answer and print it
            ans.add(-p2.peek());
            ans.add(sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b);
        } else {
            // Calculate the answer and print it
            ans.add(p1.peek());
            ans.add(sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b);
        }
    }

    // Else, the current query is to add balls to a pile
    else {
        // Add the number of balls to the total sum
        sum_b += Integer.parseInt(ql[2]);

        // If pile p1 is empty, add the ball to it
        if (p1.isEmpty()) {
            p1.add(Integer.parseInt(ql[1]));
            sum_p1 += Integer.parseInt(ql[1]);
        }

        // Else, check if the ball can be added to pile p1
        else if (p1.peek() <= Integer.parseInt(ql[1])) {
            p1.add(Integer.parseInt(ql[1]));
            sum_p1 += Integer.parseInt(ql[1]);
        }

        // Else, add the ball to pile p2 and adjust the sums accordingly
        else {
            p2.add(-Integer.parseInt(ql[1]));
            sum_p2 += Integer.parseInt(ql[1]);
            sum_p1 -= Integer.parseInt(ql[1]);
            sum_p2 -= Integer.parseInt(ql[1]);
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
for (int i = 0; i < ans.size(); i++) {
    System.out.print(ans.get(i) + " ");
}

