import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

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
        int k = 1;
        while (2 * k <= heapSize) {
            int next = 2 * k;
            if (next + 1 <= heapSize && cmp.compare(array[next], array[next + 1]) > 0) {
                next++;
            }
            if (cmp.compare(array[k], array[next]) <= 0) {
                break;
            }
            swap(k, next);
            k = next;
        }
        return res;
    }

    public Object top() {
        return isEmpty() ? null : array[1];
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
        Arrays.fill(parent, -1);
    }

    private int root(int x) {
        while (parent[x] >= 0) {
            x = parent[x];
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
            func.accept(array[2 * i], array[2 * i + 1], array[i]);
        }
    }

    public void update(int k, Object val) {
        k += size;
        array[k] = val;
        for (k >>= 1; k > 0; k >>= 1) {
            func.accept(array[2 * k], array[2 * k + 1], array[k]);
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
            func.accept(res, array[lindex[i]], res);
        }
        for (int i = rlen - 1; i >= 0; i--) {
            func.accept(res, array[rindex[i]], res);
        }
    }
}

class IndexVal {
    int index;
    int val;

    IndexVal(int index, int val) {
        this.index = index;
        this.val = val;
    }
}

class SegmentNode {
    int index;
    long val;

    SegmentNode(int index, long val) {
        this.index = index;
        this.val = val;
    }
}

class Edge {
    int a, b;
    long c;

    Edge(int a, int b, long c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class Main {
    public static void main(String[] args) {
        run();
    }

    private static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            p[i] = new IndexVal(i, a[i]);
        }
        Arrays.sort(p, Comparator.comparingInt(iv -> -iv.val));
        SegmentNode ini = new SegmentNode(n, (long) (n + 2) * 1000000000 + 1);
        SegmentTree l = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a, b) -> {
            SegmentNode p1 = (SegmentNode) a;
            SegmentNode p2 = (SegmentNode) b;
            ((SegmentNode) c).val = Math.min(p1.val, p2.val);
        });
        SegmentTree r = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a, b) -> {
            SegmentNode p1 = (SegmentNode) a;
            SegmentNode p2 = (SegmentNode) b;
            ((SegmentNode) c).val = Math.min(p1.val, p2.val);
        });
        for (int i = 0; i < n; i++) {
            l.update(i, new SegmentNode(i, a[i] + (long) (n - 1 - i) * d));
            r.update(i, new SegmentNode(i, a[i] + (long) i * d));
        }
        long sum = 0;
        UnionFind u = new UnionFind(n);
        BinaryHeap h = new BinaryHeap(Edge.class.getDeclaredFields().length, (a1, b1) -> {
            long d1 = ((Edge) a1).c - ((Edge) b1).c;
            return Long.compare(d1, 0);
        });
        for (int i = 0; i < n; i++) {
            int v = p[i].index;
            if (v > 0) {
                SegmentNode t = new SegmentNode(0, 0);
                l.find(0, v, t);
                h.push(new Edge(v, t.index, p[i].val + t.val - (long) (n - 1 - v) * d));
            }
            if (v + 1 < n) {
                SegmentNode t = new SegmentNode(0, 0);
                r.find(v + 1, n, t);
                h.push(new Edge(v, t.index, p[i].val + t.val - (long) v * d));
            }
            l.update(v, ini);
            r.update(v, ini);
        }
        while (u.getSize(0) < n) {
            Edge e = (Edge) h.pop();
            if (u.same(e.a, e.b)) continue;
            u.unite(e.a, e.b);
            sum += e.c;
        }
        System.out.println(sum);
    }
}
