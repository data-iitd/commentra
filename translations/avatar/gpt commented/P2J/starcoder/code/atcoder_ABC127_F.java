// Read the number of queries
int q = Integer.parseInt(br.readLine());
// Initialize answers and sums
int[] ans = new int[2];
int sum_b = 0;
int sum_p1 = 0;
int sum_p2 = 0;

// Initialize two heaps for managing two groups of numbers
PriorityQueue<Integer> p1 = new PriorityQueue<>();
PriorityQueue<Integer> p2 = new PriorityQueue<>(Collections.reverseOrder());

// Process each query
for (int i = 0; i < q; i++) {
    // Read the query line and convert it to a list of integers
    String[] ql = br.readLine().split(" ");
    int[] query = new int[ql.length];
    for (int j = 0; j < ql.length; j++) {
        query[j] = Integer.parseInt(ql[j]);
    }

    // If the query type is 2, perform a specific operation
    if (query[0] == 2) {
        // If both heaps are of equal length, calculate and print the result based on p2
        if (p1.size() == p2.size()) {
            ans[0] = -p2.peek();
            ans[1] = sum_p1 - p1.size() * ans[0] + p2.size() * ans[0] - sum_p2 + sum_b;
        } else {
            // If p1 is longer, calculate and print the result based on p1
            ans[0] = p1.peek();
            ans[1] = sum_p1 - p1.size() * ans[0] + p2.size() * ans[0] - sum_p2 + sum_b;
        }
        System.out.println(ans[0] + " " + ans[1]);
    } else {
        // If the query type is 1, update the heaps and sums
        sum_b += query[2];  // Add the third element of the query to the sum_b

        // If p1 is empty, push the new value into p1
        if (p1.isEmpty()) {
            p1.add(query[1]);
            sum_p1 += query[1];
        }
        // If the new value is greater than or equal to the smallest in p1, push it to p1
        else if (p1.peek() <= query[1]) {
            p1.add(query[1]);
            sum_p1 += query[1];
        }
        // Otherwise, push the negative of the new value into p2 (to maintain max-heap behavior)
        else {
            p2.add(-query[1]);
            sum_p2 += query[1];
        }

        // Balance the heaps if p1 has fewer elements than p2
        if (p1.size() < p2.size()) {
            int k = p2.poll();  // Pop the largest from p2
            p1.add(-k);  // Push it to p1 (as positive)
            sum_p2 += k;  // Update sum_p2
            sum_p1 -= k;  // Update sum_p1
        }

        // Balance the heaps if p1 has more than one extra element compared to p2
        if (p1.size() - 1 > p2.size()) {
            int k = p1.poll();  // Pop the smallest from p1
            p2.add(-k);  // Push it to p2 (as negative)
            sum_p1 -= k;  // Update sum_p1
            sum_p2 += k;  // Update sum_p2
    }
}

