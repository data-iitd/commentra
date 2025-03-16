import java.util.*;
import java.util.HashMap;
public class StronglyConnectedComponentOptimized {
    public void btrack(Map<Integer, List<Integer>> adjList, int[] visited, Stack<Integer> dfsCallsNodes, int currentNode) {
        visited[currentNode] = 1;
        List<Integer> neighbors = adjList.get(currentNode);
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) {
                    btrack(adjList, visited, dfsCallsNodes, neighbor);
                }
            }
        }
        dfsCallsNodes.add(currentNode);
    }
    public void btrack2(Map<Integer, List<Integer>> adjRevList, int[] visited, int currentNode, List<Integer> newScc) {
        visited[currentNode] = 1;
        newScc.add(currentNode);
        List<Integer> neighbors = adjRevList.get(currentNode);
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) {
                    btrack2(adjRevList, visited, neighbor, newScc);
                }
            }
        }
    }
    public int getOutput(Map<Integer, List<Integer>> adjList, int n) {
        int[] visited = new int[n];
        Arrays.fill(visited, -1);
        Stack<Integer> dfsCallsNodes = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                btrack(adjList, visited, dfsCallsNodes, i);
            }
        }
        Map<Integer, List<Integer>> adjRevList = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adjRevList.put(i, new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            List<Integer> neighbors = adjList.get(i);
            if (neighbors != null) {
                for (int neighbor : neighbors) {
                    adjRevList.get(neighbor).add(i);
                }
            }
        }
        Arrays.fill(visited, -1);
        int stronglyConnectedComponents = 0;
        while (!dfsCallsNodes.isEmpty()) {
            int node = dfsCallsNodes.pop();
            if (visited[node] == -1) {
                List<Integer> newScc = new ArrayList<>();
                btrack2(adjRevList, visited, node, newScc);
                stronglyConnectedComponents++;
            }
        }
        return stronglyConnectedComponents;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int n = scanner.nextInt();
            int e = scanner.nextInt();
            Map<Integer, List<Integer>> adjList = new HashMap<>();
            for (int i = 0; i < e; i++) {
                int src = scanner.nextInt();
                int dest = scanner.nextInt();
                adjList.putIfAbsent(src, new ArrayList<>());
                adjList.get(src).add(dest);
            }
            StronglyConnectedComponentOptimized sccFinder = new StronglyConnectedComponentOptimized();
            int result = sccFinder.getOutput(adjList, n);
            System.out.println("Number of strongly connected components: " + result);
        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please provide integers as input.");
        } finally {
            scanner.close();
        }
    }
}
