import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    // Declare static final long constants for modulus 1 and 2
    static final long MOD1 = 1000000007;
    static final long MOD2 = 998244353;

    // Declare static long array tenmod and initialize its first element
    static long[] tenmod;
    static {
        tenmod = new long[N + 1];
        tenmod[0] = 1;
    }

    // Declare static long variables MOD1 and MOD2, and static instance variables lazySegTree and sc
    static LazySegTree<S, F> lazySegTree;
    static InputReader sc;

    // Declare static final long constant inv9
    static final long inv9 = modInv(9);

    public static void main(String[] args) {
        // Initialize PrintWriter out and InputReader sc
        PrintWriter out = new PrintWriter(System.out);
        InputReader sc = new InputReader(System.in);

        // Read input N and Q
        int N = sc.nextInt();
        int Q = sc.nextInt();

        // Initialize tenmod array
        tenmod = new long[N + 1];
        tenmod[0] = 1;
        for (int j = 1; j <= N; j++) {
            tenmod[j] = (tenmod[j - 1] * 10L) % MOD2;
        }

        // Initialize S array dat and create LazySegTree lazySegTree using S and F classes
        S[] dat = new S[N];
        Arrays.setAll(dat, i -> new S(tenmod[N - i - 1], i, i));
        lazySegTree = new LazySegTree<S, F>(dat, S::op, S.E, S::map, F::composite, F.I);

        // Process each query
        for (int j = 0; j < Q; j++) {
            // Read query parameters l, r, and D
            int l = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;
            long D = sc.nextLong();

            // Apply update to lazySegTree for the given range [l, r] with the given difference D
            lazySegTree.apply(l, r + 1, new F(D, N));

            // Print the result, which is the product of all elements in the range [0, N] after applying the update
            out.println(lazySegTree.allProd().sum);
        }

        // Close PrintWriter out
        out.flush();
    }

    // Static method to calculate modular inverse of a number
    static long modInv(long x) {
        return modPow(x, MOD2 - 2);
    }

    // Static method to calculate x raised to the power of y modulo m
    static long modPow(long x, long y) {
        long z = 1;
        while (y > 0) {
            if (y % 2 == 0) {
                x = (x * x) % MOD2;
                y /= 2;
            } else {
                z = (z * x) % MOD2;
                y--;
            }
        }
        return z;
    }

    // Inner class representing a segment tree node
    static class S {
        // Declare static final S instance E, representing an empty segment tree node
        static final S E = new S(0, Integer.MAX_VALUE / 2, Integer.MIN_VALUE / 2);

        // Declare instance variables sum, l, and r
        long sum;
        int l;
        int r;

        // Constructor for S class
        public S(long sum, int l, int r) {
            this.sum = sum;
            this.l = l;
            this.r = r;
        }

        // Static method to calculate the operation of two S objects
        public static S op(S s1, S s2) {
            long sum = s1.sum + s2.sum;
            if (sum >= MOD2) {
                sum -= MOD2;
            }
            return new S(sum, Math.min(s1.l, s2.l), Math.max(s1.r, s2.r));
        }

        // Method to map an F object to an S object
        public static S map(F f, S s) {
            long c = (tenmod[(f.N - s.l)] - tenmod[(f.N - s.r - 1)]);
            if (c < 0) {
                c += MOD2;
            }
            return new S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
        }

        // Inner class representing an identity function for F
        static class F {
            // Declare static final F instance I, representing an identity function for F
            static final F I = new F(0, 0);

            // Declare instance variables D and N
            long D;
            int N;

            // Constructor for F class
            public F(long D, int N) {
                this.D = D;
                this.N = N;
            }

            // Static method to calculate the composition of two F objects
            public static F composite(F f, F g) {
                return new F(f.D, f.N);
            }
        }
    }

    // Inner class representing a lazy segment tree
    static class LazySegTree<S, F> {
        // Declare instance variables MAX, N, Log, Op, E, Mapping, Composition, and Id
        final int MAX;
        final int N;
        final int Log;
        final java.util.function.BinaryOperator<S> Op;
        final S E;
        final java.util.function.BiFunction<F, S, S> Mapping;
        final java.util.function.BinaryOperator<F> Composition;
        final F Id;

        // Declare instance variables Dat and Laz
        final S[] Dat;
        final F[] Laz;

        // Constructor for LazySegTree class
        @SuppressWarnings("unchecked")
        public LazySegTree(int n, java.util.function.BinaryOperator<S> op, S e, java.util.function.BiFunction<F, S, S> mapping, java.util.function.BinaryOperator<F> composition, F id) {
            this.MAX = n;
            int k = 1;
            while (k < n) k <<= 1;
            this.N = k;
            this.Log = Integer.numberOfTrailingZeros(N);
            this.Op = op;
            this.E = e;
            this.Mapping = mapping;
            this.Composition = composition;
            this.Id = id;
            this.Dat = (S[]) new Object[N << 1];
            this.Laz = (F[]) new Object[N];
            java.util.Arrays.fill(Dat, E);
            java.util.Arrays.fill(Laz, Id);
        }

        // Constructor for LazySegTree class with pre-initialized Dat array
        public LazySegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e, java.util.function.BiFunction<F, S, S> mapping, java.util.function.BinaryOperator<F> composition, F id) {
            this(dat.length, op, e, mapping, composition, id);
            build(dat);
        }

        // Method to build the segment tree from the given Dat array
        private void build(S[] dat) {
            int l = dat.length;
            System.arraycopy(dat, 0, Dat, N, l);
            for (int i = N - 1; i > 0; i--) {
                Dat[i] = Op.apply(Dat[i << 1 | 0], Dat[i << 1 | 1]);
            }
        }

        // Method to push down the lazy updates from the parent node to its children
        private void push(int k) {
            if (Laz[k] == Id) return;
            int lk = k << 1 | 0, rk = k << 1 | 1;
            Dat[lk] = Mapping.apply(Laz[k], Dat[lk]);
            Dat[rk] = Mapping.apply(Laz[k], Dat[rk]);
            if (lk < N) Laz[lk] = Composition.apply(Laz[k], Laz[lk]);
            if (rk < N) Laz[rk] = Composition.apply(Laz[k], Laz[rk]);
            Laz[k] = Id;
        }

        // Method to push down the lazy updates from the given node to all its descendants
        private void pushTo(int k) {
            for (int i = Log; i > 0; i--) push(k >> i);
        }

        // Method to update the segment tree from the given node to its descendants
        private void updateFrom(int k) {
            k >>= 1;
            while (k > 0) {
                Dat[k] = Op.apply(Dat[k << 1 | 0], Dat[k << 1 | 1]);
                k >>= 1;
            }
        }

        // Method to set the value of a node in the segment tree
        public void set(int p, S x) {
            exclusiveRangeCheck(p);
            p += N;
            pushTo(p);
            Dat[p] = x;
            updateFrom(p);
        }

        // Method to get the value of a node in the segment tree
        public S get(int p) {
            exclusiveRangeCheck(p);
            p += N;
            pushTo(p);
            return Dat[p];
        }

        // Method to get the product of all elements in the given range of the segment tree
        public S allProd() {
            return Dat[1];
        }

        // Method to apply a given F object to a given range in the segment tree
        public void apply(int l, int r, F f) {
            if (l > r) {
                throw new IllegalArgumentException(
                    String.format("Invalid range: [%d, %d)", l, r)
                );
            }
            inclusiveRangeCheck(l);
            inclusiveRangeCheck(r);
            if (l == r) return;
            l += N; r += N;
            pushTo(l, r);
            for (int l2 = l, r2 = r; l2 < r2;) {
                if ((l2 & 1) == 1) {
                    Dat[l2] = Mapping.apply(f, Dat[l2]);
                    if (l2 < N) Laz[l2] = Composition.apply(f, Laz[l2]);
                    l2++;
                }
                if ((r2 & 1) == 1) {
                    r2--;
                    Dat[r2] = Mapping.apply(f, Dat[r2]);
                    if (r2 < N) Laz[r2] = Composition.apply(f, Laz[r2]);
                }
                l2 >>= 1; r2 >>= 1;
            }
            updateFrom(l, r);
        }

        // Method to find the maximum right index in the segment tree where a given predicate is satisfied
        public int maxRight(int l, java.util.function.Predicate<S> g) {
            inclusiveRangeCheck(l);
            if (!g.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (l == MAX) return MAX;
            l += N;
            pushTo(l);
            S sum = E;
            do {
                l >>= Integer.numberOfTrailingZeros(l);
                if (!g.test(Op.apply(sum, Dat[l]))) {
                    while (l < N) {
                        push(l);
                        l = l << 1;
                        if (g.test(Op.apply(sum, Dat[l]))) {
                            sum = Op.apply(sum, Dat[l]);
                            l++;
                        }
                    }
                }
            }
        }
    }
}