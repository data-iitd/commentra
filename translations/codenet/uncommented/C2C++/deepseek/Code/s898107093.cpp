#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int main() {
    int n, taro = 0, hanako = 0, i;
    std::cin >> n;
    std::vector<std::string*> t(n);
    std::vector<std::string*> h(n);
    for (i = 0; i < n; i++) {
        t[i] = new std::string;
        h[i] = new std::string;
        std::cin >> *t[i];
        std::cin >> *h[i];
        if (t[i]->compare(*h[i]) < 0) hanako += 3;
        if (t[i]->compare(*h[i]) > 0) taro += 3;
        if (t[i]->compare(*h[i]) == 0) {
            taro += 1;
            hanako += 1;
        }
    }
    std::cout << taro << " " << hanako << std::endl;
    for (i = 0; i < n; i++) {
        delete t[i];
        delete h[i];
    }
    return 0;
}

