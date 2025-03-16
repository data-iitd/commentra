#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>

typedef int32_t i32;
typedef int64_t i64;

struct graph_edge {
    int32_t vertex;
    int32_t next;
};

struct directedGraph {
    std::vector<graph_edge> edge;
    std::vector<int32_t> start;
    int32_t pointer;
    int32_t vertex_num;
    int32_t edge_max_size;

    directedGraph(int vertex_num) : pointer(0), vertex_num(vertex_num), edge_max_size(1) {
        edge.resize(edge_max_size);
        start.resize(vertex_num, -1);
    }
};

directedGraph* new_graph(const int vertex_num) {
    return new directedGraph(vertex_num);
}

void add_edge(directedGraph* g, int32_t from, int32_t to) {
    if (g->pointer == g->edge_max_size) {
        g->edge_max_size *= 2;
        g->edge.resize(g->edge_max_size);
    }
    g->edge[g->pointer] = {to, g->start[from]};
    g->start[from] = g->pointer++;
}

const i32 mod = 1000000007;

i32 mod_pow(i32 r, i32 n) {
    i32 t = 1;
    i32 s = r;
    while (n > 0) {
        if (n & 1) t = (i64)t * s % mod;
        s = (i64)s * s % mod;
        n >>= 1;
    }
    return t;
}

struct node {
    i32 one;
    i32 zero;
};

node merge(node* a, i32 n) {
    i64 one = 0;
    i64 zero = 1;
    i64 total = 1;
    for (i32 i = 0; i < n; ++i) {
        one = (one * a[i].zero + zero * a[i].one) % mod;
        zero = zero * a[i].zero % mod;
        total = total * (a[i].zero + a[i].one) % mod;
    }
    return {one, (total + mod - one) % mod};
}

struct deque_val {
    node value;
};

struct Deque {
    std::vector<deque_val> array;
    size_t front;
    size_t last;
    size_t mask;

    Deque() : front(0), last(0), mask(1) {
        array.resize(2);
    }

    size_t get_size() const {
        return (last + (~front + 1)) & mask;
    }

    void realloc() {
        std::vector<deque_val> new_array(2 * (mask + 1));
        size_t k = 0;
        for (size_t i = front; i != last; i = (i + 1) & mask) {
            new_array[k++] = array[i];
        }
        array = std::move(new_array);
        front = 0;
        last = k;
        mask = 2 * mask + 1;
    }

    deque_val get_at(size_t x) const {
        return array[(front + x) & mask];
    }

    void assign_at(size_t x, deque_val v) {
        array[(front + x) & mask] = v;
    }

    void push_front(deque_val v) {
        if (((last + 1) & mask) == front) {
            realloc();
        }
        front = (front + mask) & mask;
        array[front] = v;
    }
};

int cmp_deque_size(const void* a, const void* b) {
    Deque* p = *(Deque**)a;
    Deque* q = *(Deque**)b;
    i32 d = p->get_size() - q->get_size();
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

void run() {
    i32 n;
    std::cin >> n;
    std::vector<i32> p(n + 1);
    std::vector<i32> depth(n + 1);
    std::vector<i32> cnt(n + 1);
    cnt[0] = 1;
    directedGraph* g = new_graph(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> p[i];
        add_edge(g, p[i], i);
        depth[i] = depth[p[i]] + 1;
        cnt[depth[i]]++;
    }
    std::vector<Deque*> dp(n + 1);
    std::vector<Deque*> child(n + 1);
    std::vector<node> lst(n + 1);
    for (i32 i = n; i >= 0; --i) {
        i32 v = i;
        if (g->start[v] == -1) {
            dp[v] = new Deque();
            dp[v]->push_front({1, 1});
            continue;
        }
        i32 len = 0;
        for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
            i32 u = g->edge[p].vertex;
            child[len++] = dp[u];
        }
        if (len > 1) {
            std::qsort(child.data(), len, sizeof(Deque*), cmp_deque_size);
            for (i32 d = 0; d < (i32)child[1]->get_size(); ++d) {
                i32 j = 0;
                for (; j < len && d < (i32)child[j]->get_size(); ++j) {
                    lst[j] = child[j]->get_at(d).value;
                }
                child[0]->assign_at(d, merge(lst.data(), j));
            }
            for (i32 j = 1; j < len; ++j) {
                delete child[j];
            }
        }
        dp[v] = child[0];
        dp[v]->push_front({1, 1});
    }
    i64 ans = 0;
    for (i32 i = 0; i < (i32)dp[0]->get_size(); ++i) {
        ans += (i64)mod_pow(2, n + 1 - cnt[i]) * dp[0]->get_at(i).value.one % mod;
    }
    std::cout << ans % mod << "\n";
    delete g;
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
