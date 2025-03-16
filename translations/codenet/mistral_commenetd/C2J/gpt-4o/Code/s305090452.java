import java.util.Arrays;

class BinaryHeap {
    private Object[] array;
    private int heapSize;
    private int maxSize;
    private int valSize;
    private Comparator<Object> cmp;

    public BinaryHeap(int valSize, Comparator<Object> cmp) {
        this.valSize = valSize;
        this.cmp = cmp;
        this.maxSize = 1;
        this.heapSize = 0;
        this.array = new Object[maxSize + 1];
    }

    public int getHeapSize() {
        return heapSize;
    }

    public boolean isEmpty() {
        return heapSize == 0;
    }

    public void push(Object val) {
        if (heapSize == maxSize) {
            maxSize = 2 * maxSize + 1;
            array = Arrays.copyOf(array, maxSize + 1);
        }
        heapSize++;
        array[heapSize] = val;
        int k = heapSize;
        while (k > 1) {
            int parent = k / 2;
            if (cmp.compare(array[parent], array[k]) <= 0) {
                return;
            }
            swap(parent, k);
            k = parent;
        }
    }

    public Object pop() {
        if (isEmpty()) return null;
        Object res = array[1];
        array[1] = array[heapSize];
        heapSize--;
        heapify(1);
        return res;
    }

    public Object top() {
        return isEmpty() ? null : array[1];
    }

    private void heapify(int k) {
        int n = heapSize;
        while (2 * k <= n) {
            int next = 2 * k;
            if (next + 1 <= n && cmp.compare(array[next], array[next + 1]) > 0) {
                next++;
            }
            if (cmp.compare(array[k], array[next]) <= 0) return;
            swap(k, next);
            k = next;
        }
    }

    private void swap(int i, int j) {
        Object temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

class UnionFind {
    private int[] parent;
    private int size;

    public UnionFind(int size) {
        this.size = size;
        this.parent = new int[size];
        initUnionFind();
    }

    private void initUnionFind() {
        Arrays.fill(parent, -1);
    }

    public int root(int x) {
        int[] index = new int[32];
        int len = 0;
        while (parent[x] >= 0) {
            index[len++] = x;
            x = parent[x];
        }
        for (int i = 0; i < len; i++) {
            parent[index[i]] = x;
        }
        return x;
    }

    public boolean same(int x, int y) {
        return root(x) == root(y);
    }

    public int getSize(int x) {
        return -parent[root(x)];
    }

    public void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (parent[x] > parent[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[x] += parent[y];
        parent[y] = x;
    }
}

class SegmentTree {
    private Object[] array;
    private int size;
    private int valSize;
    private BiConsumer<Object, Object> func;

    public SegmentTree(Object ini, int n, int valSize, BiConsumer<Object, Object> func) {
        this.valSize = valSize;
        this.func = func;
        int k = 1;
        while (k < n) k *= 2;
        this.size = k;
        this.array = new Object[2 * k];
        Arrays.fill(array, ini);
        for (int i = k; i < 2 * k; i++) {
            array[i] = ini;
        }
        for (int i = k - 1; i > 0; i--) {
            func.accept(array[i * 2], array[i * 2 + 1]);
        }
    }

    public void update(int k, Object val) {
        k += size;
        array[k] = val;
        for (k >>= 1; k > 0; k >>= 1) {
            func.accept(array[2 * k], array[2 * k + 1]);
        }
    }

    public void find(int l, int r, Object res) {
        int llen = 0, rlen = 0;
        int[] lindex = new int[32];
        int[] rindex = new int[32];
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) lindex[llen++] = l++;
            if (r % 2 == 1) rindex[rlen++] = --r;
        }
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen];
        }
        System.arraycopy(array[lindex[0]], 0, res, 0, valSize);
        for (int i = 1; i < llen; i++) {
            func.accept(res, array[lindex[i]]);
        }
        for (int i = rlen - 1; i >= 0; i--) {
            func.accept(res, array[rindex[i]]);
        }
    }
}

class IndexVal {
    int index;
    int val;

    public IndexVal(int index, int val) {
        this.index = index;
        this.val = val;
    }
}

class SegmentNode {
    int index;
    long val;

    public SegmentNode(int index, long val) {
        this.index = index;
        this.val = val;
    }
}

class Edge {
    int a, b;
    long c;

    public Edge(int a, int b, long c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class Main {
    public static void main(String[] args) {
        run();
    }

    public static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            p[i] = new IndexVal(i, a[i]);
        }
        Arrays.sort(p, (x, y) -> Integer.compare(y.val, x.val));
        SegmentNode ini = new SegmentNode(n, (long)(n + 2) * 1000000000 + 1);
        SegmentTree l = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a, b) -> {
            SegmentNode p1 = (SegmentNode) a;
            SegmentNode p2 = (SegmentNode) b;
            c = p1.val < p2.val ? p1 : p2;
        });
        SegmentTree r = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a, b) -> {
            SegmentNode p1 = (SegmentNode) a;
            SegmentNode p2 = (SegmentNode) b;
            c = p1.val < p2.val ? p1 : p2;
        });
        for (int i = 0; i < n; i++) {
            l.update(i, new SegmentNode(i, a[i] + (long)(n - 1 - i) * d));
            r.update(i, new SegmentNode(i, a[i] + (long)i * d));
        }
        // Further implementation needed for the heap and edge processing
    }
}

// <END-OF-CODE>
