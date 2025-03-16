import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.Character.Subset;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.time.temporal.ValueRange;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.ForkJoinPool;

import static java.util.Comparator.*;

public class Main {

    public static void main(String[] args) {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        // Create a solver instance and execute the solve method
        Solver solver = new Solver(in, out);
        solver.solve();

        // Close the output stream
        out.close();
    }

    // ======================================================================
    static class Solver {
        MyInput in; // Input handler
        PrintWriter out; // Output handler

        // Constructor to initialize input and output
        public Solver(MyInput in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        // -----------------------------------------
        public void solve() {
            // Read dimensions of the grid
            int H = ni();
            int W = ni();
            char[][] C = new char[H + 2][W + 2]; // Create a grid with padding
            char[] c;

            // Fill the grid with input characters
            for (int i = 0; i < H; i++) {
                c = ns().toCharArray();
                for (int j = 0; j < W; j++) {
                    C[i + 1][j + 1] = c[j];
                }
            }

            // Handle the case where the grid is 1x1
            if (H == 1 && W == 1) {
                prn("No");
                return;
            }

            // Check for isolated '#' characters in the grid
            for (int i = 1; i <= H; i++) {
                for (int j = 1; j <= W; j++) {
                    if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                        && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                        prn("No");
                        return;
                    }
                }
            }
            // If no isolated '#' characters are found, print "Yes"
            prn("Yes");
        }

        // -----------------------------------------
        // Class to manage counts of Integer keys
        static class MapCounter {
            private TreeMap<Integer, Integer> map; // TreeMap to store counts

            // Constructor for ascending order map
            public MapCounter() {
                map = new TreeMap<>();
            }

            // Constructor for descending order map
            public MapCounter(boolean reverse) {
                if (reverse) {
                    map = new TreeMap<Integer, Integer>(Collections.reverseOrder());
                } else {
                    map = new TreeMap<>();
                }
            }

            // Add a key with a count of 1
            public void add(Integer key) {
                add(key, 1);
            }

            // Add a key with a specified count
            public void add(Integer key, int cnt) {
                Integer val = map.get(key);
                if (val == null) {
                    map.put(key, cnt);
                } else {
                    map.put(key, val + cnt);
                }
            }

            // Remove a key by decreasing its count by 1
            public void remove(Integer key) {
                sub(key, 1, false);
            }

            // Decrease the count of a key by 1
            public void sub(Integer key) {
                sub(key, 1);
            }

            // Decrease the count of a key by a specified count
            public void sub(Integer key, int cnt) {
                sub(key, cnt, true);
            }

            // Decrease the count of a key with an option to allow negative counts
            public void sub(Integer key, int cnt, boolean minus) {
                Integer val = map.get(key);
                if (val == null) {
                    if (minus) {
                        map.put(key, -cnt); // Allow negative count
                    }
                } else if (val > cnt || minus) {
                    map.put(key, val - cnt);
                } else {
                    map.remove(key);
                }
            }

            // Set the count for a key
            public void set(Integer key, int cnt) {
                map.put(key, cnt);
            }

            // Get the count for a key, returning null if not present
            public Integer getCountwithNull(Integer key) {
                return map.get(key);
            }

            // Get the count for a key, returning 0 if not present
            public Integer getCount(Integer key) {
                Integer val = map.get(key);
                if (val == null) return 0;
                else return val;
            }

            // Get all keys in the map
            public Set<Integer> getKey() {
                return map.keySet();
            }

            // Get the number of keys in the map
            public int getKeyCount() {
                return map.keySet().size();
            }

            // Get the first key in the map
            public Integer getFirstKey() {
                return map.firstKey();
            }

            // Get the last key in the map
            public Integer getLastKey() {
                return map.lastKey();
            }

            // Clear the map
            public void clear() {
                map.clear();
            }
        }

        // -----------------------------------------
        // Binary search utility to find the rightmost minimum
        boolean isRightMin(int[] a, boolean f, int index, int key) {
            if (f && a[index] >= key) return true; // Check for greater than or equal
            else if (!f && a[index] > key) return true; // Check for greater than
            else return false;
        }

        // Perform binary search to find the smallest value >= key
        int binarySearchRightMin(int[] a, boolean f, int key) {
            int ng = -1; // Initialize lower bound
            int ok = (int) a.length; // Initialize upper bound

            // Binary search loop
            while (Math.abs(ok - ng) > 1) {
                int mid = (ok + ng) / 2;

                if (isRightMin(a, f, mid, key)) ok = mid; // Adjust upper bound
                else ng = mid; // Adjust lower bound
            }
            return ok; // Return the found index
        }

        // -----------------------------------------
        // Binary search utility to find the leftmost maximum
        boolean isLeftMax(int[] a, boolean f, int index, int key) {
            if (f && a[index] <= key) return true; // Check for less than or equal
            else if (!f && a[index] < key) return true; // Check for less than
            else return false;
        }

        // Perform binary search to find the largest value <= key
        int binarySearchLeftMax(int[] a, boolean f, int key) {
            int ng = -1; // Initialize lower bound
            int ok = (int) a.length; // Initialize upper bound

            // Binary search loop
            while (Math.abs(ok - ng) > 1) {
                int mid = (ok + ng) / 2;

                if (isLeftMax(a, f, mid, key)) ng = mid; // Adjust upper bound
                else ok = mid; // Adjust lower bound
            }
            return ng; // Return the found index
        }

        // -----------------------------------------
        // Euler Tour class for tree traversal
        static class EulerTour {
            Graph g; // Graph representation
            List<Integer> euler_tour = new ArrayList<>(); // List to store the Euler tour
            int[] begin, end; // Arrays to store entry and exit times
            int k = 0, root = 0; // Counters for DFS

            // Depth-first search to create the Euler tour
            void dfs(int v, int p, PrintWriter out) {
                out.println("v = " + v + "  p = " + p);
                begin[v] = k; // Mark the entry time
                euler_tour.add(v); // Add vertex to the tour
                k++;
                if (!g.contains(v)) {
                    return; // If the vertex is not in the graph, return
                }
                for (int i : g.get(v)) {
                    if (i != p) {
                        dfs(i, v, out); // Recursive DFS call
                        euler_tour.add(v); // Add vertex again after returning
                        k++;
                    }
                }
                end[v] = k; // Mark the exit time
            }

            // Initialize the Euler tour with the graph and root
            public void init(int p_cnt, int root, Graph g, PrintWriter out) {
                begin = new int[p_cnt + 1]; // Initialize entry array
                end = new int[p_cnt + 1]; // Initialize exit array
                this.root = root; // Set the root
                this.g = g; // Set the graph
                dfs(root, -1, out); // Start DFS from the root
            }

            // Get the part of the Euler tour corresponding to a subtree
            public List getPartTour(int v) {
                return euler_tour.subList(begin[v], end[v]);
            }

            // Get the list of vertices in a subtree
            public List<Integer> getPartList(int v) {
                Set<Integer> set = new TreeSet<>();
                set.addAll(getPartTour(v)); // Add vertices from the tour
                List<Integer> ans = new ArrayList<>();
                for (Integer p : set) {
                    ans.add(p); // Convert set to list
                }
                return ans;
            }
        }

        // -----------------------------------------
        // Class representing an unweighted graph using an adjacency list
        class Graph {
            private Map<Integer, List<Integer>> data = new HashMap<Integer, List<Integer>>(); // Adjacency list

            // Add an edge from 'from' to 'to'
            void add(int from, int to) {
                List<Integer> list = data.get(from);
                if (list == null) {
                    list = new ArrayList<Integer>();
                    data.put(from, list);
                }
                list.add(to); // Add the destination vertex
            }

            // Remove an edge from 'from' to 'to'
            void del(int from, int to) {
                List<Integer> list = data.get(from);
                if (list == null) {
                    return; // If no edges exist, return
                }
                if (list.contains(to)) {
                    list.remove((Object) to); // Remove the destination vertex
                }
            }

            // Get the list of vertices connected to the specified key
            List<Integer> get(int key) {
                return data.get(key);
            }

            // Check if the specified vertex is registered
            boolean contains(int key) {
                return data.containsKey(key);
            }

            // Get the set of all vertices in the graph
            Set<Integer> keySet() {
                return data.keySet();
            }

            // Check if two vertices are directly connected
            boolean isConnect(int key_1, int key_2) {
                List<Integer> list = data.get(key_1);
                if (list == null) return false;
                else return list.contains(key_2);
            }

            // Get the distance from the specified vertex to all other vertices
            List<PP> distList(int key) {
                List<PP> dist = new ArrayList<>(); // List to store distances
                Set<Integer> mark = new HashSet<>(); // Set to mark visited vertices
                Stack<PP> stack = new Stack<>(); // Stack for DFS
                stack.push(new PP(key, 0)); // Push the starting vertex

                // DFS loop
                while (!stack.isEmpty()) {
                    PP wk = stack.pop(); // Get the next vertex
                    int pp = wk.getKey();
                    int dd = wk.getVal();
                    mark.add(pp); // Mark the vertex as visited
                    dist.add(new PP(pp, dd)); // Store the distance
                    List<Integer> list = get(pp); // Get connected vertices
                    for (int next : list) {
                        if (mark.contains(next)) continue; // Skip visited vertices
                        stack.push(new PP(next, dd + 1)); // Push the next vertex with updated distance
                    }
                }
                return dist; // Return the list of distances
            }

            // Get the distance from the specified vertex to all other vertices (returns an array)
            int[] distV(int key) {
                int[] dist = new int[data.keySet().size() + 1]; // Array to store distances
                Arrays.fill(dist, -1); // Initialize with -1 for unreachable vertices
                Set<Integer> mark = new HashSet<>(); // Set to mark visited vertices
                Stack<PP> stack = new Stack<>(); // Stack for DFS
                stack.push(new PP(key, 0)); // Push the starting vertex

                // DFS loop
                while (!stack.isEmpty()) {
                    PP wk = stack.pop(); // Get the next vertex
                    int pp = wk.getKey();
                    int dd = wk.getVal();
                    mark.add(pp); // Mark the vertex as visited
                    dist[pp] = dd; // Store the distance
                    List<Integer> list = get(pp); // Get connected vertices
                    for (int next : list) {
                        if (mark.contains(next)) continue; // Skip visited vertices
                        stack.push(new PP(next, dd + 1)); // Push the next vertex with updated distance
                    }
                }
                return dist; // Return the distance array
            }

            Map<Integer, Integer> mapCnt = new HashMap<>(); // Map to store visit order
            Map<Integer, Integer> mapLow = new HashMap<>(); // Map for low-link values
            Set<Integer> mark = new HashSet<>(); // Set to mark visited vertices
            int number; // Counter for visit order

            // DFS for finding bridges in the graph
            int bridgeDfs(int now, int pre) {
                mark.add(now); // Mark the current vertex
                mapCnt.put(now, number); // Set the visit order
                mapLow.put(now, number); // Initialize low-link value
                int low;

                // Explore connected vertices
                for (int next : get(now)) {
                    if (next == pre) continue; // Skip the parent vertex
                    if (mark.contains(next)) {
                        if (mapLow.get(now) > mapLow.get(next)) {
                            mapLow.put(now, mapLow.get(next)); // Update low-link value
                        }
                        continue;
                    }
                    number++; // Increment visit order
                    low = bridgeDfs(next, now); // Recursive DFS call
                    if (mapLow.get(now) > low) {
                        mapLow.put(now, low); // Update low-link value
                    }
                }
                return mapLow.get(now); // Return the low-link value
            }

            // Count the number of bridges in the graph
            int bridgeCnt(int start) {
                mapCnt.clear(); // Clear visit order map
                mapLow.clear(); // Clear low-link map
                mark.clear(); // Clear visited set
                number = 0; // Reset visit order counter
                bridgeDfs(start, start); // Start DFS from the given vertex
                int ans = 0; // Counter for bridges
                for (int key : mapCnt.keySet()) {
                    if (mapCnt.get(key) == mapLow.get(key)) {
                        ans++; // Increment bridge count
                    }
                }
                return ans - 1; // Return the number of bridges
            }

            // Dump the graph structure for debugging
            void dump(PrintWriter out) {
                for (int key : data.keySet()) {
                    out.print(key + " : ");
                    for (int val : data.get(key)) {
                        out.print(val + " ");
                    }
                    out.println("");
                }
            }
        }

        // -----------------------------------------
        // Class representing a weighted graph using an adjacency list
        static class GraphWith {
            private Map<Integer, List<PP>> data = new HashMap<Integer, List<PP>>(); // Adjacency list with weights

            // Add an edge with a weight from 'key' to 'p'
            void add(int key, PP p) {
                List<PP> list = data.get(key);
                if (list == null) {
                    list = new ArrayList<PP>();
                    data.put(key, list);
                }
                list.add(p); // Add the weighted edge
            }

            // Get the list of edges connected to the specified key
            List<PP> get(int key) {
                return data.get(key);
            }

            // Check if the specified vertex is registered
            boolean contains(int key) {
                return data.containsKey(key);
            }

            // Get the set of all vertices in the graph
            Set<Integer> keySet() {
                return data.keySet();
            }

            // Check if two vertices are directly connected
            boolean isConnect(int key_1, int key_2) {
                List<PP> list = data.get(key_1);
                if (list == null) return false;
                boolean ans = false;
                for (PP p : list) {
                    if (p.getKey() == key_2) {
                        ans = true; // Found a connection
                        break;
                    }
                }
                return ans;
            }

            // Get the distance between two vertices (returns Integer.MAX_VALUE if not connected)
            int distance(int key_1, int key_2) {
                Set<Integer> mark = new HashSet<>(); // Set to mark visited vertices
                Stack<PP> stack = new Stack<>(); // Stack for DFS
                stack.push(new PP(key_1, 0)); // Push the starting vertex
                PP wk;
                int key, val;
                List<PP> list;

                // DFS loop
                while (!stack.isEmpty()) {
                    wk = stack.pop(); // Get the next vertex
                    key = wk.getKey();
                    val = wk.getVal();
                    mark.add(key); // Mark the vertex as visited
                    if (key == key_2) return val; // Return distance if found

                    list = get(key); // Get connected vertices
                    if (list == null) continue;
                    for (PP pp : list) {
                        if (mark.contains(pp.getKey())) continue; // Skip visited vertices
                        stack.push(new PP(pp.getKey(), val + pp.getVal())); // Push the next vertex with updated distance
                    }
                }
                return Integer.MAX_VALUE; // Return max value if not connected
            }
        }

        // -----------------------------------------
        // Class representing an unweighted graph using an adjacency list with Long keys
        static class GraphLong {
            private Map<Long, List<Long>> G = new HashMap<Long, List<Long>>(); // Adjacency list

            // Add an edge from 'key' to 'value'
            void add(long key, long value) {
                List<Long> list = G.get(key);
                if (list == null) {
                    list = new ArrayList<Long>();
                    G.put(key, list);
                }
                list.add(value); // Add the destination vertex
            }

            // Get the list of vertices connected to the specified key
            List<Long> get(long key) {
                return G.get(key);
            }
        }

        // -----------------------------------------
        // Class representing a weighted graph using an adjacency list with Long keys
        static class GraphLongWith {
            private Map<Long, List<PPL>> G = new HashMap<Long, List<PPL>>(); // Adjacency list with weights

            // Add an edge with a weight from 'key' to 'p'
            void add(long key, PPL p) {
                List<PPL> list = G.get(key);
                if (list == null) {
                    list = new ArrayList<PPL>();
                    G.put(key, list);
                }
                list.add(p); // Add the weighted edge
            }

            // Get the list of edges connected to the specified key
            List<PPL> get(long key) {
                return G.get(key);
            }
        }

        // -----------------------------------------
        // Print utility methods for different data types
        void prn(String s) {
            out.println(s);
        }

        void prn(int i) {
            out.println(i);
        }

        void prn(long i) {
            out.println(i);
        }

        void prr(String s) {
            out.print(s);
        }

        // Input reading utility methods
        int ni() {
            return in.nextInt();
        }

        long nl() {
            return in.nextLong();
        }

        double nd() {
            return in.nextDouble();
        }

        String ns() {
            return in.nextString();
        }

        int[] ndi(int n) {
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                ans[i] = ni();
            }
            return ans;
        }

        long[] ndl(int n) {
            long[] ans = new long[n];
            for (int i = 0; i < n; i++) {
                ans[i] = nl();
            }
            return ans;
        }

        double[] ndd(int n) {
            double[] ans = new double[n];
            for (int i = 0; i < n; i++) {
                ans[i] = nd();
            }
            return ans;
        }

        String[] nds(int n) {
            String[] ans = new String[n];
            for (int i = 0; i < n; i++) {
                ans[i] = ns();
            }
            return ans;
        }

        int[][] nddi(int n, int m) {
            int[][] ans = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = ni();
                }
            }
            return ans;
        }

        long[][] nddl(int n, int m) {
            long[][] ans = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = nl();
                }
            }
            return ans;
        }
    }

    // Class representing a pair of integers for graph edges
    static class PP {
        public int key, val; // Key and value

        public PP(int key, int val) {
            this.key = key;
            this.val = val;
        }

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public int getVal() {
            return val;
        }

        public void setVal(int val) {
            this.val = val;
        }
    }

    // Class representing a triplet of integers
    static class PPP {
        public int key, val1, val2; // Key and two values

        public PPP(int key, int val1, int val2) {
            this.key = key;
            this.val1 = val1;
            this.val2 = val2;
        }

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public int getVal1() {
            return val1;
        }

        public void setVal1(int val1) {
            this.val1 = val1;
        }

        public int getVal2() {
            return val2;
        }

        public void setVal2(int val2) {
            this.val2 = val2;
        }
    }

    // Class representing a pair of long integers for graph edges
    static class PPL {
        public long key, val; // Key and value

        public PPL(long key, long val) {
            this.key = key;
            this.val = val;
        }

        public long getKey() {
            return key;
        }

        public void setKey(long key) {
            this.key = key;
        }

        public long getVal() {
            return val;
        }

        public void setVal(long val) {
            this.val = val;
        }
    }

    // Class representing a pair of long integers with an array value
    static class PPDL {
        public long key; // Key
        public long[] val; // Array of values

        public PPDL(long key, long[] val) {
            this.key = key;
            this.val = val;
        }

        public long getKey() {
            return key;
        }

        public void setKey(long key) {
            this.key = key;
        }

        public long[] getVal() {
            return val;
        }

        public void setVal(long[] val) {
            this.val = val;
        }

        // Dump method for debugging
        public void dump(PrintWriter out) {
            out.print("key = " + key + "  val ");
            for (int i = 0; i < val.length; i++) {
                out.print("[" + val[i] + "] ");
            }
            out.println("");
        }
    }

    // Class for keys used in HashMap
    static final class PPKEY {
        private final int key, val; // Key and value

        public PPKEY(int key, int val) {
            this.key = key;
            this.val = val;
        }

        public int getKey() {
            return key;
        }

        public int getVal() {
            return val;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof PPKEY) {
                PPKEY dest = (PPKEY) obj;
                return this.key == dest.key && this.val == dest.val; // Compare keys and values
            } else {
                return false;
            }
        }

        @Override
        public int hashCode() {
            return Objects.hash(key, val); // Generate hash code
        }
    }

    // Class for keys used in HashMap with long values
    static final class PPLKEY {
        private final long key, val; // Key and value

        public PPLKEY(long key, long val) {
            this.key = key;
            this.val = val;
        }

        public long getKey() {
            return key;
        }

        public long getVal() {
            return val;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof PPLKEY) {
                PPLKEY dest = (PPLKEY) obj;
                return this.key == dest.key && this.val == dest.val; // Compare keys and values
            } else {
                return false;
            }
        }

        @Override
        public int hashCode() {
            return Objects.hash(key, val); // Generate hash code
        }
    }

    // ======================================================================
    // Class representing a pair of generic types
    static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
        /** serialVersionUID. */
        private static final long serialVersionUID = 6411527075103472113L;

        public Pair(final K key, final V value) {
            super(key, value);
        }
    }

    // Class for handling input
    static class MyInput {
        private final BufferedReader in; // BufferedReader for input
        private static int pos; // Current position in the buffer
        private static int readLen; // Length of the read buffer
        private static final char[] buffer = new char[1024 * 8]; // Input buffer
        private static char[] str = new char[500 * 8 * 2]; // Temporary string buffer
        private static boolean[] isDigit = new boolean[256]; // Digit check array
        private static boolean[] isSpace = new boolean[256]; // Space check array
        private static boolean[] isLineSep = new boolean[256]; // Line separator check array

        // Static initializer for character checks
        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true; // Mark digits
            }
            isDigit['-'] = true; // Mark negative sign
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true; // Mark whitespace
            isLineSep['\r'] = isLineSep['\n'] = true; // Mark line separators
        }

        // Constructor to initialize input stream
        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        // Read a single character from the input
        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer); // Read from input stream
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException(); // Handle end of file
                }
            }
            return buffer[pos++]; // Return the character
        }

        // Read the next integer from input
        public int nextInt() {
            int len = 0;
            str[len++] = nextChar(); // Read the first character
            len = reads(len, isSpace); // Read until space
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1; // Handle negative numbers
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0'; // Convert to integer
            if (str[0] == '-') {
                ret = -ret; // Negate if negative
            }
            return ret; // Return the integer
        }

        // Read the next long from input
        public long nextLong() {
            int len = 0;
            str[len++] = nextChar(); // Read the first character
            len = reads(len, isSpace); // Read until space
            int i = 0;
            long ret = 0L;
            if (str[0] == '-') {
                i = 1; // Handle negative numbers
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0'; // Convert to long
            if (str[0] == '-') {
                ret = -ret; // Negate if negative
            }
            return ret; // Return the long
        }

        // Read the next double from input
        public double nextDouble() {
            int len = 0;
            str[len++] = nextChar(); // Read the first character
            len = reads(len, isSpace); // Read until space
            int i = 0;
            double ret = 0;
            if (str[0] == '-') {
                i = 1; // Handle negative numbers
            }
            int cnt = 0; // Counter for decimal places
            for (; i < len; i++) {
                if (str[i] == '.') {
                    cnt = 10; // Start counting decimal places
                    continue;
                }
                if (cnt == 0) {
                    ret = ret * 10 + str[i] - '0'; // Integer part
                } else {
                    ret = ret + ((double) (str[i] - '0') / cnt); // Fractional part
                    cnt *= 10; // Increase decimal place counter
                }
            }
            if (str[0] == '-') {
                ret = -ret; // Negate if negative
            }
            return ret; // Return the double
        }

        // Read the next string from input
        public String nextString() {
            String ret = new String(nextDChar()).trim(); // Read and trim the string
            return ret;
        }

        // Read a character array from input
        public char[] nextDChar() {
            int len = 0;
            len = reads(len, isSpace); // Read until space
            char[] ret = new char[len + 1]; // Create character array
            for (int i = 0; i < len; i++) ret[i] = str[i]; // Copy characters
            ret[len] = 0x00; // Null-terminate the string
            return ret;
        }

        // Read the next non-space character
        public char nextChar() {
            while (true) {
                final int c = read(); // Read a character
                if (!isSpace[c]) {
                    return (char) c; // Return if not a space
                }
            }
        }

        // Read characters until a specified condition is met
        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read(); // Read a character
                    if (accept[c]) {
                        break; // Break if condition is met
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2]; // Resize array if needed
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c; // Add character to the array
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len; // Return the length of read characters
        }

        // Exception class for end of file
        static class EndOfFileRuntimeException extends RuntimeException {
        }
    }
}
