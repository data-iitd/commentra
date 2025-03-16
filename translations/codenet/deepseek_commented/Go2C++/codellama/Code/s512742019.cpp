
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int INF = 1 << 29;

struct Scanner {
    string s;
    int pos;

    Scanner() {
        s = "";
        pos = 0;
    }

    Scanner(string s) {
        this->s = s;
        pos = 0;
    }

    char nextChar() {
        if (pos >= s.size()) return '\0';
        return s[pos++];
    }

    void ignore(char c) {
        while (nextChar() == c);
        pos--;
    }

    string next() {
        while (pos < s.size() && s[pos] == ' ') pos++;
        string res = "";
        while (pos < s.size() && s[pos] != ' ') res += s[pos++];
        return res;
    }

    int nextInt() {
        int res = 0;
        bool neg = false;
        char c = nextChar();
        if (c == '-') {
            neg = true;
            c = nextChar();
        }
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = nextChar();
        }
        if (neg) return -res;
        return res;
    }

    ll nextLong() {
        ll res = 0;
        bool neg = false;
        char c = nextChar();
        if (c == '-') {
            neg = true;
            c = nextChar();
        }
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = nextChar();
        }
        if (neg) return -res;
        return res;
    }

    double nextDouble() {
        double res = 0;
        bool neg = false;
        char c = nextChar();
        if (c == '-') {
            neg = true;
            c = nextChar();
        }
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = nextChar();
        }
        if (c == '.') {
            double div = 1;
            c = nextChar();
            while (c >= '0' && c <= '9') {
                res += (c - '0') / div;
                div *= 10;
                c = nextChar();
            }
        }
        if (neg) return -res;
        return res;
    }

    string nextLine() {
        string res = "";
        char c = nextChar();
        while (c != '\n' && c != '\r') {
            res += c;
            c = nextChar();
        }
        return res;
    }

    bool hasNext() {
        return pos < s.size();
    }
};

struct Mon {
    int x, h;
};

struct Mons {
    vector<Mon> v;

    bool operator<(const Mons& other) const {
        return v[0].x < other.v[0].x;
    }
};

struct Node {
    int x, h;
};

struct Queue {
    vector<Node> v;

    void push(Node n) {
        v.push_back(n);
    }

    Node first() {
        return v[0];
    }

    Node pop() {
        Node res = v[0];
        v.erase(v.begin());
        return res;
    }

    bool isEmpty() {
        return v.size() == 0;
    }
};

int main() {
    Scanner sc;
    int N, D, A;
    sc >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        sc >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end());
    Queue q;
    int ans = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.isEmpty() && q.first().x < m.x) {
            total -= q.pop().h;
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            int damage = count * A;
            q.push(Node{m.x + 2*D, damage});
            total += damage;
        }
    }

    cout << ans << endl;

    return 0;
}

