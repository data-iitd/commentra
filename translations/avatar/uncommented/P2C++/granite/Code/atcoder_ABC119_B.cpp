
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        std::replace(s.begin(), s.end(), 'JPY', '* 1.0');
        std::replace(s.begin(), s.end(), 'BTC', '* 380000.0');
        std::stringstream ss;
        ss << s;
        double v;
        ss >> v;
        x[i] = v;
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    std::cout << sum << std::endl;
    return 0;
}
// END-OF-CODE