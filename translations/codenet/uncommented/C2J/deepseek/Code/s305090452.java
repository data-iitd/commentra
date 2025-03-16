public class Main {
    static class BinaryHeap {
        private Object[] array;
        private int heapSize;
        private int maxSize;
        private int valSize;
        private java.util.Comparator<?> cmp;

        public BinaryHeap(int valSize, java.util.Comparator<?> cmp) {
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

        private void heapFuncSwap(Object a, Object b, int valSize) {
            if ((valSize & 7) == 0) {
                long[] p = (long[]) a;
                long[] q = (long[]) b;
                valSize /= 8;
                while (valSize-- > 0) {
                    long tmp = p[valSize];
                    p[valSize] = q[valSize];
                    q[valSize] = tmp;
                }
            } else {
                byte[] p = (byte[]) a;
                byte[] q = (byte[]) b;
                while (valSize-- > 0) {
                    byte tmp = p[valSize];
                    p[valSize] = q[valSize];
                    q[valSize] = tmp;
                }
            }
        }

        private void heapFuncCopy(Object dst, Object src, int valSize) {
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

        public void push(Object val) {
            if (heapSize == maxSize) {
                maxSize = 2 * maxSize + 1;
                array = java.util.Arrays.copyOf(array, valSize * (maxSize + 1));
            }
            heapSize++;
            byte[] array = (byte[]) this.array;
            int k = heapSize;
            int valSize = this.valSize;
            java.util.Comparator<?> cmp = this.cmp;
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

        public void pop(Object res) {
            byte[] array = (byte[]) this.array;
            int valSize = this.valSize;
            if (res != null) {
                heapFuncCopy(res, array, valSize);
            }
            heapFuncCopy(array, array + valSize * heapSize, valSize);
            heapSize--;
            java.util.Comparator<?> cmp = this.cmp;
            int n = heapSize;
            int k = 1;
            while (2 * k + 1 <= n) {
                int c = cmp.compare(array + 2 * k * valSize, array + (2 * k + 1) * valSize);
                int next = 2 * k + (c <= 0 ? 0 : 1);
                if (cmp.compare(array + k * valSize, array + next * valSize) <= 0) return;
                heapFuncSwap(array + k * valSize, array + next * valSize, valSize);
                k = next;
            }
            if (2 * k <= n && cmp.compare(array + k * valSize, array + 2 * k * valSize) > 0) {
                heapFuncSwap(array + k * valSize, array + 2 * k * valSize, valSize);
            }
        }

        public void top(Object res) {
            byte[] array = (byte[]) this.array;
            int valSize = this.valSize;
            if (res != null) {
                heapFuncCopy(res, array, valSize);
            }
        }
    }

    static class UnionFind {
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

    static class SegmentTree {
        private Object[] array;
        private int size;
        private int valSize;
        private java.util.function.BiFunction<Object, Object, Object> func;

        public SegmentTree(Object[] ini, int n, int valSize, java.util.function.BiFunction<Object, Object, Object> func) {
            int k = 1;
            while (k < n) k *= 2;
            this.array = new Object[2 * k];
            this.size = k;
            this.valSize = valSize;
            this.func = func;
            System.arraycopy(ini, 0, array, k, n);
            for (int i = k; i < 2 * k; ++i) {
                java.lang.System.arraycopy(ini[i - k], 0, array[i], 0, valSize);
            }
            for (int i = k - 1; i > 0; --i) {
                array[i] = func.apply(array[2 * i], array[2 * i + 1]);
            }
        }

        public void update(int k, Object val) {
            k += size;
            java.lang.System.arraycopy(val, 0, array[k], 0, valSize);
            for (k >>= 1; k > 0; k >>= 1) {
                array[k] = func.apply(array[2 * k], array[2 * k + 1]);
            }
        }

        public void updateTmp(int k, Object val) {
            k += size;
            java.lang.System.arraycopy(val, 0, array[k], 0, valSize);
        }

        public void updateAll() {
            Object[] a = array;
            int size = this.size;
            for (int i = size - 1; i > 0; --i) {
                a[i] = func.apply(a[2 * i], a[2 * i + 1]);
            }
        }

        public void find(int l, int r, Object res) {
            int llen = 0;
            int rlen = 0;
            int[] lindex = new int[32];
            int[] rindex = new int[32];
            for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) lindex[llen++] = l++;
                if ((r & 1) != 0) rindex[rlen++] = --r;
            }
            if (llen == 0) {
                lindex[llen++] = rindex[--rlen];
            }
            java.lang.System.arraycopy(array[lindex[0]], 0, res, 0, valSize);
            for (int i = 1; i < llen; ++i) {
                java.lang.System.arraycopy(func.apply(res, array[lindex[i]]), 0, res, 0, valSize);
            }
            for (int i = rlen - 1; i >= 0; --i) {
                java.lang.System.arraycopy(func.apply(res, array[rindex[i]]), 0, res, 0, valSize);
            }
        }
    }

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
        java.util.Arrays.sort(p, (o1, o2) -> o1.val - o2.val);
        segment_node ini = new segment_node(n, (long) (n + 2) * 1000000000 + 1);
        SegmentTree l = new SegmentTree(new segment_node[]{ini}, n,