import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        // Create an instance of Main and call the solve method to execute the program logic
        Main main = new Main();
        main.solve();
    }

    private void solve() {
        // Initialize a Scanner to read input
        Scanner sc = new Scanner(System.in);
        
        // Read the dimensions of the grid
        int H = sc.nextInt();
        int W = sc.nextInt();
        
        // Initialize a cost matrix for the conversion costs between digits
        int[][] c = new int[10][10];
        
        // Read the conversion costs from input
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        
        // Initialize an array to store the minimum conversion costs
        int[] min = new int[10];
        
        // Set initial minimum costs based on the first column of the cost matrix
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        
        // Calculate the minimum conversion costs using dynamic programming
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = Math.min(min[i], c[i][j] + min[j]);
                }
            }
        }
        
        // Initialize the answer variable to accumulate the total minimum cost
        int ans = 0;
        
        // Read the grid values and calculate the total minimum conversion cost
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A = sc.nextInt();
                // Only add to the answer if the value is non-negative
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }

    // Custom Scanner class for reading input efficiently
    class Scanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int index;
        private int length;

        public Scanner(InputStream in) {
            this.in = in;
        }

        // Check if the character is printable
        private boolean isPrintableChar(int c) {
            return '!' <= c && c <= '~';
        }

        // Check if the character is a digit
        private boolean isDigit(int c) {
            return '0' <= c && c <= '9';
        }

        // Check if there is a next byte to read
        private boolean hasNextByte() {
            if (index < length) {
                return true;
            } else {
                try {
                    length = in.read(buffer);
                    index = 0;
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return length > 0;
            }
        }

        // Check if there is a next printable character
        private boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[index])) {
                index++;
            }
            return hasNextByte();
        }

        // Read the next byte from the input
        private int readByte() {
            return hasNextByte() ? buffer[index++] : -1;
        }

        // Read the next string from the input
        public String next() {
            if (!hasNext()) {
                throw new RuntimeException("no input");
            }
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        // Read the next long integer from the input
        public long nextLong() {
            if (!hasNext()) {
                throw new RuntimeException("no input");
            }
            long value = 0L;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (isPrintableChar(b)) {
                if (isDigit(b)) {
                    value = value * 10 + (b - '0');
                }
                b = readByte();
            }
            return minus ? -value : value;
        }

        // Read the next integer from the input
        public int nextInt() {
            return (int)nextLong();
        }

        // Read the next double from the input
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    // Interface for combination calculator
    interface CombCalculator {
        long comb(int n, int m);
    }

    // Interface for Mobius function
    interface MobiusFunction {
        int get(int n);
    }

    /**
     * Class for precomputing the Mobius function using a sieve-like method.
     * Time complexity is O(1) for queries and O(N logN) for precomputation.
     */
    class SieveMobiusFunction implements MobiusFunction {
        int size;
        int[] mobiusFunctionValues;

        public SieveMobiusFunction(int size) {
            this.size = size;
            mobiusFunctionValues = new int[size];

            // Initialize Mobius function values
            mobiusFunctionValues[0] = 0;
            mobiusFunctionValues[1] = 1;
            for (int i = 2; i < size; i++) {
                mobiusFunctionValues[i] = 1;
            }
            // Mark squares of primes
            for (int i = 2; i * i < size; i++) {
                for (int k = 1; i * i * k < size; k++) {
                    mobiusFunctionValues[i * i * k] *= 0;
                }
            }

            // Calculate Mobius function values
            for (int i = 2; i < size; i++) {
                if (mobiusFunctionValues[i] == 1) {
                    for (int k = 1; i * k < size; k++) {
                        mobiusFunctionValues[i * k] *= -2;
                    }
                }
                if (mobiusFunctionValues[i] > 1) {
                    mobiusFunctionValues[i] = 1;
                }
                if (mobiusFunctionValues[i] < -1) {
                    mobiusFunctionValues[i] = -1;
                }
            }
        }

        @Override
        public int get(int n) {
            if (n > size) {
                throw new RuntimeException("n is greater than size.");
            }
            if (n < 0) {
                return 0;
            }
            return mobiusFunctionValues[n];
        }
    }

    /**
     * Class for calculating the Mobius function directly.
     * Time complexity is O(logN).
     */
    class PrimeFactorizationMobiusFunction implements MobiusFunction {
        @Override
        public int get(int n) {
            if (n <= 0) {
                return 0;
            }
            if (n == 1) {
                return 1;
            }
            int num = 0;
            for (int i = 2; i < n; i++) {
                if (n % i == 0) {
                    n /= i;
                    num++;
                    if (n % i == 0) {
                        return 0;
                    }
                }
            }
            return num % 2 == 0 ? -1 : 1;
        }
    }

    /**
     * Class for combination calculations using precomputed factorial values (MOD supported).
     * C(N, N) % M has a time complexity of O(1), with O(max(N, logM)) for precomputation.
     * Be cautious of MLE when size exceeds 1e8.
     */
    class FactorialTableCombCalculator implements CombCalculator {
        int size;
        long[] factorialTable;
        long[] inverseFactorialTable;
        long mod;

        public FactorialTableCombCalculator(int size, long mod) {
            this.size = size;
            factorialTable = new long[size + 1];
            inverseFactorialTable = new long[size + 1];
            this.mod = mod;

            // Precompute factorial values
            factorialTable[0] = 1L;
            for (int i = 1; i <= size; i++) {
                factorialTable[i] = (factorialTable[i - 1] * i) % mod;
            }
            // Precompute inverse factorial values
            inverseFactorialTable[size] = inverse(factorialTable[size], mod);
            for (int i = size - 1; i >= 0; i--) {
                inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
            }
        }

        // Calculate modular inverse using Fermat's Little Theorem
        private long inverse(long n, long mod) {
            return pow(n, mod - 2, mod);
        }

        // Calculate power with modular arithmetic
        private long pow(long n, long p, long mod) {
            if (p == 0) {
                return 1L;
            }
            long half = pow(n, p / 2, mod);
            long ret = (half * half) % mod;
            if (p % 2 == 1) {
                ret = (ret * n) % mod;
            }
            return ret;
        }

        @Override
        public long comb(int n, int m) {
            if (n > size) {
                throw new RuntimeException("n is greater than size.");
            }
            if (n < 0 || m < 0 || n < m) {
                return 0L;
            }
            return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
        }
    }

    /**
     * Class for combination calculations using a precomputed table (MOD supported).
     * Precomputation takes O(N^2), while comb takes O(1).
     * Be cautious of MLE when size exceeds 2 * 1e4.
     */
    class TableCombCalculator implements CombCalculator {
        long[][] table;
        int size;

        public TableCombCalculator(int size, long mod) {
            this.size = size;
            table = new long[size + 1][];

            // Initialize the combination table
            table[0] = new long[1];
            table[0][0] = 1L;
            for (int n = 1; n <= size; n++) {
                table[n] = new long[n + 1];
                table[n][0] = 1L;
                for (int m = 1; m < n; m++) {
                    table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
                }
                table[n][n] = 1L;
            }
        }

        @Override
        public long comb(int n, int m) {
            if (n > size) {
                throw new RuntimeException("n is greater than size.");
            }
            if (n < 0 || m < 0 || n < m) {
                return 0L;
            }
            return table[n][m];
        }
    }

    // Interface for graph representation
    interface Graph {
        void link(int from, int to, long cost);
        Optional<Long> getCost(int from, int to);
        int getVertexNum();
    }

    // Interface for flow resolver
    interface FlowResolver {
        long maxFlow(int from, int to);
    }

    /**
     * Graph implementation using an adjacency matrix.
     * Be cautious of MLE with large graphs.
     */
    class ArrayGraph implements Graph {
        private Long[][] costArray;
        private int vertexNum;

        public ArrayGraph(int n) {
            costArray = new Long[n][];
            for (int i = 0; i < n; i++) {
                costArray[i] = new Long[n];
            }
            vertexNum = n;
        }

        @Override
        public void link(int from, int to, long cost) {
            costArray[from][to] = new Long(cost);
        }

        @Override
        public Optional<Long> getCost(int from, int to) {
            return Optional.ofNullable(costArray[from][to]);
        }

        @Override
        public int getVertexNum() {
            return vertexNum;
        }
    }

    /**
     * Flow resolver implementation using Depth-First Search (DFS).
     * The time complexity is O(E * MaxFlow) (E: number of edges, MaxFlow: maximum flow).
     */
    class DfsFlowResolver implements FlowResolver {
        private Graph graph;

        public DfsFlowResolver(Graph graph) {
            this.graph = graph;
        }

        /**
         * Calculate the maximum flow (minimum cut) from source to target.
         * @param from Source node ID
         * @param to Target node ID
         * @return Maximum flow (minimum cut)
         */
        public long maxFlow(int from, int to) {
            long sum = 0L;
            long currentFlow;
            // Continue finding flows until no more can be found
            do {
                currentFlow = flow(from, to, Long.MAX_VALUE / 3, new boolean[graph.getVertexNum()]);
                sum += currentFlow;
            } while (currentFlow > 0);
            return sum;
        }

        /**
         * Execute flow and update the graph.
         * @param from Current node ID
         * @param to Target node ID
         * @param current_flow Current flow amount
         * @param passed Array to track visited nodes
         * @return Flow amount sent to the target node / flow amount returned to the graph
         */
        private long flow(int from, int to, long current_flow, boolean[] passed) {
            passed[from] = true;
            if (from == to) {
                return current_flow;
            }
            for (int id = 0; id < graph.getVertexNum(); id++) {
                if (passed[id]) {
                    continue;
                }
                Optional<Long> cost = graph.getCost(from, id);
                if (cost.orElse(0L) > 0) {
                    long nextFlow = current_flow < cost.get() ? current_flow : cost.get();
                    long returnFlow = flow(id, to, nextFlow, passed);
                    if (returnFlow > 0) {
                        // Update the graph with the new flow
                        graph.link(from, id, cost.get() - returnFlow);
                        graph.link(id, from, graph.getCost(id, from).orElse(0L) + returnFlow);
                        return returnFlow;
                    }
                }
            }
            return 0L;
        }
    }

    /**
     * 1-indexed Binary Indexed Tree (BIT) implementation.
     */
    class BinaryIndexedTree {
        private long[] array;

        public BinaryIndexedTree(int size) {
            this.array = new long[size + 1];
        }

        /**
         * Add a value to the specified element.
         * Time complexity is O(logN).
         * @param index Index of the element to add to
         * @param value Amount to add
         */
        public void add(int index, long value) {
            for (int i = index; i < array.length; i += (i & -i)) {
                array[i] += value;
            }
        }

        /**
         * Get the sum from 1 to the specified element.
         * Time complexity is O(logN).
         * @param index Index of the end element for the sum
         * @return Sum from 1 to index
         */
        public long getSum(int index) {
            long sum = 0L;
            for (int i = index; i > 0; i -= (i & -i)) {
                sum += array[i];
            }
            return sum;
        }
    }

    /**
     * 1-indexed 2D Binary Indexed Tree (BIT) implementation.
     */
    class BinaryIndexedTree2D {
        private long[][] array;

        public BinaryIndexedTree2D(int size1, int size2) {
            this.array = new long[size1 + 1][];
            for (int i = 1; i <= size1; i++) {
                this.array[i] = new long[size2 + 1];
            }
        }

        /**
         * Add a value to the specified element in 2D.
         * Time complexity is O(logN * logN).
         * @param index1 Index of the first dimension element
         * @param index2 Index of the second dimension element
         * @param value Amount to add
         */
        public void add(int index1, int index2, long value) {
            for (int i1 = index1; i1 < array.length; i1 += (i1 & -i1)) {
                for (int i2 = index2; i2 < array.length; i2 += (i2 & -i2)) {
                    array[i1][i2] += value;
                }
            }
        }

        /**
         * Get the rectangular sum from (1,1) to the specified element.
         * Time complexity is O(logN * logN).
         * @param index1 Index of the first dimension end element
         * @param index2 Index of the second dimension end element
         * @return Rectangular sum from (1,1) to (index1,index2)
         */
        public long getSum(int index1, int index2) {
            long sum = 0L;
            for (int i1 = index1; i1 > 0; i1 -= (i1 & -i1)) {
                for (int i2 = index2; i2 > 0; i2 -= (i2 & -i2)) {
                    sum += array[i1][i2];
                }
            }
            return sum;
        }
    }

    // Interface for Union-Find data structure
    interface UnionFind {
        void union(int A, int B);
        boolean judge(int A, int B);
        Set<Integer> getSet(int id);
    }

    /**
     * Extended ArrayUnionFind that allows retrieval of the set of vertices under a root.
     * The getSet method is optimized to O(logN * logN), but union method has increased complexity.
     */
    class SetUnionFind extends ArrayUnionFind {
        Map<Integer, Set<Integer>> map;

        public SetUnionFind(int size) {
            super(size);
            map = new HashMap<>();
            for (int i = 0; i < size; i++) {
                map.put(i, new HashSet<>());
                map.get(i).add(i);
            }
        }

        @Override
        protected void unionTo(int source, int dest) {
            super.unionTo(source, dest);
            map.get(dest).addAll(map.get(source));
        }

        @Override
        public Set<Integer> getSet(int id) {
            return map.get(root(id));
        }
    }

    /**
     * Union-Find implementation using an array.
     * The getSet method has a time complexity of O(N log N), so be cautious of TLE.
     */
    class ArrayUnionFind implements UnionFind {
        int[] parent;
        int[] rank;
        int size;

        public ArrayUnionFind(int size) {
            parent = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
            rank = new int[size];
            this.size = size;
        }

        @Override
        public void union(int A, int B) {
            int rootA = root(A);
            int rootB = root(B);
            if (rootA != rootB) {
                if (rank[rootA] < rank[rootB]) {
                    unionTo(rootA, rootB);
                } else {
                    unionTo(rootB, rootA);
                    if (rank[rootA] == rank[rootB]) {
                        rank[rootA]++;
                    }
                }
            }
        }

        protected void unionTo(int source, int dest) {
            parent[source] = dest;
        }

        @Override
        public boolean judge(int A, int B) {
            return root(A) == root(B);
        }

        @Override
        public Set<Integer> getSet(int id) {
            Set<Integer> set = new HashSet<>();
            IntStream.range(0, size).filter(i -> judge(i, id)).forEach(set::add);
            return set;
        }

        protected int root(int id) {
            if (parent[id] == id) {
                return id;
            }
            parent[id] = root(parent[id]);
            return parent[id];
        }
    }

    /**
     * Utility class for prime number operations.
     */
    class PrimeNumberUtils {
        boolean[] isPrimeArray;
        List<Integer> primes;

        /**
         * Initialize the utility with a limit for prime number checks.
         * @param limit The upper limit for prime number checks (values above this will not be checked).
         */
        public PrimeNumberUtils(int limit) {
            if (limit > 10000000) {
                System.err.println("The limit is too high, initialization may cause TLE.");
            }
            primes = new ArrayList<>();
            isPrimeArray = new boolean[limit];
            if (limit > 2) {
                primes.add(2);
                isPrimeArray[2] = true;
            }

            // Sieve of Eratosthenes to find prime numbers
            for (int i = 3; i < limit; i += 2) {
                if (isPrime(i, primes)) {
                    primes.add(i);
                    isPrimeArray[i] = true;
                }
            }
        }

        public List<Integer> getPrimeNumberList() {
            return primes;
        }

        public boolean isPrime(int n) {
            return isPrimeArray[n];
        }

        // Check if a number is prime using previously found primes
        private boolean isPrime(int n, List<Integer> primes) {
            for (int prime : primes) {
                if (n % prime == 0) {
                    return false;
                }
                if (prime > Math.sqrt(n)) {
                    break;
                }
            }
            return true;
        }
    }

    // Interface for BitSet operations
    interface BitSet {
        void set(int index, boolean bit);
        boolean get(int index);
        void shiftRight(int num);
        void shiftLeft(int num);
        void or(BitSet bitset);
        void and(BitSet bitset);
    }

    /**
     * Implementation of BitSet using an array of longs.
     * get/set operations are O(1), while shift/or/and operations are O(size / 64).
     */
    class LongBit implements BitSet {
        long[] bitArray;

        public LongBit(int size) {
            bitArray = new long[((size + 63) / 64)];
        }

        @Override
        public void set(int index, boolean bit) {
            int segment = index / 64;
            int inIndex = index % 64;
            if (bit) {
                bitArray[segment] |= 1L << inIndex;
            } else {
                bitArray[segment] &= ~(1L << inIndex);
            }
        }

        @Override
        public boolean get(int index) {
            int segment = index / 64;
            int inIndex = index % 64;
            return (bitArray[segment] & (1L << inIndex)) != 0L;
        }

        @Override
        public void shiftRight(int num) {
            int shiftSeg = num / 64;
            int shiftInI = num % 64;
            for (int segment = 0; segment < bitArray.length; segment++) {
                int sourceSeg = segment + shiftSeg;
                if (sourceSeg < bitArray.length) {
                    bitArray[segment] = bitArray[sourceSeg] >>> shiftInI;
                    if (shiftInI > 0 && sourceSeg + 1 < bitArray.length) {
                        bitArray[segment] |= bitArray[sourceSeg + 1] << (64 - shiftInI);
                    }
                } else {
                    bitArray[segment] = 0L;
                }
            }
        }

        @Override
        public void shiftLeft(int num) {
            int shiftSeg = num / 64;
            int shiftInI = num % 64;
            for (int segment = bitArray.length - 1; segment >= 0; segment--) {
                int sourceSeg = segment - shiftSeg;
                if (sourceSeg >= 0) {
                    bitArray[segment] = bitArray[sourceSeg] << shiftInI;
                    if (shiftInI > 0 && sourceSeg > 0) {
                        bitArray[segment] |= bitArray[sourceSeg - 1] >>> (64 - shiftInI);
                    }
                } else {
                    bitArray[segment] = 0L;
                }
            }
        }

        public long getLong(int segment) {
            return bitArray[segment];
        }

        @Override
        public void or(BitSet bitset) {
            if (!(bitset instanceof LongBit)) {
                return;
            }
            for (int segment = 0; segment < bitArray.length; segment++) {
                bitArray[segment] |= ((LongBit)bitset).getLong(segment);
            }
        }

        @Override
        public void and(BitSet bitset) {
            if (!(bitset instanceof LongBit)) {
                return;
            }
            for (int segment = 0; segment < bitArray.length; segment++) {
                bitArray[segment] &= ((LongBit)bitset).getLong(segment);
            }
        }
    }

}
