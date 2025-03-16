
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

        // initialize adjacency list and edges
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }
        int[] a = new int[N - 1];
        int[] b = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            // read a and b
            String[] split = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
            a[i] = Integer.parseInt(split[0]) - 1;
            b[i] = Integer.parseInt(split[1]) - 1;
            // add edges
            edges.get(a[i]).add(b[i]);
            edges.get(b[i]).add(a[i]);
        }

        // initialize colors
        Map<Integer, Integer> colors = new HashMap<>();
        // initialize queue
        Queue<int[]> queue = new ArrayDeque<>();
        // add first node to queue with initial color and parent node set to -1
        queue.add(new int[]{0, -1, -1});
        while (!queue.isEmpty()) {
            // dequeue current node, its color, and its parent node
            int[] node = queue.poll();
            int currentNode = node[0];
            int usedColor = node[1];
            int parentNode = node[2];
            // set color of current node to the next available color
            int color = 1;
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue;
                }
                // if color of current node is the same as the color of the child node, increment the color
                if (color == usedColor) {
                    color++;
                }
                // assign color to the child node and add it to the queue with the current node as its parent node
                colors.put(Math.min(currentNode, childNode) * N + Math.max(currentNode, childNode), color);
                queue.add(new int[]{childNode, color, currentNode});
                // increment the color for the next iteration
                color++;
            }
        }

        // initialize maximum number of edges in a connected component
        int K = -1;
        // iterate through all nodes in the graph and update the maximum number of edges if necessary
        for (int i = 0; i < N; i++) {
            int t = edges.get(i).size();
            if (t > K) {
                K = t;
            }
        }
        // print maximum number of edges in a connected component
        System.out.println(K);

        // iterate through all edges in the graph and print their colors
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(Math.min(a[i], b[i]) * N + Math.max(a[i], b[i])));
        }
    }
}

// Constants for input buffer size and standard input scanner
private static final int IO_BUFFER_SIZE = 1 * 1024 * 1024; // 1 MB
private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in, "UTF-8"), IO_BUFFER_SIZE);
private static final StreamTokenizer st = new StreamTokenizer(br);
static {
    st.ordinaryChar(' ');
    st.ordinaryChar('\n');
    st.ordinaryChar('\r');
    st.wordChars('!', '/');
    st.wordChars(':', '@');
    st.wordChars('[', '^');
    st.wordChars('`', '~');
    st.whitespaceChars('\u0000','');
}

// Function to read a single string from standard input
private static String readString() throws Exception {
    st.nextToken();
    return st.sval;
}

// Function to read a single integer from standard input
private static int readInt() throws Exception {
    st.nextToken();
    return (int) st.nval;
}

// Function to read a single long from standard input
private static long readLong() throws Exception {
    st.nextToken();
    return (long) st.nval;
}

// Function to read a single double from standard input
private static double readDouble() throws Exception {
    st.nextToken();
    return st.nval;
}

// Function to read all integers from standard input
private static int[] readInts() throws Exception {
    return readInts(" ");
}

// Function to read all integers from standard input with a specified delimiter
private static int[] readInts(String delimiter) throws Exception {
    List<Integer> list = new ArrayList<>();
    for (String s : readLine(delimiter).split(delimiter)) {
        list.add(Integer.parseInt(s));
    }
    int[] a = new int[list.size()];
    for (int i = 0; i < a.length; i++) {
        a[i] = list.get(i);
    }
    return a;
}

// Function to read all longs from standard input
private static long[] readLongs() throws Exception {
    return readLongs(" ");
}

// Function to read all longs from standard input with a specified delimiter
private static long[] readLongs(String delimiter) throws Exception {
    List<Long> list = new ArrayList<>();
    for (String s : readLine(delimiter).split(delimiter)) {
        list.add(Long.parseLong(s));
    }
    long[] a = new long[list.size()];
    for (int i = 0; i < a.length; i++) {
        a[i] = list.get(i);
    }
    return a;
}

// Function to read all doubles from standard input
private static double[] read Doubles() throws Exception {
    return readDoubles(" ");
}

// Function to read all doubles from standard input with a specified delimiter
private static double[] readDoubles(String delimiter) throws Exception {
    List<Double> list = new ArrayList<>();
    for (String s : readLine(delimiter).split(delimiter)) {
        list.add(Double.parseDouble(s));
    }
    double[] a = new double[list.size()];
    for (int i = 0; i < a.length; i++) {
        a[i] = list.get(i);
    }
    return a;
}

// Function to read a single line from standard input
private static String readLine() throws Exception {
    return br.readLine();
}

// Function to read a single line from standard input with a specified delimiter
private static String readLine(String delimiter) throws Exception {
    StringBuilder sb = new StringBuilder();
    for (int c = br.read(); c!= -1; c = br.read()) {
        if (c == '\n' || c == '\r') {
            break;
        }
        sb.append((char) c);
    }
    return sb.toString();
}

// Function to read all lines from standard input
private static String[] readLines() throws Exception {
    List<String> list = new ArrayList<>();
    for (int c = br.read(); c!= -1; c = br.read()) {
        if (c == '\n' || c == '\r') {
            list.add(sb.toString());
            sb = new StringBuilder();
        } else {
            sb.append((char) c);
        }
    }
    return list.toArray(new String[0]);
}

// Function to read all lines from standard input with a specified delimiter
private static String[] readLines(String delimiter) throws Exception {
    List<String> list = new ArrayList<>();
    for (int c = br.read(); c!= -1; c = br.read()) {
        if (c == '\n' || c == '\r') {
            list.add(sb.toString());
            sb = new StringBuilder();
        } else if (c == delimiter.charAt(0)) {
            list.add(sb.toString());
            sb = new StringBuilder();
        } else {
            sb.append((char) c);
        }
    }
    return list.toArray(new String[0]);
}

// Function to print an array of integers to standard output
private static void print(int[] a) {
    for (int i = 0; i < a.length; i++) {
        System.out.print(a[i]);
        if (i < a.length - 1) {
            System.out.print(" ");
        }
    }
    System.out.println();
}

// Function to print an array of longs to standard output
private static void print(long[] a) {
    for (int i = 0; i < a.length; i++) {
        System.out.print(a[i]);
        if (i < a.length - 1) {
            System.out.print(" ");
        }
    }
    System.out.println();
}

// Function to print an array of doubles to standard output
private static void print(double[] a) {
    for (int i = 0; i < a.length; i++) {
        System.out.print(a[i]);
        if (i < a.length - 1) {
            System.out.print(" ");
        }
    }
    System.out.println();
}

// Function to print an array of strings to standard output
private static void print(String[] a) {
    for (int i = 0; i < a.length; i++) {
        System.out.print(a[i]);
        if (i < a.length - 1) {
            System.out.print(" ");
        }
    }
    System.out.println();
}

// Function to print a 2D array of integers to standard output
private static void print(int[][] a) {
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[i].length; j++) {
            System.out.print(a[i][j]);
            if (j < a[i].length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

// Function to print a 2D array of longs to standard output
private static void print(long[][] a) {
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[i].length; j++) {
            System.out.print(a[i][j]);
            if (j < a[i].length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

// Function to print a 2D array of doubles to standard output
private static void print(double[][] a) {
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[i].length; j++) {
            System.out.print(a[i][j]);
            if (j < a[i].length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

// Function to print a 2D array of strings to standard output
private static void print(String[][] a) {
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[i].length; j++) {
            System.out.print(a[i][j]);
  