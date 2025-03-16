#######
# Import necessary libraries
#######

import java.util.*;

# Define helper functions
class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class PairComparator implements Comparator<Pair> {
    @Override
    public int compare(Pair p1, Pair p2) {
        return p1.first - p2.first;
    }
}

class PairHeap {
    PriorityQueue<Pair> heap;

    PairHeap() {
        heap = new PriorityQueue<>(new PairComparator());
    }

    void push(int first, int second) {
        heap.add(new Pair(first, second));
    }

    Pair pop() {
        return heap.poll();
    }
}

#######
# Function to find the solution
#######

void solution() {
    // Read the first line and count the number of occurrences of each color
    String line = scanner.nextLine();
    Map<Character, Integer> boughtCount = new HashMap<>();
    for (char c : line.toCharArray()) {
        boughtCount.put(c, boughtCount.getOrDefault(c, 0) + 1);
    }

    // Read the second line and count the number of occurrences of each color
    line = scanner.nextLine();
    Map<Character, Integer> madeCount = new HashMap<>();
    for (char c : line.toCharArray()) {
        madeCount.put(c, madeCount.getOrDefault(c, 0) + 1);
    }

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in madeCount
    for (char color : madeCount.keySet()) {
        // Check if the color is present in boughtCount
        if (!boughtCount.containsKey(color)) {
            // If not, print -1 and exit the function
            System.out.println(-1);
            return;
        }

        // Update the result by adding the minimum of bought and made counts
        res += Math.min(boughtCount.get(color), madeCount.get(color));
    }

    // Print the result
    System.out.println(res);
}

#######
# Main function to run the solution function for multiple test cases
#######

void main() {
    // Read the number of test cases
    int t = scanner.nextInt();

    // Run the solution function for each test case
    for (int i = 0; i < t; i++) {
        solution();
    }
}

// Run the main function
main();

