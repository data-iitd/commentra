
import java.util.*;

public class s132677252{
    static int mod = 1000000007;

    static int mod_pow(int r, int n) {
        int t = 1;
        int s = r;
        while (n > 0) {
            if (n % 2 == 1) t = (int) ((long) t * s % mod);
            s = (int) ((long) s * s % mod);
            n /= 2;
        }
        return t;
    }

    static class Deque {
        int[] array;
        int front;
        int last;
        int mask;

        Deque() {
            int len = 2;
            array = new int[len];
            front = last = 0;
            mask = len - 1;
        }

        int get_size() {
            return (last + (~front + 1)) & mask;
        }

        int get_at(int x) {
            return array[(front + x) & mask];
        }

        void assign_at(int x, int v) {
            array[(front + x) & mask] = v;
        }

        void push_front(int v) {
            if (((last + 1) & mask) == front) {
                int[] new_array = new int[array.length * 2];
                int k = 0;
                for (int i = front; i!= last; i = (i + 1) & mask) {
                    new_array[k++] = array[i];
                }
                array = new_array;
                front = 0;
                last = k;
                mask = array.length - 1;
            }
            front = (front + mask) & mask;
            array[front] = v;
        }
    }

    static class Node {
        int one;
        int zero;

        Node(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    static Node merge(Node[] a, int n) {
        long one = 0;
        long zero = 1;
        long total = 1;
        for (int i = 0; i < n; ++i) {
            one = (one * a[i].zero + zero * a[i].one) % mod;
            zero = zero * a[i].zero % mod;
            total = total * (a[i].zero + a[i].one) % mod;
        }
        return new Node((int) one, (int) ((total + mod - one) % mod));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        Deque[] dp = new Deque[n + 1];
        Deque[] child = new Deque[n + 1];
        Node[] lst = new Node[n + 1];
        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt();
            dp[i] = new Deque();
            dp[i].push_front(new Node(1, 1));
            depth[i] = depth[p[i]] + 1;
            cnt[depth[i]]++;
        }
        for (int i = n; i >= 0; --i) {
            int v = i;
            if (dp[v] == null) {
                dp[v] = new Deque();
                dp[v].push_front(new Node(1, 1));
                continue;
            }
            int len = 0;
            for (int p = 0; p!= -1; p = g.edge[p].next) {
                int u = g.edge[p].vertex;
                child[len++] = dp[u];
            }
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> Integer.compare(a.get_size(), b.get_size()));
                for (int d = 0; d < child[1].get_size(); ++d) {
                    int j = 0;
                    for (; j < len && d < child[j].get_size(); ++j) {
                        lst[j] = child[j].get_at(d);
                    }
                    child[0].assign_at(d, merge(lst, j));
                }
                for (int j = 1; j < len; ++j) {
                    child[j] = null;
                }
            }
            dp[v] = child[0];
            dp[v].push_front(new Node(1, 1));
        }
        long ans = 0;
        for (int i = 0; i < dp[0].get_size(); ++i) {
            ans += (long) mod_pow(2, n + 1 - cnt[i]) * dp[0].get_at(i).one % mod;
        }
        System.out.println(ans % mod);
    }
}

