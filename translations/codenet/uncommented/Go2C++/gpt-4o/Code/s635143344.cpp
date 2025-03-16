#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> in(3);
    std::cin >> in[0] >> in[1] >> in[2];
    
    std::sort(in.begin(), in.end());

    std::cout << in[2] * 10 + in[1] + in[0] << std::endl;

    return 0;
}

// <END-OF-CODE>
