import java.util.*;

class BinaryHeap {
    private Object[] array;
    private int heapSize;
    private int maxSize;
    private int valSize;
    private Comparator comparator;

    public BinaryHeap(int valSize, Comparator comparator) {
        this.array = new Object[1 + 1];
        this.heapSize = 0;
        this.maxSize = 1;
        this.valSize = valSize;
        this.comparator = comparator;
    }

    public int getHeapSize() {
        return heapSize;
    }

    public boolean isEmpty() {
        return heapSize == 0;
    }

    public void freeHeap() {
        // No need to free in Java, garbage collector will handle it
    }

    public void initHeap() {
        heapSize = 0;
    }

    private void swap(Object a, Object b, int valSize) {
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

    private void copy(Object dst, Object src, int valSize) {
        if ((valSize & 7) == 0) {
            long[] p = (long[]) src;
            long[] q = (long[]) dst;
            valSize /= 8;
            while (valSize-- > 0) {
                q[0] = p[0];
            }
        } else {
            byte[] p = (byte[]) src;
            byte[] q = (byte[]) dst;
            while (valSize-- > 0) {
                q[0] = p[0];
            }
        }
    }

    public void push(Object val) {
        if (heapSize == maxSize) {
            maxSize = 2 * maxSize + 1;
            array = Arrays.copyOf(array, valSize * (maxSize + 1));
        }
        heapSize++;
        byte[] array = (byte[]) this.array;
        int k = heapSize;
        int valSize = this.valSize;
        Comparator comparator = this.comparator;
        copy(array + k * valSize, val, valSize);
        while (k > 1) {
            int parent = k / 2;
            if (comparator.compare(array + parent * valSize, array + k * valSize) <= 0) {
                return;
            }
            swap(array + parent * valSize, array + k * valSize, valSize);
            k = parent;
        }
    }

    public void pop(Object res) {
        byte[] array = (byte[]) this.array;
        int valSize = this.valSize;
        if (res != null) {
            copy(res, array + valSize, valSize);
        }
        copy(array + valSize, array + valSize * heapSize, valSize);
        heapSize--;
        Comparator comparator = this.comparator;
        int n = heapSize;
        int k = 1;
        while (2 * k + 1 <= n) {
            int c = comparator.compare(array + 2 * k * valSize, array + (2 * k + 1) * valSize);
            int next = 2 * k + (c <= 0 ? 0 : 1);
            if (comparator.compare(array + k * valSize, array + next * valSize) <= 0) return;
            swap(array + k * valSize, array + next * valSize, valSize);
            k = next;
        }
        if (2 * k <= n && comparator.compare(array + k * valSize, array + 2 * k * valSize) > 0) {
            swap(array + k * valSize, array + 2 * k * valSize, valSize);
        }
    }

    public void top(Object res) {
        byte[] array = (byte[]) this.array;
        int valSize = this.valSize;
        if (res != null) {
            copy(res, array + valSize, valSize);
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
        while (len > 0) {
            parent[index[--len]] = x;
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
        for (int i = k; i < 2 * k; ++i) {
            array[i] = ini[i - k];
        }
        for (int i = k - 1; i > 0; --i) {
            merger.merge(array[i], array[2 * i], array[2 * i + 1]);
        }
    }

    public void update(int k, T val) {
        k += size;
        array[k] = val;
        for (k >>= 1; k > 0; k >>= 1) {
            merger.merge(array[k], array[2 * k], array[2 * k + 1]);
        }
    }

    public T find(int l, int r) {
        T res = null;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) res = merger.merge(res, (T) array[l++]);
            if ((r & 1) != 0) res = merger.merge(res, (T) array[--r]);
        }
        return res;
    }
}

interface Merger<T> {
    T merge(T a, T b);
}

class IndexVal {
    int index;
    int val;
}

class SegmentNode {
    int index;
    long val;
}

class Edge {
    int a, b;
    long c;
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
            p[i] = new IndexVal();
            p[i].index = i;
            p[i].val = a[i];
        }
        Arrays.sort(p, Comparator.comparingInt(o -> o.val));
        SegmentNode[] l = new SegmentNode[n];
        SegmentNode[] r = new SegmentNode[n];
        for (int i = 0; i < n; ++i) {
            l[i] = new SegmentNode();
            l[i].index = i;
            l[i].val = (long) a[i] + (long) (n - 1 - i) * d;
            r[i] = new SegmentNode();
            r[i].index = i;
            r[i].val = (long) a[i] + (long) i * d;
        }
        SegmentTree<SegmentNode> leftTree = new SegmentTree<>(l, n,