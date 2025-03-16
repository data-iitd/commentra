#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> get_nums(int num, int t) {
    std::vector<int> result(num);
    int quotient = t / num;
    int remainder = t % num;
    
    for (int i = 0; i < num; ++i) {
        result[i] = (i < remainder) ? quotient + 1 : quotient;
    }
    
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    std::vector<int> ans;
    std::vector<int> first_part = get_nums(k, sk);
    std::vector<int> second_part = get_nums(n - k, sa - sk);
    
    ans.insert(ans.end(), first_part.begin(), first_part.end());
    ans.insert(ans.end(), second_part.begin(), second_part.end());

    std::ostringstream oss;
    for (size_t i = 0; i < ans.size(); ++i) {
        oss << ans[i];
        if (i < ans.size() - 1) {
            oss << " ";
        }
    }
    
    std::cout << oss.str() << std::endl;

    return 0;
}
// <END-OF-CODE>
