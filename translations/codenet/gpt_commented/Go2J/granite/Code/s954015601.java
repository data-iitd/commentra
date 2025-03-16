
// 幅優先探索
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class s954015601{
    public static void main(String[] args) throws Exception {
        // read N
        int N = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());

        // read edges
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            String[] ab = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
            int a = Integer.parseInt(ab[0]) - 1;
            int b = Integer.parseInt(ab[1]) - 1;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // map to store colors
        Map<String, Integer> colors = new HashMap<>();

        // stack for breadth-first search (BFS) with current node, used color, and parent node
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, -1, -1}); // start BFS from node 0 with no used color and no parent

        // perform BFS to assign colors to edges
        while (!q.isEmpty()) {
            int[] state = q.poll();
            int currentNode = state[0];
            int usedColor = state[1];
            int parentNode = state[2];
            int color = 1; // start coloring from color 1

            // iterate through child nodes of the current node
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue; // skip the parent node to avoid backtracking
                }
                if (color == usedColor) {
                    color++; // skip the color that was used by the parent
                }
                // assign color to the edge between currentNode and childNode
                colors.put(String.format("%d %d", Math.min(currentNode, childNode), Math.max(currentNode, childNode)), color);
                // push the child node onto the stack for further exploration
                q.add(new int[]{childNode, color, currentNode});
                color++; // move to the next color for the next edge
            }
        }

        // find the maximum degree of any node in the graph
        int K = 0;
        for (List<Integer> edge : edges) {
            K = Math.max(K, edge.size());
        }
        System.out.println(K); // print the maximum degree

        // print the colors assigned to each edge
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(String.format("%d %d", Math.min(i, i + 1), Math.max(i, i + 1))));
        }
    }
}

// Constants for input buffer size
private static final int IO_BUFFER_SIZE = 1 * 1024 * 1024; // 1 MB

// readString reads a string from standard input
private static String readString() throws Exception {
    return new BufferedReader(new InputStreamReader(System.in, "UTF-8")).readLine().trim();
}

// readInt reads an integer from standard input and handles any conversion errors
private static int readInt() throws Exception {
    return Integer.parseInt(readString());
}

// readLong reads a long integer from standard input and handles any conversion errors
private static long readLong() throws Exception {
    return Long.parseLong(readString());
}

// readDouble reads a double from standard input and handles any conversion errors
private static double readDouble() throws Exception {
    return Double.parseDouble(readString());
}

// readStrings reads an array of strings from standard input
private static String[] readStrings() throws Exception {
    return readString().split(" ");
}

// readInts reads an array of integers from standard input
private static int[] readInts() throws Exception {
    return Stream.of(readStrings()).mapToInt(Integer::parseInt).toArray();
}

// readLongs reads an array of long integers from standard input
private static long[] readLongs() throws Exception {
    return Stream.of(readStrings()).mapToLong(Long::parseLong).toArray();
}

// read Doubles reads an array of doubles from standard input
private static double[] read Doubles() throws Exception {
    return Stream.of(readStrings()).mapToDouble(Double::parseDouble).toArray();
}

// end of code