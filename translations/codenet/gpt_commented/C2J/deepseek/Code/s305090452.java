import java.util.*;

class BinaryHeap {
    private Object[] array;
    private int heapSize;
    private int maxSize;
    private int valSize;
    private Comparator<?> cmp;

    public BinaryHeap(int valSize, Comparator<?> cmp) {
        this.array = new Object[valSize * (1 + 1)];
        this.heapSize = 0;
        this.maxSize = 1;
        this.valSize = valSize;
        this.cmp = cmp;
    }

    public int getHeapSize() {
        return heapSize;
    }

    public boolean isEmpty() {
        return heapSize == 0;
    }

    public void freeHeap() {
        array = null;
    }

    public void initHeap() {
        heapSize = 0;
    }

    private void swap(Object a, Object b, int valSize) {
        if ((valSize & 7) == 0) {
            for (int i = 0; i < valSize / 8; i++) {
                byte temp = ((byte[]) a)[i];
                ((byte[]) a)[i] = ((byte[]) b)[i];
                ((byte[]) b)[i] = temp;
            }
        } else {
            for (int i = 0; i < valSize; i++) {
                byte temp = ((byte[]) a)[i];
                ((byte[]) a)[i] = ((byte[]) b)[i];
                ((byte[]) b)[i] = temp;
            }
        }
    }

    private void copy(Object dst, Object src, int valSize) {
        if ((valSize & 7) == 0) {
            for (int i = 0; i < valSize / 8; i++) {
                ((byte[]) dst)[i] = ((byte[]) src)[i];
            }
        } else {
            for (int i = 0; i < valSize; i++) {
                ((byte[]) dst)[i] = ((byte[]) src)[i];
            }
        }
    }

    public void push(Object val) {
        if (heapSize == maxSize) {
            maxSize = 2 * maxSize + 1;
            array = Arrays.copyOf(array, maxSize + 1);
        }
        heapSize++;
        int k = heapSize;
        int valSize = this.valSize;
        Comparator<?> cmp = this.cmp;
        copy(array[k * valSize], val, valSize);
        while (k > 1) {
            int parent = k / 2;
            if (cmp.compare(array[parent * valSize], array[k * valSize]) <= 0) {
                return;
            }
            swap(array[parent * valSize], array[k * valSize], valSize);
            k = parent;
        }
    }

    public void pop(Object res) {
        if (res != null) {
            copy(res, array[valSize], valSize);
        }
        copy(array[valSize], array[heapSize * valSize], valSize);
        heapSize--;
        int n = heapSize;
        int k = 1;
        while (2 * k + 1 <= n) {
            int c = cmp.compare(array[2 * k * valSize], array[(2 * k + 1) * valSize]);
            int next = 2 * k + (c <= 0 ? 0 : 1);
            if (cmp.compare(array[k * valSize], array[next * valSize]) <= 0) return;
            swap(array[k * valSize], array[next * valSize], valSize);
            k = next;
        }
        if (2 * k <= n && cmp.compare(array[k * valSize], array[2 * k * valSize]) > 0) {
            swap(array[k * valSize], array[2 * k * valSize], valSize);
        }
    }

    public void top(Object res) {
        if (res != null) {
            copy(res, array[valSize], valSize);
        }
    }
}

class UnionFind {
    private int[] parent;
    private int size;

    public UnionFind(int size) {
        this.parent = new int[size];
        this.size = size;
        initUnionFind();
    }

    private void initUnionFind() {
        for (int i = 0; i < size; ++i) {
            parent[i] = -1;
        }
    }

    public int root(int x) {
        int[] index = new int[32];
        int len = 0;
        while (parent[x] >= 0) {
            index[len++] = x;
            x = parent[x];
        }
        for (int i = 0; i < len; ++i) {
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
            int swap = x;
            x = y;
            y = swap;
        }
        parent[x] += parent[y];
        parent[y] = x;
    }
}

class SegmentTree<T> {
    private Object[] array;
    private int size;
    private int valSize;
    private Merger<T> merger;

    public SegmentTree(T[] ini, int n, int valSize, Merger<T> merger) {
        int k = 1;
        while (k < n) k *= 2;
        this.array = new Object[2 * k];
        this.size = k;
        this.valSize = valSize;
        this.merger = merger;
        System.arraycopy(ini, 0, array, k, n);
        for (int i = k - 1; i > 0; --i) {
            array[i] = merger.merge((T[]) array[2 * i], (T[]) array[2 * i + 1]);
        }
    }

    public void update(int k, T val) {
        k += size;
        array[k] = val;
        while (k > 1) {
            k >>= 1;
            array[k] = merger.merge((T[]) array[2 * k], (T[]) array[2 * k + 1]);
        }
    }

    public T find(int l, int r) {
        T res = (T) array[l + size];
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) > 0) res = merger.merge(res, (T) array[l++]);
            if ((r & 1) > 0) res = merger.merge(res, (T) array[--r]);
        }
        return res;
    }
}

interface Merger<T> {
    T merge(T a, T b);
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
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
            p[i] = new IndexVal(i, a[i]);
        }
        Arrays.sort(p, Comparator.comparingInt(o -> o.val));
        SegmentNode ini = new SegmentNode(n, (long) (n + 2) * 1000000000 + 1);
        SegmentTree<SegmentNode> l = new SegmentTree<>(new SegmentNode[]{ini}, n, sizeof(SegmentNode), SegmentNode::merge);
        SegmentTree<SegmentNode> r = new SegmentTree<>(new SegmentNode[]{ini}, n, sizeof(SegmentNode), SegmentNode::merge);
        for (int i = 0; i < n; ++i) {
            l.update(i, new SegmentNode(i, (long) a[i] + (long) (n - 1 - i) * d));
            r.update(i, new SegmentNode(i, (long) a[i] + (long) i * d));
        }
        l.updateAll();
        r.updateAll();
        BinaryHeap h = new BinaryHeap(sizeof(Edge), Comparator.comparingLong(e -> e.c));
        for (int i = 0; i < n; ++i) {
            int v = p[i].index;
            if (v > 0) {
                SegmentNode t = l.find(0, v);
                h.push(new Edge(v, t.index, (long) p[i].val + t.val - (long) (n - 1 - v) * d));
            }
            if (v + 1 < n) {
                SegmentNode t = r.find(v + 1, n);
                h.push(new Edge(v, t.index, (long) p[i].val + t.val - (long) v * d));
            }
            l.update(v, ini);
            r.update(v, ini);
        }
        long sum = 0;
        UnionFind u = new UnionFind(n);
        while (u.getSize(0) < n) {
            Edge e = (Edge) h.pop();
            if (u.same(e.a, e.b)) continue;
            u.unite(e.a, e.b);
            sum += e.c;
        }
        System.out.println(sum);
    }
}

class IndexVal {
    int index, val;

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

    public SegmentNode merge(SegmentNode other) {
        return this.val < other.val ? this : other;
    }
}
