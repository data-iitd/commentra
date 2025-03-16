#include <iostream>
#include <vector>
#include <limits>

#define N 100000
#define INF 1000000

struct Date {
    int go, back, cost;
};

int n;
std::vector<int> d(N, INF);
std::vector<Date> a;

void root(int b);

int main() {
    int u, k;
    std::cin >> n;
    a.reserve(500000); // Reserve space for the edges

    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            Date edge;
            edge.back = u;
            std::cin >> edge.go >> edge.cost;
            a.push_back(edge);
        }
    }

    root(a.size());

    for (int i = 0; i < n; i++)
        std::cout << i << " " << d[i] << std::endl;

    return 0;
}

void root(int b) {
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    bool flag = true;

    while (flag) {
        flag = false;
        for (int i = 0; i < b; i++) {
            if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                d[a[i].go] = a[i].cost + d[a[i].back];
                flag = true;
            }
        }
    }
}

// <END-OF-CODE>
