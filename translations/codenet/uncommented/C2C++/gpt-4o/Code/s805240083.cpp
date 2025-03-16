#include <iostream>
#include <string>
#include <queue>

#define MAX 100005

struct P {
    std::string name;
    int t;
};

std::queue<P> Q;

int main() {
    int i, q, n, T = 0;
    P a;
    std::cin >> n >> q;

    for (i = 0; i < n; i++) {
        std::cin >> a.name >> a.t;
        Q.push(a);
    }

    while (n != 0) {
        a = Q.front();
        Q.pop();
        if (a.t > q) {
            a.t -= q;
            T += q;
            Q.push(a);
        } else {
            T += a.t;
            std::cout << a.name << " " << T << std::endl;
            n--;
        }
    }

    return 0;
}

// <END-OF-CODE>
