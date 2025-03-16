

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;  // Take an integer input N, which represents the number of elements.
    std::vector<double> x;
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        std::stringstream ss(s);
        double a;
        ss >> a;
        std::string b;
        ss >> b;
        if (b == "JPY") {
            a *= 1.0;
        } else if (b == "BTC") {
            a *= 380000.0;
        }
        x.push_back(a);
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    std::cout << sum << std::endl;  // Print the sum of the elements in the vector x.
    return 0;
}
// 