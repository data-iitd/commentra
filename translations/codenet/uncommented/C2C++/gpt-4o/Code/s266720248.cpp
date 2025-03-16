#include <iostream>
#include <string>
#include <queue>

#define LEN 100005

struct P {
    std::string name;
    int t;
};

std::queue<P> Q;
int elaps = 0, n, q;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        P u;
        std::cin >> u.name;
        std::cin >> u.t;
        Q.push(u);
    }

    while (!Q.empty()) {
        P u = Q.front();
        Q.pop();
        int c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if (u.t > 0) {
            Q.push(u);
        } else {
            std::cout << u.name << " " << elaps << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
