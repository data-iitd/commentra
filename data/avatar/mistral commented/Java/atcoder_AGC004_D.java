
import java.util.ArrayList; // Importing ArrayList and List classes
import java.util.List;
import java.util.Scanner; // Importing Scanner class

public class Main {
    public static void main(String[] args) {
        // Creating a new thread and passing it a new instance of MyRunnable class
        new Thread(null, new MyRunnable(), "", 1 << 26).start();
    }

    static class MyRunnable implements Runnable {
        @Override
        public void run() {
            int n; // Variable to store the number of test cases
            int k; // Variable to store the value of k
            List<Integer> as; // List to store the input array

            try (Scanner sc = new Scanner(System.in)) {
                // Reading input values for n and k
                n = sc.nextInt();
                k = sc.nextInt();

                // Reading input values for the array as
                as = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    as.add(sc.nextInt() - 1);
                }
            }

            // Printing the result of the calculation
            System.out.println(new Calculator(n, k, as).calculate());
        }
    }

    static class Calculator {
        private int k; // Variable to store the value of k
        private int answer = 0; // Variable to store the answer
        private boolean isCalculate = false; // Flag to check if calculation has been done
        private List<List<Integer>> lists; // 2D list to store the adjacency list representation of the graph

        Calculator(int n, int k, List<Integer> as) {
            this.k = k;
            lists = new ArrayList<>();

            // Initializing the 2D list with ArrayLists of size n
            for (int i = 0; i < n; i++) {
                lists.add(new ArrayList<>());
            }

            // Building the adjacency list representation of the graph
            for (int i = 0; i < n; i++) {
                int j = as.get(i);
                if (0 < i) {
                    lists.get(j).add(i); // Adding the index of the current node to the list of neighbors of node j
                } else if (0 < j) {
                    answer++; // Incrementing the answer if the input array contains a negative index
                }
            }
        }

        int calculate() {
            if (!isCalculate) {
                dfs(0, -1); // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
                isCalculate = true;
            }
            return answer;
        }

        private int dfs(int a, int pre) {
            int h = 0; // Variable to store the height of the current node in the DFS tree

            for (int i : lists.get(a)) { // Iterating through the neighbors of the current node
                h = Math.max(h, dfs(i, a)); // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
            }

            if (0 < pre && h == k - 1) { // Checking if the current node is at the desired height k - 1 from the previous node
                h = 0; // Resetting the height to 0 if it is
                answer++; // Incrementing the answer if the current node is at the desired height
            } else {
                h++; // Incrementing the height if the current node is not the base case
            }

            return h; // Returning the height of the current node
        }
    }
}

These comments should provide a clear understanding of the code logic for each block. Let me know if you need any further clarification.