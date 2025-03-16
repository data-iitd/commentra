import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    // Constants for modulo operations
    static final long MOD1 = 1000000007;
    static final long MOD2 = 998244353;
    static long[] tenmod; // Array to store powers of 10 modulo MOD2
    static final long inv9 = modInv(9); // Inverse of 9 modulo MOD2

    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out); // Output writer
        InputReader sc = new InputReader(System.in); // Input reader
        int N = sc.nextInt(); // Read number of elements
        int Q = sc.nextInt(); // Read number of queries
        
        // Initialize the tenmod array to store powers of 10 modulo MOD2
        tenmod = new long[N + 1];
        tenmod[0] = 1; // 10^0 = 1
        for (int j = 1; j <= N; j++) {
            tenmod[j] = (tenmod[j - 1] * 10L) % MOD2; // Calculate 10^j % MOD2
        }

        // Initialize segment tree data structure
        S[] dat = new S[N];
        Arrays.setAll(dat, i -> new S(tenmod[N - i - 1], i, i)); // Create initial segment tree nodes
        LazySegTree<S, F> lazySegTree = new LazySegTree<S, F>(dat, S::op, S.E, S::map, F::composite, F.I); // Create lazy segment tree

        // Process each query
        for (int j = 0; j < Q; j++) {
            int l = sc.nextInt() - 1; // Read left index (0-based)
            int r = sc.nextInt() - 1; // Read right index (0-based)
            long D = sc.nextLong(); // Read value D to apply
            lazySegTree.apply(l, r + 1, new F(D, N)); // Apply the operation to the segment
            out.println(lazySegTree.allProd().sum); // Output the sum of the entire segment
        }
        out.flush(); // Flush the output
    }

    // Class representing a segment in the segment tree
    static class S {
        static final S E = new S(0, Integer.MAX_VALUE / 2, Integer.MIN_VALUE / 2); // Identity element
        long sum; // Sum of the segment
        int l; // Left index of the segment
        int r; // Right index of the segment

        // Constructor for segment
        public S(long sum, int l, int r) {
            super();
            this.sum = sum;
            this.l = l;
            this.r = r;
        }

        // Operation to combine two segments
        public static S op(S s1, S s2) {
            long sum = s1.sum + s2.sum; // Combine sums
            if (sum >= MOD2) {
                sum -= MOD2; // Ensure sum is within modulo
            }
            return new S(sum, Math.min(s1.l, s2.l), Math.max(s1.r, s2.r)); // Return new segment
        }

        // Map function to apply a function F to a segment S
        static S map(F f, S s) {
            long c = (tenmod[(f.N - s.l)] - tenmod[(f.N - s.r - 1)]); // Calculate contribution
            if (c < 0) {
                c += MOD2; // Ensure non-negative
            }
            return new S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r); // Return mapped segment
        }
    }

    // Class representing a function to apply in the segment tree
    static class F {
        static final F I = new F(0, 0); // Identity function
        long D; // Value to apply
        int N; // Size of the segment

        // Constructor for function
        public F(long D, int N) {
            super();
            this.D = D;
            this.N = N;
        }

        // Composite function to combine two functions
        public static F composite(F f, F g) {
            return new F(f.D, f.N); // Return combined function
        }
    }

    // Function to calculate modular inverse
    static long modInv(long x) {
        return modPow(x, MOD2 - 2); // Using Fermat's little theorem
    }

    // Function to calculate modular exponentiation
    static long modPow(long x, long y) {
        long z = 1; // Result variable
        while (y > 0) {
            if (y % 2 == 0) {
                x = (x * x) % MOD2; // Square the base
                y /= 2; // Halve the exponent
            } else {
                z = (z * x) % MOD2; // Multiply result by base
                y--; // Decrement exponent
            }
        }
        return z; // Return result
    }

    // Class representing a lazy segment tree
    static class LazySegTree<S, F> {
        final int MAX; // Maximum size of the segment tree
        final int N; // Actual size of the segment tree
        final int Log; // Logarithm of N
        final java.util.function.BinaryOperator<S> Op; // Operation for combining segments
        final S E; // Identity element for segments
        final java.util.function.BiFunction<F, S, S> Mapping; // Mapping function
        final java.util.function.BinaryOperator<F> Composition; // Composition function
        final F Id; // Identity function for lazy updates

        final S[] Dat; // Array for segment tree data
        final F[] Laz; // Array for lazy updates

        // Constructor for lazy segment tree
        @SuppressWarnings("unchecked")
        public LazySegTree(int n, java.util.function.BinaryOperator<S> op, S e, java.util.function.BiFunction<F, S, S> mapping, java.util.function.BinaryOperator<F> composition, F id) {
            this.MAX = n; // Set maximum size
            int k = 1; // Initialize size variable
            while (k < n) k <<= 1; // Find next power of 2
            this.N = k; // Set actual size
            this.Log = Integer.numberOfTrailingZeros(N); // Calculate log base 2 of N
            this.Op = op; // Set operation
            this.E = e; // Set identity element
            this.Mapping = mapping; // Set mapping function
            this.Composition = composition; // Set composition function
            this.Id = id; // Set identity function
            this.Dat = (S[]) new Object[N << 1]; // Initialize data array
            this.Laz = (F[]) new Object[N]; // Initialize lazy array
            java.util.Arrays.fill(Dat, E); // Fill data array with identity
            java.util.Arrays.fill(Laz, Id); // Fill lazy array with identity
        }

        // Constructor to build the segment tree from initial data
        public LazySegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e, java.util.function.BiFunction<F, S, S> mapping, java.util.function.BinaryOperator<F> composition, F id) {
            this(dat.length, op, e, mapping, composition, id); // Call main constructor
            build(dat); // Build the segment tree
        }

        // Build the segment tree from initial data
        private void build(S[] dat) {
            int l = dat.length; // Length of initial data
            System.arraycopy(dat, 0, Dat, N, l); // Copy data to segment tree
            for (int i = N - 1; i > 0; i--) {
                Dat[i] = Op.apply(Dat[i << 1 | 0], Dat[i << 1 | 1]); // Combine child nodes
            }
        }

        // Push lazy updates down to children
        private void push(int k) {
            if (Laz[k] == Id) return; // No lazy update to apply
            int lk = k << 1 | 0, rk = k << 1 | 1; // Left and right children
            Dat[lk] = Mapping.apply(Laz[k], Dat[lk]); // Apply lazy update to left child
            Dat[rk] = Mapping.apply(Laz[k], Dat[rk]); // Apply lazy update to right child
            if (lk < N) Laz[lk] = Composition.apply(Laz[k], Laz[lk]); // Update left child's lazy value
            if (rk < N) Laz[rk] = Composition.apply(Laz[k], Laz[rk]); // Update right child's lazy value
            Laz[k] = Id; // Reset lazy value for current node
        }

        // Push updates to a specific node
        private void pushTo(int k) {
            for (int i = Log; i > 0; i--) push(k >> i); // Push updates from root to the node
        }

        // Push updates to a range of nodes
        private void pushTo(int lk, int rk) {
            for (int i = Log; i > 0; i--) {
                if (((lk >> i) << i) != lk) push(lk >> i); // Push updates for left range
                if (((rk >> i) << i) != rk) push(rk >> i); // Push updates for right range
            }
        }

        // Update the segment tree from a specific node upwards
        private void updateFrom(int k) {
            k >>= 1; // Move to parent
            while (k > 0) {
                Dat[k] = Op.apply(Dat[k << 1 | 0], Dat[k << 1 | 1]); // Combine child nodes
                k >>= 1; // Move to parent
            }
        }

        // Update the segment tree from a range of nodes upwards
        private void updateFrom(int lk, int rk) {
            for (int i = 1; i <= Log; i++) {
                if (((lk >> i) << i) != lk) {
                    int lki = lk >> i;
                    Dat[lki] = Op.apply(Dat[lki << 1 | 0], Dat[lki << 1 | 1]); // Update left range
                }
                if (((rk >> i) << i) != rk) {
                    int rki = (rk - 1) >> i;
                    Dat[rki] = Op.apply(Dat[rki << 1 | 0], Dat[rki << 1 | 1]); // Update right range
                }
            }
        }

        // Set a value at a specific index
        public void set(int p, S x) {
            exclusiveRangeCheck(p); // Check index bounds
            p += N; // Move to the leaf node
            pushTo(p); // Push updates to the leaf
            Dat[p] = x; // Set the value
            updateFrom(p); // Update the tree upwards
        }

        // Get the value at a specific index
        public S get(int p) {
            exclusiveRangeCheck(p); // Check index bounds
            p += N; // Move to the leaf node
            pushTo(p); // Push updates to the leaf
            return Dat[p]; // Return the value
        }

        // Get the product of all segments
        public S allProd() {
            return Dat[1]; // Return the root segment
        }

        // Apply a function to a specific index
        public void apply(int p, F f) {
            exclusiveRangeCheck(p); // Check index bounds
            p += N; // Move to the leaf node
            pushTo(p); // Push updates to the leaf
            Dat[p] = Mapping.apply(f, Dat[p]); // Apply the function
            updateFrom(p); // Update the tree upwards
        }

        // Apply a function to a range of segments
        public void apply(int l, int r, F f) {
            if (l > r) {
                throw new IllegalArgumentException(
                    String.format("Invalid range: [%d, %d)", l, r) // Check for valid range
                );
            }
            inclusiveRangeCheck(l); // Check left index bounds
            inclusiveRangeCheck(r); // Check right index bounds
            if (l == r) return; // No range to apply
            l += N; r += N; // Move to leaf nodes
            pushTo(l, r); // Push updates to the range
            for (int l2 = l, r2 = r; l2 < r2;) {
                if ((l2 & 1) == 1) {
                    Dat[l2] = Mapping.apply(f, Dat[l2]); // Apply function to left child
                    if (l2 < N) Laz[l2] = Composition.apply(f, Laz[l2]); // Update lazy value for left child
                    l2++; // Move to next node
                }
                if ((r2 & 1) == 1) {
                    r2--; // Move to previous node
                    Dat[r2] = Mapping.apply(f, Dat[r2]); // Apply function to right child
                    if (r2 < N) Laz[r2] = Composition.apply(f, Laz[r2]); // Update lazy value for right child
                }
                l2 >>= 1; r2 >>= 1; // Move up the tree
            }
            updateFrom(l, r); // Update the tree upwards
        }

        // Find the maximum index satisfying a condition
        public int maxRight(int l, java.util.function.Predicate<S> g) {
            inclusiveRangeCheck(l); // Check left index bounds
            if (!g.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition."); // Check identity condition
            }
            if (l == MAX) return MAX; // If at the end, return MAX
            l += N; // Move to the leaf node
            pushTo(l); // Push updates to the leaf
            S sum = E; // Initialize sum
            do {
                l >>= Integer.numberOfTrailingZeros(l); // Move to the next segment
                if (!g.test(Op.apply(sum, Dat[l]))) { // Check condition
                    while (l < N) {
                        push(l); // Push updates
                        l = l << 1; // Move to left child
                        if (g.test(Op.apply(sum, Dat[l]))) { // Check condition
                            sum = Op.apply(sum, Dat[l]); // Update sum
                            l++; // Move to next node
                        }
                    }
                    return l - N; // Return the index
                }
                sum = Op.apply(sum, Dat[l]); // Update sum
                l++; // Move to next node
            } while ((l & -l) != l); // Continue until a leaf
            return MAX; // Return MAX if no index found
        }

        // Find the minimum index satisfying a condition
        public int minLeft(int r, java.util.function.Predicate<S> g) {
            inclusiveRangeCheck(r); // Check right index bounds
            if (!g.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition."); // Check identity condition
            }
            if (r == 0) return 0; // If at the start, return 0
            r += N; // Move to the leaf node
            pushTo(r - 1); // Push updates to the leaf
            S sum = E; // Initialize sum
            do {
                r--; // Move to previous node
                while (r > 1 && (r & 1) == 1) r >>= 1; // Move to parent if right child
                if (!g.test(Op.apply(Dat[r], sum))) { // Check condition
                    while (r < N) {
                        push(r); // Push updates
                        r = r << 1 | 1; // Move to right child
                        if (g.test(Op.apply(Dat[r], sum))) { // Check condition
                            sum = Op.apply(Dat[r], sum); // Update sum
                            r--; // Move to previous node
                        }
                    }
                    return r + 1 - N; // Return the index
                }
                sum = Op.apply(Dat[r], sum); // Update sum
            } while ((r & -r) != r); // Continue until a leaf
            return 0; // Return 0 if no index found
        }

        // Check for exclusive range validity
        private void exclusiveRangeCheck(int p) {
            if (p < 0 || p >= MAX) {
                throw new IndexOutOfBoundsException(
                    String.format("Index %d is not in [%d, %d).", p, 0, MAX) // Check bounds
                );
            }
        }

        // Check for inclusive range validity
        private void inclusiveRangeCheck(int p) {
            if (p < 0 || p > MAX) {
                throw new IndexOutOfBoundsException(
                    String.format("Index %d is not in [%d, %d].", p, 0, MAX) // Check bounds
                );
            }
        }

        // **************** DEBUG **************** //

        private int indent = 6; // Indentation for debug output

        // Set the indentation for debug output
        public void setIndent(int newIndent) {
            this.indent = newIndent;
        }

        // Convert the segment tree to string for debugging
        @Override
        public String toString() {
            return toString(1, 0); // Start from root
        }

        // Convert a specific node to string for debugging
        private String toString(int k, int sp) {
            if (k >= N) return indent(sp) + Dat[k]; // If leaf, return value
            String s = "";
            s += toString(k << 1 | 1, sp + indent); // Right child
            s += "\n";
            s += indent(sp) + Dat[k] + "/" + Laz[k]; // Current node
            s += "\n";
            s += toString(k << 1 | 0, sp + indent); // Left child
            return s; // Return string representation
        }

        // Helper function to create indentation
        private static String indent(int n) {
            StringBuilder sb = new StringBuilder();
            while (n-- > 0) sb.append(' '); // Append spaces
            return sb.toString(); // Return indentation
        }
    }

    // Class for reading input
    static class InputReader {
        private InputStream in; // Input stream
        private byte[] buffer = new byte[1024]; // Buffer for reading
        private int curbuf; // Current buffer position
        private int lenbuf; // Length of buffer

        // Constructor for input reader
        public InputReader(InputStream in) {
            this.in = in;
            this.curbuf = this.lenbuf = 0; // Initialize buffer positions
        }

        // Check if there is a next byte to read
        public boolean hasNextByte() {
            if (curbuf >= lenbuf) {
                curbuf = 0; // Reset buffer position
                try {
                    lenbuf = in.read(buffer); // Read from input stream
                } catch (IOException e) {
                    throw new InputMismatchException(); // Handle input error
                }
                if (lenbuf <= 0)
                    return false; // No more bytes to read
            }
            return true; // Bytes available
        }

        // Read a single byte from the input
        private int readByte() {
            if (hasNextByte())
                return buffer[curbuf++]; // Return byte and increment position
            else
                return -1; // No byte available
        }

        // Check if a character is a space
        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126); // Check ASCII range for printable characters
        }

        // Skip whitespace characters
        private void skip() {
            while (hasNextByte() && isSpaceChar(buffer[curbuf]))
                curbuf++; // Increment buffer position
        }

        // Check if there is a next token
        public boolean hasNext() {
            skip(); // Skip whitespace
            return hasNextByte(); // Check for next byte
        }

        // Read the next token as a string
        public String next() {
            if (!hasNext())
                throw new NoSuchElementException(); // No more tokens
            StringBuilder sb = new StringBuilder(); // String builder for result
            int b = readByte(); // Read first byte
            while (!isSpaceChar(b)) {
                sb.appendCodePoint(b); // Append character to string
                b = readByte(); // Read next byte
            }
            return sb.toString(); // Return the complete string
        }

        // Read the next token as an integer
        public int nextInt() {
            if (!hasNext())
                throw new NoSuchElementException(); // No more tokens
            int c = readByte(); // Read first byte
            while (isSpaceChar(c))
                c = readByte(); // Skip whitespace
            boolean minus = false; // Check for negative sign
            if (c == '-') {
                minus = true; // Set negative flag
                c = readByte(); // Read next byte
            }
            int res = 0; // Result variable
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException(); // Invalid character
                res = res * 10 + c - '0'; // Build integer
                c = readByte(); // Read next byte
            } while (!isSpaceChar(c)); // Continue until whitespace
            return (minus) ? -res : res; // Return result with sign
        }

        // Read the next token as a long
        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException(); // No more tokens
            int c = readByte(); // Read first byte
            while (isSpaceChar(c))
                c = readByte(); // Skip whitespace
            boolean minus = false; // Check for negative sign
            if (c == '-') {
                minus = true; // Set negative flag
                c = readByte(); // Read next byte
            }
            long res = 0; // Result variable
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException(); // Invalid character
                res = res * 10 + c - '0'; // Build long
                c = readByte(); // Read next byte
            } while (!isSpaceChar(c)); // Continue until whitespace
            return (minus) ? -res : res; // Return result with sign
        }

        // Read the next token as a double
        public double nextDouble() {
            return Double.parseDouble(next()); // Parse string to double
        }

        // Read an array of integers
        public int[] nextIntArray(int n) {
            int[] a = new int[n]; // Initialize array
            for (int i = 0; i < n; i++)
                a[i] = nextInt(); // Fill array with integers
            return a; // Return the array
        }

        // Read an array of longs
        public long[] nextLongArray(int n) {
            long[] a = new long[n]; // Initialize array
            for (int i = 0; i < n; i++)
                a[i] = nextLong(); // Fill array with longs
            return a; // Return the array
        }

        // Read a character map (2D array of characters)
        public char[][] nextCharMap(int n, int m) {
            char[][] map = new char[n][m]; // Initialize 2D array
            for (int i = 0; i < n; i++)
                map[i] = next().toCharArray(); // Fill array with character arrays
            return map; // Return the 2D array
        }
    }
}
