
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

double solve(const std::vector<double>& x, const std::vector<std::string>& u) {
return std::accumulate(x.cbegin(), x.cend(), 0.0,
[&](double sum, double value) {
return sum + value * (u[&value - &x[0]] == "JPY"? 1 : 380000);
});
}

int main() {
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
int N;
std::cin >> N;
std::vector<double> x(N);
std::vector<std::string> u(N);
for (int i = 0; i < N; ++i) {
std::cin >> x[i] >> u[i];
}
std::cout << solve(x, u) << '\n';
return 0;
}

