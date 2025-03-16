
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = sc.nextInt();
            depth[i] = depth[p[i]] + 1;
            cnt[depth[i]]++;
        }
        graph g = new graph(n + 1);
        for (int i = 1; i <= n; ++i) {
            g.addEdge(p[i], i);
        }
        deque[] dp = new deque[n + 1];
        deque[] child = new deque[n + 1];
        node[] lst = new node[n + 1];
        for (int i = n; i >= 0; --i) {
            int v = i;
            if (g.start[v] == -1) {
                dp[v] = new_deque();
                push_front(dp[v], new node(1, 1));
                continue;
            }
            int len = 0;
            for (int p = g.start[v]; p!= -1; p = g.edge[p].next) {
                int u = g.edge[p].vertex;
                child[len++] = dp[u];
            }
            if (len > 1) {
                Arrays.sort(child, new Comparator<deque>() {
                    public int compare(deque p, deque q) {
                        return get_size(p) - get_size(q);
                    }
                });
                for (int d = 0; d < get_size(child[1]); ++d) {
                    int j = 0;
                    for (; j < len && d < get_size(child[j]); ++j) {
                        lst[j] = get_at(child[j], d);
                    }
                    assign_at(child[0], d, merge(lst, j));
                }
                for (int j = 1; j < len; ++j) {
                    free_deque(child[j]);
                }
            }
            dp[v] = child[0];
            push_front(dp[v], new node(1, 1));
        }
        long ans = 0;
        for (int i = 0; i < get_size(dp[0]); ++i) {
            ans += (long) mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % mod;
        }
        System.out.println(ans % mod);
    }

    static int mod = 1000000007;

    static int mod_pow(int r, int n) {
        long t = 1;
        long s = r;
        while (n > 0) {
            if (n % 2 == 1) t = t * s % mod;
            s = s * s % mod;
            n >>= 1;
        }
        return (int) t;
    }

    static class graph {
        graph_edge[] edge;
        int[] start;
        int pointer;
        int vertex_num;
        int edge_max_size;

        graph(int vertex_num) {
            this.vertex_num = vertex_num;
            edge = new graph_edge[1];
            start = new int[vertex_num];
            pointer = 0;
            edge_max_size = 1;
            for (int i = 0; i < vertex_num; ++i) {
                start[i] = -1;
            }
        }

        void addEdge(int from, int to) {
            if (pointer == edge_max_size) {
                edge_max_size *= 2;
                graph_edge[] new_edge = new graph_edge[edge_max_size];
                for (int i = 0; i < pointer; ++i) {
                    new_edge[i] = edge[i];
                }
                edge = new_edge;
            }
            edge[pointer] = new graph_edge(to, start[from]);
            start[from] = pointer++;
        }
    }

    static class deque {
        deque_val[] array;
        int front;
        int last;
        int mask;

        deque() {
            const int len = 2;
            array = new deque_val[len];
            front = last = 0;
            mask = len - 1;
        }
    }

    static class deque_val {
        int one;
        int zero;

        deque_val(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    static class node {
        int one;
        int zero;

        node(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    static void push_front(deque d, node v) {
        if (((d.last + 1) & d.mask) == d.front) {
            deque_realloc(d);
        }
        d.front = (d.front + d.mask) & d.mask;
        d.array[d.front] = v;
    }

    static deque_val get_at(deque d, int x) {
        return d.array[(d.front + x) & d.mask];
    }

    static void assign_at(deque d, int x, deque_val v) {
        d.array[(d.front + x) & d.mask] = v;
    }

    static int get_size(deque d) {
        return (d.last + (~d.front + 1)) & d.mask;
    }

    static void deque_realloc(deque d) {
        deque_val[] array = new deque_val[2 * (d.mask + 1)];
        int k = 0;
        for (int i = d.front; i!= d.last; i = (i + 1) & d.mask) {
            array[k++] = d.array[i];
        }
        d.array = array;
        d.front = 0;
        d.last = k;
        d.mask = 2 * d.mask + 1;
    }

    static deque_val merge(node[] lst, int len) {
        deque_val v = new deque_val(0, 0);
        for (int i = 0; i < len; ++i) {
            v.one = (v.one + lst[i].one) % mod;
            v.zero = (v.zero + lst[i].zero) % mod;
        }
        return v;
    }

    static void free_deque(deque d) {
        free(d.array);
        free(d);
    }
}

// 