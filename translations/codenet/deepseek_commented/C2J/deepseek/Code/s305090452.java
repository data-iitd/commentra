public class Main {
    // Define the structure of a binary heap and its operations.
    static class BinaryHeap {
        Object[] array;
        int heapSize;
        int maxSize;
        int valSize;
        java.util.Comparator<?> cmp;
    }

    // Initialize a new binary heap with a given value size and comparison function.
    static BinaryHeap newBinaryHeap(int valSize, java.util.Comparator<?> cmp) {
        BinaryHeap h = new BinaryHeap();
        h.array = new Object[valSize * (1 + 1)];
        h.heapSize = 0;
        h.maxSize = 1;
        h.valSize = valSize;
        h.cmp = cmp;
        return h;
    }

    // Return the current size of the heap.
    static int getHeapSize(BinaryHeap h) {
        return h.heapSize;
    }

    // Check if the heap is empty.
    static boolean isEmpty(BinaryHeap h) {
        return h.heapSize == 0;
    }

    // Free the memory allocated for the heap.
    static void freeHeap(BinaryHeap h) {
        h.array = null;
        h = null;
    }

    // Initialize the heap size to zero.
    static void initHeap(BinaryHeap h) {
        h.heapSize = 0;
    }

    // Swap two elements of the heap.
    static void heapFuncSwap(Object a, Object b, int valSize) {
        if ((valSize & 7) == 0) {
            long[] p = (long[]) a;
            long[] q = (long[]) b;
            valSize /= 8;
            while (valSize-- > 0) {
                long tmp = p[0];
                p[0] = q[0];
                q[0] = tmp;
            }
        } else {
            byte[] p = (byte[]) a;
            byte[] q = (byte[]) b;
            while (valSize-- > 0) {
                byte tmp = p[0];
                p[0] = q[0];
                q[0] = tmp;
            }
        }
    }

    // Copy one element to another.
    static void heapFuncCopy(Object dst, Object src, int valSize) {
        if ((valSize & 7) == 0) {
            long[] p = (long[]) src;
            long[] q = (long[]) dst;
            valSize /= 8;
            while (valSize-- > 0) {
                q[valSize] = p[valSize];
            }
        } else {
            byte[] p = (byte[]) src;
            byte[] q = (byte[]) dst;
            while (valSize-- > 0) {
                q[valSize] = p[valSize];
            }
        }
    }

    // Add a new element to the heap.
    static void push(BinaryHeap h, Object val) {
        if (h.heapSize == h.maxSize) {
            h.maxSize = 2 * h.maxSize + 1;
            h.array = java.util.Arrays.copyOf(h.array, h.valSize * (h.maxSize + 1));
        }
        h.heapSize++;
        byte[] array = (byte[]) h.array;
        int k = h.heapSize;
        int valSize = h.valSize;
        java.util.Comparator<?> cmp = h.cmp;
        heapFuncCopy(array + k * valSize, val, valSize);
        while (k > 1) {
            int parent = k / 2;
            if (cmp.compare(array + parent * valSize, array + k * valSize) <= 0) {
                return;
            }
            heapFuncSwap(array + parent * valSize, array + k * valSize, valSize);
            k = parent;
        }
    }

    // Remove the top element from the heap.
    static void pop(BinaryHeap h, Object res) {
        byte[] array = (byte[]) h.array;
        int valSize = h.valSize;
        if (res != null) {
            heapFuncCopy(res, array, valSize);
        }
        heapFuncCopy(array, array + valSize * h.heapSize, valSize);
        h.heapSize--;
        java.util.Comparator<?> cmp = h.cmp;
        int n = h.heapSize;
        int k = 1;
        while (2 * k + 1 <= n) {
            int c = cmp.compare(array + valSize * 2 * k, array + valSize * (2 * k + 1));
            int next = 2 * k + (c <= 0 ? 0 : 1);
            if (cmp.compare(array + valSize * k, array + valSize * next) <= 0) return;
            heapFuncSwap(array + valSize * k, array + valSize * next, valSize);
            k = next;
        }
        if (2 * k <= n && cmp.compare(array + valSize * k, array + valSize * 2 * k) > 0) {
            heapFuncSwap(array + valSize * k, array + valSize * 2 * k, valSize);
        }
    }

    // Return the top element of the heap without removing it.
    static void top(BinaryHeap h, Object res) {
        byte[] array = (byte[]) h.array;
        int valSize = h.valSize;
        if (res != null) {
            heapFuncCopy(res, array, valSize);
        }
    }

    // Define the structure of Union-Find and its operations.
    static class UnionFind {
        int[] parent;
        int size;
    }

    // Initialize the parent array to -1.
    static void initUnionFind(UnionFind u) {
        for (int i = 0; i < u.size; ++i) {
            u.parent[i] = -1;
        }
    }

    // Initialize a new Union-Find structure with a given size.
    static UnionFind newUnionFind(int size) {
        UnionFind u = new UnionFind();
        u.parent = new int[size];
        u.size = size;
        initUnionFind(u);
        return u;
    }

    // Free the memory allocated for the Union-Find structure.
    static void freeUnionFind(UnionFind u) {
        u.parent = null;
        u = null;
    }

    // Find the root of a given element.
    static int root(UnionFind u, int x) {
        int[] index = new int[32];
        int len = 0;
        while (u.parent[x] >= 0) {
            index[len++] = x;
            x = u.parent[x];
        }
        while (len > 0) {
            u.parent[index[--len]] = x;
        }
        return x;
    }

    // Check if two elements are in the same set.
    static boolean same(UnionFind u, int x, int y) {
        return root(u, x) == root(u, y);
    }

    // Return the size of the set containing a given element.
    static int getSize(UnionFind u, int x) {
        return -u.parent[root(u, x)];
    }

    // Merge two sets.
    static void unite(UnionFind u, int x, int y) {
        x = root(u, x);
        y = root(u, y);
        if (x == y) return;
        if (u.parent[x] > u.parent[y]) {
            int swap = x;
            x = y;
            y = swap;
        }
        u.parent[x] += u.parent[y];
        u.parent[y] = x;
    }

    // Define the structure of a segment tree and its operations.
    static class SegmentTree {
        Object[] array;
        int size;
        int valSize;
        java.util.function.BiFunction<Object, Object, Object> func;
    }

    // Copy one memory area to another.
    static void segmentTreeMemcpy(Object dst, Object src, int size) {
        byte[] p = (byte[]) dst;
        byte[] q = (byte[]) src;
        while (size-- > 0) {
            p[size] = q[size];
        }
    }

    // Initialize a new segment tree with an initial array, size, value size, and merge function.
    static SegmentTree newSegmentTree(Object ini, int n, int valSize, java.util.function.BiFunction<Object, Object, Object> func) {
        int k = 1;
        while (k < n) k *= 2;
        SegmentTree s = new SegmentTree();
        s.array = new Object[2 * k];
        java.util.Arrays.fill(s.array, ini);
        s.size = k;
        s.valSize = valSize;
        s.func = func;
        for (int i = k; i < 2 * k; ++i) {
            segmentTreeMemcpy(s.array[i], ((byte[]) ini) + (i - k) * valSize, valSize);
        }
        for (int i = k - 1; i > 0; --i) {
            s.array[i] = s.func.apply(s.array[2 * i], s.array[2 * i + 1]);
        }
        return s;
    }

    // Update a segment tree node.
    static void update(SegmentTree s, int k, Object val) {
        k += s.size;
        segmentTreeMemcpy(s.array[k], val, s.valSize);
        for (k >>= 1; k > 0; k >>= 1) {
            s.array[k] = s.func.apply(s.array[2 * k], s.array[2 * k + 1]);
        }
    }

    // Temporarily update a segment tree node.
    static void updateTmp(SegmentTree s, int k, Object val) {
        k += s.size;
        segmentTreeMemcpy(s.array[k], val, s.valSize);
    }

    // Update all segment tree nodes.
    static void updateAll(SegmentTree s) {
        Object[] a = s.array;
        int size = s.valSize;
        for (int i = s.size - 1; i > 0; --i) {
            a[i] = s.func.apply(a[2 * i], a[2 * i + 1]);
        }
    }

    // Find the result of applying the merge function to a range of segment tree nodes.
    static void find(SegmentTree s, int l, int r, Object res) {
        Object[] a = s.array;
        int size = s.valSize;
        int llen = 0;
        int rlen = 0;
        int[] lindex = new int[32];
        int[] rindex = new int[32];
        for (l += s.size, r += s.size; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) lindex[llen++] = l++;
            if ((r & 1) != 0) rindex[rlen++] = --r;
        }
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen];
        }
        segmentTreeMemcpy(res, a[lindex[0]], size);
        for (int i = 1; i < llen; ++i) {
            res = s.func.apply(res, a[lindex[i]]);
        }
        for (int i = rlen - 1; i >= 0; --i) {
            res = s.func.apply(res, a[rindex[i]]);
        }
    }

    // Define the main function to run the program.
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        index_val[] p = new index_val[n];
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
            p[i] = new index_val(i, a[i]);
        }
        java.util.Arrays.sort(p, (a1, b1) -> Integer.compare(a1.val, b1.val));
        segment_node ini = new segment_node(n, (long) (n + 2) * 1000000000 + 1);
        SegmentTree l = newSegmentTree(ini, n, 8, (a1, b1) -> ((segment_node) a1).val < ((segment_node) b1).val ? a1 : b1);
        SegmentTree r = newSegmentTree(ini, n, 8, (a1, b1) -> ((segment_node) a1).val < ((segment_node) b1).val ? a1 : b1);
        for (int i = 0; i < n; ++i) {
            update(l, i, new segment_node(i, a[i] + (long) (n - 1 - i) * d));
            update(r, i, new segment_node(i, a[i] + (long) i * d));
        }
        updateAll(l);
        updateAll(r);
        BinaryHeap h = newBinaryHeap(8, (a1, b1) -> Long.compare((((edge) a1).c), (((edge) b1).c)));
        for (int i = 0; i < n; ++i) {
            int v = p[i].index;
            if (v > 0) {
                segment_node t = new segment_node(0, 0);
                find(l, 0, v, t);
                push(h, new edge(v, t.index, (long) p[i].val + t.val - (long) (n - 1 - v) * d));
            }
            if (v + 1 < n) {
                segment_node t = new segment_node(0, 0);
                find(r, v + 1, n, t);
                push(h, new edge(v, t.index, (long) p[i].val + t.val - (long) v * d));
            }
            update(l, v, ini);
            update(r, v, ini);
        }
        long sum = 0;
        UnionFind u = newUnionFind(n);
        while (getSize(u, 0) < n) {
            edge e = new edge(0, 0, 0);
            pop(h, e);
            if (same(u, e.a, e.b)) continue;
            unite(u, e.a, e.b);
            sum += e.c;
        }
        System.out.println(sum);
    }

    // Define the structures and functions for the program.
    static class index_val {
        int index;
        int val;

        index_val(int index, int val) {
            this.index = index;
            this.val = val;
        }
    }

    static class segment_node {
        int index;
        long val;

        segment_node(int index, long val) {
            this.index = index;
            this.val = val;
        }
    }

    static class edge {
        int a, b;
        long c;

        edge(int a, int b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
}
