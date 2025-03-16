
#####
// Import necessary modules and set recursion limit
#####
import java.util.*;

#####
// Initialize an empty graph using HashMap
#####
Map<Integer, List<Integer>> graph = new HashMap<>();

#####
// Read input: number of nodes N and color limit K
#####
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
int K = scanner.nextInt();

#####
// Read edges between nodes and add them to the graph
#####
for (int i = 0; i < N - 1; i++) {
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    graph.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
    graph.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
}

#####
// Define a recursive function dfs to calculate the answer
#####
long mod = 100000007;
long dfs(int fro, int to, int f) {
    /**
    Calculate the answer using Depth First Search.

    Parameters:
    fro (int): The current node.
    to (int): The target node.
    f (int): The current color.

    Returns:
    long: The number of ways to color the graph.
    */

    // Initialize case number and color number
    long caseNum = f == K? 1 : 0;
    int colorNum = f == K? 0 : K - 2;

    // Iterate through the neighbors of the current node
    for (int u : graph.getOrDefault(fro, Collections.emptyList())) {
        // Skip the target node
        if (u == to) {
            continue;
        }

        // Recursively call dfs on the neighbor and update case number
        long pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = caseNum * pat % mod;
        colorNum--;
    }

    // Return the final case number
    return caseNum;
}

#####
// Call the dfs function with initial values and print the result
#####
long ans = dfs(1, 0, K);
System.out.println(ans);
