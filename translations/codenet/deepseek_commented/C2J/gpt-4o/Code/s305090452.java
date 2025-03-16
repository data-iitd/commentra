import java.util.*;

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
            if (cmp.compare(array[k], array[next]) <= 0) return res;
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

    public int root(int x) {
        List<Integer> index = new ArrayList<>();
        while (parent[x] >= 0) {
            index.add(x);
            x = parent[x];
        }
        for (int i = index.size() - 1; i >= 0; i--) {
            parent[index.get(i)] = x;
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
        List<Integer> lIndex = new ArrayList<>();
        List<Integer> rIndex = new ArrayList<>();
        while (l < r) {
            if (l % 2 == 1) lIndex.add(l++);
            if (r % 2 == 1) rIndex.add(--r);
            l >>= 1;
            r >>= 1;
        }
        if (lIndex.isEmpty()) {
            lIndex.add(rIndex.remove(rIndex.size() - 1));
        }
        System.arraycopy(array, lIndex.get(0), res, 0, valSize);
        for (int i = 1; i < lIndex.size(); i++) {
            func.accept(res, array[lIndex.get(i)]);
        }
        for (int i = rIndex.size() - 1; i >= 0; i--) {
            func.accept(res, array[rIndex.get(i)]);
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
        SegmentTree l = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a) -> {
            SegmentNode p = (SegmentNode) a;
            SegmentNode q = (SegmentNode) c;
            if (p.val < q.val) {
                c = p;
            } else {
                c = q;
            }
        });
        SegmentTree r = new SegmentTree(ini, n, SegmentNode.class.getDeclaredFields().length, (c, a) -> {
            SegmentNode p = (SegmentNode) a;
            SegmentNode q = (SegmentNode) c;
            if (p.val < q.val) {
                c = p;
            } else {
                c = q;
            }
        });
        for (int i = 0; i < n; i++) {
            l.update(i, new SegmentNode(i, a[i] + (long) (n - 1 - i) * d));
            r.update(i, new SegmentNode(i, a[i] + (long) i * d));
        }
        long sum = 0;
        UnionFind u = new UnionFind(n);
        BinaryHeap h = new BinaryHeap(Edge.class.getDeclaredFields().length, (a, b) -> {
            long d = ((Edge) a).c - ((Edge) b).c;
            return d == 0 ? 0 : d < 0 ? -1 : 1;
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
